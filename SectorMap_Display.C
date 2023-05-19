//sPHENIX Sector Mapping of regions R1 R2 and R3 May 18, 2023
//Written at the Mar 2023 commisioning workfest at Brookhaven National Labaoratory
//Jennifer James
#include "TString.h"
#include "TFile.h"
#include "TSystem.h"
#include "TTree.h"
#include "TH1F.h"
#include "TH3I.h"
#include "TCanvas.h"
#include "TNtuple.h"
#include <iostream>

// forward declaration
void Ana( TNtuple*, TNtuple*, char[2], double tot[24], double dead[24], int );

void SectorMap_Display( )
{
  string runNumber = "pedestal-00010131";

  // const string fileName = "/sphenix/user/rosstom/test/testFiles/TPC_ebdc"+sectorNumber+"_"+runNumber+"-0000.prdf_TPCRawDataTree.root";

  const char* run_str[24] =  { "00", "01", "02", "03" ,"04", "05", "06", "07", "08", "09", "10" , "11", "12" , "13" , "14", "15" , "16" , "17", "18" , "19", "20", "21" , "22", "23"  };
  double tot[24] = {0};
  double dead[24] = {0};

  double tot_ult[24]={0};
  double dead_ult[24]={0};
/*
  TH1F *means_dist = new TH1F("means_dist", "Pedestal Runs, Distribution of mean ADC for each channel in TPC",200,-0.5,199.5);
  means_dist->SetXTitle("Mean ADC");
  means_dist->SetYTitle("Frequency");

  TH1F *widths_dist = new TH1F("widths_dist", "Pedestal Runs, Distribution of std. dev. ADC for each channel in TPC",100,-0.5,19.5);
  */
  TFile h_outfile10131("pedestal-10131-outfile.root", "RECREATE");
  TNtuple *h_Alive=new TNtuple("h_Alive","Location Tntuple Cuts","chan_id:fee_id:module_id:pedMean:pedStdi:sec_id");
  TNtuple *h_AliveTot=new TNtuple("h_AliveTot","Location Tntuple No Cuts","chan_id:fee_id:module_id:pedMean:pedStdi:sec_id");
 
 

  //create TNtuple to produce plots of sector_id:fee_id:channel_id
  // TH3I *h_layercenters = new TH3I("h_layercenters","Layer centers;Sector ID;FEE ID;Channel ID",24,-0.5,23.5,26,-0.5,25.5,256,-0.5,255.5); //create 3D histogram of sector ID, FEE Id, and Channl ID

  for( int i = 0; i < 24; i++ )
  {
    char run[2]; //define character string
    std::sprintf(run,run_str[i]); //print run_str values indexed at i<72

    Ana( h_Alive, h_AliveTot, run, tot, dead, i); //create Ana function

    tot_ult[i] += tot[i]; //find total channels
    dead_ult[i] += dead[i]; //find dead channels
  }

  h_outfile10131.cd();
  h_Alive->Write();
  h_AliveTot->Write();
  h_outfile10131.Close();

 }

// Define Ana function 
/*
void Ana( TNtuple *ntup, TNtuple *ntuptup, TH1F *means_dist = new TH1F("means_dist", "Distribution of mean ADC for each channel in TPC",200,0,200), TH1F *widths_dist = new TH1F("widths_dist", "Distribution of std. dev. ADC for each channel in TPC",100,0,20), char run[6] = "175241",double tot[24]={0}, double dead[24]={0}, int j = 0)
{ // Ana starts
*/
void Ana( TNtuple *Alive, TNtuple *AliveTot, char run[2] = "11",double tot[24]={0}, double dead[24]={0}, int j = 0)
{ // Ana starts     
     


  const TString filename2( Form( "/sphenix/u/jamesj3j3/workfest_Charles_mistake/sPHENIXProjects/outputfile_TPC_ebdc%s_pedestal-00010131.root", run) );
  // const string fileName = "( Form(/sphenix/user/rosstom/test/testFiles/TPC_ebdc"+sectorNumber+"_"+runNumber+"-0000.prdf_TPCRawDataTree.root) )";
  //    std::cout << "Analyze - filename2: " << filename2 << std::endl;

  //TFile *infile2 = new TFile(filename2);
  TFile* infile2 = TFile::Open(filename2);

  if(!infile2) return;

  TTree *treesd;  
  treesd = (TTree*) infile2->Get("outputTree");

  Int_t isAlive, chan, fee, module, slot;
  Float_t pedMean, pedStdi;

  treesd->SetBranchAddress("isAlive",&isAlive);
  treesd->SetBranchAddress("chan",&chan);
  treesd->SetBranchAddress("fee",&fee);
  treesd->SetBranchAddress("module",&module);
  treesd->SetBranchAddress("slot", &slot);
  treesd->SetBranchAddress("pedMean",&pedMean);
  treesd->SetBranchAddress("pedStdi",&pedStdi);

  std::cout << "sector = "<< run <<std::endl;

  UInt_t nEntries = treesd->GetEntries();
  std::string fs(run);
  float sec = std::stof(fs); 

  std::cout << "sector from char = " << sec << std::endl;  
 
  // defining a cut of the mean and standard deviation
   for (int i=0;i<nEntries;i++){
     treesd->GetEntry(i); 

     double pedestal = pedMean;
     double noise = pedStdi;
     
     //if(sec_reg_id.first != -1 && sec_reg_id.second != -1) ntuptup->Fill(1.0*sec_reg_id.first,1.0*(i%256),1.0*sec_reg_id.second);
      AliveTot->Fill(1.0*chan,1.0*fee,1.0*module,pedMean,pedStdi,1.0*sec);

      if (isAlive == 1)Alive->Fill(1.0*chan,1.0*fee,1.0*module,pedMean, pedStdi, 1.0*sec); ///addd later

    //     std::pair<int,int> sec_reg_id = get_sec_reg_id(run, i);

   }


}

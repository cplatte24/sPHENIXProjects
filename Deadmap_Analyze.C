//sPHENIX Channel Deadmap Mar 15, 2023
//Written at the Mar 2023 commisioning workfest at Brookhaven National Labaoratory
//Jennifer James, Christopher Platte, Dr. Charles Hughes
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
void Ana( TNtuple*, TNtuple*, TNtuple*, TH1F*, TH1F*, char[6], double tot[24], double dead[24], int );
std::pair<int,int> get_sec_fee_id(char[6], int);

void Deadmap_Analyze( )
{

  const char* run_str[72] =  { "183111", "183801", "184139", "184719", "185416", "190946", "191520", "192145", "192919", "193735", "194940", "195552", "001223", "235613", "235031", "233416", "223026", "215234", "214601", "214018", "212704", "212138", "211706", "204618", "003959", "005800", "011134", "011737", "012416", "012857", "013458", "014110", "014508", "014953", "201125", "015813", "211316", "212156", "2146011", "223709", "224623", "230218", "231336", "233305", "225003", "230638", "205059", "210507", "000015", "001024", "001718", "002149", "002825", "003915", "004351", "004955", "005829", "010244", "010851", "154811", "175604", "175241", "174911", "174456", "173616", "170907", "170333", "165553", "164759", "163808", "162849", "162313" };

  double tot[24] = {0};
  double dead[24] = {0};
  double tot_ult[24] ={0};
  double dead_ult[24] ={0};

  TH1F *means_dist = new TH1F("means_dist", "Pedestal Runs, Distribution of mean ADC for each channel in TPC",200,-0.5,199.5);
  means_dist->SetXTitle("Mean ADC");
  means_dist->SetYTitle("Frequency");

  TH1F *widths_dist = new TH1F("widths_dist", "Pedestal Runs, Distribution of std. dev. ADC for each channel in TPC",100,-0.5,19.5);
  TFile h_outfile("outfile.root", "RECREATE");
 
  TNtuple *h_myTntuple=new TNtuple("h_myTntuple","Location Tntuple","sector_id:fee_id:channel_id");
  TNtuple *h_myTnt=new TNtuple("h_myTnt","MW Location Tntuple","sector_id:fee_id:channel_id:pedestal:noise");
  TNtuple *h_myTntt=new TNtuple("h_myTntt","MW-Full Data Location Tntuple","sector_id:fee_id:channel_id:pedestal:noise");

  //create TNtuple to produce plots of sector_id:fee_id:channel_id
  // TH3I *h_layercenters = new TH3I("h_layercenters","Layer centers;Sector ID;FEE ID;Channel ID",24,-0.5,23.5,26,-0.5,25.5,256,-0.5,255.5); //create 3D histogram of sector ID, FEE Id, and Channl ID


  for( int i = 0; i < 72; i++ )
  {
    char run[6]; //define character string
    std::sprintf(run,run_str[i]); //print run_str values indexed at i<72

    Ana( h_myTntuple, h_myTnt, h_myTntt,  means_dist, widths_dist, run, tot, dead, i); //create Ana function

    tot_ult[i] += tot[i]; //find total channels
    dead_ult[i] += dead[i]; //find dead channels
  }

  h_outfile.cd();
  h_myTntuple->Write();
  h_myTnt->Write();
  h_myTntt->Write();
  //  h_layercenters->Write();
  h_outfile.Close();

 }

// Define Ana function
void Ana( TNtuple *ntup, TNtuple *ntuptup, TNtuple *ntupt, TH1F *means_dist = new TH1F("means_dist", "Distribution of mean ADC for each channel in TPC",200,0,200), TH1F *widths_dist = new TH1F("widths_dist", "Distribution of std. dev. ADC for each channel in TPC",100,0,20), char run[6] = "175241",double tot[24]={0}, double dead[24]={0}, int j = 0)
{ // Ana starts     


  const TString filename( Form( "/sphenix/data/data02/sphnxpro/tpc/chughes/workfest/combined/mean_width_%s_rootfile.root", run) );

    std::cout << "Analyze - filename: " << filename << std::endl;

  TFile *infile = new TFile(filename);

  if(!infile) return;

  TH1F *Mymean = (TH1F*)infile->Get("mean");
  TH1F *Myrms = (TH1F*)infile->Get("width");

 for (int i=0;i<2304;i++){
    double pedestal = Mymean->GetBinContent(i+1);
    double noise = Myrms->GetBinContent(i+1);
    if(pedestal == 0) continue;

    std::pair<int,int> sec_fee_id = get_sec_fee_id(run,i);
    if(sec_fee_id.first == -1 || sec_fee_id.second == -1) continue;

    ntupt->Fill(1.0*sec_fee_id.first,1.0*sec_fee_id.second,1.0*(i%256),1.0*pedestal,1.0*noise);

    if (pedestal > 0 && pedestal > 110 || noise < 0.5)ntup->Fill(1.0*sec_fee_id.first,1.0*sec_fee_id.second,1.0*(i%256)); 
    if (pedestal > 0 && pedestal > 110 || noise < 0.5)ntuptup->Fill(1.0*sec_fee_id.first,1.0*sec_fee_id.second,1.0*(i%256),1.0*pedestal,1.0*noise); 
  }
}
std::pair<int,int> get_sec_fee_id(char run[6], int channel){

    const char* run_str[72] =  { "183111", "183801", "184139", "184719", "185416", "190946", "191520", "192145", "192919", "193735", "194940", "195552", "001223", "235613", "235031", "233416", "223026", "215234", "214601", "214018", "212704", "212138", "211706", "204618", "003959", "005800", "011134", "011737", "012416", "012857", "013458", "014110", "014508", "014953", "201125", "015813", "211316", "212156", "2146011", "223709", "224623", "230218", "231336", "233305", "225003", "230638", "205059", "210507", "000015", "001024", "001718", "002149", "002825", "003915", "004351", "004955", "005829", "010244", "010851", "154811", "175604", "175241", "174911", "174456", "173616", "170907", "170333", "165553", "164759", "163808", "162849", "162313" };
  
  int sectors[72] = {0,1,2,3,4,5,6,7,8,9,10,11,0,1,2,3,4,5,6,7,8,9,10,11,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,12,13,14,15,16,17,18,19,20,21,22,23,12,13,14,15,16,17,18,19,20,21,22,23};

  int sec = -1;

  int fee_div = channel/256;

  //R = 0 is R1R2, =1 is R3, =2 is remaining        
  int R = -1;


  for(int i=0; i<72; i++){

    if(i<=11 || (i>=36 && i<=47)) R=0;
    else if((i>=12 && i<=23) || (i>=48 && i<=59)) R=1;
    else if((i>= 24 && i<=35) || i>=60) R=2;
    

    if(std::atoi(run_str[i]) == std::atoi(run)){
      sec = sectors[i];
      break;

    }
  }
  int fee_ids_R1R2[9] = {2,4,3,13,17,16,0,1,15};
  int fee_ids_R3[9] = {6,7,8,9,21,22,23,24,25};
  int fee_ids_remaining[9] = {4,10,11,12,14,15,18,19,20};

  int  fee_id = -1;

  if(R == 0) fee_id = fee_ids_R1R2[fee_div];
  else if(R == 1) fee_id = fee_ids_R3[fee_div];
  else if(R == 2) fee_id = fee_ids_remaining[fee_div];

  if(R == 0 && fee_id == 15) fee_id = -1;
  if(R == 2 && fee_id == 4) fee_id = -1;
 
  std::pair<int,int> sec_fee_id;

  sec_fee_id.first = sec;
  sec_fee_id.second = fee_id;
 

  return sec_fee_id;

}

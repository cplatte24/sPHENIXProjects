// includes
#ifndef __CINT__
#include "TCanvas.h"
#include "TApplication.h"
#include "TH1D.h"
#include "TH1F.h"
#include "TH2D.h"
#include "TH2F.h"
#include "TH3D.h"
#include "TString.h"
#include "TStyle.h"
#include "TFile.h"
#include "TGraphPolar.h"
#include "TGraphPolargram.h"
#include "TAxis.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TMath.h"
#include "TVirtualFitter.h"
#include "Math/MinimizerOptions.h"
#include "TFitResultPtr.h"
#include "TFitResult.h"
#include "TF1.h"
#include "TPaveLabel.h"
#include <string.h>	
#endif

using namespace std;

void Locate(Int_t id, Double_t *rbin, Double_t *thbin);

void Plot_Display(){


  Double_t A_Side_Arr[36]=  { 97.9341150195422, 98.6314760508309, 96.6915688367129, 97.1508379888268, 98.8089330024814, 98.862828713575, 99.1056456120738, 96.9215491559086, 97.2982580874511, 95.8612975391499, 96.871945259042, 98.2355059416637, 96.5921787709497, 97.12158808933, 97.3424774967853, 97.2098214285714, 97.2113502935421, 97.2972972972973, 97.1540178571429, 96.9208211143695, 98.7917555081734, 99.7209821428571, 97.361993160723, 98.5080058224163, 98.8839285714286, 99.0224828934506, 98.9339019189766, 98.4933035714286, 97.6274608783443, 95.7310565635006, 99.2745535714286, 97.9139504563233, 97.120511908994, 98.21328866555, 94.9657869012708, 98.9331436699858 };
  Double_t C_Side_Arr[36] = { 98.3816964285714, 99.8347107438017, 98.3997155049787, 98.8833054159687, 98.3058210251955, 96.2989323843416, 96.8732551647124, 96.8288444830582, 97.9025950942055, 98.4375, 98.2893450635386, 98.045486851457, 99.4974874371859, 98.4344422700587, 97.6901208244492, 96.536312849162, 97.361993160723, 98.4002843938855, 98.9391401451703, 98.8269794721408, 98.7197724039829, 97.265625, 98.014888337469, 97.9374110953058, 98.9982321744255, 98.8095238095238, 98.7197724039829, 98.3240223463687, 98.4848484848485, 97.9033404406539, 97.1540178571429, 97.9482169027846, 98.0085348506401, 98.7716359575656, 98.1427174975562, 97.3444889050564 };

  //////////////////////////////////////////////////////////////////////// 
  //          A-Side (South) Label Conventions (North)                 //  
  ///////////////////////////////////////////////////////////////////////  
  //   1 - A12_R1   16 - A17_R1   31 - A22_R1    
  //   2 - A12_R2   17 - A17_R2   32 - A22_R2   
  //   3 - A12_R3   18 - A17_R3   33 - A22_R3 
  //   4 - A13_R1   19 - A18_R1   34 - A23_R1
  //   5 - A13_R2   20 - A18_R2   35 - A23_R2
  //   6 - A13_R3   21 - A18_R3   36 - A23_R3
  //   7 - A14_R1   22 - A19_R1
  //   8 - A14_R2   23 - A19_R2
  //   9 - A14_R3   24 - A19_R3
  //  10 - A15_R1   25 - A20_R1
  //  11 - A15_R2   26 - A20_R2
  //  12 - A15_R3   27 - A20_R3
  //  13 - A16_R1   28 - A21_R1
  //  14 - A16_R2   29 - A21_R2
  //  15 - A16_R3   30 - A21_R3
  
  ////////////////////////////////////////////////////////////////////////
  //          C-Side (North) Label Conventions (South)                  //
  ///////////////////////////////////////////////////////////////////////
  //   1 - C00_R1   16 - C05_R1   31 - C10_R1    
  //   2 - C00_R2   17 - C05_R2   32 - C10_R2   
  //   3 - C00_R3   18 - C05_R3   33 - C10_R3 
  //   4 - C01_R1   19 - C06_R1   34 - C11_R1
  //   5 - C01_R2   20 - C06_R2   35 - C11_R2
  //   6 - C01_R3   21 - C06_R3   36 - C11_R3
  //   7 - C02_R1   22 - C07_R1
  //   8 - C02_R2   23 - C07_R2
  //   9 - C02_R3   24 - C07_R3
  //  10 - C03_R1   25 - C08_R1
  //  11 - C03_R2   26 - C08_R2
  //  12 - C03_R3   27 - C08_R3
  //  13 - C04_R1   28 - C09_R1
  //  14 - C04_R2   29 - C09_R2
  //  15 - C04_R3   30 - C09_R3

  gStyle->SetOptStat(0);
/*
  const char * input1="Master_Sparse.root"; //file where sparse is stored

  TFile * infile1 = TFile::Open(input1); //open the file
  
  if(!infile1){ //make sure you have the file in your directory
    cout<<input1<<" not found"<<endl;
    return;
  }

   // if have lists inside input file - create pointer to list
  // Open up the histograms from the infile and give new names
  THnSparseD* sparse = (THnSparseD *)infile1->Get("histsparse"); //get the sparse object and store it in memory
  if(!sparse){
    cout<<"sparse does not exist in "<<input1<<endl; //double check that it's in the file it should be !
    return;
  }
  sparse->THnSparse::GetAxis(2)->SetRange(1,15); //limit to ONLY real trips
 */ 
  //____________________________________________________________________________________________________// 

  // Heat map Visualization

  const Int_t N_rBins = 4; //(one inner bin NOT to be filled, 2nd bin is R1, 3rd bin is R2, 4th bin is R3)
  const Int_t N_thBins = 12; //(12 theta bins of uniform angle (360/12 = 30 degrees = TMath::Pi()/6 ~= 0.523 rad) )

  Double_t rBin_edges[N_rBins + 1] = {0.0, 0.256, 0.504, 0.752, 1.00}; //variable edges for the radial dimensions

  TGraphPolargram* polardummy1 = new TGraphPolargram("polardummy1",0,1,0,2.*TMath::Pi()); //dummy plots to get the canvas right (not to be filled)
  polardummy1->SetToGrad();
  polardummy1->SetNdivPolar(N_thBins);
  polardummy1->SetLineColor(0);
  polardummy1->SetRadialLabelSize(0);

  TGraphPolargram* polardummy2 = new TGraphPolargram("polardummy2",0,1,0,2.*TMath::Pi());
  polardummy2->SetToGrad();
  polardummy2->SetNdivPolar( N_thBins);
  polardummy2->SetLineColor(0);
  polardummy2->SetRadialLabelSize(0);

  for(Int_t i = 0 ; i < 12 ; i++){ //setting the axis label (CCW from horizontal right axis)
    char labelstr1[128];
    char labelstr2[128];
    if(i<=9){ // i -> [0:9]
      sprintf(labelstr2,"C0%d",i);

      if(i<=6){ // i -> [0:6] (halfway)
        sprintf(labelstr1,"A%d",18-i);
      }
      else if(i>6){ // i -> [7:9]
        sprintf(labelstr1,"A%d",30-i);
      }

    } 
    else { // i -> [10:11]
      sprintf(labelstr2,"C%d",i);
      sprintf(labelstr1,"A%d",30-i);
    }
    polardummy1->SetPolarLabel(i,labelstr1);
    polardummy2->SetPolarLabel(i,labelstr2);
  }

  TH2D* ErrASide = new TH2D( "ASide" , "ADC Counts North Side" , N_thBins, -TMath::Pi()/12. , 23.*TMath::Pi()/12. , N_rBins , rBin_edges ); // X maps to theta, Y maps to R

  TH2D* ErrCSide = new TH2D( "CSide" , "ADC Counts South Side" , N_thBins, -TMath::Pi()/12. , 23.*TMath::Pi()/12. , N_rBins , rBin_edges ); // X maps to theta, Y maps to R



  Double_t r, theta;
  Int_t trip_count_total = 0;

  for(Int_t i = 1; i < 73 ; i++){

    Locate(i, &r, &theta);
    //cout << "r is: "<< r <<" theta is: "<< theta <<"\n";

    if(i < 37){ //C side
      ErrCSide->Fill(theta,r,A_Side_Arr[i-1]); //fill C side with the weight = bin content
      cout<<"Region # "<<(i-1)<<" Alive Fraction = "<<A_Side_Arr[i-1]<<endl;
    }
    else if(i >= 37){ //A side
      ErrASide->Fill(theta,r,C_Side_Arr[i-37]); //fill A side with the weight = bin content
      cout<<"Region # "<<(i-1)<<" Alive Fraction = "<<C_Side_Arr[i-37]<<endl;
    }
 
  }


  TH2D* dummy_his1 = new TH2D("dummy1", "Alive Channel Fraction North Side (%)", 100, -1.5, 1.5, 100, -1.5, 1.5); //dummy histos for titles
  TH2D* dummy_his2 = new TH2D("dummy2", "Alive Channel Fraction South Side (%)", 100, -1.5, 1.5, 100, -1.5, 1.5);
  //TPaveLabels for sector labels


  TPaveLabel* A00 = new TPaveLabel( 1.046586,-0.1938999,1.407997,0.2144871, "18" );
  TPaveLabel* A01 = new TPaveLabel( 0.962076,0.4382608,1.323487,0.8466479 , "17" );
  TPaveLabel* A02 = new TPaveLabel( 0.4801947,0.8802139,0.8416056,1.288601 , "16" );
  TPaveLabel* A03 = new TPaveLabel( -0.1823921,1.011681,0.1790189,1.425662, "15" );
  TPaveLabel* A04 = new TPaveLabel( -0.8449788,0.8690253,-0.4835679,1.288601 , "14" );
  TPaveLabel* A05 = new TPaveLabel( -1.30879,0.441058,-0.9473786,0.8550394 , "13" );
  TPaveLabel* A06 = new TPaveLabel( -1.411009,-0.2050886,-1.049598,0.2144871, "12" );
  TPaveLabel* A07 = new TPaveLabel( -1.302585,-0.7757116,-0.9471979,-0.3561359 , "23" );
  TPaveLabel* A08 = new TPaveLabel( -0.8449788,-1.309971,-0.4835679,-0.8848013 , "22" );
  TPaveLabel* A09 = new TPaveLabel( -0.1823921,-1.426557,0.1790189,-1.006982 , "21" );
  TPaveLabel* A10 = new TPaveLabel( 0.4801947,-1.309076,0.8416056,-0.8839062 , "20" );
  TPaveLabel* A11 = new TPaveLabel( 0.9622567,-0.7785088,1.323668,-0.3533387 , "19" );

  TPaveLabel* C00 = new TPaveLabel( 1.046586,-0.1938999,1.407997,0.2144871, "00" );
  TPaveLabel* C01 = new TPaveLabel( 0.962076,0.4382608,1.323487,0.8466479 , "01" );
  TPaveLabel* C02 = new TPaveLabel( 0.4801947,0.8802139,0.8416056,1.288601 , "02" );
  TPaveLabel* C03 = new TPaveLabel( -0.1823921,1.011681,0.1790189,1.425662, "03" );
  TPaveLabel* C04 = new TPaveLabel( -0.8449788,0.8690253,-0.4835679,1.288601 , "04" );
  TPaveLabel* C05 = new TPaveLabel( -1.30879,0.441058,-0.9473786,0.8550394 , "05" );
  TPaveLabel* C06 = new TPaveLabel( -1.411009,-0.2050886,-1.049598,0.2144871, "06" );
  TPaveLabel* C07 = new TPaveLabel( -1.302585,-0.7757116,-0.9471979,-0.3561359 , "07" );
  TPaveLabel* C08 = new TPaveLabel( -0.8449788,-1.309971,-0.4835679,-0.8848013 , "08" );
  TPaveLabel* C09 = new TPaveLabel( -0.1823921,-1.426557,0.1790189,-1.006982 , "09" );
  TPaveLabel* C10 = new TPaveLabel( 0.4801947,-1.309076,0.8416056,-0.8839062 , "10" );
  TPaveLabel* C11 = new TPaveLabel( 0.9622567,-0.7785088,1.323668,-0.3533387 , "11" );

  A00->SetFillColor(0);
  A01->SetFillColor(0);
  A02->SetFillColor(0);
  A03->SetFillColor(0);
  A04->SetFillColor(0);
  A05->SetFillColor(0);
  A06->SetFillColor(0);
  A07->SetFillColor(0);
  A08->SetFillColor(0);
  A09->SetFillColor(0);
  A10->SetFillColor(0);
  A11->SetFillColor(0);

  C00->SetFillColor(0);
  C01->SetFillColor(0);
  C02->SetFillColor(0);
  C03->SetFillColor(0);
  C04->SetFillColor(0);
  C05->SetFillColor(0);
  C06->SetFillColor(0);
  C07->SetFillColor(0);
  C08->SetFillColor(0);
  C09->SetFillColor(0);
  C10->SetFillColor(0);
  C11->SetFillColor(0);

  gStyle->SetPalette(kBird);

  TCanvas *Error_Viz = new TCanvas("Error_Viz", "Error_Viz", 1248, 598);
  Error_Viz->Divide(2,1);
  Error_Viz->cd(1);	
  dummy_his1->Draw("");
  //polardummy1->Draw("same");
  ErrCSide->Draw("colpolzsame0");
  C00->Draw("same");
  C01->Draw("same");
  C02->Draw("same");
  C03->Draw("same");
  C04->Draw("same");
  C05->Draw("same");
  C06->Draw("same");
  C07->Draw("same");
  C08->Draw("same");
  C09->Draw("same");
  C10->Draw("same");
  C11->Draw("same");  
  Error_Viz->cd(2);
  dummy_his2->Draw("");
  //polardummy2->Draw("");
  ErrASide->Draw("colpolzsame0");
  A00->Draw("same");
  A01->Draw("same");
  A02->Draw("same");
  A03->Draw("same");
  A04->Draw("same");
  A05->Draw("same");
  A06->Draw("same");
  A07->Draw("same");
  A08->Draw("same");
  A09->Draw("same");
  A10->Draw("same");
  A11->Draw("same");

  ErrCSide->SetMaximum(100);
  ErrASide->SetMaximum(100);

  ErrCSide->SetMinimum(90);
  ErrASide->SetMinimum(90);
  

  //Set Same Scale for A and C side displays

  Double_t Maxval = TMath::Max(ErrASide->GetBinContent(ErrASide->GetMaximumBin()),ErrCSide->GetBinContent(ErrCSide->GetMaximumBin()));
  //ErrASide->SetMaximum(Maxval);
  //ErrCSide->SetMaximum(Maxval);

  //ErrASide->SetMinimum(0);
  //ErrCSide->SetMinimum(0);



  //____________________________________________________________________________________________________// 


  TFile *outf = new TFile("Trip_Histos.root","RECREATE");
  Error_Viz->Write();
  //Trip_per_stack_dist->Scale(1./trip_count_total);
  //Trip_per_stack_dist->Fit("PoissonFit","ERS");
  //cout<< "\nThe total trips = " << trip_count_total << endl;
  //delete sparsforVIZ;

  outf->Write();


}

void Locate(Int_t id, Double_t *rbin, Double_t *thbin) {

   Double_t CSIDE_angle_bins[12] = { 0.1*2.*TMath::Pi()/12 , 1.1*2.*TMath::Pi()/12 , 2.1*2.*TMath::Pi()/12 , 3.1*2.*TMath::Pi()/12 , 4.1*2.*TMath::Pi()/12 , 5.1*2.*TMath::Pi()/12 , 6.1*2.*TMath::Pi()/12 , 7.1*2.*TMath::Pi()/12 , 8.1*2.*TMath::Pi()/12 , 9.1*2.*TMath::Pi()/12 , 10.1*2.*TMath::Pi()/12 , 11.1*2.*TMath::Pi()/12 }; //CCW from x = 0 (RHS horizontal)

   Double_t ASIDE_angle_bins[12] = { 6.1*2.*TMath::Pi()/12 , 5.1*2.*TMath::Pi()/12 , 4.1*2.*TMath::Pi()/12 , 3.1*2.*TMath::Pi()/12 , 2.1*2.*TMath::Pi()/12 , 1.1*2.*TMath::Pi()/12 , 0.1*2.*TMath::Pi()/12 , 11.1*2.*TMath::Pi()/12 , 10.1*2.*TMath::Pi()/12 , 9.1*2.*TMath::Pi()/12 , 8.1*2.*TMath::Pi()/12 , 7.1*2.*TMath::Pi()/12  }; //CCW from x = 0 (RHS horizontal)

   Int_t modid3 = id % 3;

   switch(modid3) {
     case 1:
       *rbin = 0.4; //R1
       break;
     case 2:
       *rbin = 0.6; //R2
       break;
     case 0:
       *rbin = 0.8; //R3
       break;
   }

  if( id < 37){
    *thbin = CSIDE_angle_bins[TMath::FloorNint((id-1)/3)];
  }
  else if( id >= 37){
    *thbin = ASIDE_angle_bins[TMath::FloorNint((id-37)/3)];
  }


}

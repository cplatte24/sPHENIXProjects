#include <iostream>
#include "TString.h"
#include "TFile.h"
#include "TSystem.h"
#include "TTree.h"
#include "TH1F.h"
#include "TCanvas.h"


// forward declaration
void Ana( TString, TH1F*, TH1F*, TH1F*, TH1F*, char[6], double tot[24], double dead[24], int );

void Analyze2_backup( )
{

  const char* run_str[72] =  { "183111", "183801", "184139", "184719", "185416", "190946", "191520", "192145", "192919", "193735", "194940", "195552", "001223", "235613", "235031", "233416", "223026", "215234", "214601", "214018", "212704", "212138", "211706", "204618", "003959", "005800", "011134", "011737", "012416", "012857", "013458", "014110", "014508", "014953", "201125", "015813", "211316", "212156", "2146011", "223709", "224623", "230218", "231336", "233305", "225003", "230638", "205059", "210507", "000015", "001024", "001718", "002149", "002825", "003915", "004351", "004955", "005829", "010244", "010851", "154811", "175604", "175241", "174911", "174456", "173616", "170907", "170333", "165553", "164759", "163808", "162849", "162313" };

  double tot[24] = {0};

  double dead[24] = {0};

  double tot_ult[24] ={0};
  double dead_ult[24] ={0};

  TH1F *percent_dist = new TH1F("percent_dist","Percent of Channels in individual FEEs with Stuck ADCs",40,0,20);
  percent_dist->SetXTitle("Percent Stuck");
  percent_dist->SetYTitle("Counts");

  TH1F *percent_dist2 = new TH1F("percent_dist2","Percent of Channels in Whole Sector firmware with Stuck ADCs",40,0,20);
  percent_dist2->SetXTitle("Percent Stuck");
  percent_dist2->SetYTitle("Counts");

  TCanvas *percentages = new TCanvas("percentages", "Stuck ADC Percentages", 1248, 598);
  percentages->Divide(2,1);

  TH1F *means_dist = new TH1F("means_dist", "Pedestal Runs, Distribution of mean ADC for each channel in TPC",200,-0.5,199.5);
  means_dist->SetXTitle("Mean ADC");
  means_dist->SetYTitle("Frequency");

  TH1F *widths_dist = new TH1F("widths_dist", "Pedestal Runs, Distribution of std. dev. ADC for each channel in TPC",100,-0.5,19.5);
  widths_dist->SetXTitle("Std. Dev. ADC");
  widths_dist->SetYTitle("Frequency");

  TCanvas *means_widths = new TCanvas("means_widths", "TPC Noise", 1248, 598);
  means_widths->Divide(2,1);

  for( int i = 0; i < 72; i++ )
  {
    //for( int run:{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23} ) 

    //{
    const TString filename( Form( "/sphenix/data/data02/sphnxpro/tpc/chughes/workfest/combined/mean_width_%s_rootfile.root", run_str[i]) );
      //const TString filename( Form( "/sphenix/data/data02/sphnxpro/tpc/jinhuang/2023/03/07/test/test_%s.%i.bin", run, i ) );
    std::cout << "Analyze - filename: " << filename << std::endl;

    char run[6];
    std::sprintf(run,run_str[i]);

    Ana( filename, percent_dist, percent_dist2, means_dist, widths_dist, run, tot, dead, i);

    tot_ult[i] += tot[i];
    dead_ult[i] += dead[i];
    //}
  }
/*
  percentages->cd(1);
  percent_dist->Draw();
  percentages->cd(2);
  percent_dist2->Draw();
*/


  means_widths->cd(1);
  means_dist->Draw();
  means_widths->cd(2);
  widths_dist->Draw();
}

void Ana( TString rootfile = "/sphenix/data/data02/sphnxpro/tpc/chughes/outfiles/REPEAT/Sec_00_remaining/mean_width_211236_rootfile.root", TH1F* percent_hist = new TH1F("percent_dist","Percent of Channels with Stuck ADCs for firmware: d8c6a0bec3",20,0,10), TH1F* percent_hist2 = new TH1F("percent_dist2","Percent of Channels with Stuck ADCs for firmware: d8c6a0bec3",20,0,10), TH1F *means_dist = new TH1F("means_dist", "Distribution of mean ADC for each channel in TPC",200,0,200), TH1F *widths_dist = new TH1F("widths_dist", "Distribution of std. dev. ADC for each channel in TPC",100,0,20), char run_str[6] = "175241", double tot[24]={0}, double dead[24]={0}, int j = 0)
{

  TFile *infile = new TFile(rootfile);
  TH1F *Mymean = (TH1F*)infile->Get("mean");
  TH1F *Myrms = (TH1F*)infile->Get("width");

  int line_flag=0;
  float deadc=0;
  float channel_count=0;

  float feestuckchan=0;
  float FEE_chan_count=0;

  int tot_chan_count=0;
  int dead_chan_count=0;

  int Side_Sec_ID;
  if(j>=0 && j<12)        Side_Sec_ID =      j; // NS 0 - 12
  else if(j>= 12 && j<24) Side_Sec_ID = j - 12; // NS 0 - 12
  else if(j>= 24 && j<36) Side_Sec_ID = j - 24; // NS 0 - 12
  else if(j>= 36 && j<48) Side_Sec_ID = j - 24; // SS 0 - 12
  else if(j>= 48 && j<60) Side_Sec_ID = j - 36; // SS 0 - 12
  else                    Side_Sec_ID = j - 48; // SS 0 - 12

  for (int i=0;i<2304;i++){

     if(std::strncmp(run_str,"003959",6) == 0){ // 1 exclude the double counting of FEE ID 4 in d8c6a0bec3
       if(i>255){
         means_dist->Fill(Mymean->GetBinContent(i+1));
         widths_dist->Fill(Myrms->GetBinContent(i+1));

         //stuck channel or short -- channel must have some non zero value
         if( Mymean->GetBinContent(i+1) > 0 ) {tot[j]++;tot_chan_count++;}
         if( Mymean->GetBinContent(i+1) > 0 && (Mymean->GetBinContent(i+1) > 110 || Myrms->GetBinContent(i+1) < 0.7)) {dead[j]++;dead_chan_count++;}
        }
     }
     else if(std::strncmp(run_str,"005800",6) == 0){ // 2 exclude the double counting of FEE ID 4 in d8c6a0bec3
       if(i>255){
         means_dist->Fill(Mymean->GetBinContent(i+1));
         widths_dist->Fill(Myrms->GetBinContent(i+1));

         //stuck channel or short -- channel must have some non zero value
         if( Mymean->GetBinContent(i+1) > 0 ) {tot[j]++;tot_chan_count++;}
         if( Mymean->GetBinContent(i+1) > 0 && (Mymean->GetBinContent(i+1) > 110 || Myrms->GetBinContent(i+1) < 0.7)) {dead[j]++;dead_chan_count++;}
        }
     }
     else if(std::strncmp(run_str,"011134",6) == 0){ // 3 exclude the double counting of FEE ID 4 in d8c6a0bec3
       if(i>255){
         means_dist->Fill(Mymean->GetBinContent(i+1));
         widths_dist->Fill(Myrms->GetBinContent(i+1));

         //stuck channel or short -- channel must have some non zero value
         if( Mymean->GetBinContent(i+1) > 0 ) {tot[j]++;tot_chan_count++;}
         if( Mymean->GetBinContent(i+1) > 0 && (Mymean->GetBinContent(i+1) > 110 || Myrms->GetBinContent(i+1) < 0.7)) {dead[j]++;dead_chan_count++;}
       }
     }
     else if(std::strncmp(run_str,"011737",6) == 0){ // 4 exclude the double counting of FEE ID 4 in d8c6a0bec3
       if(i>255){
         means_dist->Fill(Mymean->GetBinContent(i+1));
         widths_dist->Fill(Myrms->GetBinContent(i+1));

         //stuck channel or short -- channel must have some non zero value
         if( Mymean->GetBinContent(i+1) > 0 ) {tot[j]++;tot_chan_count++;}
         if( Mymean->GetBinContent(i+1) > 0 && (Mymean->GetBinContent(i+1) > 110 || Myrms->GetBinContent(i+1) < 0.7)) {dead[j]++;dead_chan_count++;}
       }
     }
     else if(std::strncmp(run_str,"012416",6) == 0){ // 5 exclude the double counting of FEE ID 4 in d8c6a0bec3
       if(i>255){
         means_dist->Fill(Mymean->GetBinContent(i+1));
         widths_dist->Fill(Myrms->GetBinContent(i+1));

         //stuck channel or short -- channel must have some non zero value
         if( Mymean->GetBinContent(i+1) > 0 ) {tot[j]++;tot_chan_count++;}
         if( Mymean->GetBinContent(i+1) > 0 && (Mymean->GetBinContent(i+1) > 110 || Myrms->GetBinContent(i+1) < 0.7)) {dead[j]++;dead_chan_count++;}
       }
     }
     else if(std::strncmp(run_str,"012857",6) == 0){ // 6 exclude the double counting of FEE ID 4 in d8c6a0bec3
       if(i>255){
         means_dist->Fill(Mymean->GetBinContent(i+1));
         widths_dist->Fill(Myrms->GetBinContent(i+1));

         //stuck channel or short -- channel must have some non zero value
         if( Mymean->GetBinContent(i+1) > 0 ) {tot[j]++;tot_chan_count++;}
         if( Mymean->GetBinContent(i+1) > 0 && (Mymean->GetBinContent(i+1) > 110 || Myrms->GetBinContent(i+1) < 0.7)) {dead[j]++;dead_chan_count++;}
       }
     }
     else if(std::strncmp(run_str,"013458",6) == 0){ // 7 exclude the double counting of FEE ID 4 in d8c6a0bec3
       if(i>255){
         means_dist->Fill(Mymean->GetBinContent(i+1));
         widths_dist->Fill(Myrms->GetBinContent(i+1));

         //stuck channel or short -- channel must have some non zero value
         if( Mymean->GetBinContent(i+1) > 0 ) {tot[j]++;tot_chan_count++;}
         if( Mymean->GetBinContent(i+1) > 0 && (Mymean->GetBinContent(i+1) > 110 || Myrms->GetBinContent(i+1) < 0.7)) {dead[j]++;dead_chan_count++;}
       }
     }
     else if(std::strncmp(run_str,"014110",6) == 0){ // 8 exclude the double counting of FEE ID 4 in d8c6a0bec3
       if(i>255){
         means_dist->Fill(Mymean->GetBinContent(i+1));
         widths_dist->Fill(Myrms->GetBinContent(i+1));

         //stuck channel or short -- channel must have some non zero value
         if( Mymean->GetBinContent(i+1) > 0 ) {tot[j]++;tot_chan_count++;}
         if( Mymean->GetBinContent(i+1) > 0 && (Mymean->GetBinContent(i+1) > 110 || Myrms->GetBinContent(i+1) < 0.7)) {dead[j]++;dead_chan_count++;}
       }
     }
     else if(std::strncmp(run_str,"014508",6) == 0){ // 9 exclude the double counting of FEE ID 4 in d8c6a0bec3
       if(i>255){
         means_dist->Fill(Mymean->GetBinContent(i+1));
         widths_dist->Fill(Myrms->GetBinContent(i+1));

         //stuck channel or short -- channel must have some non zero value
         if( Mymean->GetBinContent(i+1) > 0 ) {tot[j]++;tot_chan_count++;}
         if( Mymean->GetBinContent(i+1) > 0 && (Mymean->GetBinContent(i+1) > 110 || Myrms->GetBinContent(i+1) < 0.7)) {dead[j]++;dead_chan_count++;}
       }
     }
     else if(std::strncmp(run_str,"014953",6) == 0){ // 10 exclude the double counting of FEE ID 4 in d8c6a0bec3
       if(i>255){
         means_dist->Fill(Mymean->GetBinContent(i+1));
         widths_dist->Fill(Myrms->GetBinContent(i+1));

         //stuck channel or short -- channel must have some non zero value
         if( Mymean->GetBinContent(i+1) > 0 ) {tot[j]++;tot_chan_count++;}
         if( Mymean->GetBinContent(i+1) > 0 && (Mymean->GetBinContent(i+1) > 110 || Myrms->GetBinContent(i+1) < 0.7)) {dead[j]++;dead_chan_count++;}
       }
     }
     else if(std::strncmp(run_str,"201125",6) == 0){ // 11 exclude the double counting of FEE ID 4 in d8c6a0bec3
       if(i>255){
         means_dist->Fill(Mymean->GetBinContent(i+1));
         widths_dist->Fill(Myrms->GetBinContent(i+1));

         //stuck channel or short -- channel must have some non zero value
         if( Mymean->GetBinContent(i+1) > 0 ) {tot[j]++;tot_chan_count++;}
         if( Mymean->GetBinContent(i+1) > 0 && (Mymean->GetBinContent(i+1) > 110 || Myrms->GetBinContent(i+1) < 0.7)) {dead[j]++;dead_chan_count++;}
       }
     }
     else if(std::strncmp(run_str,"015813",6) == 0){ // 12 exclude the double counting of FEE ID 4 in d8c6a0bec3
       if(i>255){
         means_dist->Fill(Mymean->GetBinContent(i+1));
         widths_dist->Fill(Myrms->GetBinContent(i+1));

         //stuck channel or short -- channel must have some non zero value
         if( Mymean->GetBinContent(i+1) > 0 ) {tot[j]++;tot_chan_count++;}
         if( Mymean->GetBinContent(i+1) > 0 && (Mymean->GetBinContent(i+1) > 110 || Myrms->GetBinContent(i+1) < 0.7)) {dead[j]++;dead_chan_count++;}
       }
     }
     else if(std::strncmp(run_str,"175604",6) == 0){ // 13 exclude the double counting of FEE ID 4 in d8c6a0bec3
       if(i>255) {
         means_dist->Fill(Mymean->GetBinContent(i+1));
         widths_dist->Fill(Myrms->GetBinContent(i+1));

         //stuck channel or short -- channel must have some non zero value
         if( Mymean->GetBinContent(i+1) > 0 ) {tot[j]++;tot_chan_count++;}
         if( Mymean->GetBinContent(i+1) > 0 && (Mymean->GetBinContent(i+1) > 110 || Myrms->GetBinContent(i+1) < 0.7)) {dead[j]++;dead_chan_count++;}
       }
     }
     else if(std::strncmp(run_str,"175241",6) == 0){ // 14 exclude the double counting of FEE ID 4 in d8c6a0bec3
       if(i>255){
         means_dist->Fill(Mymean->GetBinContent(i+1));
         widths_dist->Fill(Myrms->GetBinContent(i+1));

         //stuck channel or short -- channel must have some non zero value
         if( Mymean->GetBinContent(i+1) > 0 ) {tot[j]++;tot_chan_count++;}
         if( Mymean->GetBinContent(i+1) > 0 && (Mymean->GetBinContent(i+1) > 110 || Myrms->GetBinContent(i+1) < 0.7)) {dead[j]++;dead_chan_count++;}
       }
     }
     else if(std::strncmp(run_str,"174911",6) == 0){ // 15 exclude the double counting of FEE ID 4 in d8c6a0bec3
       if(i>255){
         means_dist->Fill(Mymean->GetBinContent(i+1));
         widths_dist->Fill(Myrms->GetBinContent(i+1));

         //stuck channel or short -- channel must have some non zero value
         if( Mymean->GetBinContent(i+1) > 0 ) {tot[j]++;tot_chan_count++;}
         if( Mymean->GetBinContent(i+1) > 0 && (Mymean->GetBinContent(i+1) > 110 || Myrms->GetBinContent(i+1) < 0.7)) {dead[j]++;dead_chan_count++;}
       }
     }
     else if(std::strncmp(run_str,"174456",6) == 0){ // 16 exclude the double counting of FEE ID 4 in d8c6a0bec3
       if(i>255){
         means_dist->Fill(Mymean->GetBinContent(i+1));
         widths_dist->Fill(Myrms->GetBinContent(i+1));

         //stuck channel or short -- channel must have some non zero value
         if( Mymean->GetBinContent(i+1) > 0 ) {tot[j]++;tot_chan_count++;}
         if( Mymean->GetBinContent(i+1) > 0 && (Mymean->GetBinContent(i+1) > 110 || Myrms->GetBinContent(i+1) < 0.7)) {dead[j]++;dead_chan_count++;}
       }
     }
     else if(std::strncmp(run_str,"173616",6) == 0){ // 17 exclude the double counting of FEE ID 4 in d8c6a0bec3
       if(i>255){
         means_dist->Fill(Mymean->GetBinContent(i+1));
         widths_dist->Fill(Myrms->GetBinContent(i+1));

         //stuck channel or short -- channel must have some non zero value
         if( Mymean->GetBinContent(i+1) > 0 ) {tot[j]++;tot_chan_count++;}
         if( Mymean->GetBinContent(i+1) > 0 && (Mymean->GetBinContent(i+1) > 110 || Myrms->GetBinContent(i+1) < 0.7)) {dead[j]++;dead_chan_count++;}
       }
     }
     else if(std::strncmp(run_str,"170907",6) == 0){ // 18 exclude the double counting of FEE ID 4 in d8c6a0bec3
       if(i>255){
         means_dist->Fill(Mymean->GetBinContent(i+1));
         widths_dist->Fill(Myrms->GetBinContent(i+1));

         //stuck channel or short -- channel must have some non zero value
         if( Mymean->GetBinContent(i+1) > 0 ) {tot[j]++;tot_chan_count++;}
         if( Mymean->GetBinContent(i+1) > 0 && (Mymean->GetBinContent(i+1) > 110 || Myrms->GetBinContent(i+1) < 0.7)) {dead[j]++;dead_chan_count++;}
       }
     }
     else if(std::strncmp(run_str,"170333",6) == 0){ // 19 exclude the double counting of FEE ID 4 in d8c6a0bec3
       if(i>255){
         means_dist->Fill(Mymean->GetBinContent(i+1));
         widths_dist->Fill(Myrms->GetBinContent(i+1));

         //stuck channel or short -- channel must have some non zero value
         if( Mymean->GetBinContent(i+1) > 0 ) {tot[j]++;tot_chan_count++;}
         if( Mymean->GetBinContent(i+1) > 0 && (Mymean->GetBinContent(i+1) > 110 || Myrms->GetBinContent(i+1) < 0.7)) {dead[j]++;dead_chan_count++;}
       }
     }
     else if(std::strncmp(run_str,"165553",6) == 0){ // 20 exclude the double counting of FEE ID 4 in d8c6a0bec3
       if(i>255){
         means_dist->Fill(Mymean->GetBinContent(i+1));
         widths_dist->Fill(Myrms->GetBinContent(i+1));

         //stuck channel or short -- channel must have some non zero value
         if( Mymean->GetBinContent(i+1) > 0 ) {tot[j]++;tot_chan_count++;}
         if( Mymean->GetBinContent(i+1) > 0 && (Mymean->GetBinContent(i+1) > 110 || Myrms->GetBinContent(i+1) < 0.7)) {dead[j]++;dead_chan_count++;}
       }
     }
     else if(std::strncmp(run_str,"164759",6) == 0){ // 21 exclude the double counting of FEE ID 4 in d8c6a0bec3
       if(i>255){
         means_dist->Fill(Mymean->GetBinContent(i+1));
         widths_dist->Fill(Myrms->GetBinContent(i+1));

         //stuck channel or short -- channel must have some non zero value
         if( Mymean->GetBinContent(i+1) > 0 ) {tot[j]++;tot_chan_count++;}
         if( Mymean->GetBinContent(i+1) > 0 && (Mymean->GetBinContent(i+1) > 110 || Myrms->GetBinContent(i+1) < 0.7)) {dead[j]++;dead_chan_count++;}
       }
     }
     else if(std::strncmp(run_str,"163808",6) == 0){ // 22 exclude the double counting of FEE ID 4 in d8c6a0bec3
       if(i>255){
         means_dist->Fill(Mymean->GetBinContent(i+1));
         widths_dist->Fill(Myrms->GetBinContent(i+1));

         //stuck channel or short -- channel must have some non zero value
         if( Mymean->GetBinContent(i+1) > 0 ) {tot[j]++;tot_chan_count++;}
         if( Mymean->GetBinContent(i+1) > 0 && (Mymean->GetBinContent(i+1) > 110 || Myrms->GetBinContent(i+1) < 0.7)) {dead[j]++;dead_chan_count++;}
       }
     }
     else if(std::strncmp(run_str,"162849",6) == 0){ // 23 exclude the double counting of FEE ID 4 in d8c6a0bec3
       if(i>255){
         means_dist->Fill(Mymean->GetBinContent(i+1));
         widths_dist->Fill(Myrms->GetBinContent(i+1));

         //stuck channel or short -- channel must have some non zero value
         if( Mymean->GetBinContent(i+1) > 0 ) {tot[j]++;tot_chan_count++;}
         if( Mymean->GetBinContent(i+1) > 0 && (Mymean->GetBinContent(i+1) > 110 || Myrms->GetBinContent(i+1) < 0.7)) {dead[j]++;dead_chan_count++;}
       }
     }
     else if(std::strncmp(run_str,"162313",6) == 0){ // 24 exclude the double counting of FEE ID 4 in d8c6a0bec3
       if(i>255){
         means_dist->Fill(Mymean->GetBinContent(i+1));
         widths_dist->Fill(Myrms->GetBinContent(i+1));

         //stuck channel or short -- channel must have some non zero value
         if( Mymean->GetBinContent(i+1) > 0 ) {tot[j]++;tot_chan_count++;}
         if( Mymean->GetBinContent(i+1) > 0 && (Mymean->GetBinContent(i+1) > 110 || Myrms->GetBinContent(i+1) < 0.7)) {dead[j]++;dead_chan_count++;}
       }
     }
     else {
       means_dist->Fill(Mymean->GetBinContent(i+1));
       widths_dist->Fill(Myrms->GetBinContent(i+1));

         //stuck channel or short -- channel must have some non zero value
      if( Mymean->GetBinContent(i+1) > 0 ) {tot[j]++;tot_chan_count++;}
      if( Mymean->GetBinContent(i+1) > 0 && (Mymean->GetBinContent(i+1) > 110 || Myrms->GetBinContent(i+1) < 0.7)) {dead[j]++;dead_chan_count++;}
     }



     if(Mymean->GetBinContent(i+1)>110){ 
       //std::cout<<"mean "<< i%256 + 1<<" "; 
       line_flag++;
     }
     if(Myrms->GetBinContent(i+1)<0.5){
       //std::cout<<"rms "<<i%256 + 1<<" "; 
       line_flag++;
     }
     if(Myrms->GetBinContent(i+1)<0.7){
       //std::cout<<"rms "<<i<<" ";
       line_flag++;
     }
     if(Mymean->GetBinContent(i+1)>0){channel_count++; FEE_chan_count++;}
     if(line_flag>0){cout <<endl; line_flag=0;deadc++;feestuckchan++;}

     if( ((i+1)%256)==0 ) //end of FEE
     {
       percent_hist->Fill((feestuckchan/FEE_chan_count)*100);
       //std::cout<<"StuckPercentage FEE # "<<(i+1)/256<<": "<<((feestuckchan/FEE_chan_count)*100)<<" % "<<std::endl;
       feestuckchan=0;
       FEE_chan_count=0;

     }

  }

  float stuckfraction = deadc/channel_count;
  //std::cout<<"StuckCount: "<<deadc<<std::endl;
  //std::cout<<"StuckPercentage Sector: "<<(stuckfraction*100)<<" % "<<std::endl;
  std::cout<<"ID = "<<j<<", "<<"Dead = "<<dead_chan_count<<" ,Tot = "<<tot_chan_count<<std::endl;
  percent_hist2->Fill(stuckfraction*100);
  //return 0;
}


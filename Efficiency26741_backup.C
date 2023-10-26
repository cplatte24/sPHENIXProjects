#ifdef __CLING__
#pragma cling optimize(0)
#endif
void Efficiency26741_backup()
{
//=========Macro generated from canvas: Error_Viz/Error_Viz
//=========  (Sat Sep 23 10:29:17 2023) by ROOT version 6.26/06
  TCanvas *Error_Viz = new TCanvas("Error_Viz", "Error_Viz",45,180,1248,598); //45,180,1248,598
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   Error_Viz->Range(0,0,1,1);
   Error_Viz->SetFillColor(0);
   Error_Viz->SetBorderMode(0);
   Error_Viz->SetBorderSize(0); //2
   Error_Viz->SetTickx(1);
   Error_Viz->SetTicky(1);
   Error_Viz->SetLeftMargin(0.1);
   Error_Viz->SetRightMargin(0.1);  // was 0.05
   Error_Viz->SetTopMargin(0.06);   //was 0.05
   Error_Viz->SetBottomMargin(0.06);
   Error_Viz->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: Error_Viz_1
   TPad *Error_Viz_1 = new TPad("Error_Viz_1", "Error_Viz_1",0.01,0.01,0.49,0.99);
   Error_Viz_1->Draw();
   Error_Viz_1->cd();
   Error_Viz_1->Range(-2.107595,-2.107595,1.689873,1.689873);
   Error_Viz_1->SetFillColor(0);
   Error_Viz_1->SetBorderMode(0);
   Error_Viz_1->SetBorderSize(0);
   Error_Viz_1->SetTickx(1);
   Error_Viz_1->SetTicky(1);
   Error_Viz_1->SetLeftMargin(0.32);
   Error_Viz_1->SetRightMargin(0);//was 0.05
   Error_Viz_1->SetTopMargin(0.12);//0.05
   Error_Viz_1->SetBottomMargin(0.2);
   Error_Viz_1->SetFrameBorderMode(0);
   Error_Viz_1->SetFrameBorderMode(0);
   

   TH2D *dummy1__1__1 = new TH2D("dummy1__1__1","26741-Alive Channel Fraction North Side (%)",100,-1.5,1.48,100,-1.5,1.5);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   dummy1__1__1->SetLineColor(ci);
   dummy1__1__1->SetLineWidth(2);
   dummy1__1__1->SetMarkerStyle(20);
   dummy1__1__1->SetMarkerSize(1.2);
   dummy1__1__1->GetXaxis()->SetLabelFont(42);
   dummy1__1__1->GetXaxis()->SetLabelSize(0.025);
   dummy1__1__1->GetXaxis()->SetTitleSize(0.025);
   dummy1__1__1->GetXaxis()->SetTitleOffset(1);
   dummy1__1__1->GetXaxis()->SetTitleFont(42);
   dummy1__1__1->GetXaxis()->SetTitle("Arb. Units");
   dummy1__1__1->GetYaxis()->SetLabelFont(42);
   dummy1__1__1->GetYaxis()->SetLabelSize(0.025);
   dummy1__1__1->GetYaxis()->SetTitleSize(0.025);
   dummy1__1__1->GetYaxis()->SetTitleOffset(1.1);
   dummy1__1__1->GetYaxis()->SetTitleFont(42);
   dummy1__1__1->GetYaxis()->SetTitle("Arb. Units");
   dummy1__1__1->GetZaxis()->SetLabelFont(42);
   dummy1__1__1->GetZaxis()->SetLabelSize(0.025);
   dummy1__1__1->GetZaxis()->SetTitleSize(0.05);
   dummy1__1__1->GetZaxis()->SetTitleOffset(1.1);
   dummy1__1__1->GetZaxis()->SetTitleFont(42);
   //   dummy1__1__1->GetZaxis()->SetTitle("Z-Axis Title"); // Set the z-axis title
   dummy1__1__1->Draw("");
   Double_t yAxis1[5] = {0, 0.256, 0.504, 0.752, 1}; 
   
   TH2D *CSide__2__2 = new TH2D("CSide__2__2","ADC Counts South Side",12,-0.2617994,6.021386,4, yAxis1);
   CSide__2__2->SetBinContent(29,95.9375);
   CSide__2__2->SetBinContent(30,99.60938);
   CSide__2__2->SetBinContent(31,99.76562);
   CSide__2__2->SetBinContent(32,96.32812);
   CSide__2__2->SetBinContent(33,94.20573);
   CSide__2__2->SetBinContent(34,99.47917);
   CSide__2__2->SetBinContent(35,100);
   CSide__2__2->SetBinContent(36,100);
   CSide__2__2->SetBinContent(37,90.625);
   CSide__2__2->SetBinContent(38,93.68489);
   CSide__2__2->SetBinContent(39,100);
   CSide__2__2->SetBinContent(40,97.91667);
   CSide__2__2->SetBinContent(43,98.4375);
   CSide__2__2->SetBinContent(44,95.83333);
   CSide__2__2->SetBinContent(45,95.83333);
   CSide__2__2->SetBinContent(46,97.98177);
   CSide__2__2->SetBinContent(47,96.04492);
   CSide__2__2->SetBinContent(48,97.60045);
   CSide__2__2->SetBinContent(49,97.85156);
   CSide__2__2->SetBinContent(50,97.55859);
   CSide__2__2->SetBinContent(51,98.82812);
   CSide__2__2->SetBinContent(52,95.3125);
   CSide__2__2->SetBinContent(53,100);
   CSide__2__2->SetBinContent(54,99.38616);
   CSide__2__2->SetBinContent(57,95.57292);
   CSide__2__2->SetBinContent(58,96.875);
   CSide__2__2->SetBinContent(59,98.40495);
   CSide__2__2->SetBinContent(60,99.60938);
   CSide__2__2->SetBinContent(61,97.26562);
   CSide__2__2->SetBinContent(62,98.47656);
   CSide__2__2->SetBinContent(63,97.56944);
   CSide__2__2->SetBinContent(64,98.92578);
   CSide__2__2->SetBinContent(65,98.95833);
   CSide__2__2->SetBinContent(66,99.93489);
   CSide__2__2->SetBinContent(67,99.46733);
   CSide__2__2->SetBinContent(68,98.66536);
   CSide__2__2->SetBinError(29,95.9375);
   CSide__2__2->SetBinError(30,99.60938);
   CSide__2__2->SetBinError(31,99.76562);
   CSide__2__2->SetBinError(32,96.32812);
   CSide__2__2->SetBinError(33,94.20573);
   CSide__2__2->SetBinError(34,99.47917);
   CSide__2__2->SetBinError(35,100);
   CSide__2__2->SetBinError(36,100);
   CSide__2__2->SetBinError(37,90.625);
   CSide__2__2->SetBinError(38,93.68489);
   CSide__2__2->SetBinError(39,100);
   CSide__2__2->SetBinError(40,97.91667);
   CSide__2__2->SetBinError(43,98.4375);
   CSide__2__2->SetBinError(44,95.83333);
   CSide__2__2->SetBinError(45,95.83333);
   CSide__2__2->SetBinError(46,97.98177);
   CSide__2__2->SetBinError(47,96.04492);
   CSide__2__2->SetBinError(48,97.60045);
   CSide__2__2->SetBinError(49,97.85156);
   CSide__2__2->SetBinError(50,97.55859);
   CSide__2__2->SetBinError(51,98.82812);
   CSide__2__2->SetBinError(52,95.3125);
   CSide__2__2->SetBinError(53,100);
   CSide__2__2->SetBinError(54,99.38616);
   CSide__2__2->SetBinError(57,95.57292);
   CSide__2__2->SetBinError(58,96.875);
   CSide__2__2->SetBinError(59,98.40495);
   CSide__2__2->SetBinError(60,99.60938);
   CSide__2__2->SetBinError(61,97.26562);
   CSide__2__2->SetBinError(62,98.47656);
   CSide__2__2->SetBinError(63,97.56944);
   CSide__2__2->SetBinError(64,98.92578);
   CSide__2__2->SetBinError(65,98.95833);
   CSide__2__2->SetBinError(66,99.93489);
   CSide__2__2->SetBinError(67,99.46733);
   CSide__2__2->SetBinError(68,98.66536);
   CSide__2__2->SetMinimum(80);
   CSide__2__2->SetMaximum(100);
   CSide__2__2->SetEntries(36);
   CSide__2__2->SetStats(0);
   CSide__2__2->SetContour(20);
   CSide__2__2->SetContourLevel(0,80);
   CSide__2__2->SetContourLevel(1,81);
   CSide__2__2->SetContourLevel(2,82);
   CSide__2__2->SetContourLevel(3,83);
   CSide__2__2->SetContourLevel(4,84);
   CSide__2__2->SetContourLevel(5,85);
   CSide__2__2->SetContourLevel(6,86);
   CSide__2__2->SetContourLevel(7,87);
   CSide__2__2->SetContourLevel(8,88);
   CSide__2__2->SetContourLevel(9,89);
   CSide__2__2->SetContourLevel(10,90);
   CSide__2__2->SetContourLevel(11,91);
   CSide__2__2->SetContourLevel(12,92);
   CSide__2__2->SetContourLevel(13,93);
   CSide__2__2->SetContourLevel(14,94);
   CSide__2__2->SetContourLevel(15,95);
   CSide__2__2->SetContourLevel(16,96);
   CSide__2__2->SetContourLevel(17,97);
   CSide__2__2->SetContourLevel(18,98);
   CSide__2__2->SetContourLevel(19,99);
  
   /*  
   TPaletteAxis *palette = new TPaletteAxis(1.51875,-1.5,1.6875,1.5,CSide__2__2);
   palette->SetLabelColor(1);
   palette->SetLabelFont(42);
   palette->SetLabelOffset(0.005);
   palette->SetLabelSize(0.025);
   palette->SetTitleOffset(1);
   palette->SetTitleSize(0.05);
  
   ci = TColor::GetColor("#f9f90e");
   palette->SetFillColor(ci);
   palette->SetFillStyle(1001);
   CSide__2__2->GetListOfFunctions()->Add(palette,"nb");
   */
   ci = TColor::GetColor("#000099");
   CSide__2__2->SetLineColor(ci);
   CSide__2__2->SetLineWidth(2);
   CSide__2__2->SetMarkerStyle(20);
   CSide__2__2->SetMarkerSize(1.2);
   CSide__2__2->GetXaxis()->SetLabelFont(42);
   CSide__2__2->GetXaxis()->SetLabelSize(0.025);
   CSide__2__2->GetXaxis()->SetTitleSize(0.025);
   CSide__2__2->GetXaxis()->SetTitleOffset(0.75);
   CSide__2__2->GetXaxis()->SetTitleFont(42);
   CSide__2__2->GetXaxis()->SetTitle("Arb. Units"); // Set the x-axis title
   //   CSide__2__2->Draw("colpolzsame0"); 
   CSide__2__2->GetYaxis()->SetLabelFont(42);
   CSide__2__2->GetYaxis()->SetLabelSize(0.025);
   CSide__2__2->GetYaxis()->SetTitleSize(0.025);
   CSide__2__2->GetYaxis()->SetTitleOffset(0.75);
   CSide__2__2->GetYaxis()->SetTitleFont(42);
   CSide__2__2->GetYaxis()->SetTitle("Arb. Units"); // Set the y-axis title
   //   CSide__2__2->Draw("colpolzsame0"); 
   //   CSide__2__2->GetZaxis()->SetLabelFont(42);
   //  CSide__2__2->GetZaxis()->SetLabelOffset(-0.75);
   // CSide__2__2->GetZaxis()->SetLabelSize(0.025);
   // CSide__2__2->GetZaxis()->SetTitleSize(0.025);
   // CSide__2__2->GetZaxis()->SetTitleOffset(1.3);
   // CSide__2__2->GetZaxis()->SetTitleFont(42);
   // CSide__2__2->GetZaxis()->SetTitle("Live Channel Fraction (%)"); // Set the z-axis title
   CSide__2__2->Draw("colpolsame0");
  


   TPaveLabel *pl = new TPaveLabel(1.046586,-0.1938999,1.407997,0.2144871,"00","nb");
   pl->SetFillColor(0);
   pl->SetTextFont(42);
   pl->SetTextSize(0.5);
   pl->Draw();
   
   pl = new TPaveLabel(0.962076,0.4382608,1.323487,0.8466479,"01","nb");
   pl->SetFillColor(0);
   pl->SetTextFont(42);
   pl->SetTextSize(0.5);
   pl->Draw();
   
   pl = new TPaveLabel(0.4801947,0.8802139,0.8416056,1.288601,"02","nb");
   pl->SetFillColor(0);
   pl->SetTextFont(42);
   pl->SetTextSize(0.5);
   pl->Draw();
   
   pl = new TPaveLabel(-0.1823921,1.011681,0.1790189,1.425662,"03","nb");
   pl->SetFillColor(0);
   pl->SetTextFont(42);
   pl->SetTextSize(0.5);
   pl->Draw();
   
   pl = new TPaveLabel(-0.8449788,0.8690253,-0.4835679,1.288601,"04","nb");
   pl->SetFillColor(0);
   pl->SetTextFont(42);
   pl->SetTextSize(0.5);
   pl->Draw();
   
   pl = new TPaveLabel(-1.30879,0.441058,-0.9473786,0.8550394,"05","nb");
   pl->SetFillColor(0);
   pl->SetTextFont(42);
   pl->SetTextSize(0.5);
   pl->Draw();
   
   pl = new TPaveLabel(-1.411009,-0.2050886,-1.049598,0.2144871,"06","nb");
   pl->SetFillColor(0);
   pl->SetTextFont(42);
   pl->SetTextSize(0.5);
   pl->Draw();


   pl = new TPaveLabel(-1.302585,-0.7757116,-0.9471979,-0.3561359,"07","nb");
   pl->SetFillColor(0);
   pl->SetTextFont(42);
   pl->SetTextSize(0.5);
   pl->Draw();
   
   pl = new TPaveLabel(-0.8449788,-1.309971,-0.4835679,-0.8848013,"08","nb");
   pl->SetFillColor(0);
   pl->SetTextFont(42);
   pl->SetTextSize(0.5);
   pl->Draw();
   
   pl = new TPaveLabel(-0.1823921,-1.426557,0.1790189,-1.006982,"09","nb");
   pl->SetFillColor(0);
   pl->SetTextFont(42);
   pl->SetTextSize(0.5);
   pl->Draw();

   pl= new TPaveLabel(-1.0, -1.42, -0.95, -1.37, "#it{#bf{sPHENIX}} Internal","nb");
   pl->SetFillColor(0);
   pl->SetLineColor(0);
   pl->SetLineStyle(0);
   pl->SetFillStyle(0);
   pl->SetTextFont(42);
   pl->SetTextSize(2.6);
   pl->Draw();
   
   pl = new TPaveLabel(0.4801947,-1.309076,0.8416056,-0.8839062,"10","nb");
   pl->SetFillColor(0);
   pl->SetTextFont(42);
   pl->SetTextSize(0.5);
   pl->Draw();
   
   pl = new TPaveLabel(0.9622567,-0.7785088,1.323668,-0.3533387,"11","nb");
   pl->SetFillColor(0);
   pl->SetTextFont(42);
   pl->SetTextSize(0.5);
   pl->Draw();

   pl= new TPaveLabel(0.9, 1.37, 0.95, 1.42, "#bf{TPC North Sectors}","nb");
   pl->SetFillStyle(0);
   pl->SetLineColor(0);
   pl->SetFillColor(0);
   pl->SetTextFont(42);
   pl->SetTextSize(2.6);
   pl->Draw();

   pl= new TPaveLabel(1.15, 1.22, 1.2, 1.27, "Run 26741","nb");
   pl->SetFillColor(0);
   pl->SetFillStyle(0);
   pl->SetLineColor(0);
   pl->SetTextFont(42);
   pl->SetTextSize(2.5);
   pl->Draw();

   /*
   pl= new TPaveLabel(-0.82, 1.57, -0.75, 1.17, "Live Channel Fraction (%)","nb");
   pl->SetFillStyle(0);
   pl->SetFillColor(0);
   pl->SetTextFont(42);
   pl->SetTextSize(0.3);
   pl->Draw();
   */
   Error_Viz_1->Modified();
   Error_Viz->cd();
  
// ------------>Primitives in pad: Error_Viz_2
   TPad *Error_Viz_2 = new TPad("Error_Viz_2", "Error_Viz_2",0.49,0.01,0.97,0.99);
   Error_Viz_2->Draw();
   Error_Viz_2->cd();
   Error_Viz_2->Range(-2.107595,-2.107595,1.689873,1.689873);
   Error_Viz_2->SetFillColor(0);
   Error_Viz_2->SetBorderMode(0);
   Error_Viz_2->SetBorderSize(0);
   Error_Viz_2->SetTickx(1);
   Error_Viz_2->SetTicky(0);
   Error_Viz_2->SetLeftMargin(0);
   Error_Viz_2->SetRightMargin(0.32);
   Error_Viz_2->SetTopMargin(0.12);
   Error_Viz_2->SetBottomMargin(0.2);
   Error_Viz_2->SetFrameBorderMode(0);
   //  Error_Viz_2->SetFrameBorderMode(0);

   TLatex *xlabel = new TLatex(0.49, -0.15, "X-Axis Label");
   xlabel->SetTextSize(0.03); // Set the text size                                                                                                                       
   xlabel->SetNDC(kTRUE); // Use normalized coordinates                                                                                                                   
   xlabel->Draw();   
   TH2D *dummy2__3__3 = new TH2D("dummy2__3__3","26741-Alive Channel Fraction South Side (%)",100,-1.48,1.5,100,-1.5,1.5);
   dummy2__3__3->SetStats(0);

   ci = TColor::GetColor("#000099");
   dummy2__3__3->SetLineColor(ci);
   dummy2__3__3->SetLineWidth(2);
   dummy2__3__3->SetMarkerStyle(20);
   dummy2__3__3->SetMarkerSize(1.2);
   dummy2__3__3->GetXaxis()->SetLabelFont(42);
   dummy2__3__3->GetXaxis()->SetLabelSize(0.025);
   dummy2__3__3->GetXaxis()->SetTitleSize(0.025);
   dummy2__3__3->GetXaxis()->SetTitleOffset(1);
   dummy2__3__3->GetXaxis()->SetTitleFont(42);
   dummy2__3__3->GetXaxis()->SetTitle("Arb. Units");
   dummy2__3__3->GetYaxis()->SetLabelFont(42);
   dummy2__3__3->GetYaxis()->SetLabelSize(0.025);
   dummy2__3__3->GetYaxis()->SetTitleSize(0.025);
   dummy2__3__3->GetYaxis()->SetTitleOffset(1.1);
   dummy2__3__3->GetYaxis()->SetTitle("Arb. Units");
   dummy2__3__3->GetYaxis()->SetTitleFont(42);
   dummy2__3__3->GetZaxis()->SetLabelFont(42);
   dummy2__3__3->GetZaxis()->SetLabelSize(0.025);
   dummy2__3__3->GetZaxis()->SetTitleSize(0.025);
   dummy2__3__3->GetZaxis()->SetTitleOffset(1.1);
   dummy2__3__3->GetZaxis()->SetTitleFont(42);
   dummy2__3__3->Draw("");
   Double_t yAxis2[5] = {0, 0.256, 0.504, 0.752, 1}; 
   
   TH2D *ASide__4__4 = new TH2D("ASide__4__4","ADC Counts North Side",12,-0.2617994,6.021386,4, yAxis2);
   ASide__4__4->SetBinContent(29,97.5);
   ASide__4__4->SetBinContent(30,100);
   ASide__4__4->SetBinContent(31,82.5);
   ASide__4__4->SetBinContent(32,97.5);
   ASide__4__4->SetBinContent(33,100);
   ASide__4__4->SetBinContent(34,94.66145);
   ASide__4__4->SetBinContent(35,95.83333);
   ASide__4__4->SetBinContent(36,100);
   ASide__4__4->SetBinContent(37,93.82812);
   ASide__4__4->SetBinContent(38,93.67188);
   ASide__4__4->SetBinContent(39,97.5);
   ASide__4__4->SetBinContent(40,96.71875);
   ASide__4__4->SetBinContent(43,96.31696);
   ASide__4__4->SetBinContent(44,97.43304);
   ASide__4__4->SetBinContent(45,96.875);
   ASide__4__4->SetBinContent(46,96.67969);
   ASide__4__4->SetBinContent(47,99.75586);
   ASide__4__4->SetBinContent(48,97.55859);
   ASide__4__4->SetBinContent(49,98.15849);
   ASide__4__4->SetBinContent(50,97.99107);
   ASide__4__4->SetBinContent(51,96.875);
   ASide__4__4->SetBinContent(52,89.53125);
   ASide__4__4->SetBinContent(53,97.54464);
   ASide__4__4->SetBinContent(54,99.83259);
   ASide__4__4->SetBinContent(57,98.68608);
   ASide__4__4->SetBinContent(58,95.41903);
   ASide__4__4->SetBinContent(59,95.83333);
   ASide__4__4->SetBinContent(60,94.44444);
   ASide__4__4->SetBinContent(61,93.65234);
   ASide__4__4->SetBinContent(62,96.875);
   ASide__4__4->SetBinContent(63,97.91667);
   ASide__4__4->SetBinContent(64,95.41903);
   ASide__4__4->SetBinContent(65,96.48438);
   ASide__4__4->SetBinContent(66,95.38352);
   ASide__4__4->SetBinContent(67,96.70139);
   ASide__4__4->SetBinContent(68,95.21484);
   ASide__4__4->SetBinError(29,97.5);
   ASide__4__4->SetBinError(30,100);
   ASide__4__4->SetBinError(31,82.5);
   ASide__4__4->SetBinError(32,97.5);
   ASide__4__4->SetBinError(33,100);
   ASide__4__4->SetBinError(34,94.66145);
   ASide__4__4->SetBinError(35,95.83333);
   ASide__4__4->SetBinError(36,100);
   ASide__4__4->SetBinError(37,93.82812);
   ASide__4__4->SetBinError(38,93.67188);
   ASide__4__4->SetBinError(39,97.5);
   ASide__4__4->SetBinError(40,96.71875);
   ASide__4__4->SetBinError(43,96.31696);
   ASide__4__4->SetBinError(44,97.43304);
   ASide__4__4->SetBinError(45,96.875);
   ASide__4__4->SetBinError(46,96.67969);
   ASide__4__4->SetBinError(47,99.75586);
   ASide__4__4->SetBinError(48,97.55859);
   ASide__4__4->SetBinError(49,98.15849);
   ASide__4__4->SetBinError(50,97.99107);
   ASide__4__4->SetBinError(51,96.875);
   ASide__4__4->SetBinError(52,89.53125);
   ASide__4__4->SetBinError(53,97.54464);
   ASide__4__4->SetBinError(54,99.83259);
   ASide__4__4->SetBinError(57,98.68608);
   ASide__4__4->SetBinError(58,95.41903);
   ASide__4__4->SetBinError(59,95.83333);
   ASide__4__4->SetBinError(60,94.44444);
   ASide__4__4->SetBinError(61,93.65234);
   ASide__4__4->SetBinError(62,96.875);
   ASide__4__4->SetBinError(63,97.91667);
   ASide__4__4->SetBinError(64,95.41903);
   ASide__4__4->SetBinError(65,96.48438);
   ASide__4__4->SetBinError(66,95.38352);
   ASide__4__4->SetBinError(67,96.70139);
   ASide__4__4->SetBinError(68,95.21484);
   ASide__4__4->SetMinimum(80);
   ASide__4__4->SetMaximum(100);
   ASide__4__4->SetEntries(36);
   ASide__4__4->SetStats(0);
   ASide__4__4->SetContour(20);
   ASide__4__4->SetContourLevel(0,80);
   ASide__4__4->SetContourLevel(1,81);
   ASide__4__4->SetContourLevel(2,82);
   ASide__4__4->SetContourLevel(3,83);
   ASide__4__4->SetContourLevel(4,84);
   ASide__4__4->SetContourLevel(5,85);
   ASide__4__4->SetContourLevel(6,86);
   ASide__4__4->SetContourLevel(7,87);
   ASide__4__4->SetContourLevel(8,88);
   ASide__4__4->SetContourLevel(9,89);
   ASide__4__4->SetContourLevel(10,90);
   ASide__4__4->SetContourLevel(11,91);
   ASide__4__4->SetContourLevel(12,92);
   ASide__4__4->SetContourLevel(13,93);
   ASide__4__4->SetContourLevel(14,94);
   ASide__4__4->SetContourLevel(15,95);
   ASide__4__4->SetContourLevel(16,96);
   ASide__4__4->SetContourLevel(17,97);
   ASide__4__4->SetContourLevel(18,98);
   ASide__4__4->SetContourLevel(19,99);

   TPaletteAxis *palette = new TPaletteAxis(1.51875,-1.5,1.6875,1.5,CSide__2__2);                                                                                                                              
   palette = new TPaletteAxis(1.51875,-1.5,1.6875,1.5,ASide__4__4);
   palette->SetLabelColor(1);
   palette->SetLabelFont(42);
   palette->SetLabelOffset(0.005);
   palette->SetLabelSize(0.025);
   palette->SetTitleOffset(1);
   palette->SetTitleSize(0.05);

   ci = TColor::GetColor("#f9f90e");
   palette->SetFillColor(ci);
   palette->SetFillStyle(1001);
   ASide__4__4->GetListOfFunctions()->Add(palette,"nb");

   ci = TColor::GetColor("#000099");
   ASide__4__4->SetLineColor(ci);
   ASide__4__4->SetLineWidth(2);
   ASide__4__4->SetMarkerStyle(20);
   ASide__4__4->SetMarkerSize(1.2);
   ASide__4__4->GetXaxis()->SetLabelFont(42);
   ASide__4__4->GetXaxis()->SetLabelSize(0.025);
   ASide__4__4->GetXaxis()->SetTitleSize(0.04);
   ASide__4__4->GetXaxis()->SetTitleOffset(1);
   ASide__4__4->GetXaxis()->SetTitleFont(42);
   ASide__4__4->GetXaxis()->SetTitle("Arb. Units"); // Set the x-axis title    
   ASide__4__4->GetYaxis()->SetLabelFont(42);
   //   ASide__4__4->GetYaxis()->SetLabelSize(0.025);
   // ASide__4__4->GetYaxis()->SetTitleSize(0.04);
   // ASide__4__4->GetYaxis()->SetTitleOffset(1.4);
   // ASide__4__4->GetYaxis()->SetTitleFont(42);
   // ASide__4__4->GetYaxis()->SetTitle("Arb. Units"); // Set the y-axis title
   ASide__4__4->GetZaxis()->SetLabelFont(42);
   ASide__4__4->GetZaxis()->SetLabelSize(0.025);
   ASide__4__4->GetZaxis()->SetTitleSize(0.025);
   ASide__4__4->GetZaxis()->SetTitleOffset(1.3);
   ASide__4__4->GetZaxis()->SetTitleFont(42);
   ASide__4__4->GetZaxis()->SetTitle("Live Channel Fraction (%)"); // Set the z-axis title  
   ASide__4__4->Draw("colpolzsame0");
   
   pl = new TPaveLabel(1.046586,-0.1938999,1.407997,0.2144871,"18","nb");
   pl->SetFillColor(0);
   pl->SetTextFont(42);
   pl->SetTextSize(0.5);
   pl->Draw();
   
   pl = new TPaveLabel(0.962076,0.4382608,1.323487,0.8466479,"17","nb");
   pl->SetFillColor(0);
   pl->SetTextFont(42);
   pl->SetTextSize(0.5);
   pl->Draw();
   
   pl = new TPaveLabel(0.4801947,0.8802139,0.8416056,1.288601,"16","nb");
   pl->SetFillColor(0);
   pl->SetTextFont(42);
   pl->SetTextSize(0.5);
   pl->Draw();
   
   pl = new TPaveLabel(-0.1823921,1.011681,0.1790189,1.425662,"15","nb");
   pl->SetFillColor(0);
   pl->SetTextFont(42);
   pl->SetTextSize(0.5);
   pl->Draw();
   
   pl = new TPaveLabel(-0.8449788,0.8690253,-0.4835679,1.288601,"14","nb");
   pl->SetFillColor(0);
   pl->SetTextFont(42);
   pl->SetTextSize(0.5);
   pl->Draw();
   
   pl = new TPaveLabel(-1.30879,0.441058,-0.9473786,0.8550394,"13","nb");
   pl->SetFillColor(0);
   pl->SetTextFont(42);
   pl->SetTextSize(0.5);
   pl->Draw();
   
   pl = new TPaveLabel(-1.411009,-0.2050886,-1.049598,0.2144871,"12","nb");
   pl->SetFillColor(0);
   pl->SetTextFont(42);
   pl->SetTextSize(0.5);
   pl->Draw();
   
   pl = new TPaveLabel(-1.302585,-0.7757116,-0.9471979,-0.3561359,"23","nb");
   pl->SetFillColor(0);
   pl->SetTextFont(42);
   pl->SetTextSize(0.5);
   pl->Draw();
   
   pl = new TPaveLabel(-0.8449788,-1.309971,-0.4835679,-0.8848013,"22","nb");
   pl->SetFillColor(0);
   pl->SetTextFont(42);
   pl->SetTextSize(0.5);
   pl->Draw();
   
   pl = new TPaveLabel(-0.1823921,-1.426557,0.1790189,-1.006982,"21","nb");
   pl->SetFillColor(0);
   pl->SetTextFont(42);
   pl->SetTextSize(0.5);
   pl->Draw();
   
   pl = new TPaveLabel(0.4801947,-1.309076,0.8416056,-0.8839062,"20","nb");
   pl->SetFillColor(0);
   pl->SetTextFont(42);
   pl->SetTextSize(0.5);
   pl->Draw();
   
   pl = new TPaveLabel(0.9622567,-0.7785088,1.323668,-0.3533387,"19","nb");
   pl->SetFillColor(0);
   pl->SetTextFont(42);
   pl->SetTextSize(0.5);
   pl->Draw();

   pl= new TPaveLabel(-1.0, -1.42, -0.95, -1.37, "#it{#bf{sPHENIX}} Internal","nb");
   pl->SetFillColor(0);
   pl->SetLineColor(0);
   pl->SetLineStyle(0);
   pl->SetFillStyle(0);
   pl->SetTextFont(42);
   pl->SetTextSize(2.6);
   pl->Draw();

   pl= new TPaveLabel(0.9, 1.37, 0.95, 1.42, "#bf{TPC South Sectors}","nb");
   pl->SetFillStyle(0);
   pl->SetLineColor(0);
   pl->SetFillColor(0);
   pl->SetTextFont(42);
   pl->SetTextSize(2.6);
   pl->Draw();

   pl= new TPaveLabel(1.15, 1.22, 1.2, 1.27, "Run 26741","nb");
   pl->SetFillColor(0);
   pl->SetFillStyle(0);
   pl->SetLineColor(0);
   pl->SetTextFont(42);
   pl->SetTextSize(2.5);
   pl->Draw();
   /*
   pl= new TPaveLabel(-0.82, 1.57, -0.75, 1.17, "Live Channel Fraction (%)","nb");
   pl->SetFillStyle(0);
   pl->SetFillColor(0);
   pl->SetTextFont(42);
   pl->SetTextSize(0.3);
   pl->Draw();
   */
   Error_Viz_2->Modified();
   TLatex *x = new TLatex(0.49, -0.15, "X-Axis Label");
   x->SetTextSize(0.03); // Set the text size                                                                                                                         
   x->SetNDC(kTRUE); // Use normalized coordinates                                                                                                                   
   x->Draw();

   Error_Viz->cd();
   Error_Viz->Modified();
   Error_Viz->cd();
   Error_Viz->SetSelected(Error_Viz);
}

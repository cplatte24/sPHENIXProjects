#ifdef __CLING__
#pragma cling optimize(0)
#endif
void Efficiency25503()
{
//=========Macro generated from canvas: Error_Viz/Error_Viz
//=========  (Thu Sep 14 15:49:59 2023) by ROOT version 6.26/06
   TCanvas *Error_Viz = new TCanvas("Error_Viz", "Error_Viz",0,22,1248,598);
   gStyle->SetOptStat(0);
   Error_Viz->Range(0,0,1,1);
   Error_Viz->SetFillColor(0);
   Error_Viz->SetBorderMode(0);
   Error_Viz->SetBorderSize(2);
   Error_Viz->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: Error_Viz_1
   TPad *Error_Viz_1 = new TPad("Error_Viz_1", "25503-FEE Channel Efficiency North Side",0.01,0.01,0.49,0.99);
   Error_Viz_1->Draw();
   Error_Viz_1->cd();
   Error_Viz_1->Range(-1.875,-1.875,1.875,1.875);
   Error_Viz_1->SetFillColor(0);
   Error_Viz_1->SetBorderMode(0);
   Error_Viz_1->SetBorderSize(2);
   Error_Viz_1->SetFrameBorderMode(0);
   Error_Viz_1->SetFrameBorderMode(0);
   
   TH2D *dummy1__1 = new TH2D("dummy1__1","25503-Alive Channel Fraction North Side (%)",100,-1.5,1.5,100,-1.5,1.5);
   dummy1__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   dummy1__1->SetLineColor(ci);
   dummy1__1->GetXaxis()->SetLabelFont(42);
   dummy1__1->GetXaxis()->SetTitleOffset(1);
   dummy1__1->GetXaxis()->SetTitleFont(42);
   dummy1__1->GetYaxis()->SetLabelFont(42);
   dummy1__1->GetYaxis()->SetTitleFont(42);
   dummy1__1->GetZaxis()->SetLabelFont(42);
   dummy1__1->GetZaxis()->SetTitleOffset(1);
   dummy1__1->GetZaxis()->SetTitleFont(42);
   dummy1__1->Draw("");
   Double_t yAxis1[5] = {0, 0.256, 0.504, 0.752, 1}; 
   
   TH2D *CSide__2 = new TH2D("CSide__2","ADC Counts South Side",12,-0.2617994,6.021386,4, yAxis1);
   CSide__2->SetBinContent(29,98.35938);
   CSide__2->SetBinContent(30,100);
   CSide__2->SetBinContent(31,99.6875);
   CSide__2->SetBinContent(32,94.60938);
   CSide__2->SetBinContent(33,94.46614);
   CSide__2->SetBinContent(34,95.3125);
   CSide__2->SetBinContent(35,100);
   CSide__2->SetBinContent(36,100);
   CSide__2->SetBinContent(37,93.75);
   CSide__2->SetBinContent(38,93.68489);
   CSide__2->SetBinContent(39,97.91667);
   CSide__2->SetBinContent(40,93.75);
   CSide__2->SetBinContent(43,99.38616);
   CSide__2->SetBinContent(44,97.91667);
   CSide__2->SetBinContent(45,98.4375);
   CSide__2->SetBinContent(46,96.65179);
   CSide__2->SetBinContent(47,99.21875);
   CSide__2->SetBinContent(48,99.75586);
   CSide__2->SetBinContent(49,99.38616);
   CSide__2->SetBinContent(50,96.875);
   CSide__2->SetBinContent(51,94.58705);
   CSide__2->SetBinContent(52,100);
   CSide__2->SetBinContent(53,99.6582);
   CSide__2->SetBinContent(54,99.38616);
   CSide__2->SetBinContent(57,99.73958);
   CSide__2->SetBinContent(58,97.72727);
   CSide__2->SetBinContent(59,97.65625);
   CSide__2->SetBinContent(60,98.82812);
   CSide__2->SetBinContent(61,99.28977);
   CSide__2->SetBinContent(62,98.82812);
   CSide__2->SetBinContent(63,98.28125);
   CSide__2->SetBinContent(64,93.71094);
   CSide__2->SetBinContent(65,98.40495);
   CSide__2->SetBinContent(66,99.64192);
   CSide__2->SetBinContent(67,98.97017);
   CSide__2->SetBinContent(68,95.01953);
   CSide__2->SetBinError(29,98.35938);
   CSide__2->SetBinError(30,100);
   CSide__2->SetBinError(31,99.6875);
   CSide__2->SetBinError(32,94.60938);
   CSide__2->SetBinError(33,94.46614);
   CSide__2->SetBinError(34,95.3125);
   CSide__2->SetBinError(35,100);
   CSide__2->SetBinError(36,100);
   CSide__2->SetBinError(37,93.75);
   CSide__2->SetBinError(38,93.68489);
   CSide__2->SetBinError(39,97.91667);
   CSide__2->SetBinError(40,93.75);
   CSide__2->SetBinError(43,99.38616);
   CSide__2->SetBinError(44,97.91667);
   CSide__2->SetBinError(45,98.4375);
   CSide__2->SetBinError(46,96.65179);
   CSide__2->SetBinError(47,99.21875);
   CSide__2->SetBinError(48,99.75586);
   CSide__2->SetBinError(49,99.38616);
   CSide__2->SetBinError(50,96.875);
   CSide__2->SetBinError(51,94.58705);
   CSide__2->SetBinError(52,100);
   CSide__2->SetBinError(53,99.6582);
   CSide__2->SetBinError(54,99.38616);
   CSide__2->SetBinError(57,99.73958);
   CSide__2->SetBinError(58,97.72727);
   CSide__2->SetBinError(59,97.65625);
   CSide__2->SetBinError(60,98.82812);
   CSide__2->SetBinError(61,99.28977);
   CSide__2->SetBinError(62,98.82812);
   CSide__2->SetBinError(63,98.28125);
   CSide__2->SetBinError(64,93.71094);
   CSide__2->SetBinError(65,98.40495);
   CSide__2->SetBinError(66,99.64192);
   CSide__2->SetBinError(67,98.97017);
   CSide__2->SetBinError(68,95.01953);
   CSide__2->SetMinimum(80);
   CSide__2->SetMaximum(100);
   CSide__2->SetEntries(36);
   CSide__2->SetStats(0);
   CSide__2->SetContour(20);
   CSide__2->SetContourLevel(0,80);
   CSide__2->SetContourLevel(1,81);
   CSide__2->SetContourLevel(2,82);
   CSide__2->SetContourLevel(3,83);
   CSide__2->SetContourLevel(4,84);
   CSide__2->SetContourLevel(5,85);
   CSide__2->SetContourLevel(6,86);
   CSide__2->SetContourLevel(7,87);
   CSide__2->SetContourLevel(8,88);
   CSide__2->SetContourLevel(9,89);
   CSide__2->SetContourLevel(10,90);
   CSide__2->SetContourLevel(11,91);
   CSide__2->SetContourLevel(12,92);
   CSide__2->SetContourLevel(13,93);
   CSide__2->SetContourLevel(14,94);
   CSide__2->SetContourLevel(15,95);
   CSide__2->SetContourLevel(16,96);
   CSide__2->SetContourLevel(17,97);
   CSide__2->SetContourLevel(18,98);
   CSide__2->SetContourLevel(19,99);
   
   TPaletteAxis *palette = new TPaletteAxis(1.51875,-1.5,1.6875,1.5,CSide__2);
   palette->SetLabelColor(1);
   palette->SetLabelFont(42);
   palette->SetLabelOffset(0.005);
   palette->SetLabelSize(0.035);
   palette->SetTitleOffset(1);
   palette->SetTitleSize(0.035);

   ci = TColor::GetColor("#f9f90e");
   palette->SetFillColor(ci);
   palette->SetFillStyle(1001);
   CSide__2->GetListOfFunctions()->Add(palette,"br");

   ci = TColor::GetColor("#000099");
   CSide__2->SetLineColor(ci);
   CSide__2->GetXaxis()->SetLabelFont(42);
   CSide__2->GetXaxis()->SetTitleOffset(1);
   CSide__2->GetXaxis()->SetTitleFont(42);
   CSide__2->GetYaxis()->SetLabelFont(42);
   CSide__2->GetYaxis()->SetTitleFont(42);
   CSide__2->GetZaxis()->SetLabelFont(42);
   CSide__2->GetZaxis()->SetTitleOffset(1);
   CSide__2->GetZaxis()->SetTitleFont(42);
   CSide__2->Draw("colpolzsame0");
   
   TPaveLabel *pl = new TPaveLabel(1.046586,-0.1938999,1.407997,0.2144871,"00","br");
   pl->SetFillColor(0);
   pl->SetTextSize(0.99);
   pl->Draw();
   
   pl = new TPaveLabel(0.962076,0.4382608,1.323487,0.8466479,"01","br");
   pl->SetFillColor(0);
   pl->SetTextSize(0.99);
   pl->Draw();
   
   pl = new TPaveLabel(0.4801947,0.8802139,0.8416056,1.288601,"02","br");
   pl->SetFillColor(0);
   pl->SetTextSize(0.99);
   pl->Draw();
   
   pl = new TPaveLabel(-0.1823921,1.011681,0.1790189,1.425662,"03","br");
   pl->SetFillColor(0);
   pl->SetTextSize(0.99);
   pl->Draw();
   
   pl = new TPaveLabel(-0.8449788,0.8690253,-0.4835679,1.288601,"04","br");
   pl->SetFillColor(0);
   pl->SetTextSize(0.99);
   pl->Draw();
   
   pl = new TPaveLabel(-1.30879,0.441058,-0.9473786,0.8550394,"05","br");
   pl->SetFillColor(0);
   pl->SetTextSize(0.99);
   pl->Draw();
   
   pl = new TPaveLabel(-1.411009,-0.2050886,-1.049598,0.2144871,"06","br");
   pl->SetFillColor(0);
   pl->SetTextSize(0.99);
   pl->Draw();
   
   pl = new TPaveLabel(-1.302585,-0.7757116,-0.9471979,-0.3561359,"07","br");
   pl->SetFillColor(0);
   pl->SetTextSize(0.99);
   pl->Draw();
   
   pl = new TPaveLabel(-0.8449788,-1.309971,-0.4835679,-0.8848013,"08","br");
   pl->SetFillColor(0);
   pl->SetTextSize(0.99);
   pl->Draw();
   
   pl = new TPaveLabel(-0.1823921,-1.426557,0.1790189,-1.006982,"09","br");
   pl->SetFillColor(0);
   pl->SetTextSize(0.99);
   pl->Draw();
   
   pl = new TPaveLabel(0.4801947,-1.309076,0.8416056,-0.8839062,"10","br");
   pl->SetFillColor(0);
   pl->SetTextSize(0.99);
   pl->Draw();
   
   pl = new TPaveLabel(0.9622567,-0.7785088,1.323668,-0.3533387,"11","br");
   pl->SetFillColor(0);
   pl->SetTextSize(0.99);
   pl->Draw();
   
   TPaveText *pt = new TPaveText(0.15,0.934955,0.85,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("25503-Alive Channel Fraction North Side (%)");
   pt->Draw();
   Error_Viz_1->Modified();
   Error_Viz->cd();
  
// ------------>Primitives in pad: Error_Viz_2
   TPad *Error_Viz_2 = new TPad("Error_Viz_2", "Error_Viz_2",0.51,0.01,0.99,0.99);
   Error_Viz_2->Draw();
   Error_Viz_2->cd();
   Error_Viz_2->Range(-1.875,-1.875,1.875,1.875);
   Error_Viz_2->SetFillColor(0);
   Error_Viz_2->SetBorderMode(0);
   Error_Viz_2->SetBorderSize(2);
   Error_Viz_2->SetFrameBorderMode(0);
   Error_Viz_2->SetFrameBorderMode(0);
   
   TH2D *dummy2__3 = new TH2D("dummy2__3","25503-Alive Channel Fraction South Side (%)",100,-1.5,1.5,100,-1.5,1.5);
   dummy2__3->SetStats(0);

   ci = TColor::GetColor("#000099");
   dummy2__3->SetLineColor(ci);
   dummy2__3->GetXaxis()->SetLabelFont(42);
   dummy2__3->GetXaxis()->SetTitleOffset(1);
   dummy2__3->GetXaxis()->SetTitleFont(42);
   dummy2__3->GetYaxis()->SetLabelFont(42);
   dummy2__3->GetYaxis()->SetTitleFont(42);
   dummy2__3->GetZaxis()->SetLabelFont(42);
   dummy2__3->GetZaxis()->SetTitleOffset(1);
   dummy2__3->GetZaxis()->SetTitleFont(42);
   dummy2__3->Draw("");
   Double_t yAxis2[5] = {0, 0.256, 0.504, 0.752, 1}; 
   
   TH2D *ASide__4 = new TH2D("ASide__4","ADC Counts North Side",12,-0.2617994,6.021386,4, yAxis2);
   ASide__4->SetBinContent(29,97.5);
   ASide__4->SetBinContent(30,100);
   ASide__4->SetBinContent(31,92.5);
   ASide__4->SetBinContent(32,95);
   ASide__4->SetBinContent(33,98.5677);
   ASide__4->SetBinContent(34,96.09375);
   ASide__4->SetBinContent(35,93.75);
   ASide__4->SetBinContent(36,100);
   ASide__4->SetBinContent(37,98.82812);
   ASide__4->SetBinContent(38,98.67188);
   ASide__4->SetBinContent(39,97.5);
   ASide__4->SetBinContent(40,94.29688);
   ASide__4->SetBinContent(43,94.64286);
   ASide__4->SetBinContent(44,98.15849);
   ASide__4->SetBinContent(45,96.875);
   ASide__4->SetBinContent(46,99.21875);
   ASide__4->SetBinContent(47,96.63086);
   ASide__4->SetBinContent(48,98.38867);
   ASide__4->SetBinContent(49,100);
   ASide__4->SetBinContent(50,98.21429);
   ASide__4->SetBinContent(51,98.4375);
   ASide__4->SetBinContent(52,89.45312);
   ASide__4->SetBinContent(53,97.65625);
   ASide__4->SetBinContent(54,100);
   ASide__4->SetBinContent(57,98.40199);
   ASide__4->SetBinContent(58,95.74219);
   ASide__4->SetBinContent(59,95.93098);
   ASide__4->SetBinContent(60,97.46094);
   ASide__4->SetBinContent(61,93.29427);
   ASide__4->SetBinContent(62,98.95833);
   ASide__4->SetBinContent(63,97.72727);
   ASide__4->SetBinContent(64,93.14631);
   ASide__4->SetBinContent(65,97.36328);
   ASide__4->SetBinContent(66,98.86364);
   ASide__4->SetBinContent(67,99.47917);
   ASide__4->SetBinContent(68,97.88411);
   ASide__4->SetBinError(29,97.5);
   ASide__4->SetBinError(30,100);
   ASide__4->SetBinError(31,92.5);
   ASide__4->SetBinError(32,95);
   ASide__4->SetBinError(33,98.5677);
   ASide__4->SetBinError(34,96.09375);
   ASide__4->SetBinError(35,93.75);
   ASide__4->SetBinError(36,100);
   ASide__4->SetBinError(37,98.82812);
   ASide__4->SetBinError(38,98.67188);
   ASide__4->SetBinError(39,97.5);
   ASide__4->SetBinError(40,94.29688);
   ASide__4->SetBinError(43,94.64286);
   ASide__4->SetBinError(44,98.15849);
   ASide__4->SetBinError(45,96.875);
   ASide__4->SetBinError(46,99.21875);
   ASide__4->SetBinError(47,96.63086);
   ASide__4->SetBinError(48,98.38867);
   ASide__4->SetBinError(49,100);
   ASide__4->SetBinError(50,98.21429);
   ASide__4->SetBinError(51,98.4375);
   ASide__4->SetBinError(52,89.45312);
   ASide__4->SetBinError(53,97.65625);
   ASide__4->SetBinError(54,100);
   ASide__4->SetBinError(57,98.40199);
   ASide__4->SetBinError(58,95.74219);
   ASide__4->SetBinError(59,95.93098);
   ASide__4->SetBinError(60,97.46094);
   ASide__4->SetBinError(61,93.29427);
   ASide__4->SetBinError(62,98.95833);
   ASide__4->SetBinError(63,97.72727);
   ASide__4->SetBinError(64,93.14631);
   ASide__4->SetBinError(65,97.36328);
   ASide__4->SetBinError(66,98.86364);
   ASide__4->SetBinError(67,99.47917);
   ASide__4->SetBinError(68,97.88411);
   ASide__4->SetMinimum(80);
   ASide__4->SetMaximum(100);
   ASide__4->SetEntries(36);
   ASide__4->SetStats(0);
   ASide__4->SetContour(20);
   ASide__4->SetContourLevel(0,80);
   ASide__4->SetContourLevel(1,81);
   ASide__4->SetContourLevel(2,82);
   ASide__4->SetContourLevel(3,83);
   ASide__4->SetContourLevel(4,84);
   ASide__4->SetContourLevel(5,85);
   ASide__4->SetContourLevel(6,86);
   ASide__4->SetContourLevel(7,87);
   ASide__4->SetContourLevel(8,88);
   ASide__4->SetContourLevel(9,89);
   ASide__4->SetContourLevel(10,90);
   ASide__4->SetContourLevel(11,91);
   ASide__4->SetContourLevel(12,92);
   ASide__4->SetContourLevel(13,93);
   ASide__4->SetContourLevel(14,94);
   ASide__4->SetContourLevel(15,95);
   ASide__4->SetContourLevel(16,96);
   ASide__4->SetContourLevel(17,97);
   ASide__4->SetContourLevel(18,98);
   ASide__4->SetContourLevel(19,99);
   
   palette = new TPaletteAxis(1.51875,-1.5,1.6875,1.5,ASide__4);
   palette->SetLabelColor(1);
   palette->SetLabelFont(42);
   palette->SetLabelOffset(0.005);
   palette->SetLabelSize(0.035);
   palette->SetTitleOffset(1);
   palette->SetTitleSize(0.035);

   ci = TColor::GetColor("#f9f90e");
   palette->SetFillColor(ci);
   palette->SetFillStyle(1001);
   ASide__4->GetListOfFunctions()->Add(palette,"br");

   ci = TColor::GetColor("#000099");
   ASide__4->SetLineColor(ci);
   ASide__4->GetXaxis()->SetLabelFont(42);
   ASide__4->GetXaxis()->SetTitleOffset(1);
   ASide__4->GetXaxis()->SetTitleFont(42);
   ASide__4->GetYaxis()->SetLabelFont(42);
   ASide__4->GetYaxis()->SetTitleFont(42);
   ASide__4->GetZaxis()->SetLabelFont(42);
   ASide__4->GetZaxis()->SetTitleOffset(1);
   ASide__4->GetZaxis()->SetTitleFont(42);
   ASide__4->Draw("colpolzsame0");
   
   pl = new TPaveLabel(1.046586,-0.1938999,1.407997,0.2144871,"18","br");
   pl->SetFillColor(0);
   pl->SetTextSize(0.99);
   pl->Draw();
   
   pl = new TPaveLabel(0.962076,0.4382608,1.323487,0.8466479,"17","br");
   pl->SetFillColor(0);
   pl->SetTextSize(0.99);
   pl->Draw();
   
   pl = new TPaveLabel(0.4801947,0.8802139,0.8416056,1.288601,"16","br");
   pl->SetFillColor(0);
   pl->SetTextSize(0.99);
   pl->Draw();
   
   pl = new TPaveLabel(-0.1823921,1.011681,0.1790189,1.425662,"15","br");
   pl->SetFillColor(0);
   pl->SetTextSize(0.99);
   pl->Draw();
   
   pl = new TPaveLabel(-0.8449788,0.8690253,-0.4835679,1.288601,"14","br");
   pl->SetFillColor(0);
   pl->SetTextSize(0.99);
   pl->Draw();
   
   pl = new TPaveLabel(-1.30879,0.441058,-0.9473786,0.8550394,"13","br");
   pl->SetFillColor(0);
   pl->SetTextSize(0.99);
   pl->Draw();
   
   pl = new TPaveLabel(-1.411009,-0.2050886,-1.049598,0.2144871,"12","br");
   pl->SetFillColor(0);
   pl->SetTextSize(0.99);
   pl->Draw();
   
   pl = new TPaveLabel(-1.302585,-0.7757116,-0.9471979,-0.3561359,"23","br");
   pl->SetFillColor(0);
   pl->SetTextSize(0.99);
   pl->Draw();
   
   pl = new TPaveLabel(-0.8449788,-1.309971,-0.4835679,-0.8848013,"22","br");
   pl->SetFillColor(0);
   pl->SetTextSize(0.99);
   pl->Draw();
   
   pl = new TPaveLabel(-0.1823921,-1.426557,0.1790189,-1.006982,"21","br");
   pl->SetFillColor(0);
   pl->SetTextSize(0.99);
   pl->Draw();
   
   pl = new TPaveLabel(0.4801947,-1.309076,0.8416056,-0.8839062,"20","br");
   pl->SetFillColor(0);
   pl->SetTextSize(0.99);
   pl->Draw();
   
   pl = new TPaveLabel(0.9622567,-0.7785088,1.323668,-0.3533387,"19","br");
   pl->SetFillColor(0);
   pl->SetTextSize(0.99);
   pl->Draw();
   
   pt = new TPaveText(0.15,0.934955,0.85,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   pt_LaTex = pt->AddText("25503-Alive Channel Fraction South Side (%)");
   pt->Draw();
   Error_Viz_2->Modified();
   Error_Viz->cd();
   Error_Viz->Modified();
   Error_Viz->cd();
   Error_Viz->SetSelected(Error_Viz);
}

/* 
Run this macro using 
root -l -b -q karsilastiralim.C\(\"rootfiles.txt\",\"JetMET/Run\ summary/Jet/Cleanedak4PFJets/CHEn_mediumPt_EndCap\"\)
First argument is text file with list of the rootfiles 
Second argument is name of the variable whose summary plot is needed
*/

#include "TH2D.h"
#include "TH1D.h"
#include "TH1F.h"
#include "TProfile.h"
#include "THStack.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TLine.h"
#include "TMultiGraph.h"
#include "TGraphErrors.h"
#include "TMinuit.h"
#include "TMatrixD.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


void Hstack_EndCap()
{
////////////////////////////EndCap////////////////////////////////////////////
///////////////////////////high_Pt////////////////////////////////////////////
  TCanvas *c1 = new TCanvas("c1","c1",1800,800);
  c1->SetGridy();
  c1->SetLeftMargin(0.15);
  c1->SetBottomMargin(0.15);

  TFile *f1 = new TFile("Plots/mean_Jet_Cleanedak4PFJetsCHS_CHFrac_highPt_EndCap.root");
  f1->ls(); 
  TH1F * h1 = (TH1F*)f1->Get("h1");
  h1->SetFillColorAlpha(kRed,0.35);
  h1->SetFillStyle(4050);

  TFile *f2 = new TFile("Plots/mean_Jet_Cleanedak4PFJetsCHS_NHFrac_highPt_EndCap.root");
  f2->ls(); 
  TH1F * h2 = (TH1F*)f2->Get("h1");
  h2->SetFillColorAlpha(kBlue,0.35);
  h2->SetFillStyle(4050);
  
  TFile *f3 = new TFile("Plots/mean_Jet_Cleanedak4PFJetsCHS_PhFrac_highPt_EndCap.root");
  f3->ls(); 
  TH1F * h3 = (TH1F*)f3->Get("h1");
  h3->SetFillColorAlpha(kGreen,0.35);
  h3->SetFillStyle(4050);
  
  THStack *hs1 = new THStack("hs1","highPt_EndCap");
  hs1->Add(h1,"hist");   hs1->Add(h2,"hist");   hs1->Add(h3,"hist");
  hs1->Draw("hist,P");
  //hs1->Draw("hist,p");


//define_Era 
/*
  TLine *l0 = new TLine(54,0,54,1.05);
  l0->SetLineColor(2);
  l0->Draw("hist,p");

  TLine *l1 = new TLine(142,0,142,1.05);
  l1->SetLineColor(2);
  l1->Draw("hist,p");

  TLine *l2 = new TLine(177,0,177,1.05);
  l2->SetLineColor(2);
  l2->Draw("hist,p");

  TLine *l3 = new TLine(207,0,207,1.05);
  l3->SetLineColor(2);
  l3->Draw("hist,p");


*/
//define_Era  


  const int Bin1= h2->GetNbinsX();
   for ( int i=0;i<Bin1;i++) {
	TString labelchar= h2->GetXaxis()->GetBinLabel(i+1);
	hs1->GetXaxis()->SetBinLabel(i+1,labelchar);
  }
  gPad->Modified();
  gPad->Update();
  auto legend1 = new TLegend(0.75,0.75,0.95,0.95);
  legend1->AddEntry(h3,"PhFrac","f");
  legend1->AddEntry(h2,"NHFrac","f");
  legend1->AddEntry(h1,"CHFrac","f");
  legend1->Draw("hist,p");
  c1->SaveAs("Plots/Stack_highPt_EndCap.pdf");
  c1->SaveAs("Plots/Stack_highPt_EndCap.png");
///////////////////////////low_Pt////////////////////////////////////////////

  TCanvas *c2 = new TCanvas("c2","c2",1800,800);
  c2->SetGridy();
  c2->SetLeftMargin(0.15);
  c2->SetBottomMargin(0.15);

  TFile *f4 = new TFile("Plots/mean_Jet_Cleanedak4PFJetsCHS_CHFrac_lowPt_EndCap.root");
  f4->ls(); 
  TH1F * h4 = (TH1F*)f4->Get("h1");
  h4->SetFillColorAlpha(kRed,0.35);
  h4->SetFillStyle(4050);

  TFile *f5 = new TFile("Plots/mean_Jet_Cleanedak4PFJetsCHS_NHFrac_lowPt_EndCap.root");
  f5->ls(); 
  TH1F * h5 = (TH1F*)f5->Get("h1");
  h5->SetFillColorAlpha(kBlue,0.35);
  h5->SetFillStyle(4050);
  
  TFile *f6 = new TFile("Plots/mean_Jet_Cleanedak4PFJetsCHS_PhFrac_lowPt_EndCap.root");
  f6->ls(); 
  TH1F * h6 = (TH1F*)f6->Get("h1");
  h6->SetFillColorAlpha(kGreen,0.35);
  h6->SetFillStyle(4050);
  
  THStack *hs2 = new THStack("hs2","lowPt_EndCap");
  hs2->Add(h4,"hist");   hs2->Add(h5,"hist");  hs2->Add(h6,"hist");

  hs2->Draw("hist,p");

//define_Era 
/*

  TLine *l4 = new TLine(54,0,54,1.05);
  l4->SetLineColor(2);
  l4->Draw("hist,p");

  TLine *l5 = new TLine(142,0,142,1.05);
  l5->SetLineColor(2);
  l5->Draw("hist,p");

  TLine *l6 = new TLine(177,0,177,1.05);
  l6->SetLineColor(2);
  l6->Draw("hist,p");

  TLine *l7 = new TLine(207,0,207,1.05);
  l7->SetLineColor(2);
  l7->Draw("hist,p");

*/

//define_Era  


  const int Bin2= h5->GetNbinsX();
   for ( int i=0;i<Bin2;i++) {
	TString labelchar= h5->GetXaxis()->GetBinLabel(i+1);
	hs2->GetXaxis()->SetBinLabel(i+1,labelchar);
  }
  gPad->Modified();
  gPad->Update();
  auto legend2 = new TLegend(0.75,0.75,0.95,0.95);
  legend2->AddEntry(h6,"PhFrac","f");
  legend2->AddEntry(h5,"NHFrac","f");
  legend2->AddEntry(h4,"CHFrac","f");
  legend2->Draw("hist,p");  
  c2->SaveAs("Plots/Stack_lowPt_EndCap.png");
  c2->SaveAs("Plots/Stack_lowPt_EndCap.pdf");

///////////////////////////medium_Pt////////////////////////////////////////////

  TCanvas *c3 = new TCanvas("c3","c3",1800,800);
  c3->SetGridy();
  c3->SetLeftMargin(0.15);
  c3->SetBottomMargin(0.15);

  TFile *f7 = new TFile("Plots/mean_Jet_Cleanedak4PFJetsCHS_CHFrac_mediumPt_EndCap.root");
  f7->ls(); 
  TH1F * h7 = (TH1F*)f7->Get("h1");
  h7->SetFillColorAlpha(kRed,0.35);
  h7->SetFillStyle(4050);

  TFile *f8 = new TFile("Plots/mean_Jet_Cleanedak4PFJetsCHS_NHFrac_mediumPt_EndCap.root");
  f8->ls(); 
  TH1F * h8 = (TH1F*)f8->Get("h1");
  h8->SetFillColorAlpha(kBlue,0.35);
  h8->SetFillStyle(4050);
  
  TFile *f9 = new TFile("Plots/mean_Jet_Cleanedak4PFJetsCHS_PhFrac_mediumPt_EndCap.root");
  f9->ls(); 
  TH1F * h9 = (TH1F*)f9->Get("h1");
  h9->SetFillColorAlpha(kGreen,0.35);
  h9->SetFillStyle(4050);
  
  THStack *hs3 = new THStack("hs3","mediumPt_EndCap");
  hs3->Add(h7,"hist");   hs3->Add(h8,"hist");  hs3->Add(h9,"hist");

  hs3->Draw("hist,p");

//define_Era 
/*

  TLine *l8 = new TLine(54,0,54,1.05);
  l8->SetLineColor(2);
  l8->Draw("hist,p");

  TLine *l9 = new TLine(142,0,142,1.05);
  l9->SetLineColor(2);
  l9->Draw("hist,p");

  TLine *l10 = new TLine(177,0,177,1.05);
  l10->SetLineColor(2);
  l10->Draw("hist,p");

  TLine *l11 = new TLine(207,0,207,1.05);
  l11->SetLineColor(2);
  l11->Draw("hist,p");
*/
//define_Era  


  const int Bin3= h8->GetNbinsX();
   for ( int i=0;i<Bin3;i++) {
	TString labelchar= h8->GetXaxis()->GetBinLabel(i+1);
	hs3->GetXaxis()->SetBinLabel(i+1,labelchar);
  }
  gPad->Modified();
  gPad->Update();
  auto legend3 = new TLegend(0.75,0.75,0.95,0.95);
  legend3->AddEntry(h9,"PhFrac","f");
  legend3->AddEntry(h8,"NHFrac","f");
  legend3->AddEntry(h7,"CHFrac","f");
  legend3->Draw("hist,p");  
  c3->SaveAs("Plots/Stack_mediumPt_EndCap.png");
  c3->SaveAs("Plots/Stack_mediumPt_EndCap.pdf");
}




/* 
Run this macro using 
root -l -b -q Hstack_Eta_minus_28_30.C\(\"rootfiles.txt\",\"JetMET/Run\ summary/Jet/Cleanedak4PFJetsCHS/CHEn_mediumPt_EndCap\"\)
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


void Hstack_Eta_minus_28_30()
{
////////////////////////////Frac_Eta_minus_2.8-3////////////////////////////////////////////
///////////////////////////High_Pt////////////////////////////////////////////
  TCanvas *c1 = new TCanvas("c1","c1",1800,800);
  c1->SetGrid();
  c1->SetLeftMargin(0.15);
  c1->SetBottomMargin(0.15);

  TFile *f1 = new TFile("Plots/bin22_Jet_Cleanedak4PFJetsCHS_CHFracVSeta_highPt.root");
  f1->ls(); 
  TH1F * h1 = (TH1F*)f1->Get("h5");
  h1->SetFillColor(kRed);
  h1->SetFillStyle(3001);

  TFile *f2 = new TFile("Plots/bin22_Jet_Cleanedak4PFJetsCHS_NHFracVSeta_highPt.root");
  f2->ls(); 
  TH1F * h2 = (TH1F*)f2->Get("h5");
  h2->SetFillColor(kBlue);
  h2->SetFillStyle(3001);
  
  TFile *f3 = new TFile("Plots/bin22_Jet_Cleanedak4PFJetsCHS_PhFracVSeta_highPt.root");
  f3->ls(); 
  TH1F * h3 = (TH1F*)f3->Get("h5");
  h3->SetFillColor(kGreen);
  h3->SetFillStyle(3001);
  
  THStack *hs1 = new THStack("hs1","High_Pt Frac Eta minus 2.8-3");
  hs1->Add(h1);   hs1->Add(h2);  hs1->Add(h3);

  hs1->Draw();

//define_Era 
/*

  TLine *l0 = new TLine(54,0,54,1.05);
  l0->SetLineColor(2);
  l0->Draw();

  TLine *l1 = new TLine(142,0,142,1.05);
  l1->SetLineColor(2);
  l1->Draw();

  TLine *l2 = new TLine(177,0,177,1.05);
  l2->SetLineColor(2);
  l2->Draw();

  TLine *l3 = new TLine(207,0,207,1.05);
  l3->SetLineColor(2);
  l3->Draw();


*/

//define_Era  


  const int Bin1= h2->GetNbinsX();
   for (i=0;i<Bin1;i++) {
	TString labelchar= h2->GetXaxis()->GetBinLabel(i+1);
	hs1->GetXaxis()->SetBinLabel(i+1,labelchar);
  }
  gPad->Modified();
  gPad->Update();
  auto legend = new TLegend(0.75,0.75,0.95,0.95);
  legend->AddEntry(h1,"CHFrac","f");
  legend->AddEntry(h2,"NHFrac","f");
  legend->AddEntry(h3,"PhFrac","f");
  legend->Draw();
  c1->SaveAs("Plots/Stack_High_Pt_Frac_Eta_minus_28-30.pdf");
  c1->SaveAs("Plots/Stack_High_Pt_Frac_Eta_minus_28-30.png");
///////////////////////////High_Pt////////////////////////////////////////////
///////////////////////////Medium_Pt////////////////////////////////////////////
  TCanvas *c2 = new TCanvas("c2","c2",1800,800);
  c2->SetGrid();
  c2->SetLeftMargin(0.15);
  c2->SetBottomMargin(0.15);

  TFile *f4 = new TFile("Plots/bin22_Jet_Cleanedak4PFJetsCHS_CHFracVSeta_mediumPt.root");
  f4->ls(); 
  TH1F * h4 = (TH1F*)f4->Get("h5");
  h4->SetFillColor(kRed);
  h4->SetFillStyle(3001);

  TFile *f5 = new TFile("Plots/bin22_Jet_Cleanedak4PFJetsCHS_NHFracVSeta_mediumPt.root");
  f5->ls(); 
  TH1F * h5 = (TH1F*)f5->Get("h5");
  h5->SetFillColor(kBlue);
  h5->SetFillStyle(3001);
  
  TFile *f6 = new TFile("Plots/bin22_Jet_Cleanedak4PFJetsCHS_PhFracVSeta_mediumPt.root");
  f6->ls(); 
  TH1F * h6 = (TH1F*)f6->Get("h5");
  h6->SetFillColor(kGreen);
  h6->SetFillStyle(3001);
  
  THStack *hs2 = new THStack("hs2","Medium_Pt Frac Eta minus 2.8-3");
  hs2->Add(h4);   hs2->Add(h5);  hs2->Add(h6);

  hs2->Draw();

//define_Era 
/*

  TLine *l4 = new TLine(54,0,54,1.05);
  l4->SetLineColor(2);
  l4->Draw();

  TLine *l5 = new TLine(142,0,142,1.05);
  l5->SetLineColor(2);
  l5->Draw();

  TLine *l6 = new TLine(177,0,177,1.05);
  l6->SetLineColor(2);
  l6->Draw();

  TLine *l7 = new TLine(207,0,207,1.05);
  l7->SetLineColor(2);
  l7->Draw();

*/

//define_Era  


  const int Bin2= h5->GetNbinsX();
   for (i=0;i<Bin2;i++) {
	TString labelchar= h5->GetXaxis()->GetBinLabel(i+1);
	hs2->GetXaxis()->SetBinLabel(i+1,labelchar);
  }
  gPad->Modified();
  gPad->Update();
  auto legend = new TLegend(0.75,0.75,0.95,0.95);
  legend->AddEntry(h4,"CHFrac","f");
  legend->AddEntry(h5,"NHFrac","f");
  legend->AddEntry(h6,"PhFrac","f");
  legend->Draw();
  c2->SaveAs("Plots/Stack_Medium_Pt_Frac_Eta_minus_28-30.pdf");
  c2->SaveAs("Plots/Stack_Medium_Pt_Frac_Eta_minus_28-30.png");
  
///////////////////////////Medium_Pt////////////////////////////////////////////
///////////////////////////Low_Pt////////////////////////////////////////////
  
  TCanvas *c3 = new TCanvas("c3","c3",1800,800);
  c3->SetGrid();
  c3->SetLeftMargin(0.15);
  c3->SetBottomMargin(0.15);

  TFile *f7 = new TFile("Plots/bin22_Jet_Cleanedak4PFJetsCHS_CHFracVSeta_lowPt.root");
  f7->ls(); 
  TH1F * h7 = (TH1F*)f7->Get("h5");
  h7->SetFillColor(kRed);
  h7->SetFillStyle(3001);

  TFile *f8 = new TFile("Plots/bin22_Jet_Cleanedak4PFJetsCHS_NHFacVSeta_lowPt.root");
  f8->ls(); 
  TH1F * h8 = (TH1F*)f8->Get("h5");
  h8->SetFillColor(kBlue);
  h8->SetFillStyle(3001);

  TFile *f9 = new TFile("Plots/bin22_Jet_Cleanedak4PFJetsCHS_PhFracVSeta_lowPt.root");
  f9->ls(); 
  TH1F * h9 = (TH1F*)f9->Get("h5");
  h9->SetFillColor(kGreen);
  h9->SetFillStyle(3001);
  
  THStack *hs3 = new THStack("hs3","Low_Pt Frac Eta minus 2.8-3");
  hs3->Add(h7);   hs3->Add(h8);  hs3->Add(h9);

  hs3->Draw();

//define_Era 
/*


  TLine *l8 = new TLine(54,0,54,1.05);
  l8->SetLineColor(2);
  l8->Draw();

  TLine *l9 = new TLine(142,0,142,1.05);
  l9->SetLineColor(2);
  l9->Draw();

  TLine *l10 = new TLine(177,0,177,1.05);
  l10->SetLineColor(2);
  l10->Draw();

  TLine *l11 = new TLine(207,0,207,1.05);
  l11->SetLineColor(2);
  l11->Draw();


*/
//define_Era  


  const int Bin3= h9->GetNbinsX();
   for (i=0;i<Bin3;i++) {
	TString labelchar= h9->GetXaxis()->GetBinLabel(i+1);
	hs3->GetXaxis()->SetBinLabel(i+1,labelchar);
  }
  gPad->Modified();
  gPad->Update();
  auto legend = new TLegend(0.75,0.75,0.95,0.95);
  legend->AddEntry(h7,"CHFrac","f");
  legend->AddEntry(h8,"NHFrac","f");
  legend->AddEntry(h9,"PhFrac","f");
  legend->Draw();
  c3->SaveAs("Plots/Stack_Low_Pt_Frac_Eta_minus_28-30.pdf");
  c3->SaveAs("Plots/Stack_Low_Pt_Frac_Eta_minus_28-30.png");
///////////////////////////Low_Pt////////////////////////////////////////////
////////////////////////////Frac_Eta_minus_2.8-3////////////////////////////////////////////

}


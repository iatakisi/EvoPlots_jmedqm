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


void Hstack_Barrel()
{
////////////////////////////Barrel////////////////////////////////////////////
///////////////////////////high_Pt////////////////////////////////////////////
  TCanvas *c1 = new TCanvas("c1","c1",1800,800);
  c1->SetGrid();
  c1->SetLeftMargin(0.15);
  c1->SetBottomMargin(0.15);

  TFile *f1 = new TFile("Plots/mean_Jet_Cleanedak4PFJetsCHS_CHFrac_highPt_Barrel.root");
  f1->ls(); 
  TH1F * h1 = (TH1F*)f1->Get("h1");
  h1->SetFillColor(kRed);
  h1->SetFillStyle(3001);

  TFile *f2 = new TFile("Plots/mean_Jet_Cleanedak4PFJetsCHS_NHFrac_highPt_Barrel.root");
  f2->ls(); 
  TH1F * h2 = (TH1F*)f2->Get("h1");
  h2->SetFillColor(kBlue);
  h2->SetFillStyle(3001);
  
  TFile *f3 = new TFile("Plots/mean_Jet_Cleanedak4PFJetsCHS_PhFrac_highPt_Barrel.root");
  f3->ls(); 
  TH1F * h3 = (TH1F*)f3->Get("h1");
  h3->SetFillColor(kGreen);
  h3->SetFillStyle(3001);
  
  THStack *hs1 = new THStack("hs1","highPt_Barrel");
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
  c1->SaveAs("Plots/Stack_highPt_Barrel.pdf");
  c1->SaveAs("Plots/Stack_highPt_Barrel.png");
///////////////////////////low_Pt////////////////////////////////////////////

  TCanvas *c2 = new TCanvas("c2","c2",1800,800);
  c2->SetGrid();
  c2->SetLeftMargin(0.15);
  c2->SetBottomMargin(0.15);

  TFile *f4 = new TFile("Plots/mean_Jet_Cleanedak4PFJetsCHS_CHFrac_lowPt_Barrel.root");
  f4->ls(); 
  TH1F * h4 = (TH1F*)f4->Get("h1");
  h4->SetFillColor(kRed);
  h4->SetFillStyle(3001);

  TFile *f5 = new TFile("Plots/mean_Jet_Cleanedak4PFJetsCHS_NHFrac_lowPt_Barrel.root");
  f5->ls(); 
  TH1F * h5 = (TH1F*)f5->Get("h1");
  h5->SetFillColor(kBlue);
  h5->SetFillStyle(3001);
  
  TFile *f6 = new TFile("Plots/mean_Jet_Cleanedak4PFJetsCHS_PhFrac_lowPt_Barrel.root");
  f6->ls(); 
  TH1F * h6 = (TH1F*)f6->Get("h1");
  h6->SetFillColor(kGreen);
  h6->SetFillStyle(3001);
  
  THStack *hs2 = new THStack("hs2","lowPt_Barrel");
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
  c2->SaveAs("Plots/Stack_lowPt_Barrel.png");
  c2->SaveAs("Plots/Stack_lowPt_Barrel.pdf");

///////////////////////////medium_Pt////////////////////////////////////////////

  TCanvas *c3 = new TCanvas("c3","c3",1800,800);
  c3->SetGrid();
  c3->SetLeftMargin(0.15);
  c3->SetBottomMargin(0.15);

  TFile *f7 = new TFile("Plots/mean_Jet_Cleanedak4PFJetsCHS_CHFrac_mediumPt_Barrel.root");
  f7->ls(); 
  TH1F * h7 = (TH1F*)f7->Get("h1");
  h7->SetFillColor(kRed);
  h7->SetFillStyle(3001);

  TFile *f8 = new TFile("Plots/mean_Jet_Cleanedak4PFJetsCHS_NHFrac_mediumPt_Barrel.root");
  f8->ls(); 
  TH1F * h8 = (TH1F*)f8->Get("h1");
  h8->SetFillColor(kBlue);
  h8->SetFillStyle(3001);
  
  TFile *f9 = new TFile("Plots/mean_Jet_Cleanedak4PFJetsCHS_PhFrac_mediumPt_Barrel.root");
  f9->ls(); 
  TH1F * h9 = (TH1F*)f9->Get("h1");
  h9->SetFillColor(kGreen);
  h9->SetFillStyle(3001);
  
  THStack *hs3 = new THStack("hs3","mediumPt_Barrel");
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


  const int Bin3= h8->GetNbinsX();
   for (i=0;i<Bin3;i++) {
	TString labelchar= h8->GetXaxis()->GetBinLabel(i+1);
	hs3->GetXaxis()->SetBinLabel(i+1,labelchar);
  }
  gPad->Modified();
  gPad->Update();
  auto legend = new TLegend(0.75,0.75,0.95,0.95);
  legend->AddEntry(h7,"CHFrac","f");
  legend->AddEntry(h8,"NHFrac","f");
  legend->AddEntry(h9,"PhFrac","f");
  legend->Draw();  
  c3->SaveAs("Plots/Stack_mediumPt_Barrel.png");
  c3->SaveAs("Plots/Stack_mediumPt_Barrel.pdf");
}



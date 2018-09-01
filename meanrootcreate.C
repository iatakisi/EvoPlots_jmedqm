#include "TH1.h"
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
#include <fstream>
#include <vector>
#include <string>
using namespace std;



void meanrootcreate(TString pdfname)
{
  //cout<<pdfname<<endl;
  ifstream rmean("Plots/mean.txt");
  vector<double> mean;
  double line=0;
  rmean>>line;
  int nFiles=line;
  //cout << nFiles<<endl;
  rmean>>line;
  double largemean=line;
  //cout << largemean<<endl;
  rmean>>line;
  double smallmean=line;
  //cout <<smallmean<<endl;
  string runnumber;
  vector<string> runno;

  while (!rmean.eof()){
      rmean>>line;
      mean.push_back(line);
      //cout << "mean: " << mean.back()<<"  size:"<<mean.size()<<endl;
      rmean>>runnumber;
      runno.push_back(runnumber);
      //cout << "runno: " << runno.back()<<"  size:"<<runno.size()<<endl;
   }
    
    TH1F *h1 = new TH1F("h1","Mean Values",nFiles,-0.5,nFiles-0.5);
  for (Int_t i=0;i<nFiles ;i++) {
    //cout <<"Filled :" << mean[i] << endl;
    h1->Fill(i, mean[i]);
  }
  h1->SetStats(0);
  h1->SetMarkerStyle(20);
  h1->GetXaxis()->SetTitle("Run No");
  h1->GetYaxis()->SetTitle("Mean");
  h1->GetYaxis()->SetTitleColor(2);
  h1->GetXaxis()->SetTitleColor(2);
  h1->SetMaximum(largemean+0.5);
  h1->SetMinimum(smallmean-0.5);
  h1->Draw("p");
  
  
  //define_Era 
/*
  TLine *l0 = new TLine(13,smallmean-0.5,13,largemean+0.5);
  l0->SetLineColor(2);
  l0->Draw();
  TLine *l1 = new TLine(80,smallmean-0.5,80,largemean+0.5);
  l1->SetLineColor(2);
  l1->Draw();
  TLine *l2 = new TLine(99,smallmean-0.5,99,largemean+0.5);
  l2->SetLineColor(2);
  l2->Draw();
.*/
//define_Era  
  // draw labels along X
  for (i=0;i<nFiles;i++) {
     TString runno1=runno[i];
    if((i %1)==0){h1->GetXaxis()->SetBinLabel(i+1,runno1);}
  }
  gPad->Modified();
  gPad->Update();

  TFile *rootfile1=new TFile("Plots/mean_"+pdfname+".root","RECREATE");
  h1->Write();
  rootfile1->Close();

}
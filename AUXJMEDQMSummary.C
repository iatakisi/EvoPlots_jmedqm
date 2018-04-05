
/* 

Run this macro using 
root -l -b -q FracTimeEvo.C\(\"rootfiles.txt\",\"JetMET/Run\ summary/Jet/Cleanedak4PFJets/CHEn_mediumPt_EndCap\"\)


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



std::vector<std::string> split(const std::string& text, const std::string& delims);


void AUXJMEDQMSummary(TString rootfileList, TString postname)
{
  // int colors[] = {1,2,3,4,5,6,7,8};
    
  std::cout<<" Now making summary plots for run number provided in the "<<rootfileList<<std::endl;

  int counter;
  
  //TString postname = "JetMET/Run summary/Jet/Cleanedak4PFJets/CHEn_mediumPt_EndCap";
  // TCanvas *st = new TCanvas("st","compare",100,100,800,600);
  std::vector<std::string> lines;
  lines.clear();
  
  string line;
  
  ifstream myfile (rootfileList);
  if (myfile.is_open())
    {
      while ( getline (myfile,line) )
        {
	  cout << line << '\n';
	  lines.push_back(line);
        }
      myfile.close();
    }
  
  else cout << "Unable to open file";
  
  const int nFiles = lines.size();
  //cout<<nFiles<<endl;
  TFile* fin;
  //TH1F* h;
  
  TString runno[nFiles];
  std::string runnumberrr;
  double noofrun[nFiles];
  double mean[nFiles];
  double RMS[nFiles];
  
  double zeromean = 0;
  double zerorms = 0;
  

  TLegend *leg = new TLegend(0.6269616,0.5475207,0.6837229,0.7692837,NULL,"brNDC");
  leg->SetBorderSize(0);
  leg->SetTextFont(42);
  leg->SetTextSize(0.035);
  
  
  
  //st->SetLogy();
  //st->SetLogx();
  
  std::cout<<" before for loop"<<std::endl;

  TString pdfname;
  for (int ii=0; ii<(int)lines.size(); ii++){
    // Extract the number from the rootfile
    std::vector<std::string> str_component  = split(lines.at(ii),"_");
    std::vector<std::string> str_component_pdf  = split(std::string(postname),"/");
    if (str_component_pdf.size()== 3) {
      pdfname = TString(str_component_pdf[2].c_str()) ;
    }
    else if (TString(str_component_pdf[2].c_str()) == "MET") {
      pdfname = TString(str_component_pdf[2].c_str()) + "_" + TString(str_component_pdf[3].c_str()) + "_" + TString(str_component_pdf[4].c_str()) + "_" + TString(str_component_pdf[5].c_str());
    }
    else pdfname = TString(str_component_pdf[2].c_str()) + "_" + TString(str_component_pdf[3].c_str()) + "_" + TString(str_component_pdf[4].c_str(
));
    cout<<pdfname<<endl;
    TString str_component2 = std::string(str_component[2]).c_str();
    TString runnumber = str_component2.ReplaceAll("R000","");
    
    // histogram name extraction
    TString prename = "DQMData/Run "+runnumber+"/";
    
    TString histname_ =  prename + postname;

    //std::cout<<'line.at(ii).c_str()'<<line.at(ii)<<std::endl;
    
    // Read the rootfile 
    fin = new TFile(lines.at(ii).c_str());
    //fin->ls();
    
    
    // Get the histogram
    TH1F* h = (TH1F*) fin->Get(histname_);
    
    std::cout<<" run number = "<<runnumber << endl
	     <<"  file = "<<lines.at(ii) << endl
	     <<"  histname = "<<histname_ << endl
	     <<"  integral ="<<h->Integral() << endl
	     <<" mean = "<<h->GetMean() << endl
	     <<" RMS = "<<h->GetRMS() 
	     <<endl;
    
    
    runno[ii] = runnumber;
    std::cout<<"runno= "<<runno[ii]<<std::endl;//okan
    runnumberrr=runnumber;
    std::cout<<"runnumberrr= "<<runnumberrr<<std::endl;//okan
    std::stringstream convert(runnumberrr);
    convert >> noofrun[ii];
    noofrun[ii]=noofrun[ii]-300000;
    //std::string::size_type sz;
    //noofrun[ii]= std::stod (runnumberrr,& sz);
    std::cout<<"noofrun= "<<noofrun[ii]<<std::endl;//okan
    mean[ii] = h->GetMean();
    zeromean += mean[ii];
    RMS[ii]= h->GetRMS();
    zerorms += RMS[ii];

    double smallmean = pow(2,16);
    double largemean = -pow(2,16);
    for (int j = 0; j < nFiles; j++) 
      {
	if (mean[j] < smallmean) 
	  {
	    smallmean = mean[j];
	  }
	if (mean[j] > largemean) 
	  {
	    largemean = mean[j];
	  }
      }

    double smallRMS = pow(2,16);
    double largeRMS = -pow(2,16);
    for (int jj = 0; jj < nFiles; jj++)
      {
	if (RMS[jj] < smallRMS)
	  {
	    smallRMS = RMS[jj];
	  }
	if (RMS[jj] > largeRMS)
	  {
	    largeRMS = RMS[jj];
	  }
      }
    
     
      
    fin->Close();
    
  }
 
  //histogram
  
  
  //histograms of means
  TCanvas *c1 = new TCanvas("c1","mean",1800,800);
  c1->SetGrid();
  c1->SetLeftMargin(0.15);
  c1->SetBottomMargin(0.15);
  TH1F *h1 = new TH1F("h1","Mean Values",nFiles,-0.5,nFiles-0.5);
  for (Int_t i=0;i<nFiles;i++) {
    //cout << mean[i] << endl;
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

  TLine *l0 = new TLine(13,smallmean-0.5,13,largemean+0.5);
  l0->SetLineColor(2);
  l0->Draw();

  TLine *l1 = new TLine(80,smallmean-0.5,80,largemean+0.5);
  l1->SetLineColor(2);
  l1->Draw();

  TLine *l2 = new TLine(99,smallmean-0.5,99,largemean+0.5);
  l2->SetLineColor(2);
  l2->Draw();
//define_Era  
  // draw labels along X
  for (i=0;i<nFiles;i++) {
    if((i %10)==0){h1->GetXaxis()->SetBinLabel(i+1,runno[i]);}
  }
  gPad->Modified();
  gPad->Update();
  
  if ((zeromean != 0)&&(zerorms != 0)){//this statement defined to get rid of empty histograms
      c1->SaveAs("Plots/mean_"+pdfname+".pdf");
      c1->SaveAs("Plots/mean_"+pdfname+".png");
  }

//histograms of means
  

//histograms of RMSs
  
  TCanvas *c2 = new TCanvas("c2","rms",1600,800);
  c2->SetGrid();
  c2->SetLeftMargin(0.15);
  c2->SetBottomMargin(0.15);
  TH1F *h2 = new TH1F("h1","Rms Values",nFiles,-0.5,nFiles-0.5);
  for (Int_t i=0;i<nFiles;i++) {
    //cout << RMS[i] << endl;
    h2->Fill(i, RMS[i]);
  }
  h2->SetStats(0);
  h2->SetMarkerStyle(20);
  h2->GetXaxis()->SetTitle("Run No");
  h2->GetYaxis()->SetTitle("Rms");
  h2->GetYaxis()->SetTitleColor(2);
  h2->GetXaxis()->SetTitleColor(2);
  h2->SetMaximum(largeRMS+0.5);
  h2->SetMinimum(smallRMS-0.5);
  h2->Draw("p");
//define_Era  
  TLine *l = new TLine(83,smallRMS-0.5,83,largeRMS+0.5);
  l->SetLineColor(2);
  l->Draw();
//define_Era  
  // draw labels along X
  for (i=0;i<nFiles;i++) {
    h2->GetXaxis()->SetBinLabel(i+1,runno[i]);
  }
  gPad->Modified();
  gPad->Update();
  
}

std::vector<std::string> split(const std::string& text, const std::string& delims)
{
  std::vector<std::string> tokens;
  std::size_t start = text.find_first_not_of(delims), end = 0;
  
  while((end = text.find_first_of(delims, start)) != std::string::npos)
    {
      tokens.push_back(text.substr(start, end - start));
      start = text.find_first_not_of(delims, end);
    }
  if(start != std::string::npos)
    tokens.push_back(text.substr(start));
  
  return tokens;
}


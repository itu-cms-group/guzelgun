#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TClonesArray.h"
#include "TBranch.h"

void likeli() {
    
    
    TCanvas *myc = new TCanvas("c1","gamma and lognormal",10,10,1000,1000);     //setting up a new canvas
    myc->Divide(2,2);                                                           //dividing the canvas in two
    myc->cd(1);                                                                 //cd
    
    TH1F *h1 = new TH1F("h1","Exponential",200,-20,20);                         //new histogram
    h1->FillRandom("expo",10000);                                               //exponential "expo"
    h1->Fit("expo", "L");                                                       //Likelihood "L"
    h1->Draw();
    
    myc->cd(2);
    TH1F *h2 = new TH1F("h2","Gaussian",200,-20,20);                            //new histogram
    h2->FillRandom("gaus",10000);                                               //Gaussian "gaus"
    h2->Fit("gaus", "L");                                                       //Likelihood "L"
    h2->Draw();
    
    myc->cd(3);
    TH1F *h3 = new TH1F("h3","Landau",200,-20,20);                              //new histogram
    h3->FillRandom("landau",10000);                                             //Landau "landau"
    h3->Fit("landau", "L");                                                     //Likelihood "L"
    h3->Draw();
    
    myc->cd(4);
    TF1 *mygaus = new TF1("mygaus","TMath::Gaus(x, 0, 5)",-20,20);              //fitted TMath::Gauss
    TF1 *f2 = mygaus->DrawCopy();
    f2->SetLineColor(kBlue);
    
    //TH1F *h1 = new TH1F("h1","TMath::Gaus",200,-20,20);
    //TF1 *mygaus = new TF1("mygaus","TMath::Gaus(x, 0, 5)",-20,20);
    //h1->FillRandom("mygaus",10000);
    //h1->Fit("mygaus","L");
    //h1->Draw();
}

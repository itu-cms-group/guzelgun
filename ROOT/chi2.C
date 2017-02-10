#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TClonesArray.h"
#include "TBranch.h"

void chi2(){

    TCanvas *myc = new TCanvas("c1","Chi2 Fitting",10,10,1000,1000);   //setting up a new canvas
    myc->Divide(2,2);                                                       //dividing the canvas in two
    myc->cd(1);
    
    TH1F *h1 = new TH1F("h1","Exponential",200,-20,20);
    h1->FillRandom("expo",10000);
    h1->Fit("expo");                                                   //Without any options, it's chi2
    h1->Draw();                                                        //by default
    
    myc->cd(2);
    TH1F *h2 = new TH1F("h2","Gaussian",200,-20,20);
    h2->FillRandom("gaus",10000);
    h2->Fit("gaus");
    h2->Draw();
    
    myc->cd(3);
    TH1F *h3 = new TH1F("h3","Landau",200,-20,20);
    h3->FillRandom("landau",10000);
    h3->Fit("landau");
    h3->Draw();
    
    myc->cd(4);
    TF1 *mygaus = new TF1("mygaus","TMath::Gaus(x, 0, 5)",-20,20);
    TF1 *f2 = mygaus->DrawCopy();
    f2->SetLineColor(kBlue);
    
    //TH1F *h1 = new TH1F("h1","TMath::Gaus",200,-20,20);
    //TF1 *mygaus = new TF1("mygaus","TMath::Gaus(x, 0, 5)",-20,20);
    //h1->FillRandom("mygaus",10000);
    //h1->Fit("mygaus","L");
    //h1->Draw();

}



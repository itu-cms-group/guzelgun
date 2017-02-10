#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TClonesArray.h"
#include "TBranch.h"

void polfit() {

    TCanvas *myc = new TCanvas("polfit","gamma and lognormal",10,10,1000,1000);     //setting up a new canvas
    myc->Divide(2,2);                                                               //dividing the canvas in two
    myc->cd(1);
    
    
    TH1F *h1 = new TH1F("h1","Polynomial 1",100,-20,20);                        
    h1->FillRandom("expo",10000);
    h1->Fit("expo", "L");                                                       //Likelihood "L"
    h1->Draw();
    
    myc->cd(2);
    
    TH1F *h2 = new TH1F("h2","Polynomial 2",200,-20,20);
    h2->FillRandom("pol2",10000);
    h2->Fit("pol2", "L");                                                       //Likelihood "L"
    h2->Draw();


    myc->cd(3);
    
    TH1F *h3 = new TH1F("h3","Polynomial 3",200,-20,200);
    h3->FillRandom("pol3",10000);
    h3->Fit("pol3");                                                          //chi2
    h3->Draw();
    
    myc->cd(4);
    
    TH1F *h4 = new TH1F("h3","Polynomial 4",200,-20,200);
    h4->FillRandom("pol4",10000);
    h4->Fit("pol4");                                                          //chi2
    h4->Draw();
}
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TClonesArray.h"
#include "TBranch.h"

void GausComp() {

    
    TCanvas *myc = new TCanvas("c1","gamma and lognormal",10,10,600,800);   //setting up a new canvas
    myc->Divide(1,2);                                                       //dividing the canvas in two
    myc->cd(1);
    
    TH1F *h1 = new TH1F("h1","TMath::Gaus",200,-20,20);
    TF1 *mygaus = new TF1("mygaus","TMath::Gaus(x, 0, 5)",0,6);
    h1->FillRandom("mygaus",10000);
    h1->Draw();
    
    myc->cd(2);
    TH1F *h2 = new TH1F("h2","TH1F",200,-20,20);
    h2->FillRandom("gaus",10000);
    h2->Draw();

}
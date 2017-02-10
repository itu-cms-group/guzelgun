#include "TCanvas.h"
#include "TStyle.h"
#include "TH1.h"
#include "TGaxis.h"
#include "TRandom.h"
#include "TTree.h"
#include "TClonesArray.h"
#include "TBranch.h"

void jet2()

{
    TFile* f1 = new TFile("/home/cakir/Programs/Delphes-3.4.0/leptonProdout2.root");
    TFile* f2 = new TFile("/home/cakir/Programs/Delphes-3.4.0/leptonProdout1.root");
    TTree* Delphes1;
    TTree* Delphes2;
    f1->GetObject("Delphes",Delphes1);
    f2->GetObject("Delphes",Delphes2);

    
    
    gStyle->SetOptStat(kFalse);
    TCanvas* myc = new TCanvas("c2", "my histogram", 500,800);
    Delphes1->Draw("Jet.PT");
    myc->Update();
    Float_t rightmax = 1.1*Delphes2->GetMaximum();
    Float_t scale = gPad->GetUymax()/rightmax;
    Delphes2->SetLineColor(kRed);
    Delphes2->Scale(scale);
    Delphes2->Draw("Jet.PT");
}
~    

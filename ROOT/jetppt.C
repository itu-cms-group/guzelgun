{

    TFile* f = new TFile("/home/cakir/Programs/Delphes-3.4.0/leptonProdout2.root");
    TTree* Delphes;
    f->GetObject("Delphes",Delphes);

    TCanvas* c2 = new TCanvas("c2", "my histogram", 500,800);
    
    gStyle->SetOptSTat(kFALSE);
    TH1F *h1 = new TH1F("h1","my histogram",100,-3,3);
    Delphes->Draw("Jet.PT");

}

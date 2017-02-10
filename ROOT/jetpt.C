{
    TFile* f = new TFile("/home/cakir/Programs/Delphes-3.4.0/leptonProdout2.root");
    TTree* Delphes;
    f->GetObject("Delphes",Delphes);

    TCanvas* c2 = new TCanvas("c2", "my histogram", 500,800);
    c2->Divide(1,2);

    c2->cd(1);
    Delphes->Draw("Jet.PT");

}

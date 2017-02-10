void chig() {
    
    TCanvas *myc = new TCanvas("c1","gamma and lognormal",10,10,600,800);   //setting up a new canvas
    myc->Divide(1,2);                                                       //dividing the canvas in two
    TPad *pad1 = (TPad *)myc->cd(1);                                        //setting a pad on the first half
    pad1->SetLogy();                                                        //log scaling the y axis
    pad1->SetGrid();                                                        //sets up the grid
    
    TH1F *f1 = new TH1F("f1", "Gamma", 200,-20,20);
    TF1 *fgamma = new TF1("fgamma", "TMath::GammaDist(x, [0], [1], [2])", 0, 10);
    }

void lognormal() {
    
    TCanvas *myc = new TCanvas("c1","gamma and lognormal",10,10,600,800);   //setting up a new canvas
    myc->Divide(1,2);                                                       //dividing the canvas in two
    TPad *pad1 = (TPad *)myc->cd(1);                                        //setting a pad on the first half
    //pad1->SetLogy();                                                        //log scaling the y axis
    pad1->SetGrid();                                                        //sets up the grid
    
    //GammaDist:
    //GammaDist(x, mu = 0, beta = 1)
    //gamma: shape parameter
    //mu: location parameter
    //beta: scale parameter
    
    TF1 *fgamma = new TF1("fgamma", "TMath::GammaDist(x, [0], [1], [2])", 0, 10); //Gamma Dist
    fgamma->SetParameters(0.5, 0, 1);                                             //setting parameters
    TF1 *f1 = fgamma->DrawCopy();
    f1->SetMinimum(1e-5);                                                         //min axis value
    f1->SetLineColor(kRed);                                                       //line color
    
    fgamma->SetParameters(1, 0, 1);
    TF1 *f2 = fgamma->DrawCopy("same");
    f2->SetLineColor(kGreen);
    
    fgamma->SetParameters(2, 0, 1);
    TF1 *f3 = fgamma->DrawCopy("same");
    f3->SetLineColor(kBlue);
    
    fgamma->SetParameters(5, 0, 1);
    TF1 *f4 = fgamma->DrawCopy("same");
    f4->SetLineColor(kMagenta);
    
    TLegend *legend1 = new TLegend(.55,.1,.9,.9);                               //Adding Legends
    legend1->AddEntry(f1,"gamma = 0.5 mu = 0  beta = 1","l");
    legend1->AddEntry(f2,"gamma = 1   mu = 0  beta = 1","l");
    legend1->AddEntry(f3,"gamma = 2   mu = 0  beta = 1","l");
    legend1->AddEntry(f4,"gamma = 5   mu = 0  beta = 1","l");
    legend1->Draw();
    
    //TMath::LogNormal
    
    TPad *pad2 = (TPad *)myc->cd(2);                                            //new pad, cd
    pad2->SetLogy();                                                            //log scaling y-axis
    pad2->SetLogx();                                                            //log scaling x-axis
    pad2->SetGrid();
    
    TF1 *flog = new TF1("flog", "TMath::LogNormal(x, [0], [1], [2])", 0, 10);   //LogNormal
    
    flog->SetParameters(0.5, 0, 1);                                             //parameters
    TF1 *g1 = flog->DrawCopy();
    g1->SetLineColor(kRed);
    
    flog->SetParameters(1, 0, 1);
    TF1 *g2 = flog->DrawCopy("same");
    g2->SetLineColor(kGreen);
    
    flog->SetParameters(2, 0, 1);
    TF1 *g3 = flog->DrawCopy("same");
    g3->SetLineColor(kBlue);
    
    flog->SetParameters(5, 0, 1);
    TF1 *g4 = flog->DrawCopy("same");
    g4->SetLineColor(kMagenta);
    
    TLegend *legend2 = new TLegend(0.9,0.3,0.55,0.1);                           //line Color
    legend2->AddEntry(g1, "sigma = 0.5  theta = 0   m = 1", "l");
    legend2->AddEntry(g2, "sigma = 1    theta = 0   m = 1", "l");
    legend2->AddEntry(g3, "sigma = 2    theta = 0   m = 1", "l");
    legend2->AddEntry(g4, "sigma = 5    theta = 0   m = 1", "l");
    legend2->Draw();
}

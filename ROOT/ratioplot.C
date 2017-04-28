// Example displaying two histograms and their ratio.
// Author: Olivier Couet
void ratioplot() {
   // Define two gaussian histograms. Note the X and Y title are defined
   // at booking time using the convention "Hist_title ; X_title ; Y_title"
   
    TH1F* Signal1,Signal1a;
    TFile *bkg1 = TFile::Open("denemElectron.root");
    Signal1= (TH1F*) bkg1->Get("JetPT3");
    Signal1->SetLineColor(kRed);
    
    TH1F* Signal2;
    TFile *bkg2 = TFile::Open("denemElectron.root");
    Signal2= (TH1F*) bkg2->Get("JetPT1");
    Signal2->SetLineColor(kBlue);
    
    Double_t norm1 = Signal1->GetEntries();
    Signal1->Scale(1/norm1);
    
    Double_t norm2 = Signal2->GetEntries();
    Signal2->Scale(1/norm2);
    
    
   

   // Define the Canvas
   TCanvas *c = new TCanvas("c", "canvas", 800, 800);

   // Upper plot will be in pad1
   TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
   pad1->SetBottomMargin(0); // Upper and lower plot are joined
   pad1->SetGridx();         // Vertical grid
   pad1->Draw();             // Draw the upper pad: pad1
   pad1->cd();               // pad1 becomes the current pad
   Signal1->SetStats(0);          // No statistics on upper plot
   Signal1->Draw();               // Draw signal1
   Signal2->Draw("same");         // Draw signal2 on top of signal1

   // Do not draw the Y axis label on the upper plot and redraw a small
   // axis instead, in order to avoid the first label (0) to be clipped.
   Signal1->GetYaxis()->SetLabelSize(0.);
   TGaxis *axis = new TGaxis( -5, 20, -5, 220, 20,220,510,"");
   axis->SetLabelFont(43); // Absolute font size in pixel (precision 3)
   axis->SetLabelSize(15);
   axis->Draw();

   // lower plot will be in pad
   c->cd();          // Go back to the main canvas before defining pad2
   TPad *pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.3);
   pad2->SetTopMargin(0);
   pad2->SetBottomMargin(0.2);
   pad2->SetGridx(); // vertical grid
   pad2->Draw();
   pad2->cd();       // pad2 becomes the current pad

   // Define the ratio plot
   TH1F *h3 = (TH1F*)Signal1->Clone("h3");
   h3->SetLineColor(kBlack);
   h3->SetMinimum(0.8);  // Define Y ..
   h3->SetMaximum(1.35); // .. range
   h3->Sumw2();
   h3->SetStats(0);      // No statistics on lower plot
   h3->Divide(Signal2);
   h3->SetMarkerStyle(21);
   h3->Draw("ep");       // Draw the ratio plot

   // signal1 settings
   Signal1->SetLineColor(kBlue+1);
   Signal1->SetLineWidth(2);

   // Y axis signal1 plot settings
   Signal1->GetYaxis()->SetTitleSize(20);
   Signal1->GetYaxis()->SetTitleFont(43);
   Signal1->GetYaxis()->SetTitleOffset(1.55);

   // signal2 settings
   Signal2->SetLineColor(kRed);
   Signal2->SetLineWidth(2);

   // Ratio plot (h3) settings
   h3->SetTitle(""); // Remove the ratio title

   // Y axis ratio plot settings
   h3->GetYaxis()->SetTitle("ratio signal1/signal2 ");
   h3->GetYaxis()->SetNdivisions(505);
   h3->GetYaxis()->SetTitleSize(20);
   h3->GetYaxis()->SetTitleFont(43);
   h3->GetYaxis()->SetTitleOffset(1.55);
   h3->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
   h3->GetYaxis()->SetLabelSize(15);

   // X axis ratio plot settings
   h3->GetXaxis()->SetTitleSize(20);
   h3->GetXaxis()->SetTitleFont(43);
   h3->GetXaxis()->SetTitleOffset(4.);
   h3->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
   h3->GetXaxis()->SetLabelSize(15);

}

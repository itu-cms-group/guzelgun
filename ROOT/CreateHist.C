#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TClonesArray.h"
#include "TBranch.h"
#include "TGaxis.h"

void CreateHist()
{
  gROOT->Reset();
  gSystem->Load("/Users/ceren/programs/Delphes-3.3.0/libDelphes");
  gSystem->Load("/usr/local/Cellar/root/5.34.36_2/lib/root/libHist.so");

 TFile *f1=new TFile("PY_VV_DecaysOff_10K.root");
 TTree *Jet1=f1->Get("Delphes");

 TFile *f3 = new TFile("HW_VV_10K.root");
 TTree *Jet3 = f3->Get("Delphes");
    
 TFile *f4 = new TFile("denemEta.root","recreate");

    
 //TFile *f2 =  new TFile("PY_TTbar_10K.root");
 //TTree *Jet2 = f2->Get("Delphes");

ExRootTreeReader *treeReader = new ExRootTreeReader(Jet1);
 TClonesArray *branchJet= treeReader->UseBranch("Jet");

//ExRootTreeReader *treeReader2 = new ExRootTreeReader(Jet2);
 //TClonesArray *branchJet2 = treeReader2->UseBranch("Jet");

 ExRootTreeReader *treeReader3 = new ExRootTreeReader(Jet3);
 TClonesArray *branchJet3 = treeReader3->UseBranch("Jet");

TH1F *Signal1 = new TH1F("JetPT1","JetP_{T}",100,0.0,700);
//TH1F *Signal2 = new TH1F("JetPT2","JetP_{T}",100,0.0,700);
TH1F *Signal3 = new TH1F("JetPT3","JetP_{T}",100,0.0,700);

Int_t nevent = Jet1->GetEntries();
//Int_t nevent2 = Jet2->GetEntries();
Int_t nevent3 = Jet3->GetEntries();


  for(Int_t i=0; i<nevent; i++)
        {
        //Jet1->treeReader(i);
        treeReader->ReadEntry(i);
  for(Int_t a=0;a<branchJet->GetEntries();++a)
                        {
                                Jet *jet=(Jet*)branchJet->At(0);
                                if(jet->PT>0.0 )
                          {
                                 Signal1->Fill(jet->PT);
                                TBranch *branch=Jet1->Branch("Jets","TH1F",&Signal1);
                                Signal1->SetLineColor(2);
                              //   histJetpt->Draw("");
                          }
                       }
         }
/*for(Int_t k=0; k<nevent2; k++)
        {
        treeReader2->ReadEntry(k);
                for(Int_t b=0; b<branchJet2->GetEntries(); b++)
                        {
                        Jet *jet = (Jet*)branchJet2->At(0);
                                if(jet->PT>0.0)
                                        {
                                        Signal2->Fill(jet->PT);
                                        TBranch *branch = Jet2->Branch("Jets","TH1F",&Signal2);
Signal2->SetLineColor(4);
//hJetpt2->Draw("same");
}
}
}
*/
    
for(Int_t m=0; m<nevent3; m++)
        {
        treeReader3->ReadEntry(m);
                for(Int_t d=0; d<branchJet3->GetEntries(); d++)
                        {
                        Jet *jet = (Jet*)branchJet3->At(0);
                                if(jet->PT>0.0)
                                        {
                                        Signal3->Fill(jet->PT);
                                        TBranch *branch = Jet3->Branch("Jets","TH1F",&Signal3);
Signal3->SetLineColor(6);
//hJetpt3->Draw("same");
}
}
}
TCanvas* c1 = new TCanvas("c1","Jet.Ratio",65,52,489,590) ;

    TLegend *pl = new TLegend(0.55, 0.7, 0.9, 0.87); 
    pl->SetTextSize(0.04); 
    pl->SetFillColor(0);
    pl->SetBorderSize(0);


    TLegend *pl2 = new TLegend(0.59499, 0.648148, 0.784969, 0.845679); 
    pl2->SetTextSize(0.1); 
    pl2->SetFillColor(0);
    pl2->SetBorderSize(0);

    TLine *l=new TLine(50.0,1.0,2100.0,1.0);
    l->SetLineColor(kBlue);
    l->SetLineStyle(7);
    
      TPad *pad1 = new TPad("pad1","pad1",0,0.3,1,1);
        pad1->SetLogy();
        pad1->SetBottomMargin(0.005);
        pad1->Draw();
        pad1->cd();
       
//   Double_t norm1 = Signal1->GetEntries();
//   Signal1->Scale(1/norm1);
//   Double_t norm2 = Signal2->GetEntries();
//   Signal2->Scale(1/norm2);
//   Double_t norm3 = Signal3->GetEntries();
//   Signal3->Scale(1/norm3);

   //Signal1->Draw();               // Draw h1
  // Signal2->Draw("same");         // Draw h2 on top of h1
   //Signal3->Draw("same");
   Signal1->GetXaxis()->SetRangeUser(0,700);
   //pl->Draw("same");
   c1->cd();

   gStyle->SetOptStat(0);
   pl->AddEntry(Signal1,"Sherpa+MELO");
  // pl->AddEntry(Signal2,"Pythia8");
   pl->AddEntry(Signal3,"Herwig");
  // pl2->AddEntry(Signal2,"Sherpa/MadGraph");
   pl2->AddEntry(Signal3,"aMCNLO+PY8/MadGraph");
   pl->SetLineColor(0.5);

    f4->Write();
//c1->update();

/*        TPad *pad2 = new TPad("pad2","pad2",0,0.05,1,0.3);
	pad2->SetTopMargin(0.05);
	pad2->SetBottomMargin(0.2);
	pad2->SetGridx();
	pad2->Draw();
	pad2->cd();

	 TH1F *Signal1_Clone =(TH1F*)Signal1->Clone("Signal1_Clone");
	 //TH1F *Signal2_Clone =(TH1F*)Signal2->Clone("Signal2_Clone");
	 TH1F *Signal3_Clone =(TH1F*)Signal3->Clone("Signal3_Clone");
       
        Double_t  Signal1_Error=0;
	Double_t  Signal2_Error=0;
	Double_t  Signal3_Error=0;
	Double_t  Signal1_Content=0;
	Double_t  Signal2_Content=0;
	Double_t  Signal3_Content=0;
	Double_t  A=0;
	Double_t  B=0;
	Double_t  error_prop3=0;
	Double_t  error_prop2=0;
	Double_t  error_propA=0;
	Double_t  error_prop1=0;
	Double_t  error_propB=0;

	//c1->Update();//update işlemi zorunlu

	 
  for (Int_t i=1; i< Signal1_Clone->GetNbinsX(); i++)
	{
  	  Signal1_Content=Signal1_Clone->GetBinContent(i);
  	  Signal2_Content=Signal2_Clone->GetBinContent(i);
  	  Signal3_Content=Signal3_Clone->GetBinContent(i);

  	  A=Signal3_Content/Signal2_Content;
  	  B=Signal1_Content/Signal2_Content;

  	  Signal1_Error=Signal1_Clone->GetBinError(i);
  	  Signal2_Error=Signal2_Clone->GetBinError(i);
  	  Signal3_Error=Signal3_Clone->GetBinError(i);

  	  error_prop3= (Signal3_Error/Signal3_Content)*(Signal3_Error/Signal3_Content);
  	  error_prop2= (Signal2_Error/Signal2_Content)*(Signal2_Error/Signal2_Content);
  	  error_prop1= (Signal1_Error/Signal1_Content)*(Signal1_Error/Signal1_Content);
  	  error_propA=sqrt((error_prop3+error_prop2)*A*A);
  	  error_propB=sqrt((error_prop1+error_prop2)*B*B);
    //Zaten asagıda bolucem o yuzden burada bincontent ayarlamaya gerek yok 
  	//  Signal3_Clone->SetBinContent(i,A);
  	  Signal1_Clone->SetBinError(i,error_propB);
  	//  Signal1_Clone->SetBinContent(i,B);
  	  Signal3_Clone->SetBinError(i,error_propA);
}

         Signal1_Clone->SetLineWidth(2);
	 Signal3_Clone->SetLineWidth(2);
         Signal1_Clone->SetFillColorAlpha(46,0.30);
         Signal3_Clone->SetFillColor(kGreen);
         Signal3_Clone->SetFillStyle(3001);

	
	Signal1_Clone->Divide(Signal2_Clone);
	Signal3_Clone->Divide(Signal2_Clone);

	Signal1_Clone->Draw();
	Signal3_Clone->Draw("same");
     //   Signal1_Clone->Draw("same");
//	Signal3_Clone->Draw("same");
	l->Draw();  

         Signal1_Clone->GetYaxis()->SetRangeUser(0,2);
	 Signal1_Clone->SetTitle("");
	 Signal1_Clone->GetYaxis()->SetLabelSize(0.08);
	 Signal1_Clone->GetXaxis()->SetLabelSize(0.08);
	 Signal1_Clone->GetYaxis()->SetTitle("Ratio Plot for");
	 Signal1_Clone->GetYaxis()->CenterTitle();
	 Signal1_Clone->GetXaxis()->SetTitle(" [GeV]");
         Signal1_Clone->GetYaxis()->SetTitleOffset(0.4);
         Signal1_Clone->GetXaxis()->SetTitleSize(0.1);
	 Signal1_Clone->GetYaxis()->SetTitleSize(0.1);

	pl2->Draw("same");
*/

}	


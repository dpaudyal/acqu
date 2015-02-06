{
TChain *h2 = new TChain("treeTagger") ;
h2-> Add("/home/dpaudyal/GoATTrees/GoAT_CBTaggTAPS_3775.root") ;

TChain *h1 = new TChain("treeParticles") ;
h1-> Add("/home/dpaudyal/GoATTrees/GoAT_CBTaggTAPS_3775.root") ;

//TFile *f=new TFile("/home/a2compton/result/Raw_Run_Compton_May13_1580_FirstTest.root");
// TFile *f=new TFile("/home/a2compton/result/RootTreeMC_A2G4_Compton_Generated_80_150.root");

 //TTree *tree = (TTree *)f->Get("treeRawEvent");
 //tree->SetName("tree");

 //TTree *tree = (TTree *)f->Get("treeTagger");
 //tree->SetName("tree");

Double_t test1, Pt_bm, En_bm, En_l0101,  En_l0101_unit, Px_l0101,  Py_l0101, Pz_l0101, Theta, Phi;
Double_t En_l0201,  En_l0201_unit, Px_l0201,  Py_l0201, Pz_l0201 ;
Double_t photonbeam_E;

// tree-> SetBranchAddress("Theta", &Theta) ;
// tree-> SetBranchStatus("Theta", 1) ;
Int_t nTagged, tagged_ch, nParticles, clusterSize, Apparatus;
// 
//  tree-> SetBranchAddress("nTagged", &nTagged) ;
//  tree-> SetBranchStatus("nTagged", 1) ;

//tree-> SetBranchAddress("nParticles", &nParticles) ;
//tree-> SetBranchStatus("nParticles", 1) ;

h1-> SetBranchAddress("nParticles", &nParticles) ;
h1-> SetBranchStatus("nParticles", 1) ;

h1-> SetBranchAddress("Theta", &Theta) ;
h1-> SetBranchStatus("Theta", 1) ;

h1-> SetBranchAddress("Phi", &Phi) ;
h1-> SetBranchStatus("Phi", 1) ;

h1-> SetBranchAddress("clusterSize", &clusterSize) ;
h1-> SetBranchStatus("clusterSize", 1) ;

h1-> SetBranchAddress("Apparatus", &Apparatus) ;
h1-> SetBranchStatus("Apparatus", 1) ;

h2-> SetBranchAddress("photonbeam_E", &photonbeam_E) ;
h2-> SetBranchStatus("photonbeam_E", 1) ;
// tree-> SetBranchAddress("tagged_ch", &tagged_ch) ;
// tree-> SetBranchStatus("tagged_ch", 1) ;

int nentries = h1->GetEntries();
//int nentries = tree->GetEntries();
// nentries = 50000 ;
cout << "nentries = "<< nentries << endl;
// TH1D *h_Theta = new TH1D("h_Theta", "h_Theta", 180, 0., 180.);

TH1D * h_Theta= new TH1D("h_Theta", "h_Theta", 180, 0., 180.);
TH1D * h_Phi= new TH1D("h_Phi", "h_Phi", 360, -180., 180.);

TH1D * h_nTagged= new TH1D("h_nTagged", "h_nTagged", 180, 0., 180.);
TH1D * h_tagged_ch= new TH1D("h_tagged_ch", "h_tagged_ch", 500, 0., 500.);
TH1D * h_nParticles= new TH1D("h_nParticles", "h_nParticles", 30, 0, 30);
TH1D * h_clusterSize= new TH1D("h_clusterSize", "h_clusterSize", 30, 0., 30.);
TH1D * h_photonbeam_E= new TH1D("h_photonbeam_E", "h_photonbeam_E", 200, 0., 200.);

TH2D * h_ThetaPhi= new TH2D("h_ThetaPhi", "h_ThetaPhi", 180, 0., 180., 360, -180., 180.);

TH2D * h_E_Theta= new TH2D("h_E_Theta", "h_E_Theta", 200, 0., 180., 180, 0., 180.);


for (Int_t  i = 0; i < nentries; i ++)
//for (Int_t  i = 0; i < 55157; i ++)
{
if(i%10000 == 0)
cout << i << endl ;

h1->GetEntry(i) ;
h2->GetEntry(i) ;
 
 h_E_Theta ->Fill(photonbeam_E, Theta);
 
  h_photonbeam_E->Fill(photonbeam_E);
  h_Theta->Fill(Theta);

} 
h_E_Theta->Draw("colz");
//h_photonbeam_E->Draw();
}

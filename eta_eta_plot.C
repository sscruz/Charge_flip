{
  TFile* _file0 = TFile::Open("/nfs/fanae/user/sscruz/MPAF/workdir/root/phys14exerc/templateSSDL_phys14.root");
  TDirectoryFile* Bad_El = 0;
  TDirectoryFile* Good_El = 0;

  TH2F* hBadEl = 0;
  TH2F* hGoodEl = 0;
  TH2F* tmp = 0;

  _file0 -> GetObject("SS_EtaEta",Bad_El);
  _file0 -> GetObject("OS_EtaEta",Good_El);

  // merging samples
  Bad_El -> GetObject("DYJetsToLL_M50",hBadEl);
  Bad_El -> GetObject("DYJetsToLL_M50_HT100to200",tmp);
  hBadEl -> Add(tmp);
  Bad_El -> GetObject("DYJetsToLL_M50_HT200to400",tmp);
  hBadEl -> Add(tmp);
  Bad_El -> GetObject("DYJetsToLL_M50_HT400to600",tmp);
  hBadEl -> Add(tmp);
  Bad_El -> GetObject("DYJetsToLL_M50_HT600toInf",tmp);
  hBadEl -> Add(tmp);

  Good_El-> GetObject("DYJetsToLL_M50",hGoodEl);
  Good_El -> GetObject("DYJetsToLL_M50_HT100to200",tmp);
  hGoodEl -> Add(tmp);
  Good_El -> GetObject("DYJetsToLL_M50_HT200to400",tmp);
  hGoodEl -> Add(tmp);
  Good_El -> GetObject("DYJetsToLL_M50_HT400to600",tmp);
  hGoodEl -> Add(tmp);
  Good_El -> GetObject("DYJetsToLL_M50_HT600toInf",tmp);
  hGoodEl -> Add(tmp);


  hBadEl->Divide(hGoodEl); // ss events over os events
  // hBadEl->Draw("colz text e");

  int n = 2;

  // print vector independiente
  for (int i = 0; i<n; i++){
    for (int j = 0; j<n; j++){
      for (int k = 0; k<i;k++){
	cout << 0 << "\t";
      }
      cout << 1 << "\t";
      for (int k = i+1; k<n;k++){
	cout << 0 << "\t";
      }

      for (int k = 0; k<j;k++){
	cout << 0 << "\t";
      }
      cout << 1 << "\t";
      for (int k = j+1; k<n;k++){
	cout << 0 << "\t";
      }
      cout << endl;
    }
  }
  
  // print vector independiente
  for (int i = 0; i<n; i++){
    for (int j = 0; j<n; j++){
      Int_t bin = hBadEl->GetBin(i+1,j+1);
      cout << hBadEl->GetBinContent(bin) << endl;
    }
  }


}

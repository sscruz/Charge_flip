{
  TFile* _file0 = TFile::Open("/nfs/fanae/user/sscruz/MPAF/workdir/root/phys14exerc/templateSSDL_phys14.root");
  TDirectoryFile* Bad_El = 0;
  TDirectoryFile* Good_El = 0;

  TH1F* hBadEl = 0;
  TH1F* hGoodEl = 0;
  TH1F* tmp = 0;

  _file0 -> GetObject("BadEl_Eta",Bad_El);
  _file0 -> GetObject("GoodEl_Eta",Good_El);
  
  // merging samples
  Bad_El -> GetObject("DYJetsToLL_M50",hBadEl);
  cout << hBadEl << endl;
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


    hBadEl->Divide(hGoodEl);
    //hGoodEl->Draw();
  hBadEl->Draw("colz text e");

}

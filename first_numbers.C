{
  TFile* _file0 = TFile::Open("/nfs/fanae/user/sscruz/MPAF/workdir/root/phys14exerc/templateSSDL_phys14.root");
  TDirectoryFile* Bad_El = 0;
  TDirectoryFile* Good_El = 0;
  TDirectoryFile* Bad_El_Gen = 0;
  TDirectoryFile* Good_El_Gen = 0;

  TH2F* hBadEl = 0;
  TH2F* hGoodEl = 0;
  TH2F* hBadEl_Gen = 0;
  TH2F* hGoodEl_Gen = 0;
  TH2F* tmp = 0;

  _file0 -> GetObject("BadEl_Eta",Bad_El_Gen);
  _file0 -> GetObject("GoodEl_Eta",Good_El_Gen);

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


  hGoodEl_Gen->Add(hBadEl_Gen);
  hBadEl_Gen->Divide(hGoodEl_Gen);

  float prob[2];
  prob[0] = hBadEl_Gen->GetBinContent(1);
  prob[1] = hBadEl_Gen->GetBinContent(2);
  cout << "Generation info" << endl;
  cout << "Barrel-barrel\t" << 2*prob[0]*(1-prob[0]) <<"\t +/- \t" << 2*hBadEl_Gen->GetBinError(1) <<  endl; 
  cout << "Barrel-endcap\t" << prob[1]*(1-prob[0])+  prob[0]*(1-prob[1]) <<"\t +/- \t" << hBadEl_Gen->GetBinError(1) + hBadEl_Gen->GetBinError(2) << endl; 
  cout << "Endcap-endcap\t" << 2*prob[1]*(1-prob[1]) <<"\t +/- \t" << 2*hBadEl_Gen->GetBinError(2) <<  endl;


  _file0 -> GetObject("SS_EtaEta",Bad_El);
  _file0 -> GetObject("OS_EtaEta",Good_El);
  hBadEl = (TH2F*) Bad_El -> Get("DYJetsToLL_M50");
  hGoodEl= (TH2F*) Good_El-> Get("DYJetsToLL_M50");


  cout << "Z peak info" << endl;
  float good[2][2];
  good[0][0] = hGoodEl->GetBinContent(hGoodEl->GetBin(1,1));
  good[0][1] = hGoodEl->GetBinContent(hGoodEl->GetBin(1,2));
  good[1][0] = hGoodEl->GetBinContent(hGoodEl->GetBin(2,1));
  good[1][1] = hGoodEl->GetBinContent(hGoodEl->GetBin(2,2));

  float bad[2][2];
  bad[0][0] = hBadEl->GetBinContent(hBadEl->GetBin(1,1));
  bad[0][1] = hBadEl->GetBinContent(hBadEl->GetBin(1,2));
  bad[1][0] = hBadEl->GetBinContent(hBadEl->GetBin(2,1));
  bad[1][1] = hBadEl->GetBinContent(hBadEl->GetBin(2,2));


  cout << "Barrel-barrel\t" << bad[0][0]/(good[0][0]+bad[0][0])   <<"\t +/- \t" << hBadEl->GetBinError(hBadEl->GetBin(1,1))/good[0][0] <<  endl; 
  cout << "Barrel-endcap\t" << (bad[1][0]+bad[0][1])/(bad[1][0]+bad[0][1]+good[0][1]+good[1][0]) <<"\t +/- \t" << (hBadEl->GetBinError(hBadEl->GetBin(1,2))+hBadEl->GetBinError(hBadEl->GetBin(2,1)))/(good[1][0]+good[0][1]) << endl;
  cout << "Endcap-endcap\t" << bad[1][1]/(bad[1][1]+good[1][1]) << "\t +/- \t" << hBadEl->GetBinError(hBadEl->GetBin(2,2))/good[1][1] <<  endl; 
}

void fit(double h1,double mu1,double sigma1,double h2,double mu2, double sigma2){
gStyle->SetOptFit();
TF1* func1 = new TF1("func","[0]*exp(-0.5*pow((x-[1])/[2],2.0))+[3]*exp(-0.5*pow((x-[4])/[5],2.0))+[6]*x+[7]",600.0, 1500.0);
//関数の定義、ガウス関数２つの合成+線形関数,関数の範囲
func1->SetParameters(h1, mu1, sigma1, h2, mu2,  sigma2,1,200);
func1->SetParNames("h1","mu1","sigma1","h2","mu2","sigma2","a","b");
//初期パラの設定
hadc0->Fit("func","","", 600.0, 1500.0); // Fitting
//hadc0のfitting 
}

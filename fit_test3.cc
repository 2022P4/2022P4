void fit_test3(){

int mode;
do {
    printf("設定【Single_Gaus:1/Double_gaus:2】]");
    printf("モード:"); scanf("%d",&mode);
} while (mode < 0 || mode > 2);



TF1* func1 ;
double h1 = 1000;
double mu1 = 1000;
double sigma1 = 100;
double h2 = 1000;
double mu2 = 1000;
double sigma2 = 100;

double min = 1000;
double max = 4000;

//char* mina;

switch (mode)
{
case 0:
    gStyle->SetOptFit();
    func1 = new TF1("func","[0]*exp(-0.5*pow((x-[1])/[2],2.0))+[3]*x+[4]",600.0, 1500.0);
    //関数の定義、ガウス関数2つの合成+線形関数,関数の範囲
    func1->SetParameters(1000,1000, 100,1.0,200);
    func1->SetParNames("h1","mu1","sigma1","a","b");
    //初期パラの設定
    hadc0->Fit("func","","", 600.0, 1500.0); // Fitting
    //hadc0のfitting 
    break;
case 1:
    
    printf("初期値の入力\n");
    printf("h1:"); scanf("%lf",&h1);
    printf("mu1:"); scanf("%lf",&mu1);
    printf("sigma1:"); scanf("%lf",&sigma1);
    /*範囲の設定*/
    printf("min:"); scanf("%lf",&min);
    printf("max:"); scanf("%lf",&max);
    //printf("線源:"); scanf("%s",mina);

    gStyle->SetOptFit();
    func1 = new TF1("func","[0]*exp(-0.5*pow((x-[1])/[2],2.0))+[3]*x+[4]",min, max);
    //関数の定義、ガウス関数2つの合成+線形関数,関数の範囲
    func1->SetParameters(h1,mu1, sigma1,1.0,200);
    func1->SetParNames("h1","mu1","sigma1","a","b");
    //初期パラの設定
    hadc0->Fit("func","","", min, max); // Fitting
    //hadc0のfitting 
break;

case 2:
    printf("初期値の入力\n");
    printf("h1:"); scanf("%lf",&h1);
    printf("mu1:"); scanf("%lf",&mu1);
    printf("sigma1:"); scanf("%lf",&sigma1);
    printf("h2:"); scanf("%lf",&h2);
    printf("mu2:"); scanf("%lf",&mu2);
    printf("sigma2:"); scanf("%lf",&sigma2);
    /*範囲の設定*/
    printf("min:"); scanf("%lf",&min);
    printf("max:"); scanf("%lf",&max);

    gStyle->SetOptFit();
    func1 = new TF1("func","[0]*exp(-0.5*pow((x-[1])/[2],2.0))+[3]*exp(-0.5*pow((x-[4])/[5],2.0))+[6]*x+[7]",min, max);
    //関数の定義、ガウス関数2つの合成+線形関数,関数の範囲
    func1->SetParameters(h1,mu1, sigma1,h2,mu2,sigma2,1.0,200);
    func1->SetParNames("h1","mu1","sigma1","h2","mu2","sigma2","a","b");
    //初期パラの設定
    hadc0->Fit("func","","", min, max); // Fitting
    //hadc0のfitting 
break;
default:
    printf("入力ミス\n");
break;
}



}

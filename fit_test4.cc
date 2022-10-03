void fit_test4(
    /*double h1,double mu1,double sigma1,double h2,double mu2,double sigma2,double min,double max*/
){
double min1;
double max1;
printf("1つ目のGausのfitting:\n");
printf("範囲の最小:"); scanf("%lf",&min1);
printf("範囲の最大:"); scanf("%lf",&max1);
TF1* g1 = new TF1("g1","gaus");
hadc0->Fit("g1","","",min1,max1);
double h1 =     g1->GetParameter(0);
double mean1 =  g1->GetParameter(1);
double sigma1 = g1->GetParameter(2);
g1->Draw();

double min2;
double max2;
printf("2つ目のGausのfitting:\n");
printf("範囲の最小:"); scanf("%lf",&min2);
printf("範囲の最大:"); scanf("%lf",&max2);
TF1* g2 = new TF1("g2","gaus");
hadc0->Fit("g2","","",min2,max2);
double h2 =     g2->GetParameter(0);
double mean2 =  g2->GetParameter(1);
double sigma2 = g2->GetParameter(2);


printf("h1:%f\n",h1);
printf("mean1:%f\n",mean1);
printf("sigma1:%f\n",sigma1);

printf("h2:%f\n",h2);
printf("mean2:%f\n",mean2);
printf("sigma2:%f\n",sigma2);



TF1* model;
gStyle->SetOptFit();
model = new TF1("func","[0]*exp(-0.5*pow((x-[1])/[2],2.0))+[3]*exp(-0.5*pow((x-[4])/[5],2.0))+[6]*x+[7]",min1, max2);
//関数の定義、ガウス関数2つの合成+線形関数,関数の範囲
model->SetParameters(h1,mean1, sigma1,h2,mean2,sigma2,1.0,200);
model->SetParNames("h1","mean1","sigma1","h2","mean2","sigma2","a","b");
//初期パラの設定
hadc0->Fit("func","","", min1, max2); // Fitting
//hadc0のfitting 



}

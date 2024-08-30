#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>


#include "log_duration.h"
#include "slide_average.h"

using namespace std;

int main()
{
ofstream out("out.csv");

    out<<"period"<<','<<"double"<<','<<"float"<<endl;
    for(int i = 4; i<129; i *= 2){
        out<<i<<',';
        cout<<"Period = "<<i<<endl;
        cout<<"double"<<endl;
        SlideAverage<double> slide_aver_dou(i);
        cout<<globaltime<<endl;
        out<<globaltime<<',';
        cout<<"float"<<endl;
        SlideAverage<float> slide_aver_fl(i);
        out<<globaltime<<','<<endl;
    }

    return 0;
}



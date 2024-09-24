#include<iostream>

using namespace std;

int main(){
    int d,n,g;
    for (d = 1; d < 100; d++) 
        for (n = 1; n < 100; n++) 
            for (g = 1; g < 100; g++) 
                if (((d+n+g)==100)&&((15*d+9*n+g)==300)) {
                    cout<<"Trau dung la:"<<d<<endl;
                    cout<<"Trau nam la:"<<n<<endl;
                    cout<<"Trau gia la:"<<g<<endl;
                }
            
        
    
    return 0;
}





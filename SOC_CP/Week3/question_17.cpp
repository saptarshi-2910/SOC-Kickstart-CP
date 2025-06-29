#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main(){
    string x,y;
    cin>>x>>y;

    long long num1=stoll(x,nullptr,2);
    long long num2=stoll(y,nullptr,2);

    cout<<num1*num2<<endl;

    return 0;
}

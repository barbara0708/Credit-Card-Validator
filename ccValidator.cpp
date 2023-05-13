#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

bool check(string number){
    int arr[number.length()];
    int sum=0;
    for(int i=0;i<number.length();i++){
        int curr=number[i]-'0';
        arr[i]=curr;
    }
    int h=0;
    for(int i=number.length()-1;i>=0;i--){
        if(h==1){
            arr[i]*=2;
            if(arr[i]>9){
                arr[i]=(arr[i]%10)+(arr[i]/10);
            } 
            h=0;
        }else{
            h=1;
        }
    }
    for(int elem:arr){
        sum+=elem;
    }
    if(sum%10==0){
        return true;
    }
    return false;
}

int main(){
    cout<<"Welcome to Credit Card Validator. This program uses the Luhn Algotihm to validate a CC number."<<endl;
    cout<<"You can enter \"exit\" anytime to terminate."<<endl;

    while (true)
    {
        string number;
        cin>>number;
        for_each(
            number.begin(),
            number.end(),
            [](char & c) {
                c = ::tolower(c);
        });
        if(number=="exit"){
            break;
        }
        if(check(number)){
            cout<<"This is a valid CC Number"<<endl;
        }else{
            cout<<"This CC Number is not valid"<<endl;
        }
        
    }
    
}
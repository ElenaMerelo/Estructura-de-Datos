#include<iostream>
#include<stack.h>

using namespace std;

int main(){
    stack<int> s;

    for(int i=0; i<10; i++){
        s.push(i);
    }
    
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
}
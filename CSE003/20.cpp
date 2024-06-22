#include <iostream>
#include <vector>
using namespace std;

class Stairs{
    public:
    

    int climb(int n){
        vector<int> ways;
        if(n==0||n==1){
            return 1;
        }
        ways.push_back(n);
        cout << ways<<endl;
        return climb(n-1)+climb(n-2);
    }
};

int main(){
    Stairs s;
    cout<<s.climb(4);
}
#include <iostream>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

int N,number;
int level=1;
int solution(int, int);

int main(){
    int x,y;
    cin>>x>>y;
    solution(x,y);
}

int solution(int input_N, int intput_number) {
    int answer = 0;
    vector<set<int>> dp_array(8);
    set<int>::iterator iter1,iter2;
    N=input_N;
    number=intput_number;
    for(int i=0;i<8;i++){
        int temp=0;
        for(int j=0;j<i+1;j++)temp+=N*pow(10,j);
        dp_array[i].insert(temp);
    }
    for(int i=1;i<8;i++){
        for(int j=0;j<i;j++){
            for(iter1=dp_array[j].begin();iter1!=dp_array[j].end();iter1++){
                for(iter2=dp_array[i-j-1].begin();iter2!=dp_array[i-j-1].end();iter2++){
                    dp_array[i].insert((*iter1)+(*iter2));
                    dp_array[i].insert((*iter1)-(*iter2));
                    dp_array[i].insert((*iter1)*(*iter2));
                    if((*iter2)) dp_array[i].insert((*iter1)/(*iter2));
                }
            }
        }
        if(dp_array[i].find(number)!=dp_array[i].end()) {
            answer=i+1;
            break;
        }
    }
    if(answer==0) answer=-1;
    //cin>>answer;
    //for(iter1=dp_array[answer].begin();iter1!=dp_array[answer].end();iter1++) cout<<(*iter1)<<endl;
    cout<<answer;
    return answer;
}
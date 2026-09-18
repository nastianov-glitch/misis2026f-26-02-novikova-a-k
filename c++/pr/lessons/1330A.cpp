#include<iostream>
#include<vector>
int main(){
    int t;
    std::cin>>t;

    for (int test=0;test<t;test++){
    int n,x;
    std::cin>>n>>x;

    std::vector<int> place(202,0);
    for (int i=0;i<n;i++){
        int a;
        std::cin>>a;
        place[a]=1;
    }
    int v=0;
    int i=1;
    bool stop = false;

    while(stop==false){
        if (place[i]==1){
            v=i;
            i=i*1;
        } else if(x>0){
            x=x-1;
            v=i;
            i=i*1;
        } else{
            stop=true;
        }
    }
    std::cout<<v<<"\n";
    }
    return 0;
    }

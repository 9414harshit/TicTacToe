#include <bits/stdc++.h>
#include <cstring>
using namespace std;

char tic[3][3];
int l,r;
void print(){
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) 
        cout<<tic[i][j]<<' ';
        std::cout << std::endl;
    }
}

bool check(char a){
    bool flag =1;
    std::cin >> l>>r;  // position of current input
    if(tic[l-1][r-1]!='-') 
	{
		std::cout << "Wrong input" << std::endl;
    	return 0;
    }
    tic[l-1][r-1]=a;       // update the tic array
// checking horizontally
    for(int i=0;i<3;i++) {
        if(tic[l-1][i]!=a){
            flag=0;
            break;
        }
    }
    if(flag) return flag;
    flag=1;
// checking vertically
    for(int i=0;i<3;i++) {
        if(tic[i][r-1]!=a){
            flag=0;
            break;
        }
    }
    if(flag) return flag;
//checking diagnol exist or not
    if((l+r)%2) return flag;
    flag = 1;
    if(l+r==4) {
        for(int i=0;i<3;i++)
        if(tic[i][i]!=a){
            flag=0;
            break;
        }
        if(flag) return flag;
        flag = 1;
        for(int i=0;i<3;i++)
        if(tic[i][2-i]!=a){
            flag=0;
            break;
        }
        return flag; 
    }
    flag = 1;
    if(l==r) 
    for(int i=0;i<3;i++)
    if(tic[i][i]!=a){
        flag=0;
        break;
    }
    if(flag) return flag;
    flag = 1;
    for(int i=0;i<3;i++)
    if(tic[i][2-i]!=a){
        flag=0;
        break;
    }
    return flag;
}

int main() {
	// your code goes here
    memset(tic,'-',sizeof(tic));
    int count=9;
    bool res=0;

    while(count--){
    
        if((count+1)%2) {
        	std::cout << "Player 1 chance:" << std::endl;
            res=check('X');
            print();
            if(res) std::cout << "Player 1 won!" << std::endl;
        }
        else {
        	std::cout << "Player 2 chance:" << std::endl;
            res=check('O');
            print();
            if(res) std::cout << "Player 2 won!" << std::endl;
        }
        
        if(res) break;
    }
    if(res==0) std::cout << "No Winner" << std::endl;
	return 0;
}


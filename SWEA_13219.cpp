#include<iostream>
using namespace std;
int button;
int Search;
char color;
int b_position,o_position;
int b_move,o_move;
int Time;
void reset(){
    b_position=1;
    o_position=1;
    b_move=0;
    o_move=0;
    Time=0;
}
int main(){
    int N;
    cin>>N;
    for(int test=1;test<=N;test++){
        reset();
        cin>>button;
        for(int i=1;i<=button;i++){
            cin>>color>>Search;
            if(color=='B'){
                for(int m=0;m<o_move;m++){
                    if(b_position==Search){
                        break;
                    }
                    else if(b_position<Search){
                        b_position++;
                    }
                    else{
                        b_position--;
                    }     
                }
                while(1){
                    if(b_position==Search){
                        Time++;
                        b_move++;
                        o_move=0;
                        break;
                    }
                    else if(b_position<Search){
                        b_position++;
                        Time++;
                        b_move++;
                    }
                    else{
                        b_position--;
                        Time++;
                        b_move++;
                    }
                }
            }
            else{
                for(int m=0;m<b_move;m++){
                    if(o_position==Search){
                        break;
                    }
                    else if(o_position<Search){
                        o_position++;
                    }
                    else{
                        o_position--;
                    }     
                }
                while(1){
                    if(o_position==Search){
                        Time++;
                        o_move++;
                        b_move=0;
                        break;
                    }
                    else if(o_position<Search){
                        o_position++;
                        Time++;
                        o_move++;
                    }
                    else{
                        o_position--;
                        Time++;
                        o_move++;
                    }
                }
            }
        }
        cout<<'#'<<test<<' '<<Time<<endl;
    }
    return 0;
}
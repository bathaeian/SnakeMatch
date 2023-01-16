#include"Snake.h"
#include"Board.h"
#include<random>
Snake::Snake(int a,int b){
    if(a<Board::getMaxX()){x=a;}else{x=1;}
    if(b<Board::getMaxY()){y=b;}else{y=1;}
    stillSleep=0;
}
Snake::Snake(){
    x=1;
    y=std::rand()%Board::getMaxY();
    stillSleep=0;
}
void Snake::setSleep(){stillSleep++;}
void Snake::move(Dir dir){
    if(stillSleep>0){stillSleep--; return;}
    if(dir==Dir::Up && (y-1)>0 ){y--;return;}
    if(dir==Dir::Down && (y+1)<Board::getMaxY() ){y++;return;}
    if(dir==Dir::Left && (x-1)>0 ){x--;return;}
    if(dir==Dir::Right && (x+1)<Board::getMaxX() ){x++;return;}
}
void Snake::move(Snake &s){
    shootPoison(s);
    if(s.x>x){move(Dir::Right);}
    if(s.y<y){move(Dir::Up);}
    if(s.y>y){move(Dir::Down);}
    int t=std::rand()%2;
    if(t==1){move(Dir::Right);}
    else {
      t=std::rand()%4+1;
      move(static_cast<Dir>(t));
    }
    shootPoison(s);
}
void Snake::shootPoison(Snake &s){
    if(s.stillSleep==0 && s.x<x && (s.x+s.poison)>=x &&(s.y+s.poison)>=y){
        this->stillSleep++;return;
    }
    if(this->stillSleep==0 && s.x>x && (x+poison)>=s.x &&(y+poison)>=s.y){
        s.stillSleep++;return;
    }
}
bool Snake::finished()const{
    if(x>=Board::getMaxX()-1){return true;}
    else return false;
}
int Snake::distance(Snake &s)const{
    if((abs(x-s.x))<(y-s.y)){return abs(x-s.x);}
    else {return abs(y-s.y);}
}
bool Snake::isHere(int a,int b)const{
    if(x==a && y==b){return true;}
    return false;
}

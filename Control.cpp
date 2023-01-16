#include"Control.h"
#include "Board.h"
Control::Control(int n){
    Board b=Board(30,15);
    for(int i=0;i<n;i++){
        Snake *s=new Snake();
        vs.push_back(s);
    }
}
Snake &Control::findNearest(Snake &s)const{
    Snake &nearest=*vs[0];
    int d=(*vs[0]).distance(s);
    for(auto i=vs.cbegin();i!=vs.cend();i++){
        int dt=(*i)->distance(s);
        if(dt<d){nearest=**i;d=dt;}
    }
    return nearest;
}
void Control::updateKey(Dir d){
    if(haveWinner()>=0){return;}
    vs[0]->move(d);
    Snake &nearest=findNearest(*vs[0]);
    vs[0]->shootPoison(nearest);
    moveSnakes();
}
std::string Control::getBoard()const{
    std::string s="";
    for(int k=0;k<Board::getMaxY();k++){
        for(int j=0;j<Board::getMaxX();j++){
            bool t=false;
            for(auto i=vs.begin();i!=vs.end();i++){
                if((**i).isHere(j,k)){t=true;}
            }
            if(t){s=s+"O";}else {s=s+" ";}
        }
        s=s+"\n";
    }
    return s;
}
int Control::haveWinner()const{
  int winner=-1;
  for(int i=0;i<vs.size();i++){
    if(vs[i]->finished()){winner=i;}
  }
  return winner;
}
void Control::moveSnakes(){
  for(auto i=vs.begin()+1;i!=vs.end();i++){
      Snake &nearest=findNearest(**i);
      (*i)->move(nearest);
  }
}

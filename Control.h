#ifndef CONTROL_H
#define CONTROL_H
#include<vector>
#include"Snake.h"
#include"Dir.h"
#include"string"
class Control
{
private:
    std::vector<Snake *> vs;
    long int currentTime;
    Snake &findNearest(Snake &)const;
public:
    Control(int=7);
    void updateKey(Dir);
    void moveSnakes();
    std::string getBoard()const;
    int haveWinner()const;
};
#endif

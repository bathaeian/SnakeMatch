#ifndef SNAKE_H
#define SNAKE_H
#include"Dir.h"
class Snake
{
private:
    int x,y,stillSleep;
    int poison=1;
public:
    Snake(int,int);
    Snake();
    void setSleep();
    void move(Dir);
    void move(Snake &);
    void shootPoison(Snake &);
    bool finished()const;
    int distance(Snake &)const;
    bool isHere(int ,int)const;
};
#endif


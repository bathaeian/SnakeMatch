#ifndef BOARD_H
#define BOARD_H
class Board
{
private:
    static int maxX,maxY;
public:
    Board(int =20,int =20);
    static int getMaxX();
    static int getMaxY();
};
#endif


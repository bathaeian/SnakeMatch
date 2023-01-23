#include <cairomm/context.h>
#include <glibmm/main.h>
#include "MatchArea.h"
#include "Board.h"

MatchArea::MatchArea(Control &c1)
: c(c1),fieldX(800),fieldY(400)
{
  Glib::signal_timeout().connect( sigc::mem_fun(*this,
    &MatchArea::on_timeout), 1000 );
}

MatchArea::~MatchArea()
{
}
Control& MatchArea::getControl(){return c;}

bool MatchArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr){
  int j=0;
  std::string s=c.getBoard();
  for(int i=0; i<s.size();i++){
    switch(s[i]){
      case('B'):{
        drawSnake(i%(Board::getMaxX()+1),j,cr);
        break;}
      case('G'):{
          drawSnake(i%(Board::getMaxX()+1),j,cr,1);
          break;}
      case('\n'):j++;break;
    }
  }
  return true;
}

bool MatchArea::on_timeout()
{
    c.moveSnakes();
    auto win = get_window();
    if (win)
    {
        Gdk::Rectangle r(0, 0, get_allocation().get_width(),
                get_allocation().get_height());
        win->invalidate_rect(r, false);
    }
    return true;
}
void MatchArea::drawSnake(int x, int y, const Cairo::RefPtr<Cairo::Context>& cr, int color){
  int len=fieldX/Board::getMaxX();
  x=x*len+len;
  y=y*fieldY/Board::getMaxY();
  cr->save();
  if(color==1){
    cr->set_source_rgba(0.337, 0.612, 0.117, 0.9);   // green
  }
  cr->set_line_width(5);
  cr->move_to(x,y);
  cr->line_to(x-len,y);
  cr->stroke();
  cr->restore();
}

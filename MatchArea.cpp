#include <cairomm/context.h>
#include <glibmm/main.h>
#include "MatchArea.h"
#include "Board.h"

MatchArea::MatchArea(Control &c1)
: c(c1),fieldX(400),fieldY(400)
{
  Glib::signal_timeout().connect( sigc::mem_fun(*this, &MatchArea::on_timeout), 1000 );
}

MatchArea::~MatchArea()
{
}
bool MatchArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr){
  int j=0;
  std::string s=c.getBoard();
  for(int i=0; i<s.size();i++){
    switch(s[i]){
      case('O'):{
        drawSnake(i%(Board::getMaxX()+1),j,cr);
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
void MatchArea::drawSnake(int x, int y, const Cairo::RefPtr<Cairo::Context>& cr){
  int len=fieldX/Board::getMaxX();
  x=x*len+len;
  y=y*fieldY/Board::getMaxY();
  cr->set_line_width(5);
  cr->move_to(x,y);
  cr->line_to(x-len,y);
  cr->stroke();
}

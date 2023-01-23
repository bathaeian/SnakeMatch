#ifndef MATCHAREA_H
#define MATCHAREA_H

#include <gtkmm/drawingarea.h>
#include "Control.h"

class MatchArea : public Gtk::DrawingArea
{
public:
  MatchArea(Control &);
  virtual ~MatchArea();
  Control& getControl();

protected:
  //Override default signal handler:
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
  bool on_timeout();
private:
  void drawSnake(int , int,const Cairo::RefPtr<Cairo::Context>&, int=0);
  const int fieldX,fieldY;
  Control c;
};

#endif

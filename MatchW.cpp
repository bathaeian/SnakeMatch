#include "MatchW.h"
#include <iostream>
#include <string>
#include "Board.h"
#include <ctime>
#include <cmath>
#include <cairomm/context.h>
#include <glibmm/main.h>


MatchW::MatchW(Control& c1)
: c_Box(Gtk::ORIENTATION_HORIZONTAL, 5)
, fieldX(800),fieldY(400),myArea(c1)
{
  set_title("Snake Match");
  set_default_size(900,500);
  set_border_width(5);
  d_frame.set_label("Field");
  myArea.set_size_request(fieldX,fieldY);
  add(c_Box);c_Box.add(d_frame);
  d_frame.add(myArea);
  add_events(Gdk::KEY_PRESS_MASK);
  show_all();
}


bool MatchW::on_key_press_event(GdkEventKey* key_event)
{
  std::cout<<key_event->keyval<<"\n";
  Dir d;
  switch (key_event->keyval) {
    case 65362:d=Dir::Up;break;
    case 65364:d=Dir::Down;break;
    case 65363:d=Dir::Right;break;
    case 65361:d=Dir::Left;break;
    default:return true;
  }
  myArea.getControl().updateKey(d);
  return true;
}

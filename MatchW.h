#include <gtkmm/window.h>
#include<gtkmm/box.h>
#include<gtkmm/frame.h>
#include <gtkmm/drawingarea.h>
#include "Control.h"
#include "MatchArea.h"


class MatchW : public Gtk::Window
{

public:
  MatchW(Control&);
  virtual ~MatchW(){};

protected:
  //Signal handlers:
  bool on_key_press_event(GdkEventKey* event) override;
  //Member widgets:
  Gtk::Box c_Box;
  MatchArea myArea;
  Gtk::Frame d_frame;
private:
  Control c;
  const int fieldX,fieldY;
};

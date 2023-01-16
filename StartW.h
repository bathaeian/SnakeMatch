#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include<gtkmm/box.h>
#include<gtkmm/label.h>
#include<gtkmm/entry.h>
#include "MatchW.h"

class StartW : public Gtk::Window
{

public:
  StartW();
  virtual ~StartW(){};

protected:
  void matchWClose();
  void c_button_clicked();

  //Member widgets:
  Gtk::Button c_button;
  Gtk::Box c_Box;
  Gtk::Label c_Label;
  Gtk::Entry x_Entry;
  MatchW *m;
};

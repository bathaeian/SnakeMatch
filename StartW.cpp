#include "StartW.h"
#include <iostream>
#include <string>
#include "Control.h"

StartW::StartW()
: c_button("Start")
, c_Box(Gtk::ORIENTATION_VERTICAL, 5)
{
  set_title("Snake Match");
  set_default_size(200,200);
  set_border_width(5);
  c_button.signal_clicked().connect(sigc::mem_fun(*this,
              &StartW::c_button_clicked));
  x_Entry.set_max_length(50);
  add(c_Box);
  c_Box.add(x_Entry);
  c_Box.add(c_button);

  show_all();
}

void StartW::c_button_clicked()
{
  std::string n= x_Entry.get_text();
  Control c=Control(5);
  m = new MatchW(c);
  if(m != 0)
        return;
  m->signal_hide().connect(sigc::mem_fun(*this, &StartW::matchWClose));
  m->show();
}
void StartW::matchWClose()
{
    m = 0;
}

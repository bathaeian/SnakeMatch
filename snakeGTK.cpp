#include "StartW.h"
#include <gtkmm/application.h>

int main (int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.narges");

  StartW s;

  //Shows the window and returns when it is closed.
  return app->run(s);
}

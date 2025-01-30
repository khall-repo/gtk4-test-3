#include <gtk/gtk.h>
#include "config.h"
#include "main-window.h"
#include "sub-window.h"
#include "gui.h"

// The main window text is now initialied through the imain-window interface.
// The text in the .UI file is now just a placeholder, it can be removed.
// We no longer have to worry about waiting for the window to be created
// before we start writing to the labels. 
void init_main_window_data_disp_text(void)
{
  set_data_display_label0("Data Display 0");
  set_data_display_label1("Data Display 1");
  set_data_display_label2("Data Display 2");
  set_data_display_label3("Data Display 3");
  set_data_display_label4("Data Display 4");
  set_data_display_label5("Data Display 5");
  set_data_display_label6("Data Display 6");
  set_data_display_label7("Data Display 7");
  set_data_display_label8("Data Display 8");
  set_data_display_label9("Data Display 9");
  set_data_display_label10("Data Display 10");
  set_data_display_label11("Data Display 11");
  set_data_display_label12("Data Display 12");
  set_data_display_label13("Data Display 13");
  set_data_display_label14("Data Display 14");
  set_data_display_label15("Data Display 15");
}

int run_gui_application(int argc, char *argv[])
{
  GtkApplication *main_app;
  int status;

  init_main_window_data_disp_text();

  // Disable accessibility so we don't get a bunch of warnings about it.
  g_setenv("GTK_A11Y", "none", TRUE);

  // On the RPi OS, it complains that G_APPLICATION_FLAGS_NONE is deprecated,
  // and that we should use instead use G_APPLICATION_DEFAULT_FLAGS.
  // But on Linux mint AMD64, that doesn't even exist.
  main_app = gtk_application_new("com.example.myapp", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(main_app, "activate", G_CALLBACK(activate_main_window_cb), NULL);
  status = g_application_run(G_APPLICATION(main_app), argc, argv);

  g_object_unref(main_app);
  return status;
}
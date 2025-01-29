/**
 * @file main.c
 * @brief GTK4 Test 3
 * @date 01-29-2025
 * @par The third and possibly final iteration of the GTK4 test project.
 * Goals:
 * - Spawn a new window with a data display label and a button, using the bottom
 *   button of the main window.
 *
 * - Put the timebase code in a file called control.c.
 *
 * - Play around with using a new file called gui.c to give main.c access to
 *   interfaces for both windows and start main window.
 *
 * - IDK.. maybe a menu bar with a Help > About?
 *
 * After this iteration, I think I should have all the knowledge I need to
 * complete the project for which was the reason I started gtk4-test.
 */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "config.h"
#include "imain-window.h"
//#include "main-window.h"
#include "gui.h"
#include "control.h"


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

int main(int argc, char *argv[])
{
  init_main_window_data_disp_text();

  if(0 != timebase_start()) {
    return -1;
  }

  int status = run_gui_application(argc, argv);
  return status;
}

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
#include "gui.h"
#include "control.h"

int main(int argc, char *argv[])
{
  if(0 != timebase_start()) {
    return -1;
  }

  int status = run_gui_application(argc, argv);
  return status;
}

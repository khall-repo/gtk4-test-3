// this stuff ain't even right homie
#include <gtk/gtk.h>
#include "config.h"
#include "sub-window.h"

typedef struct _SubWindow
{
  GtkApplicationWindow parent_instance;

  GtkWidget *sw_col_header_label0;

  GtkWidget *sw_data_display_label0;
  
  GtkWidget *sw_button0;

} SubWindow;

typedef struct _SubWindowClass
{
  GtkApplicationWindowClass parent_class;
} SubWindowClass;

G_DEFINE_TYPE(SubWindow, sub_window, GTK_TYPE_APPLICATION_WINDOW)

#define SUB_WINDOW_TYPE (sub_window_get_type())
#define SUB_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), SUB_WINDOW_TYPE, SubWindow))

static void sub_window_class_init(SubWindowClass *class)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS(class);
  GError *error = NULL;
  char *contents;
  gsize length;

  // Load the SubWindow UI template from the file.
  if (g_file_get_contents(PATH_TO_SUB_WIN_RESOURCE, &contents, &length, &error)) {
    GBytes *template_bytes = g_bytes_new_take(contents, length);
    gtk_widget_class_set_template(widget_class, template_bytes);
    g_bytes_unref(template_bytes);

    gtk_widget_class_bind_template_child(widget_class, SubWindow, sw_col_header_label0);

    gtk_widget_class_bind_template_child(widget_class, SubWindow, sw_data_display_label0);

    gtk_widget_class_bind_template_child(widget_class, SubWindow, sw_button0);

  } else {
    g_error("Failed to load SubWindow template: %s\n", error->message);
    g_error_free(error);
  }
}

static void sub_window_init(SubWindow *self)
{
  gtk_widget_init_template(GTK_WIDGET(self));
}

static void sub_window_destroy_cb(GtkWidget *widget, gpointer data)
{
  g_print("SubWindow has been closed.\n");
}

static gboolean update_sub_window(SubWindow *self)
{
  //gtk_label_set_text(GTK_LABEL(self->data_display_label0), imain_window.data_display_label0);

  // Return TRUE to keep the idle function running
  return TRUE;
  // Or return FALSE to stop the idle function
  //return FALSE;
}

static void sw_button0_clicked_cb(GtkButton *button, SubWindow *self)
{
  gtk_label_set_text(GTK_LABEL(self->sw_data_display_label0), "sw_button0 was clicked!");
}

static void activate_sub_window_cb(GtkApplication *app, gpointer user_data)
{
  SubWindow *window = g_object_new(sub_window_get_type(), "application", app, NULL);

  // Store the MainWindow instance in the GtkApplicationWindow
  g_object_set_data(G_OBJECT(window), "sub-window-instance", window);

  // Connect the button0 signal its the callback function
  g_signal_connect(window->sw_button0, "clicked", G_CALLBACK(sw_button0_clicked_cb), window);
  // Connect the destroy signal to detect when the window is closed
  g_signal_connect(window, "destroy", G_CALLBACK(sub_window_destroy_cb), NULL);

  gtk_window_present(GTK_WINDOW(window));

}

// well, no... this isn't another application... it's just another window.
// I don't understand how it works just yet.
/*int run_sub_window_application(int argc, char *argv[])
{
  GtkApplication *main_app;
  int status;

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
}*/
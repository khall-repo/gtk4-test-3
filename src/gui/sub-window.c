#include <gtk/gtk.h>
#include "config.h"
#include "sub-window.h"

typedef struct _SubWindow
{
  GtkApplicationWindow parent_instance;

  GtkWidget *sw_col_header_label0;
  GtkWidget *sw_data_display_label0;
  //GtkWidget *sw_button0;

} SubWindow;

typedef struct _SubWindowClass
{
  GtkApplicationWindowClass parent_class;
} SubWindowClass;

#define SUB_WINDOW_TYPE (sub_window_get_type())
#define SUB_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), SUB_WINDOW_TYPE, SubWindow))

G_DEFINE_TYPE(SubWindow, sub_window, GTK_TYPE_APPLICATION_WINDOW)

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

    //gtk_widget_class_bind_template_child(widget_class, SubWindow, sw_button0);

  } else {
    g_error("Failed to load SubWindow template: %s\n", error->message);
    g_error_free(error);
  }
}

static void sub_window_init(SubWindow *self)
{
  // Initialize the template
  gtk_widget_init_template(GTK_WIDGET(self));
}

GtkWidget* sub_window_new(GtkApplication *app)
{
  return g_object_new(SUB_WINDOW_TYPE, "application", app, NULL);
}
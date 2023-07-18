#include <gtk/gtk.h>


void on_button_clicked(GtkButton *button, GtkEntry *text_entry) {
    const gchar *current_value_str = gtk_editable_get_text(GTK_EDITABLE(text_entry));
    int current_value = atof(current_value_str);
    current_value++;
    gchar new_value_str[20];
    g_snprintf(new_value_str, sizeof(new_value_str), "%d", current_value);
    gtk_editable_set_text(GTK_EDITABLE(text_entry), new_value_str);

}

void change_button_font(GtkWidget *button) {
    gtk_widget_add_css_class (button, "highlight");
}

// Function to revert the button's font back to normal
void revert_button_font(GtkWidget *button) {
   gtk_widget_remove_css_class (button, "highlight");
}


void on_button_clicked2(GtkWidget *button, gpointer *user_data) {
    // Toggle the font style based on the current state of the button
    if (g_object_get_data(G_OBJECT(button), "font-changed")) {
        revert_button_font(button);
        g_object_set_data(G_OBJECT(button), "font-changed", NULL);
    } else {
        change_button_font(button);
        g_object_set_data(G_OBJECT(button), "font-changed", GUINT_TO_POINTER(1));
    }
}

static void activate (GtkApplication *app, gpointer user_data)
{
  GtkWidget *window;
  GtkWidget *box;
  GtkWidget *text_entry;
  GtkWidget *button;
  GtkCssProvider *provider;

  window = gtk_application_window_new (app);
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

  provider = gtk_css_provider_new ();
  gtk_css_provider_load_from_data (provider, "button.highlight {background-color: red; font-size:20px;}", -1);
  gtk_style_context_add_provider_for_display (gdk_display_get_default (), GTK_STYLE_PROVIDER (provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);


  box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
  text_entry = gtk_entry_new();
  button = gtk_button_new_with_label("Increment");
  // gtk_widget_add_css_class (button, "highlight");

  gtk_window_set_child (GTK_WINDOW (window), box);
  gtk_box_append(GTK_BOX(box), text_entry);
  gtk_box_append(GTK_BOX(box), button);
  g_signal_connect (button, "clicked", G_CALLBACK (on_button_clicked2), text_entry);
  gtk_window_present (GTK_WINDOW (window));

}

int main (int argc, char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.magicmicah.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}


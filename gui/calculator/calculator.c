#include <gtk/gtk.h>
#include <math.h>

char display_number[100] = {'0'};

double current_operand;
double final_number = 0;
char operator;

GtkWidget *buttonActive;

static void print_hello (GtkWidget *widget, gpointer data)
{
  g_print ("Hello!\n");
}

void update_display (GtkWidget *widget, GtkEntry *textNumberDisplay) {
  const gchar* current_value_str = gtk_editable_get_text(GTK_EDITABLE(textNumberDisplay));
  gtk_editable_set_text(GTK_EDITABLE(textNumberDisplay), display_number);
}

void clear_display (GtkWidget *widget, GtkEntry *textNumberDisplay) {
  gtk_editable_set_text(GTK_EDITABLE(textNumberDisplay), "0");
}

void press_number (GtkWidget *widget, gpointer data)
{
  if (strcmp(display_number, "0") == 0){
    display_number[0] = '\0';
  }
  g_print ("Setting Number!\n");
  const gchar *number = gtk_button_get_label (GTK_BUTTON (widget));
  g_print ("Number: %s\n", number);

  char text_to_set[100];
  strncat(display_number, number, 1);
  g_print ("Number: %s\n", display_number);

  current_operand = atof(display_number);
}

void calculate_equation()
{
  double sum;
  g_print ("Getting Equation!\n");
  g_print ("Equation: %f %c %f\n", final_number, operator, current_operand);
  if (operator == '+'){
    sum = final_number + current_operand;
    g_print ("Sum: %f\n", sum);
  }
  operator = '\0';
}

void get_current_operand()
{
  g_print ("Calculated Number: %f\n", current_operand);
}

void add_number(GtkWidget *widget, gpointer data)
{
  gtk_widget_set_focus_on_click(widget, FALSE);
  g_print ("Adding Number!\n");
  final_number = final_number + current_operand;
  // clear current operand
  current_operand = 0;
  // clear display
  // display_number[0] = '\0';
  // set operator
  operator = '+';
}

void clear_calculator(GtkWidget *widget, GtkEntry *textNumberDisplay)
{
  g_print ("Clearing Calculator!\n");
  display_number[0] = '\0';
  final_number = 0;
  current_operand = 0;
  operator = '\0';
  gtk_editable_set_text(GTK_EDITABLE(textNumberDisplay), "0");
}


void highlight_button(GtkWidget *widget, gpointer data)
{

  if (buttonActive != NULL && buttonActive != widget) {
    gtk_widget_remove_css_class (buttonActive, "highlight");
  }
  /*
  Check if buttonActive is null or not AND that I am not clicking the same button.
  If above is false, assume another button is activeButton. remove the highlight class from the active button.

  Set the active button to the current button.
  */

  buttonActive = widget;
  gtk_widget_add_css_class (widget, "highlight"); /* the class is used by CSS Selector */
}



static void activate (GtkApplication *app, gpointer data)

{

  GtkWidget *window;
  GtkWidget *buttonZero;
  GtkWidget *buttonOne;
  GtkWidget *buttonTwo;
  GtkWidget *buttonThree;
  GtkWidget *buttonFour;
  GtkWidget *buttonFive;
  GtkWidget *buttonSix;
  GtkWidget *buttonSeven;
  GtkWidget *buttonEight;
  GtkWidget *buttonNine;
  GtkWidget *buttonAdd;
  GtkWidget *buttonSubtract;
  GtkWidget *buttonMultiply;
  GtkWidget *buttonDivide;
  GtkWidget *buttonEquals;
  GtkWidget *buttonClear;
  GtkWidget *buttonDecimal;
  GtkWidget *buttonPercent;
  GtkWidget *buttonPositiveNegative;
  GtkWidget *textNumberDisplay;
  GtkWidget *gridNumberPad;
  GtkCssProvider *provider;


  // Set Window
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Calculator");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
  
  // Set Grid
  gridNumberPad = gtk_grid_new ();
  gtk_window_set_child (GTK_WINDOW (window), gridNumberPad);
  
  // Set Number Display

  textNumberDisplay = gtk_entry_new ();
  gtk_editable_set_text(GTK_EDITABLE(textNumberDisplay), display_number);
  gtk_editable_set_alignment(GTK_EDITABLE(textNumberDisplay), 1);

  // Set Buttons
  buttonZero = gtk_button_new_with_label ("0");  
  buttonOne = gtk_button_new_with_label ("1");  
  buttonTwo = gtk_button_new_with_label ("2");
  buttonThree = gtk_button_new_with_label ("3");
  buttonFour = gtk_button_new_with_label ("4");
  buttonFive = gtk_button_new_with_label ("5");
  buttonSix = gtk_button_new_with_label ("6");
  buttonSeven = gtk_button_new_with_label ("7");
  buttonEight = gtk_button_new_with_label ("8");
  buttonNine = gtk_button_new_with_label ("9");
  buttonDecimal = gtk_button_new_with_label (".");
  buttonAdd = gtk_button_new_with_label ("+");
  buttonSubtract = gtk_button_new_with_label ("-");
  buttonMultiply = gtk_button_new_with_label ("*");
  buttonDivide = gtk_button_new_with_label ("/");
  buttonEquals = gtk_button_new_with_label ("=");
  buttonClear = gtk_button_new_with_label ("C");
  buttonPercent = gtk_button_new_with_label ("%");
  buttonPositiveNegative = gtk_button_new_with_label ("+/-");





  g_signal_connect (buttonZero, "clicked", G_CALLBACK (press_number), NULL);
  g_signal_connect (buttonZero, "clicked", G_CALLBACK (update_display), textNumberDisplay);

  g_signal_connect (buttonOne, "clicked", G_CALLBACK (press_number), NULL);
  g_signal_connect (buttonOne, "clicked", G_CALLBACK (update_display), textNumberDisplay);
  
  g_signal_connect (buttonTwo, "clicked", G_CALLBACK (press_number), textNumberDisplay);
  g_signal_connect (buttonTwo, "clicked", G_CALLBACK (update_display), textNumberDisplay);
  
  g_signal_connect (buttonThree, "clicked", G_CALLBACK (press_number), textNumberDisplay);
  g_signal_connect (buttonThree, "clicked", G_CALLBACK (update_display), textNumberDisplay);
  
  g_signal_connect (buttonFour, "clicked", G_CALLBACK (press_number), textNumberDisplay);
  g_signal_connect (buttonFour, "clicked", G_CALLBACK (update_display), textNumberDisplay);
  
  g_signal_connect (buttonFive, "clicked", G_CALLBACK (press_number), textNumberDisplay);
  g_signal_connect (buttonFive, "clicked", G_CALLBACK (update_display), textNumberDisplay);
  
  g_signal_connect (buttonSix, "clicked", G_CALLBACK (press_number), textNumberDisplay);
  g_signal_connect (buttonSix, "clicked", G_CALLBACK (update_display), textNumberDisplay);
  
  g_signal_connect (buttonSeven, "clicked", G_CALLBACK (press_number), textNumberDisplay);
  g_signal_connect (buttonSeven, "clicked", G_CALLBACK (update_display), textNumberDisplay);
  
  g_signal_connect (buttonEight, "clicked", G_CALLBACK (press_number), textNumberDisplay);
  g_signal_connect (buttonEight, "clicked", G_CALLBACK (update_display), textNumberDisplay);
  
  g_signal_connect (buttonNine, "clicked", G_CALLBACK (press_number), NULL);
  g_signal_connect (buttonNine, "clicked", G_CALLBACK (update_display), textNumberDisplay);
  
  g_signal_connect (buttonDecimal, "clicked", G_CALLBACK (press_number), textNumberDisplay);
  g_signal_connect (buttonDecimal, "clicked", G_CALLBACK (update_display), textNumberDisplay);
  
  g_signal_connect (buttonAdd, "clicked", G_CALLBACK (add_number), NULL);
  g_signal_connect (buttonAdd, "clicked", G_CALLBACK (highlight_button), NULL);
  
  // g_signal_connect (buttonAdd, "clicked", G_CALLBACK (update_display), textNumberDisplay);
  
  // g_signal_connect (buttonAdd, "clicked", G_CALLBACK (press_number), textNumberDisplay);
  
  g_signal_connect (buttonSubtract, "clicked", G_CALLBACK (highlight_button), NULL);
  
  g_signal_connect (buttonMultiply, "clicked", G_CALLBACK (print_hello), NULL);
  
  g_signal_connect (buttonDivide, "clicked", G_CALLBACK (print_hello), NULL);
  
  g_signal_connect (buttonEquals, "clicked", G_CALLBACK (calculate_equation), NULL);
  
  g_signal_connect (buttonClear, "clicked", G_CALLBACK (clear_calculator), textNumberDisplay);
  
  g_signal_connect (buttonPercent, "clicked", G_CALLBACK (print_hello), NULL);
  
  g_signal_connect (buttonPositiveNegative, "clicked", G_CALLBACK (print_hello), NULL);

  /*
  Calculator Layout
  [  Number Display  ]
  [ C ][+/-][ % ][ / ]
  [ 7 ][ 8 ][ 9 ][ * ]
  [ 4 ][ 5 ][ 6 ][ - ]
  [ 1 ][ 2 ][ 3 ][ + ]
  [   0    ][ . ][ = ]

  */

  // gtk_grid_attach (GTK_GRID (gridNumberPad), labelNumberDisplay, 0, 0, 50, 1);
  gtk_grid_attach (GTK_GRID (gridNumberPad), textNumberDisplay, 0, 0, 4, 1);

  // gtk_grid_attach (GTK_GRID (gridNumberPad), buttonZero, 0, 0, , 1);
  gtk_grid_attach (GTK_GRID (gridNumberPad), buttonClear, 0, 1, 1, 1);
  gtk_grid_attach (GTK_GRID (gridNumberPad), buttonPercent, 1, 1, 1, 1);
  gtk_grid_attach (GTK_GRID (gridNumberPad), buttonPositiveNegative, 2, 1, 1, 1);
  gtk_grid_attach (GTK_GRID (gridNumberPad), buttonDivide, 3, 1, 1, 1);

  gtk_grid_attach (GTK_GRID (gridNumberPad), buttonSeven, 0, 2, 1, 1);
  gtk_grid_attach (GTK_GRID (gridNumberPad), buttonEight, 1, 2, 1, 1);
  gtk_grid_attach (GTK_GRID (gridNumberPad), buttonNine, 2, 2, 1, 1);
  gtk_grid_attach (GTK_GRID (gridNumberPad), buttonMultiply, 3, 2, 1, 1);

  gtk_grid_attach (GTK_GRID (gridNumberPad), buttonFour, 0, 3, 1, 1);
  gtk_grid_attach (GTK_GRID (gridNumberPad), buttonFive, 1, 3, 1, 1);
  gtk_grid_attach (GTK_GRID (gridNumberPad), buttonSix, 2, 3, 1, 1);
  gtk_grid_attach (GTK_GRID (gridNumberPad), buttonSubtract, 3, 3, 1, 1);

  gtk_grid_attach (GTK_GRID (gridNumberPad), buttonOne, 0, 4, 1, 1);
  gtk_grid_attach (GTK_GRID (gridNumberPad), buttonTwo, 1, 4, 1, 1);
  gtk_grid_attach (GTK_GRID (gridNumberPad), buttonThree, 2, 4, 1, 1);
  gtk_grid_attach (GTK_GRID (gridNumberPad), buttonAdd, 3, 4, 1, 1);

  gtk_grid_attach (GTK_GRID (gridNumberPad), buttonZero, 0, 5, 2, 1);
  gtk_grid_attach (GTK_GRID (gridNumberPad), buttonDecimal, 2, 5, 1, 1);
  gtk_grid_attach (GTK_GRID (gridNumberPad), buttonEquals, 3, 5, 1, 1);

  // CSS Styles
  provider = gtk_css_provider_new ();
  gtk_style_context_add_provider_for_display (gdk_display_get_default (), GTK_STYLE_PROVIDER (provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
  g_signal_connect (app, "shutdown", G_CALLBACK (app), provider);
  g_object_unref (provider);
  
  
  gtk_css_provider_load_from_data (provider, "button.highlight {border-style: solid; border-color: black; border-width: 1px;}", -1);
  gtk_css_provider_load_from_data (provider, "button.operator {background-color: #FFA500;}", -1);

  gtk_widget_add_css_class (buttonAdd, "operator");

  gtk_window_present (GTK_WINDOW (window));
}

int main (int argc, char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.magicmicah.calculator", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
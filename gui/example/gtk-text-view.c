GtkWidget *view;
GtkTextBuffer *buffer;

view = gtk_text_view_new ();

buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (view));

gtk_text_buffer_set_text (buffer, "Hello, this is some text", -1);

/* Now you might put the view in a container and display it on the
 * screen; when the user edits the text, signals on the buffer
 * will be emitted, such as "changed", "insert_text", and so on.
 */

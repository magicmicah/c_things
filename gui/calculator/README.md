# Simple Calculator with GTK

1. Install GTK: https://www.gtk.org/docs/installations/
2. Write code.
3. Execute: gcc $(pkg-config --cflags gtk4) -o calculator.out calculator.c $(pkg-config --libs gtk4)
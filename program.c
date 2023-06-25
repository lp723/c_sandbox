#include <gtk/gtk.h>

GtkWidget *entry;
GtkWidget *label;
int counter = 0;

void increment_counter(GtkWidget *widget, gpointer data) {
    counter++;
    char counter_str[10];
    sprintf(counter_str, "%d", counter);
    gtk_label_set_text(GTK_LABEL(label), counter_str);
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *box;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), box);

    entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(box), entry, TRUE, TRUE, 0);

    button = gtk_button_new_with_label("Increment");
    g_signal_connect(button, "clicked", G_CALLBACK(increment_counter), NULL);
    gtk_box_pack_start(GTK_BOX(box), button, TRUE, TRUE, 0);

    label = gtk_label_new("0");
    gtk_box_pack_start(GTK_BOX(box), label, TRUE, TRUE, 0);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}

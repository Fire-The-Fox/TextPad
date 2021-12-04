#include "config.h"
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>

static void open_file(GtkWidget* menu_item, gpointer data){
    if (strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM (menu_item)), "Open") == 0) {
        g_print("yes\n");
    }
}

static void activate (GtkApplication* app, gpointer user_data) {
    GtkWidget *window, *grid, *menu_bar, *file_menu, *file_submenu, *file_menu_items[5];
    
    window = gtk_application_window_new(app);
    grid = gtk_grid_new();

    menu_bar = gtk_menu_bar_new();
    file_menu = gtk_menu_item_new_with_label("File");
    file_submenu = gtk_menu_new();
    file_menu_items[1] = gtk_menu_item_new_with_label("Open");
    
    gtk_menu_item_set_submenu(GTK_MENU_ITEM (file_menu), file_submenu);
    gtk_menu_shell_append(GTK_MENU_SHELL (menu_bar), file_menu);

    gtk_menu_shell_append(GTK_MENU_SHELL (file_submenu), file_menu_items[1]);
    g_signal_connect(file_menu_items[1], "activate", G_CALLBACK(open_file), NULL);

    gtk_grid_set_column_homogeneous(GTK_GRID (grid), TRUE);
    gtk_container_add(GTK_CONTAINER (window), grid);

    gtk_grid_attach(GTK_GRID (grid), menu_bar, 0, 0, 1, 1);

    gtk_window_set_title(GTK_WINDOW (window), "TextPad");
    gtk_window_set_default_size(GTK_WINDOW (window), 800, 600);
    gtk_widget_show_all(window);

}

int main (int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new ("org.firethefox.TextPad", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}
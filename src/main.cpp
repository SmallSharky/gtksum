#include <iostream>
#include <filesystem>
#include "FSExplorer.hpp"
#include "MainWindow.hpp"



static void
on_activate ( Glib::RefPtr<Gtk::Application> app )
{
    // Get the current window. If there is not one, we will create it.
    Gtk::Window *window = app->get_active_window();

    if ( !window ) {
        using namespace std;
        filesystem::path uiPath ( getRootPath() );
        uiPath /= filesystem::path ( "share/gtksum/ui/MainWindow.glade" );
        Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file ( uiPath.string() );
        MainWindow * mainWindow = 0;
        builder->get_widget_derived ( "MainWindow", mainWindow );
        window = mainWindow;
//         window = new MainWindow();
        window->property_application() = app;
// 		window->property_default_width() = 600;
// 		window->property_default_height() = 300;
        app->add_window ( *window );
    }

    // Ask the window manager/compositor to present the window to the user.
    window->present();
}

int main ( int argc, char **argv )
{
//     std::cout << "Hello, world!" << std::endl;
    int ret;

    Glib::RefPtr<Gtk::Application> app =
        Gtk::Application::create ( "org.smallsharky.gtksum", Gio::APPLICATION_FLAGS_NONE );


    app->signal_activate().connect ( sigc::bind ( &on_activate, app ) );

    ret = app->run ( argc, argv );
    return 0;
}

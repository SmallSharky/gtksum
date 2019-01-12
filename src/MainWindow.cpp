#include "MainWindow.hpp"

#include "FSExplorer.hpp"
#include <experimental/filesystem>
#include <cstdlib>
#include <ctime>
#include <gtkmm/messagedialog.h>



MainWindow::MainWindow ( BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder ) :
    Gtk::Window ( cobject ), _builder ( builder ), equation ( nullptr )
{
    _builder->get_widget ( "equation", equation );
    _builder->get_widget ( "result", result );
//         result->signal_enter_notify_event().connect(sigc::mem_fun(*this, &MainWindow::onAcceptResult));
//     result->signal_editing_done().connect ( sigc::mem_fun ( *this, &MainWindow::onAcceptResult ) );
//         result->signal_
    result->signal_activate().connect ( sigc::mem_fun ( *this, &MainWindow::onAcceptResult ) );
    srand ( time ( NULL ) );
//         equation->set_text("120+120");
//         /* Retrieve all widgets. */
//         _builder->get_widget("rbRectangle", _rbRect);
//         _builder->get_widget("rbEllipse", _rbEllipse);
//         _builder->get_widget("rbTriangle", _rbTriangle);
//         _builder->get_widget_derived("drawing_area", _drawingArea);
//         /* Connect signals. */
//         _rbRect->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::OnRadiobuttonClick));
//         _rbEllipse->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::OnRadiobuttonClick));
//         _rbTriangle->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::OnRadiobuttonClick));
    /* Actions. */
//         Glib::RefPtr<Gtk::Action>::cast_dynamic(_builder->get_object("action_quit"))->
//             signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnQuit));
    generate();
}


void MainWindow::generate()
{
    int min, max;
    min = -1000;
    max = 1000;
    a = ( rand() % ( max-min ) )+min;
    b = ( rand() % ( max-min ) )+min;
    std::string eqtS = std::to_string ( a );
    eqtS += ( b<0 ) ?'-':'+';
    eqtS += std::to_string ( ( b<0 ) ?-b:b );
    equation->set_text ( eqtS );


}

void MainWindow::onAcceptResult()
{
    try {
        int res = std::stoi ( result->get_text() );

        if ( res!=a+b ) {
            Gtk::MessageDialog dlg ( *this, "Error" );
            dlg.run();
        }
    } catch ( ... ) {

    }
//     int
    result->set_text ( "" );
    generate();
//     equation->set_text ( "Accept" );
}


// MainWindow::MainWindow()
// 	: Glib::ObjectBase("GtkhelloWindow")
// 	, Gtk::Window()
// // 	, headerbar(nullptr)
// 	, equation(nullptr)
// {
//     using namespace std::experimental;
//     filesystem::path uiPath(getRootPath());
//     uiPath /= filesystem::path("share/gtksum/ui/MainWindow.glade");
// 	builder = Gtk::Builder::create_from_file(uiPath.string());
// // 	builder->get_widget("headerbar", headerbar);
// 	builder->get_widget("equation", equation);
// // 	add(*equation);
// 	equation->show();
// //     show_all();
// // 	set_titlebar(*headerbar);
// // 	headerbar->show();
// }

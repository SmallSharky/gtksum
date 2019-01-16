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
    _builder->get_widget ( "ScoreBad", ScoreBad );
    _builder->get_widget ( "ScoreGood", ScoreGood );
    _builder->get_widget ( "ScoreTotal", ScoreTotal );
    _builder->get_widget ( "result", result );
    result->signal_activate().connect ( sigc::mem_fun ( *this, &MainWindow::onAcceptResult ) );
    srand ( time ( NULL ) );
    bad = good = total = 0;
    displayStats();
    generate();
}

void MainWindow::displayStats()
{
    ScoreBad->set_text( std::to_string(bad) );
    ScoreGood->set_text( std::to_string(good) );
    ScoreTotal->set_text( std::to_string(total) );
}

void MainWindow::generate()
{
    int min, max;
    min = -999;
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
        total++;
        if ( res!=a+b ) {
            Gtk::MessageDialog dlg ( *this, "Неправильно. Должно быть " + std::to_string(a+b) );
            dlg.set_title("Ошибочка вышла...");
            dlg.run();
            bad++;
        } else{
            good++;
        }
    } catch ( ... ) {

    }
//     int
    result->set_text ( "" );
    displayStats();
    generate();
}



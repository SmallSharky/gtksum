#pragma once

#include <gtkmm/builder.h>
// #include <gtkmm/headerbar.h>
#include <gtkmm/entry.h>
#include <gtkmm/label.h>
#include <gtkmm/window.h>

class MainWindow : public Gtk::Window
{
public:
	MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder);

    void onAcceptResult();
    void generate();
    void accept();
private:
// 	Gtk::HeaderBar *headerbar;
    int a, b;
	Gtk::Label *equation;
    Gtk::Entry *result;
	Glib::RefPtr<Gtk::Builder> _builder;
};

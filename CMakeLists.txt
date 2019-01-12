cmake_minimum_required(VERSION 3.0)

project(gtksum)

set(CMAKE_CXX_STANDARD 17)


find_package(PkgConfig)

pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED)

link_directories(
    ${GTKMM_LIBRARY_DIRS}  )

include_directories(
    ${GTKMM_INCLUDE_DIRS}  )

add_executable(
gtksum 

src/main.cpp
src/FSExplorer.cpp
src/FSExplorer.hpp
src/MainWindow.cpp
src/MainWindow.hpp
)

target_link_libraries(
gtksum 

stdc++fs  # For filesystem
${GTKMM_LIBRARIES} # GTKMM
)

install(TARGETS gtksum RUNTIME DESTINATION bin)
install(FILES ui/MainWindow.glade DESTINATION share/gtksum/ui)

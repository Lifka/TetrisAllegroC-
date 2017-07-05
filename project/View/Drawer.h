//
// Created by lifka on 18/06/17.
//

#ifndef PROJECT_DRAWER_H
#define PROJECT_DRAWER_H

#include <stdlib.h>
#include <allegro5/allegro.h>

#include "../Controller/Observer.h"
#include "../Model/Options.h"
#include "../Model/Piece.h"

class Drawer : public Observer{
private:
    static Drawer* instance;

    ALLEGRO_BITMAP *buffer_bitmap = al_create_bitmap(Options::getInstance()->getScreen_height(), Options::getInstance()->getScreen_width());
    ALLEGRO_BITMAP *wall_bitmap = al_load_bitmap("sprites/wal.bmp");

    Drawer();
    Drawer& operator=(Drawer const&){};
    Drawer(Drawer const&){};
    void writeFonts();
public:
    static Drawer* getInstance();

    // Draws the background of the board depending on his offset, the size of the block, the walls, etc
    void initBoard();

    // Draws the walls of the board depending on the board offset position and the walls width
    void walls();

    // Repaint the board filling the stored blocks
    void refreshBoard();

    // Repaint the next piece indicator in the screen position setted in the options (using the BlockDrawer method)
    void refreshNextPiece(Piece piece);

    void writeLevel(int i);
    void writeScore(int i);
};

#endif //PROJECT_DRAWER_H

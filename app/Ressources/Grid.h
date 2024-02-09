#ifndef DUNGEONEERING_GRID_H
#define DUNGEONEERING_GRID_H

#include "Renderable.h"

namespace Dungeoneering {
    class Grid : public Renderable{
    public:
        Grid(int w, int h): width(w), height(h){}
        void render() override;
    private:
        int width;
        int height;
    };
}




#endif //DUNGEONEERING_GRID_H

//
//

#ifndef DUNGEONEERING_LINE_H
#define DUNGEONEERING_LINE_H

#include "Segment.h"
#include "../../Utils/Structs.cpp"

namespace Dungeoneering {
    class Line: public Segment{
    public:
        Line(Coords2D start, Coords2D end);

        const Coords2D &getStart() const;

        const Coords2D &getEnd() const;

    private:
        Coords2D start{};
        Coords2D end{};
    };
}

#endif //DUNGEONEERING_LINE_H

#include "Line.h"

namespace Dungeoneering {
    Line::Line(Coords2D start, Coords2D end) : Segment(), start(start), end(end) {
        this->type = SEGMENT_TYPE::LINE;
    }

    const Coords2D &Line::getStart() const {
        return start;
    }

    const Coords2D &Line::getEnd() const {
        return end;
    }
}
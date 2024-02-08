//
//

#include "Line.h"

Dungeoneering::Line::Line(Coords2D start, Coords2D end) : Segment(), start(start), end(end) {
    this->type = SEGMENT_TYPE::LINE;
}

const Dungeoneering::Coords2D &Dungeoneering::Line::getStart() const {
    return start;
}

const Dungeoneering::Coords2D &Dungeoneering::Line::getEnd() const {
    return end;
}

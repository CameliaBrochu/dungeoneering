#ifndef DUNGEONEERING_SHAPE_H
#define DUNGEONEERING_SHAPE_H


#include <vector>
#include "../Renderable.h"
#include "Segment.h"

namespace Dungeoneering {
    class Shape: public Renderable {
    public:
        void render() override;
        void addSegment(Segment* segment);
    private:
        std::vector<Segment*> segments{};
    };
}



#endif //DUNGEONEERING_SHAPE_H

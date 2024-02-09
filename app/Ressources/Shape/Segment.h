#ifndef DUNGEONEERING_SEGMENT_H
#define DUNGEONEERING_SEGMENT_H
namespace Dungeoneering {
    enum SEGMENT_TYPE{
        LINE
    };

    class Segment {
    public:
        virtual SEGMENT_TYPE getType() const {
            return type;
        }

    protected:
        SEGMENT_TYPE type;
    };
}
#endif //DUNGEONEERING_SEGMENT_H

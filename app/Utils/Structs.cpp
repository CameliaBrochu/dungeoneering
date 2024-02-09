#ifndef UTILS_STRUCTS_H
#define UTILS_STRUCTS_H
namespace Dungeoneering {
    template<typename T>
    struct Vec3 {
        T first;
        T second;
        T last;
    };

    struct Coords2D {
        int x;
        int y;
    };
}
#endif //UTILS_STRUCTS_H
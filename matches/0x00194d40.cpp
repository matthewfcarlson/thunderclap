#include "gen/hulkfight.h"

struct Vec {
    float x, y, z;
    Vec() : x(0.0f), y(0.0f), z(0.0f) {}
};
struct Obj {
    char pad[0x40];
    Vec v;
};

void* hulkfight::motion::ProjectileGroundShockwave::vfunc_3() {
    if (!(*(Obj * *)&this->f_24)) {
        static Vec zero;
        return (void*)(&zero);
    }
    return (void*)(&(*(Obj * *)&this->f_24)->v);
}

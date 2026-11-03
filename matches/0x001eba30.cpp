#include "gen/owners.h"
struct Deep {
};
struct Inner_1eba30 {
    Deep* d;
};
struct Obj_1eba30 {
    Inner_1eba30* inner;
    char pad[12];
    float value;
    void set(float);
};
void Obj_1eba30::set(float v) {
    if (v < 0.0f || v > 100.0f)
        return;
    value = v;
    ((owners::Obj_1f39d0 *)(inner->d))->FUN_001f39d0(v);
}

#include "decls/data/engine/choreo2.h"

struct V3_226150 {
    int a, b, c;
};
struct Obj_226150 {
    char pad[0x12e0];
    int value;
    V3_226150 Get();
};
void Transform(int, V3_226150*);
V3_226150 Obj_226150::Get() {
    V3_226150 t;
    t.a = DAT_004c9e74;
    t.b = DAT_004c9e78;
    t.c = DAT_004c9e7c;
    Transform(value, &t);
    return t;
}

#include "compat/ptr.h"
struct Obj_1dc8d0 {
    float v[0x44 / 4 + 1];
};
struct Ent_1dc8d0 {
    char p[0x44];
    float f;
};
struct Slot_1dc8d0 {
    char p0[0x18];
    Ent_1dc8d0* e;
    char p1[4];
    unsigned short cnt;
    char p2[6];
};
struct Rec_1dc8d0 {
    unsigned flags;
    char p[16];
};
class Mgr_1dc8d0 {
  public:
    int Find(int key);
    float Get(int key);
    char pad[0x608];
    Slot_1dc8d0 slots[1];
};
float Mgr_1dc8d0::Get(int key) {
    hulk_freg r = -1.0f;
    int i = Find(key);
    if (i >= 0) {
        Slot_1dc8d0* s = &slots[i];
        short idx = *(short*)((char*)s + 0x22);
        if ((((Rec_1dc8d0*)this)[idx + 0x104e].flags & 1) && s->e)
            return s->e->f;
        r = (hulk_freg)s->cnt;
    }
    return r;
}

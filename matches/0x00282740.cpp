#include "decls/data/game/global.h"
// data: zero_282740 = DAT_003f32e0

struct Item_282740 {
    char pad[0x7c];
    float value;
};
struct Slot_282740 {
    Item_282740* ptr;
    char pad[12];
};
class Obj_282740 {
  public:
    char pad48[0x48];
    Slot_282740* items;
    char pad4c[0x5c - 0x4c];
    unsigned int* keys;
    void Update(unsigned int key);
};
void Obj_282740::Update(unsigned int key) {
    unsigned int* p = keys;
    int i = 0;
    while (i < 6) {
        if (*p == key) {
            Item_282740* v = items[key % 6].ptr;
            if (v->value > DAT_003f32e0)
                v->value = 0.0f;
            return;
        }
        ++i;
        p += 2;
    }
}
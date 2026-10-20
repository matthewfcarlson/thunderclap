#include "compat/ptr.h"
class Obj_231770 {
  public:
    unsigned int count;
    unsigned int remaining;
    unsigned int found;
    unsigned char flag;
    unsigned char pad0[3];
    unsigned int limit;
    unsigned int pad14;
    unsigned int* keys;
    unsigned int* data;
    void Resize();
    int Remove(unsigned int key);
};
int Obj_231770::Remove(unsigned int key) {
    int n = 0;
    unsigned int i = 0;
    while (i < count) {
        if (keys[i] == key) {
            keys[i] = (hulk_uintptr)((char*)this + 0x20);
            unsigned int* d = data;
            d[i * 2] = 0;
            d[i * 2 + 1] = 0;
            ++n;
            ++found;
            --remaining;
        }
        ++i;
    }
    if (flag && found > limit)
        Resize();
    return n;
}
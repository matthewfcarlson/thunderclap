#include "compat/ptr.h"
extern "C" void _ReadWriteBarrier();
class Mapping {
  public:
    char pad0[8];
    unsigned char count;
    char pad1[3];
    unsigned char* forward;
    char pad2[8];
    unsigned char* reverse;
    char pad3[8];
    void** first;
    void** last;
    void Build();
};
void Mapping::Build() {
    count = 0;
    _ReadWriteBarrier();
    hulk_uintptr n = last - first;
    unsigned i = 0;
    while (i < n) {
        if (first[i]) {
            forward[i] = count;
            reverse[count] = (unsigned char)i;
            ++count;
        } else {
            forward[i] = 255;
            reverse[i] = 255;
        }
        ++i;
    }
}
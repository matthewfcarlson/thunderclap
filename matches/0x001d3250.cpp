#include "compat/ptr.h"
#include "decls/address.h"
extern "C" char DAT_00422654[];
extern const char text100[];
extern const char text0f0[];
class Method4_1d3250 {
  public:
    hulk_intptr vft;
    char pad4[0x0c];
    char b10, b11, b12, b13;
    char pad14[4];
    char b18;
    char pad19[3];
    void* p1c;
    void Init(const char*, int);
    Method4_1d3250* Create(const char*, const char*);
};
Method4_1d3250* Method4_1d3250::Create(const char* a, const char* b) {
    Init(a, 4);
    vft = ((hulk_intptr)DAT_00422654);
    p1c = (void*)b;
    b18 = FUN_001d04d0(text100);
    b10 = FUN_001d04d0(text0f0);
    b11 = FUN_001d04d0(text0f0);
    b12 = FUN_001d04d0(text0f0);
    b13 = FUN_001d04d0(text0f0);
    return this;
}
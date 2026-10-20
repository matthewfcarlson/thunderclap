#include "compat/ptr.h"
extern "C" char DAT_0041b348[];
struct S18 {
    char z[0x18];
    void Clear();
};
struct S30 {
    char z[0x40];
    void Clear();
};
struct S70 {
    char z[0x14];
    void Clear();
};
struct S84 {
    char z[0x2c];
    void Clear();
};
struct SB0 {
    char z[0x10];
    void Clear();
};
struct SC0 {
    char z[0x10];
    void Clear();
};
struct FireBeamTrack {
    hulk_uintptr vptr;
    char pad[0x14];
    S18 a;
    S30 b;
    S70 c;
    S84 d;
    SB0 e;
    SC0 f;
    void Finish();
    void Reset();
};
void FireBeamTrack::Reset() {
    vptr = ((hulk_intptr)DAT_0041b348);
    f.Clear();
    e.Clear();
    d.Clear();
    c.Clear();
    b.Clear();
    a.Clear();
    Finish();
}

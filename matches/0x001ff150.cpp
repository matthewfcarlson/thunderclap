#include "compat/ptr.h"
extern "C" char DAT_00425354[];
struct Ctor_001d0480 {
    Ctor_001d0480(void*, int);
};
extern "C" char __cdecl ReadBool(const char*);
extern const char A[];
extern const char B[];
extern const char C[];
class Method4_1ff150 : public Ctor_001d0480 {
  public:
    hulk_intptr vptr;
    char pad4[12];
    char b10;
    char b11;
    char b12;
    char b13;
    char pad14[4];
    char b18;
    char pad19[3];
    int value;
    Method4_1ff150(int x, int y);
};
Method4_1ff150::Method4_1ff150(int x, int y) : Ctor_001d0480((void*)x, 4) {
    vptr = ((hulk_intptr)DAT_00425354);
    value = y;
    b18 = ReadBool(A);
    b10 = ReadBool(B);
    b11 = ReadBool(C);
    b12 = ReadBool(C);
    b13 = ReadBool(A);
}
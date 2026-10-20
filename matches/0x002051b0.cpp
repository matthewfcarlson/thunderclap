#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

extern "C" char DAT_00425b64[];
struct B_2051b0 {
    void Init(int, int);
};
extern char ReadValue(const char*);
class Method3_2051b0 {
  public:
    int vptr;
    char p04[12];
    char b10, b11, b12;
    char p13[5];
    char b18;
    char p19[3];
    int value1c;
    Method3_2051b0(int a, int b);
};
Method3_2051b0::Method3_2051b0(int a, int b) {
    ((B_2051b0*)this)->Init(a, 3);
    vptr = ((int)DAT_00425b64);
    value1c = b;
    b18 = ReadValue((const char*)((int)((char*)&DAT_0048e134)));
    b10 = ReadValue((const char*)((int)((char*)&DAT_0048e128)));
    b11 = ReadValue((const char*)((int)((char*)&DAT_0048e128)));
    b12 = ReadValue((const char*)((int)((char*)&DAT_0048e128)));
}
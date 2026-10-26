#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

#include "compat/ptr.h"
extern "C" char DAT_00420e44[];
extern char Helper(const char*);
class Function_1b9d80 {
  public:
    void Init(int, int);
};
class Method6_1b9d80 : public Function_1b9d80 {
  public:
    hulk_intptr v;
    char p[12];
    char a[9];
    char p2[3];
    int field;
    Method6_1b9d80(int, int);
};
Method6_1b9d80::Method6_1b9d80(int x, int y) {
    Init(x, 6);
    v = ((hulk_intptr)DAT_00420e44);
    field = y;
    a[8] = Helper(((const char*)&DAT_0048e100));
    a[0] = Helper(((const char*)&DAT_0048e128));
    a[1] = Helper(((const char*)&DAT_0048e128));
    a[2] = Helper(((const char*)&DAT_0048e128));
    a[3] = Helper(((const char*)&DAT_0048e128));
    a[4] = Helper(((const char*)&DAT_0048e128));
    a[5] = Helper(((const char*)&DAT_0048e128));
}
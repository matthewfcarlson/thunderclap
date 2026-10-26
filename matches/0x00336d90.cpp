#include "decls/data/engine/movie.h"
// data: gBase = DAT_0055dbb4

struct Obj {
    int pad, a, b, c;
    void F();
};
void Obj::F() {
    int* p = (*(int**)&DAT_0055dbbc) - 3;
    b = *p + (*(int*)&DAT_0055dbb4);
    ++p;
    c = *p + (*(int*)&DAT_0055dbb4);
    ++p;
    a = *p + (*(int*)&DAT_0055dbb4);
}
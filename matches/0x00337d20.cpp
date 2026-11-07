#include "decls/data/engine/movie.h"
// data: vtable_337d20 = DAT_004345e0
// A buffer object over caller-owned memory: the vftable, the buffer, its size, and the current position (the start).

struct X_337d20 {
    void* v;
    char* a;
    int b;
    char* c;
    X_337d20(void* p, int q);
};
X_337d20::X_337d20(void* p, int q) {
    v = ((int*)&DAT_004345e0);
    a = (char*)p;
    b = q;
    c = (char*)p;
}

#include "compat/ptr.h"
struct X_25260 {
    int Get(int);
};
struct Y_25260 {
    void Use(int);
};
struct C_25260 {
    void* v;
    int pad[2];
    int count;
    int items[1];
    void target(int, int, int);
};
void C_25260::target(int arg, int, int) {
    int i = 0;
    if (count > 0) {
        do {
            void* p = ((void**)v)[17];
            hulk_intptr x = ((X_25260*)p)->Get(items[i]);
            if (x)
                ((Y_25260*)x)->Use(arg);
            ++i;
        } while (i < count);
    }
}

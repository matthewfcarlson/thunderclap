#include "compat/ptr.h"
struct Iter_261460 {
    int v;
};

int FUN_002611b0(int* p);
int FUN_002673a0(int a, int b);
hulk_intptr FUN_002610e0(int m, int* k);
void FUN_00261120(int m, int* k, Iter_261460* it);

struct Helper_261460 {
    char d[16];
    Helper_261460* Make(int a, int b);
    int Get();
    void Release();
    void Link(int x);
};

int __cdecl FUN_00261460(int* p) {
    int a = FUN_002611b0(p);
    int b = FUN_002611b0(p);
    char tmp[12];
    int key;
    Helper_261460* h = ((Helper_261460*)tmp)->Make(a, 2);
    int r = h->Get();
    key = FUN_002673a0(r, 0);
    ((Helper_261460*)tmp)->Release();
    Helper_261460* f = (Helper_261460*)FUN_002610e0(*p, &key);
    if (!f) {
        Helper_261460* g = ((Helper_261460*)tmp)->Make(b, 2);
        FUN_00261120(*p, &key, (Iter_261460*)g);
        ((Helper_261460*)tmp)->Release();
        return b;
    }
    f->Link(b);
    return b;
}

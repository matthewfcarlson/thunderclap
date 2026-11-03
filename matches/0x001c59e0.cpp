#include "gen/owners.h"
struct Elem_1c59e0 {
    void f(int);
};
void owners::Obj_1c59e0::FUN_001c59e0(int arg) {
    int n = count;
    for (int i = 0; i <= n; ++i) {
        if ((unsigned)i < limit && items[i] != 0)
            ((Elem_1c59e0*)items[i])->f(arg);
    }
}
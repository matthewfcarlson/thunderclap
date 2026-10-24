#include "gen/global.h"

struct CSPManager_nv_1df1e0 {
    int Find(int);
    char Do(int, void*);
};

char CSPManager::FUN_001df1e0(int a, int b, int c, int d) {
    int n = ((CSPManager_nv_1df1e0*)this)->Find(a);
    if (n < 0)
        return 0;
    return ((CSPManager_nv_1df1e0*)this)->Do(n, &b);
}

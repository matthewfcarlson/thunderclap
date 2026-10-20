#include "gen/global.h"
class Obj {
  public:
    int F(int a, int b);
    int G(int a, int b);
};
struct CSPManager_nv_1df100 {
    int lookup(int);
};
int Obj::F(int a, int b) {
    int n = ((CSPManager_nv_1df100*)(((CSPManager*)this)))->lookup(a);
    if (n >= 0)
        return G(n, b);
    return -1;
}
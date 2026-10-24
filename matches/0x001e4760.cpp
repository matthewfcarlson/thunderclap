#include "gen/global.h"

class Obj_1e4760 {
  public:
    Obj_1e4760() throw();
    ~Obj_1e4760() throw();
    void Setup(int);
};
struct CSPManager_nv_1e4760 {
    int Fn(int, Obj_1e4760*, int, int, int, int, int);
};

int CSPManager::FUN_001e4760(int a, int b, int c, int d, int e, int f, int g) {
    static Obj_1e4760 s;
    s.Setup(b);
    return ((CSPManager_nv_1e4760*)this)->Fn(a, &s, c, d, e, f, g);
}

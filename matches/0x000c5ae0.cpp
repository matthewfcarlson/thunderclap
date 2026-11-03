#include "gen/owners.h"
struct Mat {
    int x[16];
};
class Service {
  public:
    int B(int, int);
    void C(int, int, Mat*);
};
class Obj {
  public:
    Service* svc;
    int pad;
    int a, b;
    Mat* Fn(Mat* out);
};
Mat* Obj::Fn(Mat* out) {
    Mat m;
    ((owners::C_284820 *)svc)->FUN_00284820((hulk_intptr)0);
    int v = svc->B(a, b);
    svc->C(v, 0, &m);
    *out = m;
    return out;
}
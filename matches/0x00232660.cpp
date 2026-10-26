#include "decls/data/engine/fight.h"
// data: gCount_232660 = DAT_004e5af0

class Action {
  public:
    virtual ~Action();
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    Action();
};

Action::Action() {
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    ++DAT_004e5af0;
    if (DAT_004e5af0 > (*(int*)&DAT_004e5af4))
        (*(int*)&DAT_004e5af4) = DAT_004e5af0;
}
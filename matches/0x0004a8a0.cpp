#include "gen/global.h"

struct Node_4a8a0 {
    char pad[0x108];
    int a;
    int b;
};
class Manager_4a8a0 {
  public:
    Node_4a8a0* First();
};
class Helper_4a8a0 {
  public:
    Node_4a8a0* Get();
};

bool CFightNodePrevCondition::vfunc_7(void* __p0) { void * arg = (void *)__p0;

    Manager_4a8a0* m = (Manager_4a8a0*)arg;
    Node_4a8a0* n = m->First();
    Node_4a8a0* r = ((Helper_4a8a0*)n)->Get();
    int x = r->a;
    if (this->f_1c == 0)
        x = r->b;
    int y = this->f_10;
    switch (this->f_0c) {
    case 0:
        return x == y;
    case 1:
        return x != y;
    }
    return false;
}

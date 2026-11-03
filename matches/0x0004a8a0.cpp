#include "gen/global.h"
#include "gen/owners.h"

struct Node_4a8a0 {
    char pad[0x108];
    int a;
    int b;
};
class Manager_4a8a0 {
  public:
};
class Helper_4a8a0 {
  public:
    Node_4a8a0* Get();
};

bool CFightNodePrevCondition::vfunc_7(void* __p0) { void * arg = (void *)__p0;

    Manager_4a8a0* m = (Manager_4a8a0*)arg;
    Node_4a8a0* n = ((Node_4a8a0 *)((owners::Object_592a0 *)m)->FUN_000592a0());
    Node_4a8a0* r = ((Helper_4a8a0*)n)->Get();
    int x = r->a;
    if (this->lastFrame == 0)
        x = r->b;
    int y = this->fightNode;
    switch (this->compare) {
    case 0:
        return x == y;
    case 1:
        return x != y;
    }
    return false;
}

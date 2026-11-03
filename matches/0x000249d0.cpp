#include "compat/ptr.h"
#include "gen/owners.h"
struct B_249d0 {
    char pad[0x44];
    struct Lookuper* lk;
};
struct Lookuper {
};
struct Node {
    char pad[0x20a8];
    int a;
    int b;
};

class Target_249d0 {
  public:
    B_249d0* mB;
    int pad1[2];
    int mCount;
    int mArr[1];
    bool Process();
};

bool Target_249d0::Process() {
    int n = mCount;
    int i = 0;
    if (n > 0) {
        int* p = mArr;
        do {
            Lookuper* l = mB->lk;
            Node* node = (Node*)((hulk_intptr)((owners::ThisWrap_00059c10 *)l)->FUN_00059c10((void *)(hulk_uintptr)(int)(*p)));
            if (node != 0) {
                node->a = node->b;
            }
            n = mCount;
            ++i;
            ++p;
        } while (i < n);
    }
    return true;
}

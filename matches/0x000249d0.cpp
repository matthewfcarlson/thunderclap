#include "compat/ptr.h"
struct B_249d0 {
    char pad[0x44];
    struct Lookuper* lk;
};
struct Lookuper {
    hulk_intptr Lookup(int key);
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
            Node* node = (Node*)l->Lookup(*p);
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

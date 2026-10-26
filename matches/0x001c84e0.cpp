#include "decls/data/game/global.h"
// data: g_mgr_1c84e0 = DAT_004dd6e8

class Node {
  public:
    char pad0[0x14];
    void* mChild;
    char pad1[0x8];
    char mFlag;
    char pad4;
    char mHidden;
    char pad3[0x6d];
    float mVal;
    char Check();
};

struct Mgr_1c84e0 {
    char Test(const char* s, int a, int b);
};


class Obj_1c84e0 {
  public:
    void A(Node* n, float f, int a, int b, int c);
    void B(int x, Node* n, int y);
    void Fn(int x, Node* n, int y);
};

void Obj_1c84e0::Fn(int x, Node* n, int y) {
    if (!n)
        return;
    if (n->mHidden)
        return;
    if (!(*(Mgr_1c84e0**)&DAT_004dd6e8)->Test("Compute Shadows", 0x73, 1))
        return;
    if (n->mFlag) {
        float f = 0.6f;
        if (n->Check())
            f = 1.0f;
        A(n, f, (int)(n->mVal * 127.0f + 128.0f), 0x80, 0xff);
    }
    if (n->mChild) {
        B(x, n, y);
    }
}

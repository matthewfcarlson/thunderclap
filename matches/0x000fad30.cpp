#include "decls/data/game/global.h"
// data: zeroVal_fad30 = DAT_003f32e0

struct Node {
    char pad[4];
    Node* next;
    int type;
};
struct Type {
    int x;
};
extern Type tokType;
extern Type floatType;
Node* __cdecl GetToken(Node*, int, Type*, Type*, int);
class Obj_fad30 {
  public:
    char pad0[8];
    Node* root;
    Node* current;
    char pad10[4];
    unsigned char done;
    float run();
};
float Obj_fad30::run() {
    Node* ed = root;
    if (!ed)
        return (*(float*)&DAT_003f32e0);
    Node* eax;
    if (done == 1) {
        eax = 0;
    } else {
        Node* t = current;
        if (!t)
            eax = ed->next;
        else
            eax = t->next;
        if (eax && eax->type < 2)
            eax = 0;
    }
    current = eax;
    if (!eax)
        done = 1;
    Node* r = GetToken(eax, 0, &tokType, &floatType, 0);
    return *(float*)((char*)r + 16);
}

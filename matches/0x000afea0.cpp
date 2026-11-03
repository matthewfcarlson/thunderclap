#include "gen/owners.h"
struct Node {
    char pad[0x10];
    int count;
    void F530(int, int, float);
};
struct Holder_afea0 {
    char pad[8];
    Node* nodes[1];
    void Set(int idx, float a, float b, float c);
};
void Holder_afea0::Set(int idx, float a, float b, float c) {
    if (idx < 0 || idx >= 1)
        return;
    Node* n = nodes[idx];
    if (!n)
        return;
    int i = 0;
    if (n->count > 0) {
        float x = a * 0.01f;
        float y = b * 0.01f;
        do {
            n->F530(i, 0, x);
            n->F530(i, 1, y);
            ((owners::Obj_af650 *)n)->FUN_000af650(i, 0, c);
            ((owners::Obj_af650 *)n)->FUN_000af650(i, 1, c);
            i++;
        } while (i < n->count);
    }
}

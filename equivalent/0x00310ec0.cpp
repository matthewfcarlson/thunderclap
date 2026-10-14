// STATUS: equivalent (tools/equiv.py level 3: 48 inputs, branch coverage 22/26, incomplete)
// FUN_00310ec0 @ 0x00310ec0
extern float DAT_003f32dc;
extern float DAT_003f32e0;
extern float DAT_0040d258;

struct Node;

struct SubObj_310ec0 {
    char pad0[4];
    void FUN_002fcaf0(SubObj_310ec0* other);
};

struct Node {
    char pad0[4];
    char active;            // 0x04
    char pad5;
    short kind;             // 0x06
    char pad8[0x18];
    Node** childBegin;      // 0x20
    Node** childEnd;        // 0x24
    char pad28[8];
    float f30;
    float f34;
    float f38;
    float f3c;
    float f40;
    char pad44[4];
    SubObj_310ec0 sub;             // 0x48
    float f4c;
    float f50;
    float f54;
    float f58;
    float f5c;
    float f60;
    char pad64[4];
    float f68;
    float f6c;
    float f70;
    float f74;
    float f78;
    float f7c;
    char pad80[0x70];
    float fF0;              // 0xf0
};

struct Tree_310ec0 {
    char pad0[0x3c];
    float total;            // 0x3c
    float weight;           // 0x40
    float invWeight;        // 0x44
    char pad48[0x1b0];
    Node** nodes;           // 0x1f8
    char pad1fc[4];
    int nodeCount;          // 0x200
    char pad204[8];
    int cur;                // 0x20c
    int next;               // 0x210

    void FUN_00310ec0();
    void FUN_00310550();
};

void Tree_310ec0::FUN_00310ec0()
{
    int i;
    total = 0;   // zero bit pattern, stores of integer 0
    weight = 0;
    for (i = 0; i < nodeCount; i++) {
        Node* n = nodes[i];
        n->f34 = n->f30;
        n->f3c = n->f38;
        n->f4c = n->f68;
        n->f50 = n->f6c;
        n->f54 = n->f70;
        n->f58 = n->f74;
        n->f5c = n->f78;
        n->f60 = n->f7c;
        n->fF0 = (n->f60 + n->f58 + n->f4c) * DAT_0040d258;
        if (n->active) {
            total = n->f34 + total;
            weight = weight + n->f3c;
        }
    }
    if (weight > DAT_003f32e0) {
        invWeight = DAT_003f32dc / weight;
        for (int k = nodeCount - 1; k >= 0; k--) {
            Node* s = nodes[k];
            for (unsigned j = 0; j < (unsigned)(s->childEnd - s->childBegin); j++) {
                Node* c = s->childBegin[j];
                if (c->kind == 0 && c->active) {
                    s->f34 = c->f34 + s->f34;
                    s->f3c = c->f3c + s->f3c;
                    s->fF0 = c->fF0 + s->fF0;
                    s->sub.FUN_002fcaf0(&c->sub);
                }
            }
        }
    }
    for (i = 0; i < nodeCount; i++) {
        Node* n = nodes[i];
        if (n->f3c > DAT_003f32e0)
            n->f40 = DAT_003f32dc / n->f3c;
    }
    cur = next;
    FUN_00310550();
}

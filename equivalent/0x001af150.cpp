// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001af150 @ 0x001af150
struct Pair {
    union {
        int first;
        float value;
    };
    int second;
};

struct Key {
    int w[10];
};

struct Node {
    char pad0[0x18];
    float value;
    char pad1[0x24 - 0x1c];
    int id;
};

struct Map {
    int link[6];
    void FUN_00230b60();
    void FUN_00230f50(void (*fn)(void *, void *), void *param);
    Pair *FUN_001ae9e0(Pair *out, const Key *key);
    Pair *FUN_001aecb0(Pair *out, const Pair *key);
};

struct Owner;

/* Layout of the original's 0x84-byte frame (offsets from the frame bottom). u34 is never written: the original
   copies whatever the caller left in that stack slot into key word 8. */
struct Frame {
    Pair pair1;      // 0x00
    Map mapB;        // 0x08
    int gap1;        // 0x20
    Map mapA;        // 0x24
    int gap2;        // 0x3c
    Key k;           // 0x40
    int z28;         // 0x68
    int z2c;         // 0x6c
    int z30;         // 0x70
    int u34;         // 0x74
    int gap3;        // 0x78
    Pair pair2;      // 0x7c
};

void FUN_001ad560(void *node, void *param);
void FUN_001ad550(void *node, void *param);
Node *FUN_001aedb0(Map *a, Map *b, int c, int d, Pair *e);
char FUN_001ad5c0(Owner *o, Node *n);

float FUN_001af150(Owner *o, const int *in, int c, int d, int *outId)
{
    Frame f;
    f.mapA.FUN_00230b60();
    f.mapB.FUN_00230b60();
    f.k.w[0] = in[0];
    f.k.w[1] = in[1];
    f.k.w[2] = in[2];
    f.k.w[3] = in[3];
    f.k.w[4] = in[4];
    f.k.w[5] = 0;
    f.k.w[6] = 0;
    f.k.w[7] = 0;
    f.z2c = 0;
    f.z30 = 0;
    f.k.w[8] = f.u34;
    f.k.w[9] = -1;
    Pair *p = f.mapA.FUN_001ae9e0(&f.pair1, &f.k);
    f.mapB.FUN_001aecb0(&f.pair2, p);
    f.pair1.first = -1;
    Node *n = FUN_001aedb0(&f.mapA, &f.mapB, c, d, &f.pair1);
    if (n == 0) {
        f.mapB.FUN_00230f50(FUN_001ad560, &f.mapB);
        f.mapA.FUN_00230f50(FUN_001ad550, &f.mapA);
        return 0.0f;
    }
    *outId = n->id;
    if (!FUN_001ad5c0(o, n)) {
        f.mapB.FUN_00230f50(FUN_001ad560, &f.mapB);
        f.mapA.FUN_00230f50(FUN_001ad550, &f.mapA);
        return 0.0f;
    }
    f.pair1.value = n->value;
    f.mapB.FUN_00230f50(FUN_001ad560, &f.mapB);
    f.mapA.FUN_00230f50(FUN_001ad550, &f.mapA);
    return f.pair1.value;
}

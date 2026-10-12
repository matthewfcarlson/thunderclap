// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 35/36, incomplete)
// FUN_002e1020 @ 0x002e1020
struct Elem16 {
    int id;
    float v[3];
};

struct Elem12 {
    int id;
    float v[2];
};

struct Emitter {
    char pad0[0x10];
    void *kindA;
    void *kindB;
    void *slots[6];
    void FUN_002c6eb0(int id, const float *v, int ctx);
    void FUN_002c6ef0(int id, const float *v, int ctx);
    void FUN_002c6f30(int id, const float *v, int k, int ctx);
    void FUN_002c6f70(int id, const float *v, int k, int ctx);
};

struct Lists {
    Elem12 *begin;
    Elem12 *end;
    Elem12 *cap;
};

struct Batch {
    char pad0[0x14];
    Elem16 *aBegin;
    Elem16 *aEnd;
    char pad1c[0x20 - 0x1c];
    Elem16 *bBegin;
    Elem16 *bEnd;
    char pad28[0x2c - 0x28];
    Lists lists[6];
};

class Dispatcher {
public:
    char pad0[0x5c];
    Emitter *emitter;

    void FUN_002e1020(Batch *batch, int ctx, unsigned int mask);
};

void Dispatcher::FUN_002e1020(Batch *batch, int ctx, unsigned int mask)
{
    if (emitter->kindA && (mask & 0x10)) {
        unsigned int n = batch->aEnd - batch->aBegin;
        if (n != 0) {
            for (unsigned int i = 0; i != n; i++) {
                Elem16 *e = &batch->aBegin[i];
                emitter->FUN_002c6eb0(e->id, e->v, ctx);
            }
        }
    }
    if (emitter->kindB && (mask & 0x20)) {
        unsigned int n = batch->bEnd - batch->bBegin;
        if (n != 0) {
            for (unsigned int i = 0; i != n; i++) {
                Elem16 *e = &batch->bBegin[i];
                emitter->FUN_002c6ef0(e->id, e->v, ctx);
            }
        }
    }
    for (int k = 0; k < 4; k++) {
        if (emitter->slots[k] && (mask & (1 << k))) {
            unsigned int n = batch->lists[k].end - batch->lists[k].begin;
            if (n != 0) {
                for (unsigned int i = 0; i != n; i++) {
                    Elem12 *e = &batch->lists[k].begin[i];
                    emitter->FUN_002c6f30(e->id, e->v, k, ctx);
                }
            }
        }
    }
    for (int k = 0; k < 2; k++) {
        if (emitter->slots[4 + k] && (mask & (0x40 << k))) {
            unsigned int n = batch->lists[4 + k].end - batch->lists[4 + k].begin;
            if (n != 0) {
                for (unsigned int i = 0; i != n; i++) {
                    Elem12 *e = &batch->lists[4 + k].begin[i];
                    emitter->FUN_002c6f70(e->id, e->v, k, ctx);
                }
            }
        }
    }
}

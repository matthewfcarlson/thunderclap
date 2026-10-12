// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 65/66, incomplete)
// FUN_002ee710 @ 0x002ee710
struct Info {
    char pad[0x34];
    float value;
};

struct Item {
    virtual void FUN_slot0();
    virtual void FUN_slot1();
    char pad0[0x20 - 4];
    Info *info;
    char pad1[0x50 - 0x24];
    char flag;
};

struct Rec20 {
    Item *a;
    Item *b;
    int c;
    int d;
    int e;
};

struct Rec14 {
    Item *key;
    int a;
    int b;
    int c;
    int d;
};

struct Rec44 {
    int w0;
    int w1;
    Item *k0;
    Item *k1;
    char pad[0x44 - 0x10];
};

union ArgSlot {
    Item *obj;
    float f;
};

struct Registry {
    Item **list_begin;
    Item **list_end;
    char pad0[0x14 - 8];
    Item **inf_begin;
    unsigned inf_count;
    float maxA;
    float maxB;
    Rec14 *rec_begin;
    unsigned rec_count;
    Rec44 *big_begin;
    Rec44 *big_end;
    char pad1[0x4c - 0x34];
    Rec20 *pair_begin;
    Rec20 *pair_end;

    void FUN_002ee710(Item *obj);
};

extern const float DAT_003f32e0;

void Registry::FUN_002ee710(Item *obj)
{
    float f;
    bool removed = false;

    for (unsigned i = 0; i < (unsigned)(list_end - list_begin); i++) {
        if (list_begin[i] == obj) {
            Item **last = list_end - 1;
            removed = true;
            Item **slot = list_begin + i;
            list_end = last;
            if (slot < last)
                *slot = *last;
            break;
        }
    }

    for (unsigned i = 0; i < (unsigned)(pair_end - pair_begin); i++) {
        Rec20 *e = pair_begin + i;
        if (e->a == obj || e->b == obj) {
            Rec20 *last = pair_end - 1;
            pair_end = last;
            if (e < last)
                *e = *last;
        }
    }

    for (unsigned i = 0; i < (unsigned)(big_end - big_begin); i++) {
        Rec44 *e = big_begin + i;
        if (e->k0 == obj || e->k1 == obj) {
            big_begin[i].w0 = 0;
            big_begin[i].w1 = 0;
            big_begin[i].k0 = 0;
            big_begin[i].k1 = 0;
        }
    }

    if (obj->flag) {
        bool found = false;
        if (rec_count != 0) {
            for (unsigned i = 0; i < rec_count; i++) {
                if (found)
                    rec_begin[i - 1] = rec_begin[i];
                else if (rec_begin[i].key == obj)
                    found = true;
            }
            if (found)
                rec_count = rec_count - 1;
        }
    } else {
        f = obj->info->value;
        unsigned cnt = inf_count;
        if (cnt != 0) {
            unsigned i = 0;
            while (i < inf_count) {
                if (inf_begin[i] == obj)
                    break;
                i++;
            }
            if (i < inf_count) {
                while (i < cnt - 1) {
                    inf_begin[i] = inf_begin[i + 1];
                    i++;
                    cnt = inf_count;
                }
                inf_begin[inf_count - 1] = 0;
                inf_count = inf_count - 1;
            }
        }
        if (f >= maxA) {
            float m = DAT_003f32e0;
            unsigned c = inf_count;
            Item **q = inf_begin;
            for (; c != 0; c--, q++) {
                Info *in = (*q)->info;
                if (m < in->value)
                    m = in->value;
            }
            maxA = m;
        }
        if (f >= maxB) {
            float m = DAT_003f32e0;
            unsigned c = inf_count;
            Item **q = inf_begin;
            for (; c != 0; c--, q++) {
                Info *in = (*q)->info;
                if (m < in->value)
                    m = in->value;
            }
            maxB = m;
        }
    }

    if (removed)
        obj->FUN_slot1();
}

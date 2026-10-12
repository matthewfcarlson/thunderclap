// STATUS: equivalent (tools/equiv.py level 3: 103 inputs, branch coverage 40/40)
// FUN_00226610 @ 0x00226610
extern "C" double sqrt(double);

struct Vec3 {
    float x, y, z;
};

class Chan {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int a, float t, Vec3 *out);
};

class Child {
public:
    Chan *FUN_00288960(unsigned __int64 key);
};

class IdObj {
public:
    virtual void addRef();
    char pad04[0x10 - 4];
    float f10;
    float f14;
    char pad18[0x20 - 0x18];
    int f20;
    Child *FUN_00288ad0(unsigned __int64 key);
};

struct Slot {
    Chan *tran;
    Chan *rot;
};

struct Record {
    IdObj *id;
    Slot slots[64];
    int tail;
};

struct Entry {
    int slot;
    float weight;
};

struct Keys {
    char pad[0x10];
    unsigned count;
    char pad2[0x24 - 0x14];
    unsigned __int64 *keys;
};

class Table {
public:
    char pad0[0x10];
    Keys *keysOwner;
    char pad1[0x28 - 0x14];
    unsigned perRow;
    unsigned rows;
    unsigned count;
    Record records[9];
    Entry entries[1];

    void FUN_00226610(unsigned row, IdObj **ids, float *weights);
};

void Table::FUN_00226610(unsigned row, IdObj **ids, float *weights)
{
    if (row >= rows)
        return;
    Entry *e = entries + perRow * row;
    unsigned m10 = keysOwner->count;
    unsigned k = 0;
    if (perRow == 0)
        return;
    do {
        IdObj *id = ids[k];
        if (id == 0) {
            e->slot = 9;
            if (weights == 0) {
                e->weight = 0.0f;
            } else if (weights[k] >= 0.0f) {
                e->weight = weights[k];
            } else {
                e->weight = 0.0f;
            }
        } else {
            unsigned idx = count;
            unsigned i;
            for (i = 0; i < count; i++) {
                if (records[i].id == id) {
                    idx = i;
                    break;
                }
            }
            if (idx == count && count < 9) {
                records[count].id = ids[k];
                ids[k]->addRef();
                for (unsigned j = 0; j < m10; j++) {
                    unsigned __int64 key = keysOwner->keys[j];
                    Child *child = ids[k]->FUN_00288ad0(key);
                    if (child) {
                        records[count].slots[j].rot = child->FUN_00288960(0x00544f5200544f52ui64);
                        records[count].slots[j].tran = child->FUN_00288960(0x544345564e415254ui64);
                    } else {
                        records[count].slots[j].rot = 0;
                        records[count].slots[j].tran = 0;
                    }
                }
                records[count].tail = ids[k]->f20;
                count++;
            }
            e->slot = idx;
            if (row == 0) {
                e->weight = 0.0f;
            } else if (weights != 0 && weights[k] >= 0.0f) {
                e->weight = weights[k];
            } else {
                Chan *chan = records[idx].slots[0].tran;
                if (chan == 0) {
                    e->weight = 0.0f;
                } else {
                    IdObj *rid = records[idx].id;
                    Vec3 v;
                    v.x = 0.0f;
                    v.y = 0.0f;
                    v.z = 0.0f;
                    float t = rid->f10 - 1.0f;
                    chan->v5(0, t, &v);
                    float len = (float)sqrt((double)(v.z * v.z + v.x * v.x + v.y * v.y));
                    e->weight = len;
                    if (rid->f14 > 0.0f) {
                        double q = t / rid->f14;
                        if (q > 0.0)
                            e->weight = (float)(len / q);
                    }
                }
            }
        }
        k++;
        e++;
    } while (k < perRow);
}

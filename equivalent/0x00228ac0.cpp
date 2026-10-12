// STATUS: equivalent (tools/equiv.py level 3: 80 inputs, branch coverage 34/34)
// FUN_00228ac0 @ 0x00228ac0
extern "C" double sqrt(double);

struct Vec3 {
    float x, y, z;
};

class Anim {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(int a, float t, Vec3 *out);
};

class Channel {
public:
    Anim *FUN_00288960(int tagA, int tagB);
};

class Obj {
public:
    virtual void vfunc_0();
    char pad04[0xc];
    float radius;
    float scale;
    char pad18[8];
    int f20;
    Channel *FUN_00288ad0(int lo, int hi);
};

struct Key {
    int lo;
    int hi;
};

struct Info {
    char pad0[0x10];
    unsigned int count;
    char pad14[0x24 - 0x14];
    Key *keys;
};

struct Entry {
    Anim *trans;
    Channel *rot;
};

struct Slot {
    Obj *obj;
    Entry entries[0x40];
    int f204;
};

class Blender {
public:
    char pad00[0x10];
    Info *info;
    char pad14[0x28 - 0x14];
    unsigned int stride;
    unsigned int maxIndex;
    unsigned int slotCount;
    Slot slots[4];
    float weights[3];
    int rows[1];

    void FUN_00228ac0(unsigned int index, Obj **objs, float weight);
};

void Blender::FUN_00228ac0(unsigned int index, Obj **objs, float weight)
{
    if (index >= maxIndex)
        return;
    if (index == 0)
        weights[0] = 0;
    else
        weights[index] = weight;

    unsigned int n = stride + 1;
    int *row = &rows[index * n];
    unsigned int keyCount = info->count;
    if (n == 0)
        return;

    for (unsigned int k = 0; k < n; k++) {
        Obj *obj = objs[k];
        if (obj == 0) {
            row[k] = 4;
            continue;
        }

        unsigned int count = slotCount;
        unsigned int sel = count;
        for (unsigned int i = 0; i < slotCount; i++) {
            if (slots[i].obj == obj) {
                sel = i;
                break;
            }
        }
        if (sel == count && count < 4) {
            slots[count].obj = objs[k];
            objs[k]->vfunc_0();
            for (unsigned int j = 0; j < keyCount; j++) {
                Channel *ch = objs[k]->FUN_00288ad0(info->keys[j].lo, info->keys[j].hi);
                if (ch != 0) {
                    // FourCC tags: "ROT", "TRAN"/"VECT"
                    slots[slotCount].entries[j].rot = (Channel *)ch->FUN_00288960(0x544f52, 0x544f52);
                    slots[slotCount].entries[j].trans = ch->FUN_00288960(0x4e415254, 0x54434556);
                } else {
                    slots[slotCount].entries[j].rot = 0;
                    slots[slotCount].entries[j].trans = 0;
                }
            }
            slots[slotCount].f204 = objs[k]->f20;
            slotCount++;
        }
        row[k] = sel;

        if (weights[index] < 0.0f) {
            Anim *anim = slots[sel].entries[0].trans;
            if (anim != 0) {
                Obj *o = slots[sel].obj;
                Vec3 out;
                out.x = 0;
                out.y = 0;
                out.z = 0;
                float t = o->radius - 1.0f;
                anim->vfunc_5(0, t, &out);
                float len = (float)sqrt(out.z * out.z + out.x * out.x + out.y * out.y);
                weights[index] = len;
                if (o->scale > 0.0f) {
                    double q = t / o->scale;
                    if (q > 0.0f)
                        weights[index] = len / q;
                }
            }
        }
    }
}

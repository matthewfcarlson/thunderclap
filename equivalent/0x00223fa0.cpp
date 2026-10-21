// STATUS: equivalent (tools/equiv.py level 3: 13934 inputs, branch coverage 34/34)
// FUN_00223fa0 @ 0x00223fa0
#include "compat/ptr.h"
struct Matrix {
    float m[16];
};

// a matrix with extra transform state: 0x54 bytes
struct Pose {
    Matrix matrix;
    char extra[0x14];
    Pose() {}
    void FUN_00221b30(Pose *src);
    void FUN_00221ee0();
};

struct Target_223fa0 {
    char pad0[0x20];
    char b20;
    char b21;
    char b22;
    char b23;
};

struct Layer_223fa0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void Apply(Pose *out, Pose *xform, Target_223fa0 *target, float weight);
};

struct Elem_223fa0 {
    Layer_223fa0 *layer;
    char pad4[0x10];
    int key;        // 0x14
    float factor;   // 0x18
    char pad1c[8];
    float weight;   // 0x24
};

void __cdecl FUN_00223dc0(Elem_223fa0 *first, Elem_223fa0 *last, int depth);

class Blender_223fa0 {
public:
    char pad0[0x10];
    Pose xform;         // 0x10
    Target_223fa0 *target;     // 0x64
    unsigned int count; // 0x68
    Elem_223fa0 elems[16];     // 0x6c
    bool dirty;         // 0x2ec
    void FUN_00223fa0();
};

void Blender_223fa0::FUN_00223fa0()
{
    if (count == 0)
        return;
    if (dirty) {
        Elem_223fa0 *first = elems;
        Elem_223fa0 *last = elems + count;
        dirty = false;
        FUN_00223dc0(first, last, (int)(last - first));
    }
    Pose pose;
    pose.FUN_00221b30(&xform);
    hulk_freg sum = elems[0].weight;
    int key0 = elems[0].key;
    int curKey = key0;
    unsigned int start = 0;
    unsigned int i = 1;
    hulk_freg weight;
    volatile float acc;
    volatile float wt;
    if (count > 1) {
        do {
            int key = elems[i].key;
            if (key != curKey) {
                if (curKey == key0) {
                    weight = 1.0f;
                } else if (sum > 0.0f) {
                    if (sum > 1.0f)
                        weight = 1.0f;
                    else
                        weight = sum;
                } else {
                    weight = 0.0f;
                }
                acc = elems[i].factor * elems[i].weight;
                elems[start].layer->Apply(&pose, &xform, target, weight);
                for (unsigned int j = start + 1; j < i; j++) {
                    hulk_freg p = elems[j].weight * elems[j].factor;
                    hulk_freg t = acc + p;
                    acc = t;
                    if (t > 0.0f)
                        wt = p / acc * weight;
                    else
                        wt = 0.0f;
                    elems[j].layer->Apply(&pose, &xform, target, wt);
                }
                sum = 0.0f;
                curKey = key;
                start = i;
            }
            sum += elems[i].weight;
            i++;
        } while (i < count);
    }
    if (curKey == key0) {
        weight = 1.0f;
    } else if (sum > 0.0f) {
        if (sum > 1.0f)
            weight = 1.0f;
        else
            weight = sum;
    } else {
        weight = 0.0f;
    }
    acc = elems[start].weight * elems[start].factor;
    elems[start].layer->Apply(&pose, &xform, target, weight);
    for (unsigned int j = start + 1; j < count; j++) {
        hulk_freg p = elems[j].weight * elems[j].factor;
        hulk_freg t = acc + p;
        acc = t;
        if (t > 0.0f)
            wt = p / acc * weight;
        else
            wt = 0.0f;
        elems[j].layer->Apply(&pose, &xform, target, wt);
    }
    xform.FUN_00221ee0();
    target->b22 = 1;
    target->b23 = 1;
    target->b20 = 0;
    target->b21 = 1;
}

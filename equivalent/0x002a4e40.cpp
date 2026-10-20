// STATUS: equivalent (tools/equiv.py level 3: 157 inputs, branch coverage 22/24, incomplete)
// FUN_002a4e40 @ 0x002a4e40
#include "compat/ptr.h"
extern "C" void *__cdecl FUN_0008d6d0(hulk_uintptr size);

class Drawable {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void v2();
    virtual void v3();
    virtual Drawable *Clone();
    virtual void SetParent(Drawable *parent);
};

struct Elem_2a4e40 {
    Drawable *obj;
    Drawable **begin;
    Drawable **end;
    int pad;
    void FUN_002a4890();
};

struct ElemVec_2a4e40 {
    Elem_2a4e40 *begin;
    Elem_2a4e40 *end;
    bool FUN_002a4d10(hulk_uintptr count, Elem_2a4e40 *fill);
};

class __declspec(novtable) DrawableBase_2a4e40 {
public:
    virtual void b0();
    char pad04[0x3c];
    void FUN_002a3530(const DrawableBase_2a4e40 *src);
    DrawableBase_2a4e40(const DrawableBase_2a4e40 &src) { FUN_002a3530(&src); }
};

namespace pure3d {
class DrawableContainer : public DrawableBase_2a4e40 {
public:
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    int f40;
    DrawableContainer *self;   // 0x44
    ElemVec_2a4e40 elems;             // 0x48
    DrawableContainer(const DrawableContainer &src);
};
}

pure3d::DrawableContainer::DrawableContainer(const DrawableContainer &src)
    : DrawableBase_2a4e40(src)
{
    f40 = src.f40;
    elems.begin = 0;
    elems.end = 0;

    Elem_2a4e40 fill;
    fill.obj = 0;
    fill.begin = 0;
    fill.end = 0;
    elems.FUN_002a4d10(src.elems.end - src.elems.begin, &fill);
    fill.FUN_002a4890();
    self = this;

    hulk_uintptr count = src.elems.end - src.elems.begin;
    if (count != 0) {
        unsigned int offset = 0;
        do {
            Drawable *clone = ((Elem_2a4e40 *)((char *)src.elems.begin + offset))->obj->Clone();
            Elem_2a4e40 *dst = (Elem_2a4e40 *)((char *)elems.begin + offset);
            if (clone != 0)
                clone->AddRef();
            if (dst->obj != 0)
                dst->obj->Release();
            dst->obj = clone;

            Elem_2a4e40 *se = (Elem_2a4e40 *)((char *)src.elems.begin + offset);
            hulk_uintptr m = se->end - se->begin;
            if (m != 0) {
                Elem_2a4e40 *de = (Elem_2a4e40 *)((char *)elems.begin + offset);
                if (de->begin == 0) {
                    Drawable **p = (Drawable **)FUN_0008d6d0(m * 4);
                    de->begin = p;
                    if (p == 0) {
                        de->begin = 0;
                        de->end = 0;
                    } else {
                        de->end = p + m;
                        for (unsigned int k = 0; k < m; k++)
                            p[k] = 0;
                    }
                }
                for (unsigned int j = 0; j < m; j++) {
                    Drawable *c2 = ((Elem_2a4e40 *)((char *)src.elems.begin + offset))->begin[j]->Clone();
                    c2->SetParent(clone);
                    Drawable **slot = &((Elem_2a4e40 *)((char *)elems.begin + offset))->begin[j];
                    c2->AddRef();
                    if (*slot != 0)
                        (*slot)->Release();
                    *slot = c2;
                }
            }
            offset += 0x10;
            count--;
        } while (count != 0);
    }
}

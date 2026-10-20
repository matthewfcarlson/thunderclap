// STATUS: equivalent (tools/equiv.py level 3: 48 inputs, branch coverage 24/24)
// FUN_0022f230 @ 0x0022f230
#include "compat/ptr.h"
void* FUN_0008d690(hulk_uintptr size);
void FUN_000a9e50(void* p);
void __stdcall FUN_00011520(void* base, int stride, int count, void (*fn)(void*));

struct Matrix4_22f230 {
    char data[0x80];
    Matrix4_22f230* FUN_0022e470(const Matrix4_22f230* src);
};

struct Elem_22f230 {
    unsigned int w0, w1, w2, w3;
};

struct Shape_22f230 {
    unsigned int f00;
    unsigned int f04;
    Matrix4_22f230 m08;
    Matrix4_22f230 m88;
    char flag108;
    char pad109[3];
    unsigned int f10c;
    unsigned int count;
    Elem_22f230* elems;
    unsigned int* extra;
    unsigned int f11c;
    unsigned int f120;
    Shape_22f230* FUN_0022f230(const Shape_22f230* src);
};

Shape_22f230* Shape_22f230::FUN_0022f230(const Shape_22f230* src)
{
    f00 = src->f00;
    f04 = src->f04;
    flag108 = src->flag108;
    m08.FUN_0022e470(&src->m08);
    m88.FUN_0022e470(&src->m88);
    f10c = src->f10c;
    extra = 0;
    unsigned int n = src->count;
    count = n;
    if (n != 0) {
        Elem_22f230* e = (Elem_22f230*)FUN_0008d690(n << 4);
        if (e != 0)
            FUN_00011520(e, 0x10, n, (void (*)(void*))FUN_000a9e50);
        elems = e;
    }
    for (unsigned int i = 0; i < count; i++) {
        Elem_22f230* d = &elems[i];
        const Elem_22f230* s = &src->elems[i];
        d->w0 = s->w0;
        d->w1 = s->w1;
        d->w2 = s->w2;
        d->w3 = s->w3;
    }
    unsigned int m = count;
    if (m >= 4) {
        if (flag108 == 0)
            m -= 3;
    } else if (flag108 == 0) {
        m = 0;
    }
    m++;
    if (src->extra != 0) {
        extra = (unsigned int*)FUN_0008d690(m * 4);
        for (unsigned int i = 0; i < m; i++)
            extra[i] = src->extra[i];
    }
    f11c = src->f11c;
    f120 = src->f120;
    return this;
}

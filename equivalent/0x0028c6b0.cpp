// STATUS: equivalent (tools/equiv.py level 3: 142 inputs, branch coverage 12/12)
// FUN_0028c6b0 @ 0x0028c6b0
#include "compat/ptr.h"
#include "gen/owners.h"
struct Stream {
};

struct Float1Channel_28c6b0 {
    int field_00;
    int field_04;
    int field_08;
    int field_0c;
    int field_10;
    void *field_14;
    void *field_18;
    Float1Channel_28c6b0 *FUN_0028bab0(unsigned x, Float1Channel_28c6b0 *parent);
};

struct Parent_28c6b0 {
};

struct Reader {
    char pad[0x284];
    Stream *stream;
    char FUN_002669f0();
    hulk_intptr FUN_00266a30();
    void FUN_00266be0();
};

extern "C" void *FUN_0008d690(unsigned size);

Float1Channel_28c6b0 * __stdcall FUN_0028c6b0(Reader *r, unsigned unused, Parent_28c6b0 *parent)
{
    unsigned x;
    unsigned a;
    Float1Channel_28c6b0 *node;

    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&x), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&a), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&x), (hulk_intptr)1, 4, (hulk_intptr)1);

    if (parent == 0) {
        void *mem = FUN_0008d690((int)sizeof(Float1Channel_28c6b0));
        node = 0;
        if (mem)
            node = ((Float1Channel_28c6b0 *)mem)->FUN_0028bab0(x, 0);
    } else {
        void *mem = ((void *)((owners::C_2888c0 *)parent)->FUN_002888c0((int)sizeof(Float1Channel_28c6b0), 7));
        node = 0;
        if (mem)
            node = ((Float1Channel_28c6b0 *)mem)->FUN_0028bab0(x, (Float1Channel_28c6b0 *)parent);
    }

    node->field_08 = a;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(node->field_14), (hulk_intptr)x, 2, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(node->field_18), (hulk_intptr)x, 4, (hulk_intptr)1);

    while (r->FUN_002669f0()) {
        if ((char *)r->FUN_00266a30() == ((char*)0x00121110)) {
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&parent), (hulk_intptr)1, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&x), (hulk_intptr)1, 4, (hulk_intptr)1);
            node->field_04 = x;
        }
        r->FUN_00266be0();
    }
    return node;
}

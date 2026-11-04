// STATUS: equivalent (tools/equiv.py level 3: 142 inputs, branch coverage 12/12)
// FUN_0028cfd0 @ 0x0028cfd0
#include "compat/ptr.h"
#include "gen/owners.h"
struct Stream {
};

struct ColourChannel_28cfd0 {
    int field_00;
    int field_04;
    int field_08;
    int field_0c;
    int field_10;
    void *field_14;
    void *field_18;
    ColourChannel_28cfd0 *FUN_0028c470(unsigned x, ColourChannel_28cfd0 *parent);
};

struct Parent_28cfd0 {
};

struct Reader {
    char pad[0x284];
    Stream *stream;
    char FUN_002669f0();
    hulk_intptr FUN_00266a30();
    void FUN_00266be0();
};

extern "C" void *FUN_0008d690(unsigned size);

ColourChannel_28cfd0 * __stdcall FUN_0028cfd0(Reader *r, unsigned unused, Parent_28cfd0 *parent)
{
    unsigned x;
    unsigned a;
    ColourChannel_28cfd0 *node;

    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&x), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&a), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&x), (hulk_intptr)1, 4, (hulk_intptr)1);

    if (parent == 0) {
        void *mem = FUN_0008d690(sizeof(ColourChannel_28cfd0));
        node = 0;
        if (mem)
            node = ((ColourChannel_28cfd0 *)mem)->FUN_0028c470(x, 0);
    } else {
        void *mem = ((void *)((owners::C_2888c0 *)parent)->FUN_002888c0(sizeof(ColourChannel_28cfd0), 7));
        node = 0;
        if (mem)
            node = ((ColourChannel_28cfd0 *)mem)->FUN_0028c470(x, (ColourChannel_28cfd0 *)parent);
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

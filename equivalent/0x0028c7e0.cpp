// STATUS: equivalent (tools/equiv.py level 3: 142 inputs, branch coverage 12/12)
// FUN_0028c7e0 @ 0x0028c7e0
#include "compat/ptr.h"
struct Stream {
    void FUN_002647e0(void *dest, unsigned count, unsigned size, int flag);
};

struct Float2Channel_28c7e0 {
    int field_00;
    int field_04;
    int field_08;
    int field_0c;
    int field_10;
    void *field_14;
    void *field_18;
    Float2Channel_28c7e0 *FUN_0028bba0(unsigned x, Float2Channel_28c7e0 *parent);
};

struct Parent_28c7e0 {
    void *FUN_002888c0(int size, int tag);
};

struct Reader {
    char pad[0x284];
    Stream *stream;
    char FUN_002669f0();
    hulk_intptr FUN_00266a30();
    void FUN_00266be0();
};

void *FUN_0008d690(unsigned size);

Float2Channel_28c7e0 * __stdcall FUN_0028c7e0(Reader *r, unsigned unused, Parent_28c7e0 *parent)
{
    unsigned x;
    unsigned a;
    Float2Channel_28c7e0 *node;

    r->stream->FUN_002647e0(&x, 1, 4, 1);
    r->stream->FUN_002647e0(&a, 1, 4, 1);
    r->stream->FUN_002647e0(&x, 1, 4, 1);

    if (parent == 0) {
        void *mem = FUN_0008d690(0x1c);
        node = 0;
        if (mem)
            node = ((Float2Channel_28c7e0 *)mem)->FUN_0028bba0(x, 0);
    } else {
        void *mem = parent->FUN_002888c0(0x1c, 7);
        node = 0;
        if (mem)
            node = ((Float2Channel_28c7e0 *)mem)->FUN_0028bba0(x, (Float2Channel_28c7e0 *)parent);
    }

    node->field_08 = a;
    r->stream->FUN_002647e0(node->field_14, x, 2, 1);
    r->stream->FUN_002647e0(node->field_18, x * 2, 4, 1);

    while (r->FUN_002669f0()) {
        if ((char *)r->FUN_00266a30() == ((char*)0x00121110)) {
            r->stream->FUN_002647e0(&parent, 1, 4, 1);
            r->stream->FUN_002647e0(&x, 1, 4, 1);
            node->field_04 = x;
        }
        r->FUN_00266be0();
    }
    return node;
}

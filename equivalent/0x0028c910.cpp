// STATUS: equivalent (tools/equiv.py level 3: 3054 inputs, branch coverage 42/42)
// FUN_0028c910 @ 0x0028c910
#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" void *FUN_0008d690(unsigned int size);

struct Stream {
};

struct Reader {
    char pad[0x284];
    Stream *stream;
    int FUN_00266c30();
    char FUN_002669f0();
    hulk_intptr FUN_00266a30();
    void FUN_00266be0();
};

struct Obj_28c910 {
    int pad0;
    int field4;
    int field8;
    char padc[8];
    short *data14;
};
struct Vector3DOFChannel_28c910 : public Obj_28c910 {
    int *data18;
    Vector3DOFChannel_28c910 *FUN_0028bf20(int id, Obj_28c910 *existing);
};
struct ObjA_28c910 : public Obj_28c910 {
    int field18;
    int field1c, field20, field24;
    int *data28;
    ObjA_28c910 *FUN_0028bd40(int id, Obj_28c910 *existing);
};
struct Vector2DOFChannel_28c910 : public ObjA_28c910 {
    Vector2DOFChannel_28c910 *FUN_0028be20(int id, Obj_28c910 *existing);
};

union Arg1_28c910 { Reader *reader; int id; short count16; };
union Arg3_28c910 { Obj_28c910 *obj; int value; };

Obj_28c910 *__stdcall FUN_0028c910(Arg1_28c910 a1, int a2, Arg3_28c910 a3) {
    Reader *r = a1.reader;
    struct { int l10, l14, l18, l1c, l20, l24, l28; } f;
    Obj_28c910 *obj;
    int id;
    switch (r->FUN_00266c30()) {
    case 0x121102:
        ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&a1.id), (hulk_intptr)1, 4, (hulk_intptr)1);
        ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.l1c), (hulk_intptr)1, 4, (hulk_intptr)1);
        ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&a1.count16), (hulk_intptr)1, 2, (hulk_intptr)1);
        {
            int s = a1.count16;
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.l20), (hulk_intptr)3, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&a1.id), (hulk_intptr)1, 4, (hulk_intptr)1);
            id = a1.id;
            ObjA_28c910 *o;
            if (a3.obj == 0) {
                void *mem = FUN_0008d690((int)sizeof(ObjA_28c910));
                o = 0;
                if (mem)
                    o = ((ObjA_28c910 *)mem)->FUN_0028bd40(id, 0);
            } else {
                o = (ObjA_28c910 *)((void *)((owners::C_2888c0 *)(Obj_28c910 *)(a3.obj))->FUN_002888c0((int)sizeof(ObjA_28c910), 7));
                if (o)
                    o = o->FUN_0028bd40(id, a3.obj);
            }
            o->field8 = f.l1c;
            o->field18 = s;
            o->field1c = f.l20;
            o->field20 = f.l24;
            o->field24 = f.l28;
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(o->data14), (hulk_intptr)id, 2, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(o->data28), (hulk_intptr)id, 4, (hulk_intptr)1);
            obj = o;
        }
        break;
    case 0x121103:
        ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&a1.id), (hulk_intptr)1, 4, (hulk_intptr)1);
        ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.l10), (hulk_intptr)1, 4, (hulk_intptr)1);
        ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&a1.count16), (hulk_intptr)1, 2, (hulk_intptr)1);
        {
            int s = a1.count16;
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.l14), (hulk_intptr)1, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.l18), (hulk_intptr)1, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.l1c), (hulk_intptr)1, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&a1.id), (hulk_intptr)1, 4, (hulk_intptr)1);
            id = a1.id;
            Vector2DOFChannel_28c910 *o;
            if (a3.obj == 0) {
                void *mem = FUN_0008d690((int)sizeof(Vector2DOFChannel_28c910));
                o = 0;
                if (mem)
                    o = ((Vector2DOFChannel_28c910 *)mem)->FUN_0028be20(id, 0);
            } else {
                o = (Vector2DOFChannel_28c910 *)((void *)((owners::C_2888c0 *)(Obj_28c910 *)(a3.obj))->FUN_002888c0((int)sizeof(Vector2DOFChannel_28c910), 7));
                if (o)
                    o = o->FUN_0028be20(id, a3.obj);
            }
            o->field8 = f.l10;
            o->field18 = s;
            o->field1c = f.l14;
            o->field20 = f.l18;
            o->field24 = f.l1c;
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(o->data14), (hulk_intptr)id, 2, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(o->data28), (hulk_intptr)(id * 2), 4, (hulk_intptr)1);
            obj = o;
        }
        break;
    case 0x121104:
        ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&a1.id), (hulk_intptr)1, 4, (hulk_intptr)1);
        ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.l10), (hulk_intptr)1, 4, (hulk_intptr)1);
        ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&a1.id), (hulk_intptr)1, 4, (hulk_intptr)1);
        {
            id = a1.id;
            Vector3DOFChannel_28c910 *o;
            if (a3.obj == 0) {
                void *mem = FUN_0008d690((int)sizeof(Vector3DOFChannel_28c910));
                o = 0;
                if (mem)
                    o = ((Vector3DOFChannel_28c910 *)mem)->FUN_0028bf20(id, 0);
            } else {
                o = (Vector3DOFChannel_28c910 *)((void *)((owners::C_2888c0 *)(Obj_28c910 *)(a3.obj))->FUN_002888c0((int)sizeof(Vector3DOFChannel_28c910), 7));
                if (o)
                    o = o->FUN_0028bf20(id, a3.obj);
            }
            o->field8 = f.l10;
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(o->data14), (hulk_intptr)id, 2, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(o->data18), (hulk_intptr)(id * 3), 4, (hulk_intptr)1);
            obj = o;
        }
        break;
    default:
        return 0;
    }
    while (r->FUN_002669f0()) {
        if (r->FUN_00266a30() == 0x121110) {
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&a1.id), (hulk_intptr)1, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&a3.value), (hulk_intptr)1, 4, (hulk_intptr)1);
            obj->field4 = a3.value;
        }
        r->FUN_00266be0();
    }
    return obj;
}

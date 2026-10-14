// STATUS: equivalent (tools/equiv.py level 3: 3054 inputs, branch coverage 42/42)
// FUN_0028c910 @ 0x0028c910
void *FUN_0008d690(unsigned int size);

struct Stream {
    void FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Reader {
    char pad[0x284];
    Stream *stream;
    int FUN_00266c30();
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

struct Obj_28c910 {
    int pad0;
    int field4;
    int field8;
    char padc[8];
    short *data14;
    void *FUN_002888c0(int size, int tag);
};
struct ObjC_28c910 : public Obj_28c910 {
    int *data18;
    ObjC_28c910 *FUN_0028bf20(int id, Obj_28c910 *existing);
};
struct ObjA_28c910 : public Obj_28c910 {
    int field18;
    int field1c, field20, field24;
    int *data28;
    ObjA_28c910 *FUN_0028bd40(int id, Obj_28c910 *existing);
};
struct ObjB_28c910 : public ObjA_28c910 {
    ObjB_28c910 *FUN_0028be20(int id, Obj_28c910 *existing);
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
        r->stream->FUN_002647e0(&a1.id, 1, 4, 1);
        r->stream->FUN_002647e0(&f.l1c, 1, 4, 1);
        r->stream->FUN_002647e0(&a1.count16, 1, 2, 1);
        {
            int s = a1.count16;
            r->stream->FUN_002647e0(&f.l20, 3, 4, 1);
            r->stream->FUN_002647e0(&a1.id, 1, 4, 1);
            id = a1.id;
            ObjA_28c910 *o;
            if (a3.obj == 0) {
                void *mem = FUN_0008d690(0x2c);
                o = 0;
                if (mem)
                    o = ((ObjA_28c910 *)mem)->FUN_0028bd40(id, 0);
            } else {
                o = (ObjA_28c910 *)a3.obj->FUN_002888c0(0x2c, 7);
                if (o)
                    o = o->FUN_0028bd40(id, a3.obj);
            }
            o->field8 = f.l1c;
            o->field18 = s;
            o->field1c = f.l20;
            o->field20 = f.l24;
            o->field24 = f.l28;
            r->stream->FUN_002647e0(o->data14, id, 2, 1);
            r->stream->FUN_002647e0(o->data28, id, 4, 1);
            obj = o;
        }
        break;
    case 0x121103:
        r->stream->FUN_002647e0(&a1.id, 1, 4, 1);
        r->stream->FUN_002647e0(&f.l10, 1, 4, 1);
        r->stream->FUN_002647e0(&a1.count16, 1, 2, 1);
        {
            int s = a1.count16;
            r->stream->FUN_002647e0(&f.l14, 1, 4, 1);
            r->stream->FUN_002647e0(&f.l18, 1, 4, 1);
            r->stream->FUN_002647e0(&f.l1c, 1, 4, 1);
            r->stream->FUN_002647e0(&a1.id, 1, 4, 1);
            id = a1.id;
            ObjB_28c910 *o;
            if (a3.obj == 0) {
                void *mem = FUN_0008d690(0x2c);
                o = 0;
                if (mem)
                    o = ((ObjB_28c910 *)mem)->FUN_0028be20(id, 0);
            } else {
                o = (ObjB_28c910 *)a3.obj->FUN_002888c0(0x2c, 7);
                if (o)
                    o = o->FUN_0028be20(id, a3.obj);
            }
            o->field8 = f.l10;
            o->field18 = s;
            o->field1c = f.l14;
            o->field20 = f.l18;
            o->field24 = f.l1c;
            r->stream->FUN_002647e0(o->data14, id, 2, 1);
            r->stream->FUN_002647e0(o->data28, id * 2, 4, 1);
            obj = o;
        }
        break;
    case 0x121104:
        r->stream->FUN_002647e0(&a1.id, 1, 4, 1);
        r->stream->FUN_002647e0(&f.l10, 1, 4, 1);
        r->stream->FUN_002647e0(&a1.id, 1, 4, 1);
        {
            id = a1.id;
            ObjC_28c910 *o;
            if (a3.obj == 0) {
                void *mem = FUN_0008d690(0x1c);
                o = 0;
                if (mem)
                    o = ((ObjC_28c910 *)mem)->FUN_0028bf20(id, 0);
            } else {
                o = (ObjC_28c910 *)a3.obj->FUN_002888c0(0x1c, 7);
                if (o)
                    o = o->FUN_0028bf20(id, a3.obj);
            }
            o->field8 = f.l10;
            r->stream->FUN_002647e0(o->data14, id, 2, 1);
            r->stream->FUN_002647e0(o->data18, id * 3, 4, 1);
            obj = o;
        }
        break;
    default:
        return 0;
    }
    while (r->FUN_002669f0()) {
        if (r->FUN_00266a30() == 0x121110) {
            r->stream->FUN_002647e0(&a1.id, 1, 4, 1);
            r->stream->FUN_002647e0(&a3.value, 1, 4, 1);
            obj->field4 = a3.value;
        }
        r->FUN_00266be0();
    }
    return obj;
}

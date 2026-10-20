// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 36/36)
// FUN_002be720 @ 0x002be720
// FUN_002be720 @ 0x002be720
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "compat/ptr.h"
#include "decls/data/engine/pure3d.h"
#include "gen/pure3d.h"

extern "C" int atexit(void (*)());

struct Rec_2be720 {
    char pad0[0x10];
    int lo;
    int hi;
};

struct Row_2be720 {
    Rec_2be720 recs[1];
};

struct ImageConverter_nv_2be720 {
    void FUN_002de230();
};

class Source_2be720 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17();
    virtual int v18(int arg);
    char pad04[0x14];
    int kind;
    char pad1c[4];
    int f20;
    char pad24[4];
    char f28;
    char f29;
};

class Obj_2be720 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15();
    virtual void v16(int arg);
    char pad04[0x1c];
    int f20;
    char pad24[4];
    char f28;
    char f29;
};

class ObjSmall : public Obj_2be720 {
public:
    ObjSmall *FUN_002bffc0();
    char pad2a[0x6];
};

class ObjBig : public Obj_2be720 {
public:
    ObjBig *FUN_002bfcb0();
    char pad2a[0x40e];
};

void *thunk_FUN_0008d690(unsigned int size);
void *FUN_00266e00(int pool, int size);
void *FUN_0008d6d0(hulk_uintptr size);
int FUN_00267090(void *p);
void FUN_003647b0();

class Loader_2be720 {
public:
    char pad0[0x40];
    int count;
    void *f44;
    void *f48;
    char pad4c[0x10];
    int f5c;
    char pad60[0xc];
    int f6c;
    char pad70[0x30];
    char useSmall;

    int FUN_002bd570(Row_2be720 **rows, int *rowCount, int *recCount);
    void FUN_002bd790(int idx, Rec_2be720 *rec, int lo, int hi, Source_2be720 *src, Obj_2be720 *obj, pure3d::ImageConverter *aux);
    void FUN_002bdaf0(int idx, Rec_2be720 *rec, int lo, int hi);

    int Load(Source_2be720 *src, pure3d::ImageConverter *aux);
};

int Loader_2be720::Load(Source_2be720 *src, pure3d::ImageConverter *aux)
{
    int rowCount;
    int recCount;
    Row_2be720 **rows = 0;

    count = FUN_002bd570(0, &rowCount, &recCount);
    rows = (Row_2be720 **)FUN_00266e00(1, rowCount * 4);
    for (int i = 0; i < rowCount; i++)
        rows[i] = (Row_2be720 *)FUN_00266e00(1, recCount * 24);
    FUN_002bd570(rows, &rowCount, &recCount);

    f48 = FUN_0008d6d0(count * 4);
    f44 = FUN_0008d6d0(count * 4 * 3 * 8);

    if (aux == 0) {
        if ((DAT_00554bd4 & 1) == 0) {
            DAT_00554bd4 |= 1;
            ((ImageConverter_nv_2be720*)&((*(pure3d::ImageConverter*)&DAT_00554bd0)))->FUN_002de230();
            atexit(FUN_003647b0);
        }
        aux = ((pure3d::ImageConverter*)&DAT_00554bd0);
    }

    Obj_2be720 *obj = 0;
    if (useSmall) {
        ObjSmall *mem = (ObjSmall *)thunk_FUN_0008d690(0x30);
        if (mem)
            obj = mem->FUN_002bffc0();
        obj->f29 = src->f29;
    } else if (src->kind == 8) {
        ObjBig *mem = (ObjBig *)thunk_FUN_0008d690(0x438);
        if (mem)
            obj = mem->FUN_002bfcb0();
        Source_2be720 *s = src;
        Obj_2be720 *o = obj;
        o->v16(s->v18(0x100));
    } else if (src->kind == 0x20) {
        ObjSmall *mem = (ObjSmall *)thunk_FUN_0008d690(0x30);
        if (mem)
            obj = mem->FUN_002bffc0();
        obj->f29 = src->f29;
    }

    obj->f28 = src->f28;
    obj->f20 = src->f20;
    obj->v0();

    int step = f5c * 2;
    int index = 0;
    Row_2be720 **row = rows;
    for (int r = rowCount; r > 0; r--) {
        int off = 0;
        for (int c = recCount; c > 0; c--) {
            Rec_2be720 *rec = (Rec_2be720 *)((char *)*row + off);
            int lo = rec->hi;
            int limit = f6c;
            if (lo > limit)
                lo += step;
            else
                lo = DAT_004d0898;
            int hi = rec->lo;
            if (hi > limit)
                hi += step;
            else
                hi = DAT_004d0898;
            FUN_002bd790(index, rec, lo, hi, src, obj, aux);
            FUN_002bdaf0(index, (Rec_2be720 *)((char *)*row + off), lo, hi);
            index++;
            off += 0x18;
        }
        row++;
    }

    obj->v1();
    for (int i = 0; i < rowCount; i++)
        FUN_00267090(rows[i]);
    return FUN_00267090(rows);
}

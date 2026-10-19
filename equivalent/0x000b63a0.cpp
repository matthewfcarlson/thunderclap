// STATUS: equivalent (tools/equiv.py level 3: 1207 inputs, branch coverage 10/10)
// FUN_000b63a0 @ 0x000b63a0
// cl-flags: /GS
extern char DAT_0049dba4[];
extern char DAT_0049dbbc[];

class FEObject {
public:
    virtual void vfunc_0();
};

class TextSelector : public FEObject {
public:
    virtual void vfunc_1();
};

class Manager_b63a0 {
public:
    int FUN_000f7240(int a, int b);
};

struct Label_b63a0 {
    char data[0x24];
    void FUN_000f7930();
    void FUN_000f7960();
    void FUN_000f7a10(int index, int flag);
    void FUN_000f8500(const char *name, Manager_b63a0 *manager, char flag);
};

struct Name_b63a0 {
    const char *FUN_0027b010();
};

struct Row_b63a0 {
    char pad0[8];
    int keyA;
    int keyB;
    char pad10[0x38 - 0x10];
    int value;
};

struct Table_b63a0 {
    char pad0[0xc80];
    int count;
    Row_b63a0 *FUN_00090250(int index);
};

struct RowName {
    char pad0[8];
    Name_b63a0 name;
};

class Owner_b63a0 {
public:
    char pad0[0x50];
    Table_b63a0 *table;
    void FUN_000b63a0();
};

class Selector_b63a0 : public TextSelector {
public:
    virtual void vfunc_2(); virtual void vfunc_3();
};

FEObject *__cdecl FUN_000fc260(const char *name);
Manager_b63a0 *__cdecl FUN_000fc1b0();
void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
int __cdecl FUN_000964a0(char *dst, int size, const char *fmt, ...);

class SelectorView_b63a0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18();
    virtual void v19(Label_b63a0 *text, int a, int b);
    virtual void v20(int index, Label_b63a0 *text);
    void FUN_000e36c0();
};

void Owner_b63a0::FUN_000b63a0()
{
    if (table) {
        SelectorView_b63a0 *sel = (SelectorView_b63a0 *)FUN_00344e74(FUN_000fc260("stats_table"), 0, DAT_0049dba4, DAT_0049dbbc, 0);
        if (sel) {
            Label_b63a0 label;
            char number[16];
            label.FUN_000f7930();
            sel->FUN_000e36c0();
            for (int i = 1; i < table->count; i++) {
                int value = table->FUN_00090250(i)->value;
                Row_b63a0 *row = table->FUN_00090250(i);
                int ka = row->keyA;
                int kb = row->keyB;
                int idx = FUN_000fc1b0()->FUN_000f7240(ka, kb);
                if (idx != -1) {
                    label.FUN_000f7a10(idx, 0);
                } else {
                    Manager_b63a0 *m = FUN_000fc1b0();
                    RowName *rn = (RowName *)table->FUN_00090250(i);
                    label.FUN_000f8500(rn->name.FUN_0027b010(), m, 1);
                }
                sel->v19(&label, 0, 0);
                FUN_000964a0(number, 0x10, "%d", value);
                label.FUN_000f8500(number, FUN_000fc1b0(), 0);
                sel->v20(i - 1, &label);
            }
            sel->v3();
            label.FUN_000f7960();
        }
    }
}

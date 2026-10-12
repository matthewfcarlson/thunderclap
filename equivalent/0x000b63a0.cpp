// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 10/10)
// FUN_000b63a0 @ 0x000b63a0
extern char DAT_0049dba4[];
extern char DAT_0049dbbc[];
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);

class FEObject {
public:
    virtual void vfunc_0();
};

class TextSelector : public FEObject {
public:
    virtual void vfunc_1();
};

class Manager {
public:
    int FUN_000f7240(int a, int b);
};

struct Label {
    char data[0x24];
    void FUN_000f7930();
    void FUN_000f7960();
    void FUN_000f7a10(int index, int flag);
    void FUN_000f8500(const char *name, Manager *manager, char flag);
};

struct Name {
    const char *FUN_0027b010();
};

struct Row {
    char pad0[8];
    int keyA;
    int keyB;
    char pad10[0x38 - 0x10];
    int value;
};

struct Table {
    char pad0[0xc80];
    int count;
    Row *FUN_00090250(int index);
};

struct RowName {
    char pad0[8];
    Name name;
};

class Owner {
public:
    char pad0[0x50];
    Table *table;
    void FUN_000b63a0();
};

class Selector : public TextSelector {
public:
    virtual void vfunc_2(); virtual void vfunc_3();
};

FEObject *__cdecl FUN_000fc260(const char *name);
Manager *__cdecl FUN_000fc1b0();
void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
int __cdecl FUN_000964a0(char *dst, int size, const char *fmt, ...);

class SelectorView {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18();
    virtual void v19(Label *text, int a, int b);
    virtual void v20(int index, Label *text);
    void FUN_000e36c0();
};

void Owner::FUN_000b63a0()
{
    unsigned int cookie = DAT_004d9968;
    if (table) {
        SelectorView *sel = (SelectorView *)FUN_00344e74(FUN_000fc260("stats_table"), 0, DAT_0049dba4, DAT_0049dbbc, 0);
        if (sel) {
            Label label;
            char number[16];
            label.FUN_000f7930();
            sel->FUN_000e36c0();
            for (int i = 1; i < table->count; i++) {
                int value = table->FUN_00090250(i)->value;
                Row *row = table->FUN_00090250(i);
                int ka = row->keyA;
                int kb = row->keyB;
                int idx = FUN_000fc1b0()->FUN_000f7240(ka, kb);
                if (idx != -1) {
                    label.FUN_000f7a10(idx, 0);
                } else {
                    Manager *m = FUN_000fc1b0();
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
    __security_check_cookie(cookie);
}

// STATUS: equivalent (tools/equiv.py level 3: 13003 inputs, branch coverage 41/42, incomplete)
// FUN_002218d0 @ 0x002218d0
// FUN_002218d0 @ 0x002218d0
struct Operand_2218d0 {
    int kind;
    int val;
    int f08;
    int f0c;
    int f10;
};

struct Table_2218d0 {
    char pad00[0xc];
    unsigned int* words;
};

struct Pool_2218d0 {
    char pad00[8];
    int handle;
};

struct Ctx_2218d0 {
    Table_2218d0* table;
    char pad04[8];
    Pool_2218d0* pool;
    char pad10[0x14];
    int counter;
    char pad28[0xc];
    unsigned char minReg;
};

void* FUN_00221200(Ctx_2218d0* c, Operand_2218d0* op);
void FUN_00220d90(Ctx_2218d0* c, Operand_2218d0* op);
extern "C" int __cdecl FUN_00221190(void *, void *);
extern "C" void __cdecl FUN_00221110(void *, void *);
void FUN_002207c0(Ctx_2218d0* c, int* dst, int src);
extern "C" int __cdecl FUN_00220b20(void *, unsigned int, unsigned int);
// equiv-conv: FUN_00221860 eax ecx edx edi stack
void FUN_00221860(void* extra, void* self, int sel, Operand_2218d0* a, Ctx_2218d0* c);

extern "C" void FUN_002218d0(void * c, int sel, void * a_, void * b)
{
    Operand_2218d0 * a = (Operand_2218d0 *)a_;
    if (sel == 5) {
        if (((Operand_2218d0 *)b)->f0c != ((Operand_2218d0 *)b)->f10)
            FUN_00221190((Ctx_2218d0 *)((Ctx_2218d0 *)c), (Operand_2218d0 *)((Operand_2218d0 *)b));
        else
            FUN_00220d90(((Ctx_2218d0 *)c), ((Operand_2218d0 *)b));
        if (((Operand_2218d0 *)b)->kind == 0xa) {
            Table_2218d0* tab = ((Ctx_2218d0 *)c)->table;
            if ((tab->words[((Operand_2218d0 *)b)->val] & 0x3f) == 0x13) {
                if (a->kind == 0xb) {
                    if (a->val >= (int)((Ctx_2218d0 *)c)->minReg && a->val < 0xfa)
                        ((Ctx_2218d0 *)c)->counter--;
                }
                unsigned int* words = tab->words;
                unsigned int old = words[((Operand_2218d0 *)b)->val];
                words[((Operand_2218d0 *)b)->val] = old ^ (((unsigned int)a->val << 15 ^ old) & 0xff8000);
                a->kind = ((Operand_2218d0 *)b)->kind;
                a->val = ((Operand_2218d0 *)b)->val;
                return;
            }
        }
        FUN_00221110((Ctx_2218d0 *)((Ctx_2218d0 *)c), (Operand_2218d0 *)((Operand_2218d0 *)b));
        if (((Operand_2218d0 *)b)->kind == 0xb) {
            if (((Operand_2218d0 *)b)->val >= (int)((Ctx_2218d0 *)c)->minReg && ((Operand_2218d0 *)b)->val < 0xfa)
                ((Ctx_2218d0 *)c)->counter--;
        }
        if (a->kind == 0xb) {
            if (a->val >= (int)((Ctx_2218d0 *)c)->minReg && a->val < 0xfa)
                ((Ctx_2218d0 *)c)->counter--;
        }
        a->val = FUN_00220b20((Ctx_2218d0 *)((Ctx_2218d0 *)c), (int)(((a->val << 9 | ((Operand_2218d0 *)b)->val) << 6) | 0x13), (int)(((Ctx_2218d0 *)c)->pool->handle));
        a->kind = 0xa;
        return;
    }
    if (sel == 12) {
        FUN_00220d90(((Ctx_2218d0 *)c), ((Operand_2218d0 *)b));
        FUN_002207c0(((Ctx_2218d0 *)c), &a->f10, ((Operand_2218d0 *)b)->f10);
        a->kind = ((Operand_2218d0 *)b)->kind;
        a->val = ((Operand_2218d0 *)b)->val;
        a->f08 = ((Operand_2218d0 *)b)->f08;
        a->f0c = ((Operand_2218d0 *)b)->f0c;
        return;
    }
    if (sel == 13) {
        FUN_00220d90(((Ctx_2218d0 *)c), ((Operand_2218d0 *)b));
        FUN_002207c0(((Ctx_2218d0 *)c), &a->f0c, ((Operand_2218d0 *)b)->f0c);
        a->kind = ((Operand_2218d0 *)b)->kind;
        a->val = ((Operand_2218d0 *)b)->val;
        a->f08 = ((Operand_2218d0 *)b)->f08;
        a->f10 = ((Operand_2218d0 *)b)->f10;
        return;
    }
    void* self = FUN_00221200(((Ctx_2218d0 *)c), a);
    void* extra = FUN_00221200(((Ctx_2218d0 *)c), ((Operand_2218d0 *)b));
    if (((Operand_2218d0 *)b)->kind == 0xb) {
        if (((Operand_2218d0 *)b)->val >= (int)((Ctx_2218d0 *)c)->minReg && ((Operand_2218d0 *)b)->val < 0xfa)
            ((Ctx_2218d0 *)c)->counter--;
    }
    if (a->kind == 0xb) {
        if (a->val >= (int)((Ctx_2218d0 *)c)->minReg && a->val < 0xfa)
            ((Ctx_2218d0 *)c)->counter--;
    }
    FUN_00221860(extra, self, sel, a, ((Ctx_2218d0 *)c));
}

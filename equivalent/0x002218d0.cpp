// STATUS: equivalent (tools/equiv.py level 3: 191 inputs, branch coverage 41/42, incomplete)
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
void FUN_00221190(Ctx_2218d0* c, Operand_2218d0* op);
void FUN_00221110(Ctx_2218d0* c, Operand_2218d0* op);
void FUN_002207c0(Ctx_2218d0* c, int* dst, int src);
int FUN_00220b20(Ctx_2218d0* c, int a, int b);
// equiv-conv: FUN_00221860 eax ecx edx edi stack
void FUN_00221860(void* extra, void* self, int sel, Operand_2218d0* a, Ctx_2218d0* c);

void FUN_002218d0(Ctx_2218d0* c, int sel, Operand_2218d0* a, Operand_2218d0* b)
{
    if (sel == 5) {
        if (b->f0c != b->f10)
            FUN_00221190(c, b);
        else
            FUN_00220d90(c, b);
        if (b->kind == 0xa) {
            Table_2218d0* tab = c->table;
            if ((tab->words[b->val] & 0x3f) == 0x13) {
                if (a->kind == 0xb) {
                    if (a->val >= (int)c->minReg && a->val < 0xfa)
                        c->counter--;
                }
                unsigned int* words = tab->words;
                unsigned int old = words[b->val];
                words[b->val] = old ^ (((unsigned int)a->val << 15 ^ old) & 0xff8000);
                a->kind = b->kind;
                a->val = b->val;
                return;
            }
        }
        FUN_00221110(c, b);
        if (b->kind == 0xb) {
            if (b->val >= (int)c->minReg && b->val < 0xfa)
                c->counter--;
        }
        if (a->kind == 0xb) {
            if (a->val >= (int)c->minReg && a->val < 0xfa)
                c->counter--;
        }
        a->val = FUN_00220b20(c, ((a->val << 9 | b->val) << 6) | 0x13, c->pool->handle);
        a->kind = 0xa;
        return;
    }
    if (sel == 12) {
        FUN_00220d90(c, b);
        FUN_002207c0(c, &a->f10, b->f10);
        a->kind = b->kind;
        a->val = b->val;
        a->f08 = b->f08;
        a->f0c = b->f0c;
        return;
    }
    if (sel == 13) {
        FUN_00220d90(c, b);
        FUN_002207c0(c, &a->f0c, b->f0c);
        a->kind = b->kind;
        a->val = b->val;
        a->f08 = b->f08;
        a->f10 = b->f10;
        return;
    }
    void* self = FUN_00221200(c, a);
    void* extra = FUN_00221200(c, b);
    if (b->kind == 0xb) {
        if (b->val >= (int)c->minReg && b->val < 0xfa)
            c->counter--;
    }
    if (a->kind == 0xb) {
        if (a->val >= (int)c->minReg && a->val < 0xfa)
            c->counter--;
    }
    FUN_00221860(extra, self, sel, a, c);
}

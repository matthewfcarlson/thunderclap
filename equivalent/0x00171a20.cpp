// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// hulkfight::motion::PushOutAction::vfunc_3 @ 0x00171a20
struct Table { char pad[0xc]; unsigned int limit; unsigned int FUN_002843a0(unsigned int lo, unsigned int hi); };
struct Layers { char pad[0x64]; Table *table; };
struct Ctx {
    void *FUN_00059a30();
    Layers *FUN_00059a40();
};
struct Owner { Ctx *FUN_000592a0(); };
struct Data { char pad[0x18]; unsigned int keyLo; unsigned int keyHi; };

class PushOutAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x1c - 4];
    Data *data;
    Owner *owner;
    unsigned int index;
};

bool PushOutAction::vfunc_3(int a, int b)
{
    Ctx *ctx = owner->FUN_000592a0();
    if (ctx == 0)
        return false;
    if (ctx->FUN_00059a30() == 0)
        return false;
    Layers *layers = ctx->FUN_00059a40();
    if (layers == 0)
        return false;
    Table *t = layers->table;
    unsigned int lo = data->keyLo;
    unsigned int hi = data->keyHi;
    if ((lo | hi) != 0) {
        index = t->FUN_002843a0(lo, hi);
        if (index == 0xffff)
            index = 0;
    }
    return index < t->limit;
}

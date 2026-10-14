// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// hulkfight::motion::PushOutAction::vfunc_3 @ 0x00171a20
struct Table_171a20 { char pad[0xc]; unsigned int limit; unsigned int FUN_002843a0(unsigned int lo, unsigned int hi); };
struct Layers_171a20 { char pad[0x64]; Table_171a20 *table; };
struct Ctx_171a20 {
    void *FUN_00059a30();
    Layers_171a20 *FUN_00059a40();
};
struct Owner_171a20 { Ctx_171a20 *FUN_000592a0(); };
struct Data_171a20 { char pad[0x18]; unsigned int keyLo; unsigned int keyHi; };

class PushOutAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x1c - 4];
    Data_171a20 *data;
    Owner_171a20 *owner;
    unsigned int index;
};

bool PushOutAction::vfunc_3(int a, int b)
{
    Ctx_171a20 *ctx = owner->FUN_000592a0();
    if (ctx == 0)
        return false;
    if (ctx->FUN_00059a30() == 0)
        return false;
    Layers_171a20 *layers = ctx->FUN_00059a40();
    if (layers == 0)
        return false;
    Table_171a20 *t = layers->table;
    unsigned int lo = data->keyLo;
    unsigned int hi = data->keyHi;
    if ((lo | hi) != 0) {
        index = t->FUN_002843a0(lo, hi);
        if (index == 0xffff)
            index = 0;
    }
    return index < t->limit;
}

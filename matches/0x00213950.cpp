typedef unsigned int u32;
struct Obj {
    u32 pad[2];
    u32* stack;
};
struct Sub {
    char pad[6];
    unsigned char flag;
};
struct Result {
    int kind;
    Sub* sub;
};
struct Helper {};
Result* __fastcall FUN_00212bb0(Helper*, Obj*);
int __cdecl FUN_00213950(Obj* p, Helper* h) {
    int ret = 0;
    Result* r = FUN_00212bb0(h, p);
    p->stack = p->stack - 2;
    u32* q = p->stack;
    if (r->kind == 6) {
        Sub* s = r->sub;
        if (0 == s->flag) {
            ret = 1;
            *(u32*)((char*)s + 0x10) = q[0];
            *(u32*)((char*)s + 0x14) = q[1];
        }
    }
    return ret;
}

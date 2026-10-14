typedef unsigned int u32_213950;
struct Obj_213950 {
    u32_213950 pad[2];
    u32_213950* stack;
};
struct Sub_213950 {
    char pad[6];
    unsigned char flag;
};
struct Result_213950 {
    int kind;
    Sub_213950* sub;
};
struct Helper_213950 {};
Result_213950* __fastcall FUN_00212bb0(Helper_213950*, Obj_213950*);
int __cdecl FUN_00213950(Obj_213950* p, Helper_213950* h) {
    int ret = 0;
    Result_213950* r = FUN_00212bb0(h, p);
    p->stack = p->stack - 2;
    u32_213950* q = p->stack;
    if (r->kind == 6) {
        Sub_213950* s = r->sub;
        if (0 == s->flag) {
            ret = 1;
            *(u32_213950*)((char*)s + 0x10) = q[0];
            *(u32_213950*)((char*)s + 0x14) = q[1];
        }
    }
    return ret;
}

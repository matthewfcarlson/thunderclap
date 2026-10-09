struct Obj {
    char pad0[0x47];
    unsigned char value;
};
struct State {
    Obj* obj;
    char pad4[8];
    const char* context;
    char pad10[0x14];
    int level;
};
void __cdecl FUN_0021b060(const char*, const char*);
void __cdecl FUN_00220850(State* s, int amount) {
    int sum = s->level + amount;
    if (sum > (int)s->obj->value) {
        if (sum >= 0xfa)
            FUN_0021b060(s->context, "function or expression too complex");
        s->obj->value = (unsigned char)sum;
    }
    s->level += amount;
}
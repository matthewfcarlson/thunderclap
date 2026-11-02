struct Obj_220850 {
    char pad0[0x47];
    unsigned char value;
};
struct State_220850 {
    Obj_220850* obj;
    char pad4[8];
    const char* context;
    char pad10[0x14];
    int level;
};
void __cdecl FUN_0021b060(const char*, const char*);
extern "C" void __cdecl FUN_00220850(void * s, int amount) {
    int sum = ((State_220850 *)s)->level + amount;
    if (sum > (int)((State_220850 *)s)->obj->value) {
        if (sum >= 0xfa)
            FUN_0021b060(((State_220850 *)s)->context, "function or expression too complex");
        ((State_220850 *)s)->obj->value = (unsigned char)sum;
    }
    ((State_220850 *)s)->level += amount;
}
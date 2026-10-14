struct State_1c0a40 {
    char pad[0xd0];
    unsigned value;
};
struct Context {
    State_1c0a40*** FUN_000862e0();
};
struct Effect_1c0a40 {
    void FUN_000f86f0(int, int);
};
extern int __cdecl FUN_00266da0(int);
struct Object {
    char pad[0x30];
    unsigned value;
    Effect_1c0a40* first;
    Effect_1c0a40* second;
    char gap[0x10];
    Context* context;
    void FUN_001c0360(int, int);
    int FUN_001c0a40(Context* arg);
};
int Object::FUN_001c0a40(Context* arg) {
    int previous = FUN_00266da0(14);
    context = arg;
    State_1c0a40*** result = arg->FUN_000862e0();
    (**result)->value = value;
    if (first)
        first->FUN_000f86f0(900, 50400);
    if (second)
        second->FUN_000f86f0(250, 13000);
    FUN_001c0360(2, 0);
    return FUN_00266da0(previous);
}
typedef unsigned char u8;
struct Inner;
struct Mid {
    int a;
};
struct Ret {
    void last();
};
struct Obj {
    Inner* getA();
};
struct Inner {
    Mid* getB();
};
struct State {
    char pad[0x14];
    u8 flag;
};
Ret* FUN_678d0();
struct TokenAction {
    char pad[0x1c];
    State* state;
    Obj* object;
    void vfunc_4();
};
void TokenAction::vfunc_4() {
    if (object) {
        Inner* a = object->getA();
        Mid* b = a->getB();
        *((u8*)b + 0x1b84) = 0;
        if (state->flag) {
            FUN_678d0()->last();
        }
    }
}

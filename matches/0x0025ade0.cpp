struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_00262800();
struct Target {
    int first;
    int pad;
    Pair value;
};
Target* __fastcall FUN_0025ade0(Target* self) {
    self->first = 0;
    self->value = FUN_00262800();
    return self;
}
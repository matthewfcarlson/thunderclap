struct Pair_25ade0 {
    int a;
    int b;
};
extern Pair_25ade0 __cdecl FUN_00262800();
struct Target_25ade0 {
    int first;
    int pad;
    Pair_25ade0 value;
};
Target_25ade0* __fastcall FUN_0025ade0(Target_25ade0* self) {
    self->first = 0;
    self->value = FUN_00262800();
    return self;
}
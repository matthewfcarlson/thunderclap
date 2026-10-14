struct Pair_35d600 {
    int a;
    int b;
};
extern "C" Pair_35d600 __cdecl FUN_0027b020(const char*);
extern char g4004a0[];
extern char g4ddf38[];
extern char g4ddf3c[];
void FUN_0035d600() {
    Pair_35d600 r = FUN_0027b020(g4004a0);
    *(int*)g4ddf38 = r.a;
    *(int*)g4ddf3c = r.b;
}

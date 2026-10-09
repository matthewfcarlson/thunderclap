extern void __cdecl ReleaseThing(int);
extern void __cdecl DoPair(int, int);
struct Target {
    int first;
    int second;
    int pad;
    int third;
};
void __fastcall FUN_002fa0f0(Target* param_1) {
    if (param_1->third != 0)
        ReleaseThing(param_1->third);
    if (param_1->first != 0) {
        DoPair(param_1->first, param_1->second);
        ReleaseThing(param_1->first);
    }
}
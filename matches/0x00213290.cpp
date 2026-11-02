extern "C" void _ReadWriteBarrier();
struct Result {
    int type;
    int value;
};
Result* __fastcall FUN_00212bb0(int, int);
extern "C" int __cdecl FUN_00213290(int a, int b) {
    int x = *(volatile int*)&b;
    _ReadWriteBarrier();
    Result* r = FUN_00212bb0(x, a);
    if (r->type != 8)
        return 0;
    return r->value;
}
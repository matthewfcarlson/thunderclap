extern "C" void _ReadWriteBarrier();
struct Result {
    int type;
    int value;
};
Result* __fastcall lookup(int, int);
int __cdecl target(int a, int b) {
    int x = *(volatile int*)&b;
    _ReadWriteBarrier();
    Result* r = lookup(x, a);
    if (r->type != 8)
        return 0;
    return r->value;
}
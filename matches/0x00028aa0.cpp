extern "C" __int64 __cdecl FUN_002672f0(int, int, int);
union Two {
    __int64 both;
    struct {
        int a, b;
    } halves;
};
class X {
  public:
    void* FUN_00024280(int, int);
    int FUN_00028aa0(int);
};
int X::FUN_00028aa0(int x) {
    Two p;
    p.both = FUN_002672f0(x, 0, 0);
    char* q = (char*)FUN_00024280(p.halves.a, p.halves.b);
    if (!q)
        return 0;
    return *(int*)(q + 0x318);
}
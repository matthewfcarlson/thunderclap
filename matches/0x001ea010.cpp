extern "C" __int64 __cdecl FUN_002672f0(int, int, int);
class X {
  public:
    int consume(__int64*);
    int Fn(int);
};
int X::Fn(int p) {
    __int64 v = FUN_002672f0(p, 0, 0);
    return consume(&v);
}

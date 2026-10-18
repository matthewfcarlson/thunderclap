__int64 __cdecl get(int, int, int);
class X {
  public:
    int consume(__int64*);
    int Fn(int);
};
int X::Fn(int p) {
    __int64 v = get(p, 0, 0);
    return consume(&v);
}

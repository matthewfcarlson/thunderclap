__int64 __cdecl get(int, int, int);
class X {
  public:
    void consume(__int64*);
    void Fn(int);
};
void X::Fn(int p) {
    __int64 v = get(p, 0, 0);
    consume(&v);
}

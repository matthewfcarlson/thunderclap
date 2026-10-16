extern "C" unsigned __int64 __cdecl compute(int, int, int);
class Obj {
  public:
    void use(int, unsigned __int64);
    void fn(int a, int b);
};
void Obj::fn(int a, int b) {
    unsigned __int64 v = compute(b, 0, 0);
    use(a, v);
}
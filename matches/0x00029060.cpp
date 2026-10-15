extern "C" __int64 __cdecl Convert(int, int, int);
class Elem {
  public:
    void Test(int);
};
class Obj {
  public:
    Elem* Find(__int64);
    void Fn(int, int);
};
void Obj::Fn(int a, int b) {
    Elem* p = Find(Convert(a, 0, 0));
    if (p)
        p->Test(b);
}
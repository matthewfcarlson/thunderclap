extern "C" __int64 __cdecl fetch(int, int, int);
class Obj {
  public:
    void set(__int64);
    void fn(int);
};
void Obj::fn(int x) {
    set(fetch(x, 0, 0));
}
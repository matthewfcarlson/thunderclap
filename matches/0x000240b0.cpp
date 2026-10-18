extern "C" __int64 __cdecl fetch(int, int, int);
class Obj {
  public:
    int set(__int64);
    int fn(int);
};
int Obj::fn(int x) {
    return set(fetch(x, 0, 0));
}
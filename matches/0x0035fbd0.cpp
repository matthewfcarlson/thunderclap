class Thing {
  public:
    int Get();
};
extern Thing obj;
extern "C" __int64 __cdecl f(int, int, int);
extern __int64 result;
void target() {
    int n = obj.Get();
    result = f(n, 0, 0);
}
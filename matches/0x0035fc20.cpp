class Obj {
  public:
    int Get();
};
extern Obj obj;
extern "C" __int64 __cdecl FUN_002672f0(int, int, int);
extern __int64 result;
void FUN_0035fc20() {
    int n = obj.Get();
    result = FUN_002672f0(n, 0, 0);
}
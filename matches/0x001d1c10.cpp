class C_1d1c10 {
    char a[8];
    int obj;
    char b[0x5464];
    int vals[8];
    int idx;

  public:
    bool f(int);
};
int __cdecl FUN_00212d70(int);
int __cdecl FUN_00212d80(int, int);
int __cdecl FUN_00213c50(int, int);
bool C_1d1c10::f(int p) {
    if (idx < 0)
        return false;
    int n = FUN_00212d70(obj);
    int v = vals[idx];
    if (n != v + 1) {
        FUN_00212d80(obj, v);
        return false;
    }
    return FUN_00213c50(obj, p) != 0;
}
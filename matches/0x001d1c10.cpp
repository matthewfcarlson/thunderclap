class C {
    char a[8];
    int obj;
    char b[0x5464];
    int vals[8];
    int idx;

  public:
    bool f(int);
};
int __cdecl A(int);
int __cdecl B(int, int);
int __cdecl D(int, int);
bool C::f(int p) {
    if (idx < 0)
        return false;
    int n = A(obj);
    int v = vals[idx];
    if (n != v + 1) {
        B(obj, v);
        return false;
    }
    return D(obj, p) != 0;
}
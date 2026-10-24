extern void f13640(int, int, int);
extern int f12f00(int, int);
extern void f12d80(int, int);
class C_1d1930 {
  public:
    char pad[8];
    int m;
    bool Run(int n);
};
bool C_1d1930::Run(int n) {
    if (n >= 1) {
        f13640(m, -10000, n);
        if (f12f00(m, -1) == 0) {
            f12d80(m, -2);
            return false;
        }
        return true;
    }
    return false;
}

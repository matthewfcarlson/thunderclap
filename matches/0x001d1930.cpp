extern void f13640(int, int, int);
extern int f12f00(int, int);
extern void f12d80(int, int);
class C { public: char pad[8]; int m; bool Run(int n); };
bool C::Run(int n) {
    if (n >= 1) {
        f13640(m, -10000, n);
        if (f12f00(m, -1) == 0) f12d80(m, -2);
        else goto success;
    }
    return false;
success:
    return true;
}
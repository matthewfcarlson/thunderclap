struct ThisWrap_000e74e0 {
    int Inner(int);
    int Target(int x);
};
extern int __cdecl Combine(int, int, void*, void*, int);
extern char a, b, c;
int ThisWrap_000e74e0::Target(int x) {
    return Combine(Combine(this->Inner(x), 0, &a, &b, 0), 0, &b, &c, 0);
}
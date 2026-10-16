struct Pair {
    int a, b;
};
extern Pair __cdecl Make(const char*, int, int);
extern Pair g;
void FUN_0035fc00() {
    g = Make("Template", 0, 0);
}
extern int source;
extern int result[2];
struct Pair {
    int a, b;
};
Pair __cdecl getPair(int, int, int);
void target() {
    Pair p = getPair(source, 0, 0);
    result[0] = p.a;
    result[1] = p.b;
}
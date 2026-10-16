extern int input;
extern int output[2];
struct Pair {
    int a, b;
};
Pair __cdecl func(int, int, int);
void target() {
    Pair p = func(input, 0, 0);
    output[0] = p.a;
    output[1] = p.b;
}
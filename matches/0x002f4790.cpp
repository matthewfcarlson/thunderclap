extern void target(int, int, int);
void wrapper(int a, int b) { target(a, b, (b - a) >> 1); }
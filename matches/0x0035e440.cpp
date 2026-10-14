typedef unsigned long long U64;
extern U64 FUN_0027b020(const char*);
extern int g1;
extern int g2;
void FUN_0035e440() {
    U64 r = FUN_0027b020("drop");
    g1 = (int)r;
    g2 = (int)(r >> 32);
}

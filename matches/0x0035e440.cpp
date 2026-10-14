typedef unsigned long long U64_35e440;
extern U64_35e440 FUN_0027b020(const char*);
extern int g1_35e440;
extern int g2_35e440;
void FUN_0035e440() {
    U64_35e440 r = FUN_0027b020("drop");
    g1_35e440 = (int)r;
    g2_35e440 = (int)(r >> 32);
}

// cl-flags: /O2
extern int gValue;
extern int gLow;
extern int gHigh;

struct Result {
    int lo;
    int hi;
};
Result Get(int a, int b, int c);

void target() {
    int a = gValue;
    Result r = Get(a, 0, 0);
    gLow = r.lo;
    gHigh = r.hi;
}

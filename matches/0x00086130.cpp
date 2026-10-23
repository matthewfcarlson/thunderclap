struct X {
    char pad[0x38];
    unsigned int lo;
    unsigned int hi;
    double Get();
};
extern const float DAT_003ffaac;
double X::Get() {
    struct Q {
        unsigned int lo;
        unsigned int hi;
    };
    Q a = *(Q*)&lo;
    unsigned int h = a.hi;
    a.hi &= 0x7fffffff;
    double v = (double)*(__int64*)&a;
    a.hi = h & 0x80000000;
    a.lo = 0;
    double n = -(double)*(__int64*)&a;
    return (n + v) * DAT_003ffaac;
}
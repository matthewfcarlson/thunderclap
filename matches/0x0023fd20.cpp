struct Thing_23fd20 {
    int value;
    unsigned short a;
    unsigned short pad;
    unsigned short b;
    Thing_23fd20* run(int arg);
};
extern void helper(int*, int, int, int);
Thing_23fd20* Thing_23fd20::run(int arg) {
    a = 2;
    b = 0;
    helper(&arg, 0, 0, arg);
    value = arg;
    return this;
}
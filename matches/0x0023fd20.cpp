struct Thing {
    int value;
    unsigned short a;
    unsigned short pad;
    unsigned short b;
    Thing* run(int arg);
};
extern void helper(int*, int, int, int);
Thing* Thing::run(int arg) {
    a = 2;
    b = 0;
    helper(&arg, 0, 0, arg);
    value = arg;
    return this;
}
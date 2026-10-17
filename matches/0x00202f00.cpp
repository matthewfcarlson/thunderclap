struct Inner {
    char pad[8];
    int value;
};
struct Outer {
    char pad[0x24];
    Inner* inner;
};
extern Outer* DAT_004dd700;
int* FUN_00202f00() {
    Inner* p = DAT_004dd700->inner;
    p->value = 0;
    return &p->value;
}
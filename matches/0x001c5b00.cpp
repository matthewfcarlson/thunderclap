struct Inner_1c5b00 {
    int Helper(int);
};
struct Outer_1c5b00 {
    char pad[0x128];
    Inner_1c5b00 inner;
    int Target(int);
};
int Outer_1c5b00::Target(int a0) {
    return inner.Helper(a0);
}
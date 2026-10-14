struct Inner_15aa00 {
    int x;
};
struct X_15aa00 {
    char pad[0x48];
    Inner_15aa00 i;
    Inner_15aa00* Fn();
};
Inner_15aa00* X_15aa00::Fn() {
    return &i;
}

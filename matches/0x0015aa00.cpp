struct Inner {
    int x;
};
struct X {
    char pad[0x48];
    Inner i;
    Inner* Fn();
};
Inner* X::Fn() {
    return &i;
}

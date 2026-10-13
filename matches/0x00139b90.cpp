struct S {
    char pad[0xc];
    int m;
    char Target(int v);
};
char S::Target(int v) {
    m = v;
    return 1;
}

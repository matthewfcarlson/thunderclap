struct S {
    char pad[16];
    int m;
    char Fn(int x);
};

char S::Fn(int x) {
    m = x;
    return 1;
}

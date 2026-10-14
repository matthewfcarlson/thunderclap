struct X {
    char pad[0x54];
    int m54;
    char Set(int v);
};

char X::Set(int v) {
    m54 = v;
    return 1;
}

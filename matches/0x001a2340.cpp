struct X_1a2340 {
    char pad[0x54];
    int m54;
    char Set(int v);
};

char X_1a2340::Set(int v) {
    m54 = v;
    return 1;
}

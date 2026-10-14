struct X_683c0 {
    char pad[16];
    unsigned int m10;
    char Set(int v);
};

char X_683c0::Set(int v) {
    m10 = v;
    return 1;
}
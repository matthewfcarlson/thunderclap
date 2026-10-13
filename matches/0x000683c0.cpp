struct X {
    char pad[16];
    unsigned int m10;
    char Set(int v);
};

char X::Set(int v) {
    m10 = v;
    return 1;
}
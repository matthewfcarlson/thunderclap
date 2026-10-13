struct X {
    char pad[0x1d];
    unsigned char m1d;
    unsigned char Set(unsigned char v);
};

unsigned char X::Set(unsigned char v) {
    m1d = v;
    return 1;
}

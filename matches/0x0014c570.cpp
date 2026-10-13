struct X {
    char pad[0xc];
    unsigned char mValue;
    bool mSet;
    unsigned char Set(unsigned char v);
};
unsigned char X::Set(unsigned char v) {
    mValue = v;
    return 1;
}

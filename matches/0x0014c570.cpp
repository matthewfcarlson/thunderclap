struct X_14c570 {
    char pad[0xc];
    unsigned char mValue;
    bool mSet;
    unsigned char Set(unsigned char v);
};
unsigned char X_14c570::Set(unsigned char v) {
    mValue = v;
    return 1;
}

struct Obj {
    char pad[0x20];
    unsigned char m;
    unsigned char Set(unsigned char value);
};

unsigned char Obj::Set(unsigned char value) {
    m = value;
    return 1;
}

struct Obj {
    char pad[0xc];
    unsigned char m;
    unsigned char Set(unsigned char x);
};
unsigned char Obj::Set(unsigned char x) {
    m = x;
    return 1;
}
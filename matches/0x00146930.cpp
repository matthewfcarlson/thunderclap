struct Obj {
    char pad[12];
    char m;
    unsigned char Set(unsigned char c);
};
unsigned char Obj::Set(unsigned char c) {
    m = (char)c;
    return 1;
}

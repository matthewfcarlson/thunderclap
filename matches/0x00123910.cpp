struct Obj_123910 {
    char pad[0xc];
    unsigned char m;
    unsigned char Set(unsigned char x);
};
unsigned char Obj_123910::Set(unsigned char x) {
    m = x;
    return 1;
}
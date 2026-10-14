struct Obj_146930 {
    char pad[12];
    char m;
    unsigned char Set(unsigned char c);
};
unsigned char Obj_146930::Set(unsigned char c) {
    m = (char)c;
    return 1;
}

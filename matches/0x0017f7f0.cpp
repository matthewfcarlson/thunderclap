struct Obj_17f7f0 {
    char pad[0x14];
    int value;
    unsigned char Set(int x);
};

unsigned char Obj_17f7f0::Set(int x) {
    value = x;
    return 1;
}

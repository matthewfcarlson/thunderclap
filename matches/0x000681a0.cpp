struct Obj_681a0 {
    char pad[0x20];
    unsigned char m;
    unsigned char Set(unsigned char value);
};

unsigned char Obj_681a0::Set(unsigned char value) {
    m = value;
    return 1;
}

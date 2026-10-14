struct Obj_68c60 {
    char pad[0x10];
    int mValue;
    unsigned char Set(int v);
};

unsigned char Obj_68c60::Set(int v) {
    mValue = v;
    return 1;
}

struct Obj_1a1f10 {
    char pad[0x10];
    int mValue;
    char Set(int x);
};

char Obj_1a1f10::Set(int x) {
    mValue = x;
    return 1;
}

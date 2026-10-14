struct Obj_114f50 {
    char pad[0x14];
    int value;
    char Set(int x);
};

char Obj_114f50::Set(int x) {
    value = x;
    return 1;
}

struct Obj_1a26c0 {
    char pad[0xc4];
    int value;
    char Set(int x);
};

char Obj_1a26c0::Set(int x) {
    value = x;
    return 1;
}
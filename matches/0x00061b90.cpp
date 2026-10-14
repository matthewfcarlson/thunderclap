struct Obj_61b90 {
    char pad[0x20];
    int m20;
    char Set(int x);
};

char Obj_61b90::Set(int x) {
    m20 = x;
    return 1;
}
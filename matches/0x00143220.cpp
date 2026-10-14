struct Obj_143220 {
    char pad[0x34];
    int value;
    char Set(int v);
};

char Obj_143220::Set(int v) {
    value = v;
    return 1;
}

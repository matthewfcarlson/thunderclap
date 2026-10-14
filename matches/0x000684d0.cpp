struct Obj_684d0 {
    char pad[0x30];
    int value;
    char Set(int v);
};

char Obj_684d0::Set(int v) {
    value = v;
    return 1;
}

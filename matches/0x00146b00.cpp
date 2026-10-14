struct Obj_146b00 {
    char pad[0x28];
    int value;
    char Set(int x);
};
char Obj_146b00::Set(int x) {
    value = x;
    return 1;
}

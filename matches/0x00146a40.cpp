struct Obj_146a40 {
    char pad[12];
    int value;
    unsigned char Set(int x);
};
unsigned char Obj_146a40::Set(int x) {
    value = x;
    return 1;
}

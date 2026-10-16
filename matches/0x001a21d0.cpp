struct Obj {
    char pad[0x2c];
    float angle;
    char Set(float);
};
char Obj::Set(float x) {
    angle = x * 0.017453292519943295f;
    return 1;
}
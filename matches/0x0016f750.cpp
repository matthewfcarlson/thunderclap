struct Obj {
    char pad[0x34];
    float angle;
    char SetAngle(float a);
};
char Obj::SetAngle(float a) {
    angle = a * 0.017453292519943295f;
    return 1;
}
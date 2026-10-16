struct Obj {
    char pad[0x28];
    float angle;
    bool Set(float x);
};
bool Obj::Set(float x) {
    angle = x * 0.017453292519943295f;
    return true;
}
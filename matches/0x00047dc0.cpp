struct Obj {
    char pad[16];
    float angle;
    bool SetAngle(float x);
};
bool Obj::SetAngle(float x) {
    angle = x * 0.017453292f;
    return true;
}
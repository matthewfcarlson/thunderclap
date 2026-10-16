class Obj {
    char pad[0x14];
    float angle;

  public:
    bool SetAngle(float x);
};
bool Obj::SetAngle(float x) {
    angle = x * 0.017453292f;
    return true;
}
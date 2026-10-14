class Obj {
  public:
    char pad[0x30];
    float angle;
    bool SetAngle(float deg);
};
bool Obj::SetAngle(float deg) {
    angle = deg * 0.01745329238474369f;
    return true;
}
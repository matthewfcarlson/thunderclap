class Obj_13e940 {
  public:
    char pad[0x30];
    float angle;
    bool SetAngle(float deg);
};
bool Obj_13e940::SetAngle(float deg) {
    angle = deg * 0.01745329238474369f;
    return true;
}
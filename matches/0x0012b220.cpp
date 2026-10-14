class Obj_12b220 {
  public:
    char pad[0x10];
    float mF10;
    bool SetAngle(float angle);
};
const float kDegToRad = 0.0174533f;
bool Obj_12b220::SetAngle(float angle) {
    mF10 = angle * kDegToRad;
    return true;
}

extern const float kRadian = 0.0174533f;
class Obj_1239c0 {
  public:
    char pad[0x14];
    float mAngle;
    char SetAngle(float value);
};
char Obj_1239c0::SetAngle(float value) {
    mAngle = value * kRadian;
    return 1;
}

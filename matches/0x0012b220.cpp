class Obj_12b220 {
  public:
    char pad[0x10];
    float mF10;
    bool SetArc_0012b220(float angle);
};
const float kDegToRad = 0.017453292f;
bool Obj_12b220::SetArc_0012b220(float angle) {
    mF10 = angle * kDegToRad;
    return true;
}

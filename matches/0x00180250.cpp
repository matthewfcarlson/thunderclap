extern const float Rad = 0.0174533f;
class Obj {
  public:
    char pad[0x20];
    float mAngle;
    char Set(float v);
};
char Obj::Set(float v) {
    mAngle = v * Rad;
    return 1;
}

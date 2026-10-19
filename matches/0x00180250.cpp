extern const float Rad = 0.017453292f;
class Obj_180250 {
  public:
    char pad[0x20];
    float mAngle;
    char Set(float v);
};
char Obj_180250::Set(float v) {
    mAngle = v * Rad;
    return 1;
}

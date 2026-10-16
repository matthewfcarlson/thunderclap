class Obj {
  public:
    char pad[0x54];
    float angle;
    char SetAngle(float degrees);
};
char Obj::SetAngle(float degrees) {
    angle = degrees * 0.017453292f;
    return 1;
}
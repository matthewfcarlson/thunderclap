class Obj {
    char pad[0x38];
    float angle;

  public:
    char SetAngle(float v);
};
char Obj::SetAngle(float v) {
    angle = v * 0.017453292f;
    return 1;
}
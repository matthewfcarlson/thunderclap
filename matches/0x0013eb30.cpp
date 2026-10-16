class Obj {
    char pad[0x2c];
    float angle;

  public:
    char SetAngle(float a);
};
char Obj::SetAngle(float a) {
    angle = a * 0.017453292519943295f;
    return 1;
}
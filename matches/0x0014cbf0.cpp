class Obj {
  public:
    char pad[0x30];
    float angle;
    char SetAngle(float a);
};
char Obj::SetAngle(float a) {
    angle = a * 0.017453292519943295f;
    return 1;
}

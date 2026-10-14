class Obj {
  public:
    char Pad[0x20];
    float Angle;
    char SetAngle(float a);
};

char Obj::SetAngle(float a) {
    Angle = a * 0.017453292519943295f;
    return 1;
}

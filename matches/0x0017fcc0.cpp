class Obj_17fcc0 {
  public:
    char Pad[0x20];
    float Angle;
    char SetAngle(float a);
};

char Obj_17fcc0::SetAngle(float a) {
    Angle = a * 0.017453292519943295f;
    return 1;
}

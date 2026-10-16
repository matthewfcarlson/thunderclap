class Obj {
    char pad[0x9c];
    float angle;

  public:
    unsigned char SetAngle(float a);
};
unsigned char Obj::SetAngle(float a) {
    angle = a * 0.017453292519943295f;
    return 1;
}
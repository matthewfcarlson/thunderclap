class Obj {
    char pad[0x28];
    float angle;

  public:
    char SetAngle(float a);
};
char Obj::SetAngle(float a) {
    angle = a * 0.0174532925f;
    return 1;
}
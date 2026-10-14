class Obj {
  public:
    char pad[0x30];
    float angle;
    char SetAngle(float deg);
};

char Obj::SetAngle(float deg) {
    float rad = deg * 0.0174532925f;
    angle = rad;
    return 1;
}

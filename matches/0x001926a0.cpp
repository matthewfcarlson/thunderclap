class Obj {
    char pad[0x34];
    float angle;

  public:
    char SetAngle(float x);
};
char Obj::SetAngle(float x) {
    angle = x * 0.017453292f;
    return 1;
}
class Thing {
    char pad[0x18];
    float angle;

  public:
    char SetAngle(float value);
};
char Thing::SetAngle(float value) {
    angle = value * 0.017453292519943295f;
    return 1;
}
class Thing_1332a0 {
  public:
    char Pad[0x24];
    float mAngle;
    char SetAngle(float a);
};
char Thing_1332a0::SetAngle(float a) {
    mAngle = a * 0.017453292519943295f;
    return 1;
}
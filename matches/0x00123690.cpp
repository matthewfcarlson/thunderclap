class Thing {
  public:
    char pad[16];
    float radians;
    char SetAngle(float a);
};
char Thing::SetAngle(float a) {
    radians = a * 0.017453292519943295f;
    return 1;
}
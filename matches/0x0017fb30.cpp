class Thing {
  public:
    char pad[0x50];
    float angle;
    bool SetAngle(float a);
};
bool Thing::SetAngle(float a) {
    angle = a * 0.0174532925f;
    return true;
}
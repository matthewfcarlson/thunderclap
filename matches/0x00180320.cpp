class Thing {
  public:
    char pad[16];
    float angle;
    bool SetAngle(float a);
};
bool Thing::SetAngle(float a) {
    angle = a * 0.017453292f;
    return true;
}
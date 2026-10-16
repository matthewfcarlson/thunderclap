class Thing {
  public:
    char pad[0x24];
    float angle;
    bool SetAngle(float v);
};
bool Thing::SetAngle(float v) {
    angle = v * 0.0174532925f;
    return true;
}

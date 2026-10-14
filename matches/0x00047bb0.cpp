class O_47bb0 {
  public:
    char pad[0x14];
    float mAngle;
    bool SetAngle(float a);
};
bool O_47bb0::SetAngle(float a) {
    mAngle = a * 0.017453292519943295f;
    return true;
}
class Obj {
    char pad[0x14];
    float angle;

  public:
    bool SetArc_00047c20(float x);
};
bool Obj::SetArc_00047c20(float x) {
    angle = x * 0.017453292f;
    return true;
}
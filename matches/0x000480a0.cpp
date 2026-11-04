class Obj_480a0 {
  public:
    char pad[0x10];
    float mVal;
    bool SetArc_000480a0(float a);
};
bool Obj_480a0::SetArc_000480a0(float a) {
    mVal = a * 0.017453292522f;
    return true;
}

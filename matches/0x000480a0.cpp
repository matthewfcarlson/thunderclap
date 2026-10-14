class Obj {
  public:
    char pad[0x10];
    float mVal;
    bool Set(float a);
};
bool Obj::Set(float a) {
    mVal = a * 0.017453292522f;
    return true;
}

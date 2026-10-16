class Obj {
    char pad[0x24];
    float angle;

  public:
    bool Set(float x);
};
bool Obj::Set(float x) {
    angle = x * 0.017453292f;
    return true;
}
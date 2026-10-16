class Obj {
    char pad[0x14];
    float angle;

  public:
    bool Set(float degrees);
};
bool Obj::Set(float degrees) {
    angle = degrees * 0.017453292f;
    return true;
}
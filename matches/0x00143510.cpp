class Obj {
  public:
    char pad[0x38];
    float value;
    bool Set(float a);
};
bool Obj::Set(float a) {
    value = a * (float)0.017453292f;
    return true;
}

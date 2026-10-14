class Obj_143510 {
  public:
    char pad[0x38];
    float value;
    bool Set(float a);
};
bool Obj_143510::Set(float a) {
    value = a * (float)0.017453292f;
    return true;
}

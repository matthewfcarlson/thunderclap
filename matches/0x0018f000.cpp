class Obj {
    char pad[0x50];
    float value;

  public:
    bool Set(float x);
};
bool Obj::Set(float x) {
    value = x * 0.017453292f;
    return true;
}
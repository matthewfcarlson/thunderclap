class Obj {
  public:
    char pad[0x10];
    float value;
    bool Fn(float degrees);
};
bool Obj::Fn(float degrees) {
    value = degrees * 0.017453292519943295f;
    return true;
}
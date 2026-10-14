class Obj {
  public:
    char pad[0xf4];
    float value;
    bool Set(float angle);
};

bool Obj::Set(float angle) {
    value = angle * 0.017453292519943f;
    return true;
}

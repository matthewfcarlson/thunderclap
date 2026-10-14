extern const float kRad = 0.01745329252f;
class Obj {
  public:
    char pad[0x1c];
    float value;
    bool Set(float x);
};

bool Obj::Set(float x) {
    value = x * kRad;
    return true;
}

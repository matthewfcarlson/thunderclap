const float kDegreesToRadians = 0.017453292519943295f;
class O_165920 {
  public:
    char pad[0x10];
    float m;
    bool Set(float value);
};

bool O_165920::Set(float value) {
    float rad = value * kDegreesToRadians;
    m = rad;
    return true;
}
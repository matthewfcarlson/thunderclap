extern const float kRadiansToDegrees = 0.017453292f;

class Thing_6ad10 {
  public:
    char pad[0x4c];
    float value;
    bool Set(float degrees);
};

bool Thing_6ad10::Set(float degrees) {
    value = degrees * kRadiansToDegrees;
    return true;
}

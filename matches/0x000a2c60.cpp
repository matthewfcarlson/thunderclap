extern const float zero;
class Obj {
    char pad[0x450];
    float oldVal;
    float target;
    float speed;

  public:
    void Set(float value, float time);
    void helper(float);
};
void Obj::Set(float value, float time) {
    target = value;
    speed = 0.0f;
    if (oldVal != value) {
        if (time <= zero) {
            helper(value);
            return;
        }
        speed = (value - oldVal) / time;
    }
}
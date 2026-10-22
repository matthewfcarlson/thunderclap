extern const float zero_a2c60;
class CChaseCamera_a2c60 {
    char pad[0x450];
    float oldVal;
    float target;
    float speed;

  public:
    void Set(float value, float time);
    void helper(float);
};
void CChaseCamera_a2c60::Set(float value, float time) {
    target = value;
    speed = 0.0f;
    if (oldVal != value) {
        if (time <= zero_a2c60) {
            helper(value);
            return;
        }
        speed = (value - oldVal) / time;
    }
}
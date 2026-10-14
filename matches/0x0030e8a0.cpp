extern const float threshold_30e8a0;
class Obj_30e8a0 {
  public:
    char pad[0x38];
    float a;
    float b;
    float c;
    int state;
    void Update();
};
void Obj_30e8a0::Update() {
    state = 0;
    if (a > threshold_30e8a0) {
        state = 2;
        a = 1.0f;
        c = 0.0f;
        b = 0.0f;
        return;
    }
    if (b > threshold_30e8a0) {
        state = 3;
        a = 0.0f;
        b = 1.0f;
        c = 0.0f;
        return;
    }
    if (c > threshold_30e8a0) {
        state = 4;
        a = 0.0f;
        c = 1.0f;
        b = 0.0f;
    }
}

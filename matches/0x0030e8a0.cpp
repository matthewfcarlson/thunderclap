extern const float threshold;
class Obj {
  public:
    char pad[0x38];
    float a;
    float b;
    float c;
    int state;
    void Update();
};
void Obj::Update() {
    state = 0;
    if (a > threshold) {
        state = 2;
        a = 1.0f;
        c = 0.0f;
        b = 0.0f;
        return;
    }
    if (b > threshold) {
        state = 3;
        a = 0.0f;
        b = 1.0f;
        c = 0.0f;
        return;
    }
    if (c > threshold) {
        state = 4;
        a = 0.0f;
        c = 1.0f;
        b = 0.0f;
    }
}

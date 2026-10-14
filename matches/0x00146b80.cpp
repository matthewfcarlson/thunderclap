class X_146b80 {
  public:
    bool Set(float v);
    char pad[0x34];
    float angle;
};

const float kScale_146b80 = 0.3f;

bool X_146b80::Set(float v) {
    angle = v * kScale_146b80;
    return true;
}

class X {
  public:
    bool Set(float v);
    char pad[0x34];
    float angle;
};

const float kScale = 0.3f;

bool X::Set(float v) {
    angle = v * kScale;
    return true;
}

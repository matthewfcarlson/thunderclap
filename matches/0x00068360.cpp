class Thing_68360 {
  public:
    char pad[0x14];
    float angle;
    bool Set(float v);
};

bool Thing_68360::Set(float v) {
    bool r = true;
    angle = v * 0.0174532925f;
    return r;
}

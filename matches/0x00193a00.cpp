class O_193a00 {
  public:
    char pad[0x68];
    float value;
    bool Set(float angle);
};

bool O_193a00::Set(float angle) {
    value = angle * 0.017453292f;
    return true;
}

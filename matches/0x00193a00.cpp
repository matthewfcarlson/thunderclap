class O {
  public:
    char pad[0x68];
    float value;
    bool Set(float angle);
};

bool O::Set(float angle) {
    value = angle * 0.017453292f;
    return true;
}

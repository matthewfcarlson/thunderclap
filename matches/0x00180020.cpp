class X_180020 {
  public:
    char pad[0x4c];
    float value;
    char Fn(float arg);
};
char X_180020::Fn(float arg) {
    value = arg * 0.017453292f;
    return 1;
}

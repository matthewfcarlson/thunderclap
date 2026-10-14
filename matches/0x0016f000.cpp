class T_16f000 {
  public:
    char pad[0x4c];
    float value;
    float Get();
};
float T_16f000::Get() {
    return value;
}

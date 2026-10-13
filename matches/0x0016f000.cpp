class T {
  public:
    char pad[0x4c];
    float value;
    float Get();
};
float T::Get() {
    return value;
}

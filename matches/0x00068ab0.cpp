class T {
  public:
    char g(float x);
    char pad[0x48];
    float m48;
};
char T::g(float x) {
    m48 = x * 0.017453292f;
    return 1;
}
class X {
  public:
    char pad[0x48];
    float m48;
    float Get();
};
float X::Get() {
    return m48;
}

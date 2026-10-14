class X_13000 {
  public:
    char pad[0xec];
    int value;
    int Get();
};
int X_13000::Get() {
    return value;
}
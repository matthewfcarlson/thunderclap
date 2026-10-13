class X {
  public:
    char pad[0xec];
    int value;
    int Get();
};
int X::Get() {
    return value;
}
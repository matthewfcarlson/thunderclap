class A {
  public:
    char pad[0x134];
    int value;
    int Get();
};

int A::Get() {
    return value;
}

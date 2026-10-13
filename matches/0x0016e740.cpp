class A {
  public:
    char pad[0x18];
    int m18;
    int* Get();
};

int* A::Get() {
    return &m18;
}

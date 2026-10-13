class A {
  public:
    char pad[0x10];
    void* Get10();
};

void* A::Get10() {
    return (char*)this + 0x10;
}

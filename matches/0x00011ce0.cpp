class A {
  public:
    char pad[0x18];
    void* Get();
};
void* A::Get() {
    return (char*)this + 0x18;
}

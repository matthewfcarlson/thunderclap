class A {
  public:
    char pad[0x10];
    struct X* Get();
};

struct X {};

X* A::Get() {
    return (X*)((char*)this + 0x10);
}

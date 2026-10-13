class Base {
  public:
    char pad[0x10];
};
class A : public Base {
  public:
    void* Get();
};
void* A::Get() {
    return (char*)this + 0x10;
}
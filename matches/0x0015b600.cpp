struct Sub {
    char pad[0x40];
};
class A {
  public:
    Sub sub;
    void* Get();
};
void* A::Get() {
    return (char*)&sub + 0x40;
}

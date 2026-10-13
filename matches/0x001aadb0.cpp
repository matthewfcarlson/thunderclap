class A {
  public:
    char pad[0x10];
    int* Get();
};
int* A::Get() {
    return (int*)((char*)this + 0x10);
}
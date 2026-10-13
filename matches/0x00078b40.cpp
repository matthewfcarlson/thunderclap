class A {
  public:
    char pad[0x59c];
    void* m59c;
    void* Get();
};
void* A::Get() {
    return m59c;
}

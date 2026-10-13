class T {
  public:
    char pad[0x18];
    int* f();
};
int* T::f() {
    return (int*)((char*)this + 0x18);
}
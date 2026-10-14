class T_12310 {
  public:
    char pad[0x18];
    int* f();
};
int* T_12310::f() {
    return (int*)((char*)this + 0x18);
}
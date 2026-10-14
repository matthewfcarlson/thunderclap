class C_e3750 {
  public:
    char pad[0x1d98];
    void* p;
    void f(void* x);
};
void C_e3750::f(void* x) {
    p = x;
    if (x)
        *((char*)x + 0x74) = 0;
}
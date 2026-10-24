namespace core {
struct I0 {
    virtual void a(int);
};
struct I1 {
    virtual void a(int);
};
struct Iextra {
    virtual void a(int);
    char pad[4];
};
struct I2 {
    virtual void a(int);
    virtual void b();
    virtual void c(unsigned);
};
struct __declspec(dllexport) CementLibrary : I0, I1, Iextra, I2 {
    void a(int);
    void b();
    void c(unsigned);
};
void CementLibrary::c(unsigned flags) {
    a(0);
}
} // namespace core
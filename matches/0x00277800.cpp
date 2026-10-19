namespace core {
struct I0 {
    virtual void a();
};
struct I1 {
    virtual void a();
};
struct Iextra {
    virtual void a();
    char pad[4];
};
struct I2 {
    virtual void a();
    virtual void b();
    virtual void c(unsigned);
};
struct __declspec(dllexport) CementLibrary : I0, I1, Iextra, I2 {
    void a();
    void b();
    void c(unsigned);
};
void CementLibrary::c(unsigned flags) {
    a();
}
} // namespace core
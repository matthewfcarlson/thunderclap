class H {
  public:
    void* lookup(unsigned int, unsigned int);
};
extern const float gZero;
class C {
  public:
    char pad[0x2f4];
    float f(unsigned int);
};
float C::f(unsigned int x) {
    H* h = (H*)((char*)this + 0x2f4);
    void* p = h->lookup(0x66980, x);
    if (!p)
        return gZero;
    return *(float*)((char*)p + 0x18);
}
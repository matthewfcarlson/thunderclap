class H {
  public:
    void* lookup(unsigned int, unsigned int);
};
extern const float gZero_670e0;
class C_670e0 {
  public:
    char pad[0x2f4];
    float f(unsigned int);
};
float C_670e0::f(unsigned int x) {
    H* h = (H*)((char*)this + 0x2f4);
    void* p = h->lookup(0x66980, x);
    if (!p)
        return gZero_670e0;
    return *(float*)((char*)p + 0x18);
}
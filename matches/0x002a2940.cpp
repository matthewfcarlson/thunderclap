class O {
  public:
    void* Get(int n);
};
void* O::Get(int n) {
    void* p = *(void**)this;
    return (char*)p + (n << 4);
}

class O_2a2940 {
  public:
    void* Get(int n);
};
void* O_2a2940::Get(int n) {
    void* p = *(void**)this;
    return (char*)p + (n << 4);
}

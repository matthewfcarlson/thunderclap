class BufferDataReader {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual unsigned vfunc_4(void*, unsigned);
    virtual void f5();
    char pad[4];
    char* data;
    int unused;
    unsigned size;
    unsigned pos;
};
extern "C" void* memcpy(void*, const void*, unsigned);
unsigned BufferDataReader::vfunc_4(void* dst, unsigned n) {
    unsigned available = size - pos;
    if (available < n)
        n = available;
    memcpy(dst, data + pos, n);
    pos += n;
    return n;
}
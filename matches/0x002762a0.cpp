namespace core {
class Source {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual signed char f6();
};
class File {
  public:
    virtual void vfunc_24();
    char pad[8];
    Source* source;
    char gap[14];
    char rest[18];
    void* access();
};
void* File::access() {
    if (source->f6() & 0x80)
        return 0;
    return this->rest;
}
} // namespace core
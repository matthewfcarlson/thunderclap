class Inner_23bad0 {
  public:
    virtual void f0();
    virtual void f1();
};
class IFileDataReader {
  public:
    virtual void f0();
    virtual void f1();
    virtual IFileDataReader* v2(unsigned int);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    int pad;
    Inner_23bad0* inner;
};
extern int vtFight;
extern int vtRef_23bad0;
extern void cleanup(IFileDataReader*);
IFileDataReader* IFileDataReader::v2(unsigned int flags) {
    Inner_23bad0* p = inner;
    *(volatile int*)this = (int)&vtFight;
    p->f1();
    *(volatile int*)this = (int)&vtRef_23bad0;
    if (flags & 1)
        cleanup(this);
    return this;
}

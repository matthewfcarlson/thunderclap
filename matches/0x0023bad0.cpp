class Inner {
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
    Inner* inner;
};
extern int vtFight;
extern int vtRef;
extern void cleanup(IFileDataReader*);
IFileDataReader* IFileDataReader::v2(unsigned int flags) {
    Inner* p = inner;
    *(volatile int*)this = (int)&vtFight;
    p->f1();
    *(volatile int*)this = (int)&vtRef;
    if (flags & 1)
        cleanup(this);
    return this;
}

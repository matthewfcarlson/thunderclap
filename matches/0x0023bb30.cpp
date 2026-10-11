extern "C" char DAT_003f6098[];
extern "C" char DAT_00428760[];
class LoadObject {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
};
class StreamDataReader : public LoadObject {
  public:
    virtual void D();
    virtual void E();
    virtual void F();
    int pad;
    LoadObject* mObj;
    virtual StreamDataReader* vfunc_2(int);
};
extern void Destroy(StreamDataReader*);
StreamDataReader* StreamDataReader::vfunc_2(int flags) {
    LoadObject* p = mObj;
    ((int*)this)[0] = ((int)DAT_00428760);
    p->B();
    ((int*)this)[0] = ((int)DAT_003f6098);
    if (flags & 1)
        Destroy(this);
    return this;
}
class SeqAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual int f5();
    virtual void f6();
};
namespace audio {
class SeqActionStream : public SeqAction {
  public:
    char pad[0x20 - 4];
    int value;
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual int vfunc_5(int);
    virtual void g6();
};
int SeqActionStream::vfunc_5(int) {
    return value;
}
} // namespace audio
class SeqAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class SeqActionChannelSendVolumes : public SeqAction {
  public:
    virtual void vfunc_3(int);
};
void SeqActionChannelSendVolumes::vfunc_3(int) {
    *(int*)((char*)this + 0xc) = 4;
}
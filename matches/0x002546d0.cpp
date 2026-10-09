class SeqAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int, char);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    char pad[0x1c];
};
class SeqActionSilence : public SeqAction {
  public:
    virtual void vfunc_2(int, char);
};
void SeqActionSilence::vfunc_2(int, char flag) {
    *(int*)((char*)this + 0x18) = 2;
    if (flag)
        *(int*)((char*)this + 0xc) = 0;
}
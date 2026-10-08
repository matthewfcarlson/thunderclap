namespace audio {
class SeqActionWait {
public:
    virtual void vfunc_0();
    virtual void vfunc_1(int);
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    char pad[8];
    int state;
};
void SeqActionWait::vfunc_1(int) { state = 3; }
}
namespace audio {
class SeqActionClip {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int, unsigned char);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    char pad[8];
    int field_c;
    char pad10[8];
    int field_18;
};
void SeqActionClip::vfunc_2(int, unsigned char flag) {
    field_18 = 1;
    if (flag) field_c = 0;
}
}
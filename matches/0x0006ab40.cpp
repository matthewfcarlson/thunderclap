class CTrack {
  public:
    virtual int vfunc_0(int index);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
};
class CStageTrack : public CTrack {
  public:
    virtual int vfunc_0(int index);
};
extern int* gTable;
int CStageTrack::vfunc_0(int index) {
    return gTable[index];
}

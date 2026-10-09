class SeqEventCondition {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    bool Base0(void*);
    bool Base1(void*);
    char pad[0x14];
};
bool Check(void*, void*);
int SeqEventCondition::vfunc_0(void* arg) {
    if (Base0(arg) && Base1(arg) && Check(arg, (char*)this + 0x14))
        return 1;
    return 0;
}
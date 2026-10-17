// STATUS: equivalent (tools/equiv.py level 3: 2973 inputs, branch coverage 0/0)
// ControllerState::vfunc_1 @ 0x000dd7e0
struct ControllerState {
    virtual void vfunc_0();
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
    char unused[8];
    unsigned int *first;
    unsigned int *second;
};
void ControllerState::vfunc_1() {
    unsigned int *p = first;
    p[0]=0; p[1]=0; p[2]=0; p[3]=0; p[4]=0;
    p[5]=0; p[6]=0; p[7]=0; p[8]=0; p[9]=0;
    p = second;
    p[0]=0; p[1]=0; p[2]=0; p[3]=0; p[4]=0;
    p[5]=0; p[6]=0; p[7]=0; p[8]=0; p[9]=0;
}

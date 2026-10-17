// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// CMoveAgent::vfunc_7 @ 0x00102bc0
struct MoveTarget {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5();
    virtual void* slot6(const char*, int);
};
struct CMoveAgent {
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6();
    virtual void vfunc_7(char); virtual void vfunc_8(void*); virtual void vfunc_9(); virtual void vfunc_10();
    char padding[0x58 - 4]; MoveTarget* moveTarget;
};
void CMoveAgent::vfunc_7(char enabled) {
    if (enabled)
        vfunc_8(moveTarget->slot6("move", -1));
}
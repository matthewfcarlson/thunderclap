// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CSubtitleManager,void,float,float,float>::vfunc_2 @ 0x001c01b0
struct CSubtitleManager { char padding[4]; };
struct Closure3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void* unused, const float* values, void* unused2);
    char pad[0x1c - 4];
    void (CSubtitleManager::*method)(float, float, float);
    CSubtitleManager* target;
};
void Closure3::vfunc_2(void* unused, const float* values, void* unused2) {
    (target->*method)(values[0], values[1], values[2]);
}
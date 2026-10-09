class NonCopyable { public: virtual void vfunc_0(); virtual void vfunc_1(); };
class CGameController : public NonCopyable {
public:
    int pad;
    void* member;
    virtual CGameController* vfunc_2(unsigned char flag);
};
void Destroy(CGameController*);
CGameController* CGameController::vfunc_2(unsigned char flag) {
    *(void**)this = (void*)0x405e2c;
    ((NonCopyable*)member)->vfunc_1();
    *(void**)this = (void*)0x3f6098;
    if (flag & 1) Destroy(this);
    return this;
}
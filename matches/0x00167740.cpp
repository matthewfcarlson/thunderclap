// Same code shape as 0x0011cbc0 (propagated; names are from that function)
extern "C" void __cdecl ai_free(void* p);
extern "C" void __cdecl ai_delete(void* p);
struct VFT {
    int x;
};
extern const VFT PathLocatorTestCondition_vftable;

namespace hulkfight { namespace motion { class TargetCharacterTemplateCondition {
  public:
    virtual void vfunc_0();
    virtual void p_vfunc_1();
    virtual void p_vfunc_2();
    virtual void c_vfunc_3();
    virtual void p_vfunc_4();
    void* vfunc_5(unsigned char flag);
    virtual void vfunc_6();
    void Cleanup();
    char pad[8];
    void* m_p;
}; }}

void* hulkfight::motion::TargetCharacterTemplateCondition::vfunc_5(unsigned char flag) {
    *(const VFT**)this = &PathLocatorTestCondition_vftable;
    ai_free(m_p);
    Cleanup();
    if (flag & 1) {
        ai_delete(this);
    }
    return this;
}

// Same code shape as 0x0011cbc0 (propagated; names are from that function)
extern "C" void __cdecl ai_free(void* p);
extern "C" void __cdecl ai_delete(void* p);
struct VFT {
    int x;
};
extern const VFT CommentTrack_23daf0_vftable;

class CommentTrack_23daf0 {
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
};

void* CommentTrack_23daf0::vfunc_5(unsigned char flag) {
    *(const VFT**)this = &CommentTrack_23daf0_vftable;
    ai_free(m_p);
    Cleanup();
    if (flag & 1) {
        ai_delete(this);
    }
    return this;
}

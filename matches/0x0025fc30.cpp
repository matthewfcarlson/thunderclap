extern "C" char DAT_0042aa40[];
extern "C" char DAT_004e79d0[];
extern void* g_ptr;
extern int g_count_25fc30;
extern unsigned char g_flag_25fc30;
namespace om { class MetaType {
  public:
    virtual MetaType* vfunc_0(unsigned char);
    virtual void vfunc_1();
    virtual void vfunc_2();
}; }
void Register(void* p, om::MetaType* self);
void Cleanup(void* p, om::MetaType* self);
om::MetaType* om::MetaType::vfunc_0(unsigned char param) {
    void* p = g_ptr;
    *(void**)this = (void*)((int)DAT_0042aa40);
    Register(p, this);
    g_count_25fc30 = g_count_25fc30 - 1;
    if (param & 1)
        Cleanup((void*)((int)DAT_004e79d0), this);
    return this;
}

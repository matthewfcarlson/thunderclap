extern "C" char DAT_0042aa40[];
extern "C" char DAT_004e79d0[];
extern void* g_ptr;
extern int g_count;
extern unsigned char g_flag;
class MetaType {
  public:
    virtual MetaType* vfunc_0(unsigned char);
    virtual void vfunc_1();
    virtual void vfunc_2();
};
void Register(void* p, MetaType* self);
void Cleanup(void* p, MetaType* self);
MetaType* MetaType::vfunc_0(unsigned char param) {
    void* p = g_ptr;
    *(void**)this = (void*)((int)DAT_0042aa40);
    Register(p, this);
    g_count = g_count - 1;
    if (param & 1)
        Cleanup((void*)((int)DAT_004e79d0), this);
    return this;
}

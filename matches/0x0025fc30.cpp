#include "compat/ptr.h"
#include "decls/data/engine/om.h"
// data: g_count_25fc30 = DAT_004e79cc, g_ptr = DAT_004cd360

extern "C" char DAT_0042aa40[];
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
    void* p = (*(void**)&DAT_004cd360);
    *(void**)this = (void*)((hulk_intptr)DAT_0042aa40);
    Register(p, this);
    (*(int*)&DAT_004e79cc) = (*(int*)&DAT_004e79cc) - 1;
    if (param & 1)
        Cleanup((void*)((hulk_intptr)DAT_004e79d0), this);
    return this;
}

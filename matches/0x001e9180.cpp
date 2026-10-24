#include "compat/ptr.h"
#include "gen/core.h"

class CSoundSequence_1e9180 : public core::IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual CSoundSequence_1e9180* f2(unsigned char);
    char pad[0x18];
    void* member;
};
extern int seq_vftable_1e9180, base_vftable;
extern void thunk(void*);
CSoundSequence_1e9180* CSoundSequence_1e9180::f2(unsigned char flag) {
    *(hulk_ulongptr*)this = (hulk_ulongptr)&seq_vftable_1e9180;
    if (member) {
        struct X {
            virtual void a();
            virtual void b();
        };
        ((X*)member)->b();
        member = 0;
    }
    *(hulk_ulongptr*)this = (hulk_ulongptr)&base_vftable;
    if (flag & 1)
        thunk(this);
    return this;
}
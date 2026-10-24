// cl-flags: /O2 /GR /GX
#include "gen/core.h"



class Member_1eee90 {
  public:
    ~Member_1eee90();

  private:
    char data[0x10];
};

class CSoundTriggerExecutionState_1eee90 : public core::IRefCount {
  public:
    virtual void* vfunc_2(unsigned char flags);

  private:
    char pad[0x18];
    Member_1eee90 mMember;
};

extern "C" void* IRefCount_vftable_1eee90[];
void __cdecl operator delete(void*);
void __cdecl operator delete[](void*);

void* CSoundTriggerExecutionState_1eee90::vfunc_2(unsigned char flags) {
    CSoundTriggerExecutionState_1eee90* esi = this;
    unsigned char bl = flags;

    if (bl & 2) {
        int eax = *(int*)((char*)esi - 4);
        void* ebp = (char*)esi - 4;
        int ecx = eax + eax * 4;
        --eax;
        esi = (CSoundTriggerExecutionState_1eee90*)((char*)esi + ecx * 8);
        if (eax < 0)
            goto vector_loop_end;
        int edi = eax + 1;
        do {
            esi = (CSoundTriggerExecutionState_1eee90*)((char*)esi - 0x28);
            Member_1eee90* m = (Member_1eee90*)((char*)esi + 0x18);
            m->~Member_1eee90();
            --edi;
            *(void***)esi = IRefCount_vftable_1eee90;
        } while (edi);
    vector_loop_end:
        if (bl & 1) {
            operator delete[](ebp);
        }
        return ebp;
    }

    Member_1eee90* m = (Member_1eee90*)((char*)esi + 0x18);
    m->~Member_1eee90();
    *(void***)esi = IRefCount_vftable_1eee90;
    if (bl & 1) {
        operator delete(esi);
    }
    return esi;
}
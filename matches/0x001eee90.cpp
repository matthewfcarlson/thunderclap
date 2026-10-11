// cl-flags: /O2 /GR /GX

class IRefCount {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void* vfunc_2(unsigned char flags);
};

class Member {
  public:
    ~Member();

  private:
    char data[0x10];
};

class CSoundTriggerExecutionState : public IRefCount {
  public:
    virtual void* vfunc_2(unsigned char flags);

  private:
    char pad[0x18];
    Member mMember;
};

extern "C" void* IRefCount_vftable[];
void __cdecl operator delete(void*);
void __cdecl operator delete[](void*);

void* CSoundTriggerExecutionState::vfunc_2(unsigned char flags) {
    CSoundTriggerExecutionState* esi = this;
    unsigned char bl = flags;

    if (bl & 2) {
        int eax = *(int*)((char*)esi - 4);
        void* ebp = (char*)esi - 4;
        int ecx = eax + eax * 4;
        --eax;
        esi = (CSoundTriggerExecutionState*)((char*)esi + ecx * 8);
        if (eax < 0)
            goto vector_loop_end;
        int edi = eax + 1;
        do {
            esi = (CSoundTriggerExecutionState*)((char*)esi - 0x28);
            Member* m = (Member*)((char*)esi + 0x18);
            m->~Member();
            --edi;
            *(void***)esi = IRefCount_vftable;
        } while (edi);
    vector_loop_end:
        if (bl & 1) {
            operator delete[](ebp);
        }
        return ebp;
    }

    Member* m = (Member*)((char*)esi + 0x18);
    m->~Member();
    *(void***)esi = IRefCount_vftable;
    if (bl & 1) {
        operator delete(esi);
    }
    return esi;
}
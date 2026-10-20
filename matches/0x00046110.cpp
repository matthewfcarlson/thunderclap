// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* RDLHandler_46110_vftable[];

class RDLHandler_46110 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CCharacterTemplateManager_46110 : public RDLHandler_46110 {
  public:
    CCharacterTemplateManager_46110* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CCharacterTemplateManager_46110* CCharacterTemplateManager_46110::vfunc_5(signed char flags) {
    *(void***)this = RDLHandler_46110_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

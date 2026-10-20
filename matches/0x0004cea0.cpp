// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CCondition_4cea0_vftable[];

class CCondition_4cea0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CGrappleSizeCondition : public CCondition_4cea0 {
  public:
    CGrappleSizeCondition* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CGrappleSizeCondition* CGrappleSizeCondition::vfunc_5(signed char flags) {
    *(void***)this = CCondition_4cea0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

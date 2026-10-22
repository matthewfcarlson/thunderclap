// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CTrack_vftable[];

class CTrack {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class FightNodeTimeCondition_235d00 : public CTrack {
  public:
    FightNodeTimeCondition_235d00* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

FightNodeTimeCondition_235d00* FightNodeTimeCondition_235d00::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

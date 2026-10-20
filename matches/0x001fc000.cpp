// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Entity_1fc000_vftable[];

class Entity_1fc000 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CTriggerVolume_1fc000 : public Entity_1fc000 {
  public:
    CTriggerVolume_1fc000* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CTriggerVolume_1fc000* CTriggerVolume_1fc000::vfunc_5(signed char flags) {
    *(void***)this = Entity_1fc000_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

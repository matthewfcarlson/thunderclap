// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// CSmartPropAttachedCondition::vfunc_7 @ 0x00049190
struct Slot_49190 { int FUN_001d64a0(); };
struct Player_49190 {
    bool FUN_00035f20();
    Slot_49190* FUN_00035ef0(int i);
};
void* __fastcall FUN_000592a0(void* owner);
Player_49190* __fastcall FUN_00059a30(void* x);

class CSmartPropAttachedCondition {
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6();
    virtual bool vfunc_7(void* actor);
    char pad04[8];
    char matchId;
    char pad0d[3];
    int propId;
    int slotIndex;
};

bool CSmartPropAttachedCondition::vfunc_7(void* actor)
{
    Player_49190* p = FUN_00059a30(FUN_000592a0(actor));
    if (slotIndex == -1) {
        if (!p->FUN_00035f20())
            return false;
        if (!matchId)
            return true;
        for (int i = 0; i < 8; i++) {
            Slot_49190* s = p->FUN_00035ef0(i);
            if (s && s->FUN_001d64a0() == propId)
                return true;
        }
        return false;
    }
    Slot_49190* s = p->FUN_00035ef0(slotIndex);
    if (!s)
        return false;
    if (!matchId)
        return true;
    return s->FUN_001d64a0() == propId;
}

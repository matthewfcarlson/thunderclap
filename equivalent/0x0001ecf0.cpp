// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// CSmartPropUpdateAttachmentAction::vfunc_6 @ 0x0001ecf0
struct Ref { virtual void vfunc_0(); virtual void vfunc_1(); };
struct Attachment { char pad[0x14]; int id; };
struct Finder { Ref* FUN_00035ef0(int); };
struct Owner { Finder* FUN_00059a30(); void FUN_00059a40(); };
struct Source { Owner* FUN_000592a0(); };
struct CSmartPropUpdateAttachmentAction { void* vptr; char pad[0x18]; Source* source; Attachment* attachment; Ref* current; bool vfunc_6(int); };
bool CSmartPropUpdateAttachmentAction::vfunc_6(int) {
    Owner* owner = source->FUN_000592a0();
    Finder* finder = owner->FUN_00059a30();
    owner->FUN_00059a40();
    finder->FUN_00035ef0(attachment->id);
    Ref* next = finder->FUN_00035ef0(attachment->id);
    if (next) next->vfunc_0();
    if (current) current->vfunc_1();
    current = next;
    return next != 0;
}
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00173410 @ 0x00173410
namespace hulkfight { namespace motion {
struct Ref { virtual void FUN_00000000(); virtual void FUN_00000001(); };
struct Base { Base(); virtual void FUN_00000002(); };
struct JointTrackerAction : Base { char pad[0x18]; int value; Ref* ref; int other; char pad2[0x4c]; int last; JointTrackerAction(int v, Ref* r); };
JointTrackerAction::JointTrackerAction(int v, Ref* r) : Base() {
    value = 0;
    ref = 0;
    other = 0;
    last = 0;
    value = v;
    if (r) r->FUN_00000000();
    if (ref) ref->FUN_00000001();
    ref = r;
}
}}
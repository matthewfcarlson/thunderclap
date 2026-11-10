// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Node_296b20_vftable[];

class Node_296b20 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class LeafNode_296b20 : public Node_296b20 {
  public:
    LeafNode_296b20* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

LeafNode_296b20* LeafNode_296b20::vfunc_5(signed char flags) {
    *(void***)this = Node_296b20_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

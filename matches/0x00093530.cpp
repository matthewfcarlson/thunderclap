// Same code shape as 0x000933a0 (propagated; names are from that function)
class Inner_93530 {
  public:
    void Reset();
};
void FreeMem(void*);
class CUnlockableJumpMarker_93530 {
  public:
    virtual ~CUnlockableJumpMarker_93530();
    char pad[0x14];
    void* mPtr18;
};
CUnlockableJumpMarker_93530::~CUnlockableJumpMarker_93530() {
    if (mPtr18) {
        FreeMem(mPtr18);
        mPtr18 = 0;
    }
    ((Inner_93530*)((char*)this + 0x10))->Reset();
}

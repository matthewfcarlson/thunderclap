// Same code shape as 0x000933a0 (propagated; names are from that function)
class Inner_93430 {
  public:
    void Reset();
};
void FreeMem(void*);
class CUnlockable {
  public:
    virtual ~CUnlockable();
    char pad[0x14];
    void* mPtr18;
};
CUnlockable::~CUnlockable() {
    if (mPtr18) {
        FreeMem(mPtr18);
        mPtr18 = 0;
    }
    ((Inner_93430*)((char*)this + 0x10))->Reset();
}

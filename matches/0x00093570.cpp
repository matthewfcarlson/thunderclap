// Same code shape as 0x000933a0 (propagated; names are from that function)
class Inner_93570 {
  public:
    void Reset();
};
void FreeMem(void*);
class CUnlockableMovie_93570 {
  public:
    virtual ~CUnlockableMovie_93570();
    char pad[0x14];
    void* mPtr18;
};
CUnlockableMovie_93570::~CUnlockableMovie_93570() {
    if (mPtr18) {
        FreeMem(mPtr18);
        mPtr18 = 0;
    }
    ((Inner_93570*)((char*)this + 0x10))->Reset();
}

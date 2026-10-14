class Inner_933a0 {
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
    ((Inner_933a0*)((char*)this + 0x10))->Reset();
}

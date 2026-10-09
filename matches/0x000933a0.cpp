class Inner {
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
    ((Inner*)((char*)this + 0x10))->Reset();
}

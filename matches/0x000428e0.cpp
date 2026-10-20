class Context {
  public:
    int Check();
};
class CCharacter_428e0 {
  public:
    char pad0[0x10];
    Context* mContext;
    char pad14[0x334 - 0x14];
    CCharacter_428e0* mNext;
    void UpdateA(int, int);
    void UpdateB(int, int);
    void UpdateC(int, int);
    void UpdateNext(int, int);
};
void CCharacter_428e0::UpdateA(int a, int b) {
    CCharacter_428e0* p = this;
    do {
        if (p->mContext->Check()) {
            p->UpdateB(a, b);
            p->UpdateC(a, b);
        }
        if (!p->mNext)
            break;
        p->mNext->UpdateNext(a, b);
        p = p->mNext;
    } while (1);
}
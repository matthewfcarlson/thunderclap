class Sub {
  public:
    void Init();
    char b[8];
};
class CUnlockable {
  public:
    CUnlockable();
    virtual void V();
    char p4[4];
    unsigned char flag;
    char p9[7];
    Sub sub;
    int p18;
    char p1c[4];
    int p20;
};
class CUnlockableJumpMarker : public CUnlockable {
  public:
    CUnlockableJumpMarker();
    virtual void W();
};
inline CUnlockable::CUnlockable() {
    flag = 1;
    sub.Init();
}
CUnlockableJumpMarker::CUnlockableJumpMarker() {
    p18 = 0;
    p20 = 0;
}

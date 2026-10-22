__int64 __cdecl FUN_002672f0(int, int, int);
int __cdecl FUN_002673a0(int, int);
class CSoundCommand_1f0150 {
  public:
    virtual void v();
    int a, b, c;
    CSoundCommand_1f0150(int z) : a(0), b(0), c(z) {}
};
struct Q {
    __int64 value;
    Q(int x) : value(0) { value = FUN_002672f0(x, 0, 0); }
};
class CSoundCommand_PlaySequenceEvent : public CSoundCommand_1f0150 {
  public:
    Q q;
    int g;
    CSoundCommand_PlaySequenceEvent(int x, int y, int z);
    virtual void v();
};
CSoundCommand_PlaySequenceEvent::CSoundCommand_PlaySequenceEvent(int x, int y, int z) : CSoundCommand_1f0150(z), q(x) {
    g = FUN_002673a0(y, 0);
}
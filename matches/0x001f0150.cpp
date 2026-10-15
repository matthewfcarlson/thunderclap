__int64 __cdecl FUN_002672f0(int, int, int);
int __cdecl FUN_002673a0(int, int);
class Base {
  public:
    virtual void v();
    int a, b, c;
    Base(int z) : a(0), b(0), c(z) {}
};
struct Q {
    __int64 value;
    Q(int x) : value(0) { value = FUN_002672f0(x, 0, 0); }
};
class CSoundCommand_PlaySequenceEvent : public Base {
  public:
    Q q;
    int g;
    CSoundCommand_PlaySequenceEvent(int x, int y, int z);
    virtual void v();
};
CSoundCommand_PlaySequenceEvent::CSoundCommand_PlaySequenceEvent(int x, int y, int z) : Base(z), q(x) {
    g = FUN_002673a0(y, 0);
}
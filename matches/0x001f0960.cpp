typedef unsigned __int64 u64;
u64 __cdecl First(int, int, int);
int __cdecl Second(int, int);
class Base {
  public:
    virtual void Fn();
    int a, b, c;
    Base(int x) : a(0), b(0), c(x) {}
};
struct Pair {
    int d, e;
    Pair() : d(0), e(0) {}
};
class CSoundCommand_CueNISEvent : public Base {
  public:
    Pair p;
    int f;
    CSoundCommand_CueNISEvent(int x, int y, int z);
    virtual void Fn();
};
CSoundCommand_CueNISEvent::CSoundCommand_CueNISEvent(int x, int y, int z) : Base(z) {
    u64 v = First(x, 0, 0);
    p.d = (int)v;
    p.e = (int)(v >> 32);
    f = Second(y, 0);
}
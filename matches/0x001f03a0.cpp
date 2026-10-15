typedef unsigned __int64 I64;
extern I64 __cdecl Make64(int, int, int);
extern int __cdecl MakeInt(int, int);
struct Pair {
    int lo, hi;
    Pair() : lo(0), hi(0) {}
    void operator=(I64 v) {
        lo = (int)v;
        hi = (int)(v >> 32);
    }
};
class Base {
  public:
    int a, b, c;
    Base() : a(0), b(0), c(0) {}
};
class CSoundCommand_SetLoopPitchEvent : public Base {
  public:
    virtual void Fn();
    Pair value;
    int mid, arg1, arg2;
    CSoundCommand_SetLoopPitchEvent(int, int, int, int, int);
};
CSoundCommand_SetLoopPitchEvent::CSoundCommand_SetLoopPitchEvent(int x, int y, int z, int w, int unused) {
    value = Make64(x, 0, 0);
    mid = MakeInt(y, 0);
    arg1 = z;
    arg2 = w;
}
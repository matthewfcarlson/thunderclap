extern "C" unsigned __int64 __cdecl createPair(int, int, int);
extern "C" int __cdecl createOther(int, int);
class CSoundCommand_1f04e0 {
  public:
    int a, b, c;
    virtual void run();
    CSoundCommand_1f04e0(int x) : a(0), b(0), c(x) {}
};
struct Pair {
    unsigned __int64 v;
    Pair() : v(0) {}
    void Init(int p) { v = createPair(p, 0, 0); }
};
class CSoundCommand_StopTunableEvent : public CSoundCommand_1f04e0 {
  public:
    Pair pair;
    int other, value;
    CSoundCommand_StopTunableEvent(int p, int q, int r, int x);
    virtual void run();
};
CSoundCommand_StopTunableEvent::CSoundCommand_StopTunableEvent(int p, int q, int r, int x) : CSoundCommand_1f04e0(x) {
    pair.Init(p);
    other = createOther(q, 0);
    value = r;
}

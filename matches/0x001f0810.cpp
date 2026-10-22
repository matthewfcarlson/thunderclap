extern "C" unsigned __int64 getMusic(int, int, int);
extern "C" int getEvent(int, int);
class CSoundCommand_1f0810 {
  public:
    virtual void f();
    int a, b, c;
    CSoundCommand_1f0810(int x) : a(0), b(0), c(x) {}
};
struct Pair {
    int d, e;
    Pair() : d(0), e(0) {}
    void set(unsigned __int64 v) {
        d = (int)v;
        e = (int)(v >> 32);
    }
};
class CSoundCommand_PlayMusicEvent : public CSoundCommand_1f0810 {
  public:
    Pair p;
    int f;
    CSoundCommand_PlayMusicEvent(int x, int y, int z);
    virtual void g();
};
CSoundCommand_PlayMusicEvent::CSoundCommand_PlayMusicEvent(int x, int y, int z) : CSoundCommand_1f0810(z) {
    p.set(getMusic(x, 0, 0));
    f = getEvent(y, 0);
}
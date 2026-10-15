extern "C" unsigned __int64 getMusic(int, int, int);
extern "C" int getEvent(int, int);
class Base {
  public:
    virtual void f();
    int a, b, c;
    Base(int x) : a(0), b(0), c(x) {}
};
struct Pair {
    int d, e;
    Pair() : d(0), e(0) {}
    void set(unsigned __int64 v) {
        d = (int)v;
        e = (int)(v >> 32);
    }
};
class CSoundCommand_PlayMusicEvent : public Base {
  public:
    Pair p;
    int f;
    CSoundCommand_PlayMusicEvent(int x, int y, int z);
    virtual void g();
};
CSoundCommand_PlayMusicEvent::CSoundCommand_PlayMusicEvent(int x, int y, int z) : Base(z) {
    p.set(getMusic(x, 0, 0));
    f = getEvent(y, 0);
}
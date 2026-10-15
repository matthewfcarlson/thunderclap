class Base {
  public:
    virtual void f();
    char pad[4];
    Base();
};
class Track {
  public:
    Track(const char*, int);
    char pad[12];
};
char* __cdecl find(const char*, int);
struct Ptr {
    char* p;
    inline Ptr& operator=(char* v) {
        p = v;
        return *this;
    }
};
class SeqEventCrossFade : public Base {
  public:
    int a, b, c, d;
    char e, f;
    char gap[2];
    Track track;
    Ptr name;
    int x, y;
    SeqEventCrossFade();
    virtual void g();
};
SeqEventCrossFade::SeqEventCrossFade() : a(0), b(1000), c(0), d(1000), e(0), f(0), track("MySeqTrack", 2) {
    name = find("stitched", 0);
    x = 0;
    y = 0;
}
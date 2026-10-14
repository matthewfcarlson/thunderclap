class PathTrack;
void __cdecl thunk(int);
class Init_11c840 {
  public:
    void init();
};
class Base_11c840 {
  public:
    void base();
};
class PathTrack {
  public:
    virtual ~PathTrack();
    char pad[0x34];
    int m38;
    char pad3c[4];
};
PathTrack::~PathTrack() {
    thunk(m38);
    ((Init_11c840*)((char*)this + 0x40))->init();
    ((Base_11c840*)this)->base();
}

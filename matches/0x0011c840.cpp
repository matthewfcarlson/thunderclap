class PathTrack;
void __cdecl thunk(int);
class Init { public: void init(); };
class Base { public: void base(); };
class PathTrack {
public:
    virtual ~PathTrack();
    char pad[0x34];
    int m38;
    char pad3c[4];
};
PathTrack::~PathTrack() {
    thunk(m38);
    ((Init*)((char*)this + 0x40))->init();
    ((Base*)this)->base();
}

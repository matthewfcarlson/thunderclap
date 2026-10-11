extern "C" char DAT_00412ad0[];
struct Base {
    virtual void f();
    ~Base();
};
struct Sub {
    unsigned char x[8];
    void Dtor();
};
struct WallRunTrack : Base {
    unsigned char pad[0x34];
    Sub a;
    Sub b;
    Sub c;
    void Kill();
};
void WallRunTrack::Kill() {
    *(void**)this = (void*)((int)DAT_00412ad0);
    c.Dtor();
    b.Dtor();
    a.Dtor();
    this->Base::~Base();
}

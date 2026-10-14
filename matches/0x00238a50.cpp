typedef unsigned int u32_238a50;
extern u32_238a50 PrintTrack_vftable;
void __cdecl ReleaseThing(int);
struct PrintTrack {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    int p0, p1, p2;
    int m10;
    int m14;
    void Finish();
    void Cleanup();
};
void PrintTrack::Finish() {
    *(u32_238a50*)this = (u32_238a50)&PrintTrack_vftable;
    ReleaseThing(m10);
    ReleaseThing(m14);
    Cleanup();
}
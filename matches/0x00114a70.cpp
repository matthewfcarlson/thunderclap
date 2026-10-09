typedef unsigned int u32;
void* __cdecl Alloc(unsigned int);
class Base {
  public:
    void Init();
};
class Member {
  public:
    void Init();
};
class HulkActionTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    int x[10];
};
HulkActionTrack* target() {
    HulkActionTrack* p = (HulkActionTrack*)Alloc(0x28);
    if (p) {
        ((Base*)p)->Init();
        *(u32*)p = 0x40dc14;
        *(u32*)((char*)p + 0xc) = 0;
        *(u32*)((char*)p + 0x10) = 0xbf800000;
        ((Member*)((char*)p + 0x18))->Init();
        *(u32*)((char*)p + 0x20) = 0;
        *(u32*)((char*)p + 8) = 1;
        return p;
    }
    return (HulkActionTrack*)0L;
}
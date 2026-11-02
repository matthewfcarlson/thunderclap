class CGrabTrack {
  public:
    virtual void v();
    ~CGrabTrack();
    char pad[0x14];
    char a[0x20];
    char b[0xc];
    char c[4];
};
extern "C" void __fastcall FUN_0027af50(void*);
extern "C" void __fastcall FUN_00234150(void*);
extern "C" void __fastcall FUN_00234150(void*);
void __fastcall FD(void*);
CGrabTrack::~CGrabTrack() {
    FUN_00234150((char*)this + 0x44);
    FUN_00234150((char*)this + 0x38);
    FUN_0027af50((char*)this + 0x18);
    FD(this);
}

class CGrabTrack {
  public:
    virtual void v();
    ~CGrabTrack();
    char pad[0x14];
    char a[0x20];
    char b[0xc];
    char c[4];
};
void __fastcall FA(void*);
void __fastcall FB(void*);
void __fastcall FC(void*);
void __fastcall FD(void*);
CGrabTrack::~CGrabTrack() {
    FC((char*)this + 0x44);
    FB((char*)this + 0x38);
    FA((char*)this + 0x18);
    FD(this);
}

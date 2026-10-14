extern "C" char DAT_00404b3c[];
extern const char* gName_983d0;
class CamInit {
  public:
    void InitBase();
};
class CamSetup {
  public:
    void SetupPart();
};
class CamCfg {
  public:
    void ConfigPart(const char*);
};
struct Blend_983d0 {
    int vft;
    char pad1[0x1a8 - 4];
    int field1a8;
};
extern "C" Blend_983d0* __fastcall FUN_000983d0(Blend_983d0* self) {
    char* p;
    CamCfg* c;
    ((CamInit*)self)->InitBase();
    self->vft = ((int)DAT_00404b3c);
    p = (char*)self + 0x1a8;
    ((CamSetup*)p)->SetupPart();
    c = (CamCfg*)((char*)self + 8);
    const char* n = gName_983d0;
    *(int*)((char*)self + 0xd0) = 5;
    c->ConfigPart(n);
    *(int*)p = 0;
    *(int*)((char*)self + 0x174) = 0;
    *(int*)((char*)self + 0x170) = 0;
    *(int*)((char*)self + 0x17c) = 0;
    return self;
}

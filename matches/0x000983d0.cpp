extern const char* gName;
class CamInit { public: void InitBase(); };
class CamSetup { public: void SetupPart(); };
class CamCfg { public: void ConfigPart(const char*); };
struct Blend {
  int vft;
  char pad1[0x1a8 - 4];
  int field1a8;
};
extern "C" Blend* __fastcall FUN_000983d0(Blend* self) {
  char* p;
  CamCfg* c;
  ((CamInit*)self)->InitBase();
  self->vft = 0x404b3c;
  p = (char*)self + 0x1a8;
  ((CamSetup*)p)->SetupPart();
  c = (CamCfg*)((char*)self + 8);
  const char* n = gName;
  *(int*)((char*)self + 0xd0) = 5;
  c->ConfigPart(n);
  *(int*)p = 0;
  *(int*)((char*)self + 0x174) = 0;
  *(int*)((char*)self + 0x170) = 0;
  *(int*)((char*)self + 0x17c) = 0;
  return self;
}

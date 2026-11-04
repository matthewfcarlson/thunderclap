#include "decls/data/game/hulkfight.h"
// data: gName_983d0 = DAT_0049e108

#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" char DAT_00404b3c[];
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
};
struct Blend_983d0 {
    hulk_intptr vft;
    char pad04[0x8 - 4];
    char cfg08[0xd0 - 0x8];
    int fieldd0;
    char padd4[0x170 - 0xd4];
    int field170;
    int field174;
    char pad178[0x17c - 0x178];
    int field17c;
    char pad180[0x1a8 - 0x180];
    int field1a8;
};
extern "C" Blend_983d0* __fastcall FUN_000983d0(Blend_983d0* self) {
    char* p;
    CamCfg* c;
    ((CamInit*)self)->InitBase();
    self->vft = ((hulk_intptr)DAT_00404b3c);
    p = (char*)&self->field1a8;
    ((CamSetup*)p)->SetupPart();
    c = (CamCfg*)self->cfg08;
    const char* n = DAT_0049e108;
    self->fieldd0 = 5;
    ((owners::Target_27b040 *)c)->FUN_0027b040((hulk_uintptr)n);
    *(int*)p = 0;
    self->field174 = 0;
    self->field170 = 0;
    self->field17c = 0;
    return self;
}

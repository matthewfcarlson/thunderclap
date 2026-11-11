// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00034400..0x00034ca0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/data/game/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fbb41d57 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fbb41d57 {} using namespace fn_fbb41d57;
#include "game/hulkfight.h"

// ---- declarations shared by the functions below
namespace fn_fbb41d57 {
extern "C" int __cdecl FUN_0034483c(float);
class Obj_34770 {
  public:
    char pad[0x2f8];
    unsigned char value;
    unsigned char Get() { return value; }
};
struct Obj_34800 {
    char pad[0x340];
    float value;
};
class Obj_34820 {
  public:
    float Get();
    char pad[0x348];
    float value;
};
class Obj_34890 {
  public:
    char pad[0x370];
    float value;
    float GetValue();
};
struct Obj_348f0 {
    char pad[0x384];
    char value;
};
struct X_34ad0 {
    void Call();
    X_34ad0* Target();
};
class Obj_34b70 {
  public:
    char pad[0x1b48];
    unsigned char m;
    void Set(unsigned char v);
};


// 0x00034400 FUN_00034400 (9 B): matches/0x00034400.cpp
// sym: ?FUN_00034400@fn_fbb41d57@@YAHM@Z
int __cdecl FUN_00034400(float f) {
    return (int)f;
}

} // namespace fn_fbb41d57

// 0x00034440 FUN_00034440 (35 B): matches/0x00034440.cpp
// sym: ?FUN_00034440@Vec3_34440@owners@@QAEXPAU12@0@Z
void owners::Vec3_34440::FUN_00034440(owners::Vec3_34440* a, owners::Vec3_34440* b) {
    x = a->x + b->x;
    y = a->y + b->y;
    z = a->z + b->z;
}


// 0x000344b0 FUN_000344b0 (33 B): matches/0x000344b0.cpp
// sym: ?FUN_000344b0@Vec3_344b0@owners@@QAEPAU12@M@Z
owners::Vec3_344b0* owners::Vec3_344b0::FUN_000344b0(float s) {
    x *= s;
    y *= s;
    z *= s;
    return this;
}

namespace fn_fbb41d57 {

// 0x00034770 FUN_00034770 (7 B): matches/0x00034770.cpp
// sym: ?FUN_00034770@fn_fbb41d57@@YIEPAVObj_34770@1@@Z
unsigned char __fastcall FUN_00034770(Obj_34770* self) {
    return self->Get();
}


// 0x00034800 FUN_00034800 (7 B): matches/0x00034800.cpp
// sym: ?FUN_00034800@fn_fbb41d57@@YIMPAUObj_34800@1@@Z
float __fastcall FUN_00034800(Obj_34800* self) {
    return self->value;
}


// 0x00034820 FUN_00034820 (7 B): matches/0x00034820.cpp
// sym: ?Get@Obj_34820@fn_fbb41d57@@QAEMXZ
float Obj_34820::Get() {
    return value;
}


// 0x00034890 FUN_00034890 (7 B): matches/0x00034890.cpp
// sym: ?GetValue@Obj_34890@fn_fbb41d57@@QAEMXZ
float Obj_34890::GetValue() {
    return value;
}


// 0x000348f0 FUN_000348f0 (7 B): matches/0x000348f0.cpp
// sym: @FUN_000348f0@4
extern "C" char __fastcall FUN_000348f0(Obj_348f0* self) {
    return self->value;
}


// 0x00034ad0 FUN_00034ad0 (12 B): matches/0x00034ad0.cpp
// sym: ?Target@X_34ad0@fn_fbb41d57@@QAEPAU12@XZ
X_34ad0* X_34ad0::Target() {
    Call();
    return this;
}


// 0x00034b70 FUN_00034b70 (13 B): matches/0x00034b70.cpp
// sym: ?Set@Obj_34b70@fn_fbb41d57@@QAEXE@Z
void Obj_34b70::Set(unsigned char v) {
    m = v;
}

} // namespace fn_fbb41d57

// 0x00034c80 FUN_00034c80 (20 B): matches/0x00034c80.cpp
// sym: ?FUN_00034c80@Wrapper_34c80@owners@@QAEXH@Z
void owners::Wrapper_34c80::FUN_00034c80(int value) {
    FUN_001c5080((*(float*)&DAT_00421894), value);
}


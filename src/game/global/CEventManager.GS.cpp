// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001c96e0..0x001cc5e0 (kind game, layer game, confidence high), dominant class CEventManager
#include "tree_prelude.h"
#include "decls/address.h"
#include "decls/data/game/hulkfight/scenario.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f6c94213 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f6c94213 {} using namespace fn_f6c94213;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f6c94213 {
struct Vec3_1c9840 { float x,y,z; };
struct Writer_1c9840 {
 void FUN_001d1e50(const char*, Vec3_1c9840);
 void FUN_001d1d10();
};
void __cdecl FUN_00096d50(char*, int, unsigned int, unsigned int);
struct Actor_1c9840 {
 char pad0[0x14];
 char actor[0x40];
 char templ[0x20];
 char variation[0x24];
 unsigned int teamLow;
 unsigned int teamHigh;
 Vec3_1c9840 position;
 Writer_1c9840* FUN_001d4c90();
 bool target();
};
struct Service_1c9970 {
 void FUN_001d1e10(const char*, int);
 void FUN_001d1d10();
};
extern "C" Service_1c9970* __cdecl FUN_001d4c90();
void __cdecl FUN_00096d50(char*, unsigned int, unsigned int, unsigned int);
struct Properties_1c9b80 {
    void FUN_001d1d10();
};
struct Frame_1c9b80 {
    char buffer[32];
};
struct Object {
    char padding[0x18];
    unsigned int idLow, idHigh;
    Properties_1c9b80* FUN_001d4c90();
    bool target();
};
struct Report {    void FUN_001d1d10(); };
struct Actor_1ca430 { const char* FUN_00036d00(); };
struct Registry_1ca430 {  };
} // namespace fn_f6c94213
struct World { char pad[0x44]; Registry_1ca430* registry; };
namespace fn_f6c94213 {
extern "C" void __cdecl FUN_00096d50(char*, int, int, int);
struct Target_1ca430 { char pad[0x10]; int actor; char pad14[4]; int prop1; int prop2; int type1; int type2; int index; Report* FUN_001d4c90(); bool run(); };
struct Record_1cbc20 { unsigned size; char data[220]; };
struct Queue_1cbc20 { char pad[16]; Record_1cbc20* next; Record_1cbc20* end; bool FUN_001cbc20(const Record_1cbc20* source); };


// 0x001c9840 FUN_001c9840 (212 B): equivalent/0x001c9840.cpp
// sym: ?target@Actor_1c9840@fn_f6c94213@@QAE_NXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001c9840 @ 0x001c9840
bool Actor_1c9840::target() {
 Writer_1c9840* writer = FUN_001d4c90();
 if (!writer || !((owners::Obj_1d2e80 *)writer)->FUN_001d2e80()) {
 return false;
 }
 ((owners::Thing_1d1d50 *)writer)->FUN_001d1d50((hulk_uintptr)"actor", (hulk_uintptr)actor);
 ((owners::Thing_1d1d50 *)writer)->FUN_001d1d50((hulk_uintptr)"template", (hulk_uintptr)templ);
 ((owners::Thing_1d1d50 *)writer)->FUN_001d1d50((hulk_uintptr)"template_variation", (hulk_uintptr)variation);
 writer->FUN_001d1e50("position", position);
 char team[32];
 FUN_00096d50(team,32,teamLow,teamHigh);
 ((owners::Thing_1d1d50 *)writer)->FUN_001d1d50((hulk_uintptr)"team", (hulk_uintptr)team);
 writer->FUN_001d1d10();
 return true;
}

} // namespace fn_f6c94213

// 0x001c9970 FUN_001c9970 (169 B): equivalent/0x001c9970.cpp
// sym: ?FUN_001c9970@Object_1c9970@owners@@QAE_NXZ
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 6/6)
// FUN_001c9970 @ 0x001c9970
bool owners::Object_1c9970::FUN_001c9970() {
 bool result = false;
 if (FUN_001c9840()) {
  Service_1c9970* service = FUN_001d4c90();
  if (service && ((owners::Obj_1d2e80 *)service)->FUN_001d2e80()) {
   char origin[32];
   FUN_00096d50(origin, 32, originLow, originHigh);
   ((owners::Thing_1d1d50 *)service)->FUN_001d1d50((hulk_uintptr)"origin", (hulk_uintptr)origin);
   service->FUN_001d1e10("devastator", devastator);
   service->FUN_001d1d10();
   result = true;
  }
 }
 return result;
}

namespace fn_f6c94213 {

// 0x001c9b80 FUN_001c9b80 (119 B): equivalent/0x001c9b80.cpp
// sym: ?target@Object@fn_f6c94213@@QAE_NXZ
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 4/4)
// FUN_001c9b80 @ 0x001c9b80
bool Object::target() {
    Frame_1c9b80 fr;
    Properties_1c9b80* properties = FUN_001d4c90();
    if (!properties || !((owners::Obj_1d2e80 *)properties)->FUN_001d2e80()) {
        return false;
    }
    FUN_00096d50(fr.buffer, 32, idLow, idHigh);
    ((owners::Thing_1d1d50 *)properties)->FUN_001d1d50((hulk_uintptr)"civilian", (hulk_uintptr)(fr.buffer));
    properties->FUN_001d1d10();
    return true;
}

} // namespace fn_f6c94213

// 0x001c9c50 FUN_001c9c50 (119 B): equivalent/0x001c9c50.cpp [wrapped: conflict: Object]
// sym: ?target@Object@fn_001c9c50@@QAE_NXZ
namespace fn_001c9c50 {
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 4/4)
// FUN_001c9c50 @ 0x001c9c50
// cl-flags: /GS
struct Properties_1c9c50 {
    void FUN_001d1d10();
};
extern "C++" __declspec(nothrow) void __cdecl FUN_00096d50(char* buffer, int size, unsigned int low, unsigned int high);
struct Frame_1c9c50 {
    char buffer[32];
};
struct Object {
    char padding[0x18];
    unsigned int idLow, idHigh;
    Properties_1c9c50* FUN_001d4c90();
    bool target();
};
bool Object::target() {
    Frame_1c9c50 fr;
    Properties_1c9c50* properties = FUN_001d4c90();
    if (!properties || !((owners::Obj_1d2e80 *)properties)->FUN_001d2e80()) {
        return false;
    }
    FUN_00096d50(fr.buffer, 32, idLow, idHigh);
    ((owners::Thing_1d1d50 *)properties)->FUN_001d1d50((hulk_uintptr)"civilian", (hulk_uintptr)(fr.buffer));
    properties->FUN_001d1d10();
    return true;
}
} // namespace fn_001c9c50


// 0x001c9d20 FUN_001c9d20 (119 B): equivalent/0x001c9d20.cpp [wrapped: conflict: Object]
// sym: ?target@Object@fn_001c9d20@@QAE_NXZ
namespace fn_001c9d20 {
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 4/4)
// FUN_001c9d20 @ 0x001c9d20
// cl-flags: /GS
struct Properties_1c9d20 {
    void FUN_001d1d10();
};
extern "C++" __declspec(nothrow) void __cdecl FUN_00096d50(char* buffer, int size, unsigned int low, unsigned int high);
struct Frame_1c9d20 {
    char buffer[32];
};
struct Object {
    char padding[0x18];
    unsigned int idLow, idHigh;
    Properties_1c9d20* FUN_001d4c90();
    bool target();
};
bool Object::target() {
    Frame_1c9d20 fr;
    Properties_1c9d20* properties = FUN_001d4c90();
    if (!properties || !((owners::Obj_1d2e80 *)properties)->FUN_001d2e80()) {
        return false;
    }
    FUN_00096d50(fr.buffer, 32, idLow, idHigh);
    ((owners::Thing_1d1d50 *)properties)->FUN_001d1d50((hulk_uintptr)"civilian", (hulk_uintptr)(fr.buffer));
    properties->FUN_001d1d10();
    return true;
}
} // namespace fn_001c9d20


// 0x001c9df0 FUN_001c9df0 (119 B): equivalent/0x001c9df0.cpp [wrapped: conflict: Object]
// sym: ?target@Object@fn_001c9df0@@QAE_NXZ
namespace fn_001c9df0 {
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 4/4)
// FUN_001c9df0 @ 0x001c9df0
// cl-flags: /GS
struct Properties_1c9df0 {
    void FUN_001d1d10();
};
extern "C++" __declspec(nothrow) void __cdecl FUN_00096d50(char* buffer, int size, unsigned int low, unsigned int high);
struct Frame_1c9df0 {
    char buffer[32];
};
struct Object {
    char padding[0x18];
    unsigned int idLow, idHigh;
    Properties_1c9df0* FUN_001d4c90();
    bool target();
};
bool Object::target() {
    Frame_1c9df0 fr;
    Properties_1c9df0* properties = FUN_001d4c90();
    if (!properties || !((owners::Obj_1d2e80 *)properties)->FUN_001d2e80()) {
        return false;
    }
    FUN_00096d50(fr.buffer, 32, idLow, idHigh);
    ((owners::Thing_1d1d50 *)properties)->FUN_001d1d50((hulk_uintptr)"civilian", (hulk_uintptr)(fr.buffer));
    properties->FUN_001d1d10();
    return true;
}
} // namespace fn_001c9df0


// 0x001c9ec0 FUN_001c9ec0 (119 B): equivalent/0x001c9ec0.cpp [wrapped: conflict: Object]
// sym: ?target@Object@fn_001c9ec0@@QAE_NXZ
namespace fn_001c9ec0 {
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 4/4)
// FUN_001c9ec0 @ 0x001c9ec0
// cl-flags: /GS
struct Properties_1c9ec0 {
    void FUN_001d1d10();
};
extern "C++" __declspec(nothrow) void __cdecl FUN_00096d50(char* buffer, int size, unsigned int low, unsigned int high);
struct Frame_1c9ec0 {
    char buffer[32];
};
struct Object {
    char padding[0x18];
    unsigned int idLow, idHigh;
    Properties_1c9ec0* FUN_001d4c90();
    bool target();
};
bool Object::target() {
    Frame_1c9ec0 fr;
    Properties_1c9ec0* properties = FUN_001d4c90();
    if (!properties || !((owners::Obj_1d2e80 *)properties)->FUN_001d2e80()) {
        return false;
    }
    FUN_00096d50(fr.buffer, 32, idLow, idHigh);
    ((owners::Thing_1d1d50 *)properties)->FUN_001d1d50((hulk_uintptr)"civilian", (hulk_uintptr)(fr.buffer));
    properties->FUN_001d1d10();
    return true;
}
} // namespace fn_001c9ec0

namespace fn_f6c94213 {

// 0x001ca430 FUN_001ca430 (270 B): equivalent/0x001ca430.cpp
// sym: ?run@Target_1ca430@fn_f6c94213@@QAE_NXZ
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 8/8)
// FUN_001ca430 @ 0x001ca430
bool Target_1ca430::run() { Report* report = FUN_001d4c90(); bool result=false; if (report && ((owners::Obj_1d2e80 *)report)->FUN_001d2e80()) { char buffer[32]; FUN_00096d50(buffer,32,prop1,prop2); ((owners::Thing_1d1d50 *)report)->FUN_001d1d50((hulk_uintptr)"prop", (hulk_uintptr)buffer); FUN_00096d50(buffer,32,type1,type2); ((owners::Thing_1d1d50 *)report)->FUN_001d1d50((hulk_uintptr)"prop_type", (hulk_uintptr)buffer); ((owners::Obj_1d1dd0 *)report)->FUN_001d1dd0((hulk_intptr)"attachment_index", index); World* world=DAT_004dd700; int actorId=actor; if (world) { Actor_1ca430* found=((Actor_1ca430 *)((owners::ThisWrap_00059c10 *)(world->registry))->FUN_00059c10((void *)(hulk_uintptr)(int)actorId)); const char* name=found ? found->FUN_00036d00() : "UNKNOWN"; ((owners::Thing_1d1d50 *)report)->FUN_001d1d50((hulk_uintptr)"actor", (hulk_uintptr)name); ((owners::Thing_1d1d50 *)report)->FUN_001d1d50((hulk_uintptr)"prop_DANGEROUS", (hulk_uintptr)"prop_DANGEROUS is not defined in RELEASE!"); ((owners::Thing_1d1d50 *)report)->FUN_001d1d50((hulk_uintptr)"prop_type_DANGEROUS", (hulk_uintptr)"prop_type_DANGEROUS is not defined in RELEASE!"); result=true; } report->FUN_001d1d10(); }  return result; }

} // namespace fn_f6c94213

// 0x001ca5b0 FUN_001ca5b0 (254 B): equivalent/0x001ca5b0.cpp [wrapped: conflict: World]
// sym: ?FUN_001ca5b0@Target_1ca5b0@fn_001ca5b0@@QAE_NXZ
namespace fn_001ca5b0 {
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 8/8)
// FUN_001ca5b0 @ 0x001ca5b0
// cl-flags: /GS
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Actor_1ca5b0 { const char* FUN_00036d00(); };
struct Lookup_1ca5b0 {  };
struct World { char pad[0x44]; Lookup_1ca5b0* lookup; };
struct Reporter_1ca5b0 {   void FUN_001d1d10(); };
extern void __cdecl FUN_00096d50(char*, unsigned int, unsigned int, unsigned int);
struct Target_1ca5b0 { char pad[0x10]; unsigned int actor; char pad14[4]; unsigned int propLow,propHigh,typeLow,typeHigh; Reporter_1ca5b0* FUN_001d4c90(); bool FUN_001ca5b0(); };
bool Target_1ca5b0::FUN_001ca5b0() {
 Reporter_1ca5b0* reporter = FUN_001d4c90();
 if (!reporter || !((owners::Obj_1d2e80 *)reporter)->FUN_001d2e80()) { return false; }
 char buffer[32];
 FUN_00096d50(buffer,32,propLow,propHigh);
 ((owners::Thing_1d1d50 *)reporter)->FUN_001d1d50((hulk_uintptr)"prop", (hulk_uintptr)buffer);
 FUN_00096d50(buffer,32,typeLow,typeHigh);
 ((owners::Thing_1d1d50 *)reporter)->FUN_001d1d50((hulk_uintptr)"prop_type", (hulk_uintptr)buffer);
 World* manager=DAT_004dd700;
 unsigned int id=actor;
 if (!manager) { reporter->FUN_001d1d10();  return false; }
 Actor_1ca5b0* found=((Actor_1ca5b0 *)((owners::ThisWrap_00059c10 *)(manager->lookup))->FUN_00059c10((void *)(hulk_uintptr)(unsigned int)id));
 const char* name=found ? found->FUN_00036d00() : "UNKNOWN";
 ((owners::Thing_1d1d50 *)reporter)->FUN_001d1d50((hulk_uintptr)"actor", (hulk_uintptr)name);
 ((owners::Thing_1d1d50 *)reporter)->FUN_001d1d50((hulk_uintptr)"prop_DANGEROUS", (hulk_uintptr)"prop_DANGEROUS is not defined in RELEASE!");
 ((owners::Thing_1d1d50 *)reporter)->FUN_001d1d50((hulk_uintptr)"prop_type_DANGEROUS", (hulk_uintptr)"prop_type_DANGEROUS is not defined in RELEASE!");
 reporter->FUN_001d1d10();
 return true;
}
} // namespace fn_001ca5b0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001ca730 FUN_001ca730 (249 B): equivalent/0x001ca730.cpp [wrapped: conflict: Object]
// sym: ?target@Object@fn_001ca730@@QAE_NXZ
namespace fn_001ca730 {
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 4/4)
// FUN_001ca730 @ 0x001ca730
// cl-flags: /GS
struct Reporter_1ca730 {
 void FUN_001d1d10();
};
void __cdecl FUN_00096d50(char*, unsigned int, unsigned int, unsigned int);
struct Object {
 char pad[0x18];
 unsigned int propLo, propHi;
 unsigned int typeLo, typeHi;
 unsigned int increase;
 unsigned int unused;
 unsigned int originLo, originHi;
 Reporter_1ca730* FUN_001d4c90();
 bool target();
};
bool Object::target() {
 Reporter_1ca730* r = FUN_001d4c90();
 if (!r || !((owners::Obj_1d2e80 *)r)->FUN_001d2e80()) {
 return false;
 }
 char buffer[32];
 FUN_00096d50(buffer, 32, propLo, propHi);
 ((owners::Thing_1d1d50 *)r)->FUN_001d1d50((hulk_uintptr)"prop", (hulk_uintptr)buffer);
 FUN_00096d50(buffer, 32, typeLo, typeHi);
 ((owners::Thing_1d1d50 *)r)->FUN_001d1d50((hulk_uintptr)"prop_type", (hulk_uintptr)buffer);
 FUN_00096d50(buffer, 32, originLo, originHi);
 ((owners::Thing_1d1d50 *)r)->FUN_001d1d50((hulk_uintptr)"origin", (hulk_uintptr)buffer);
 ((owners::Obj_1d1dd0 *)r)->FUN_001d1dd0((hulk_intptr)"ers_increase", (int)increase);
 ((owners::Thing_1d1d50 *)r)->FUN_001d1d50((hulk_uintptr)"prop_DANGEROUS", (hulk_uintptr)"prop_DANGEROUS is not defined in RELEASE!");
 ((owners::Thing_1d1d50 *)r)->FUN_001d1d50((hulk_uintptr)"prop_type_DANGEROUS", (hulk_uintptr)"prop_type_DANGEROUS is not defined in RELEASE!");
 r->FUN_001d1d10();
 return true;
}
} // namespace fn_001ca730


// 0x001ca890 FUN_001ca890 (270 B): equivalent/0x001ca890.cpp [wrapped: conflict: World]
// sym: ?run@Target_1ca890@fn_001ca890@@QAE_NXZ
namespace fn_001ca890 {
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 8/8)
// FUN_001ca890 @ 0x001ca890
// cl-flags: /GS
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Actor_1ca890 { const char* FUN_00036d00(); };
struct Registry_1ca890 {  };
struct World { char pad[0x44]; Registry_1ca890* registry; };
struct Writer_1ca890 {    void FUN_001d1d10(); };
extern "C++" __declspec(nothrow) void __cdecl FUN_00096d50(char*, int, unsigned int, unsigned int);
struct Target_1ca890 { char pad[0x10]; unsigned int actor; char pad14[4]; unsigned int propLow, propHigh, typeLow, typeHigh, attachment; Writer_1ca890* FUN_001d4c90(); bool run(); };
bool Target_1ca890::run() {
 Writer_1ca890* writer = FUN_001d4c90();
 bool result = false;
 if (writer && ((owners::Obj_1d2e80 *)writer)->FUN_001d2e80()) {
 char buffer[32];
 FUN_00096d50(buffer, 32, propLow, propHigh);
 ((owners::Thing_1d1d50 *)writer)->FUN_001d1d50((hulk_uintptr)"prop", (hulk_uintptr)buffer);
 FUN_00096d50(buffer, 32, typeLow, typeHigh);
 ((owners::Thing_1d1d50 *)writer)->FUN_001d1d50((hulk_uintptr)"prop_type", (hulk_uintptr)buffer);
 ((owners::Obj_1d1dd0 *)writer)->FUN_001d1dd0((hulk_intptr)"attachment_index", (int)attachment);
 World* world = DAT_004dd700;
 unsigned int id = actor;
 if (world) {
 Actor_1ca890* a = ((Actor_1ca890 *)((owners::ThisWrap_00059c10 *)(world->registry))->FUN_00059c10((void *)(hulk_uintptr)(unsigned int)id));
 const char* name = a ? a->FUN_00036d00() : "UNKNOWN";
 ((owners::Thing_1d1d50 *)writer)->FUN_001d1d50((hulk_uintptr)"actor", (hulk_uintptr)name);
 ((owners::Thing_1d1d50 *)writer)->FUN_001d1d50((hulk_uintptr)"prop_DANGEROUS", (hulk_uintptr)"prop_DANGEROUS is not defined in RELEASE!");
 ((owners::Thing_1d1d50 *)writer)->FUN_001d1d50((hulk_uintptr)"prop_type_DANGEROUS", (hulk_uintptr)"prop_type_DANGEROUS is not defined in RELEASE!");
 result = true;
 }
 writer->FUN_001d1d10();
 }
 return result;
}
} // namespace fn_001ca890
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001caa10 FUN_001caa10 (193 B): equivalent/0x001caa10.cpp [wrapped: conflict: Object]
// sym: ?target@Object@fn_001caa10@@QAE_NXZ
namespace fn_001caa10 {
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 4/4)
// FUN_001caa10 @ 0x001caa10
// cl-flags: /GS
struct Properties_1caa10 {
 void FUN_001d1d10();
};
extern "C++" __declspec(nothrow) void __cdecl FUN_00096d50(char* buffer, int size, unsigned int low, unsigned int high);
struct Object {
 char padding[0x18];
 unsigned int propLow, propHigh;
 unsigned int typeLow, typeHigh;
 Properties_1caa10* FUN_001d4c90();
 bool target();
};
bool Object::target() {
 Properties_1caa10* properties = FUN_001d4c90();
 if (!properties || !((owners::Obj_1d2e80 *)properties)->FUN_001d2e80()) {
 return false;
 }
 char buffer[32];
 FUN_00096d50(buffer, 32, propLow, propHigh);
 ((owners::Thing_1d1d50 *)properties)->FUN_001d1d50((hulk_uintptr)"prop", (hulk_uintptr)buffer);
 FUN_00096d50(buffer, 32, typeLow, typeHigh);
 ((owners::Thing_1d1d50 *)properties)->FUN_001d1d50((hulk_uintptr)"prop_type", (hulk_uintptr)buffer);
 ((owners::Thing_1d1d50 *)properties)->FUN_001d1d50((hulk_uintptr)"prop_DANGEROUS", (hulk_uintptr)"prop_DANGEROUS is not defined in RELEASE!");
 ((owners::Thing_1d1d50 *)properties)->FUN_001d1d50((hulk_uintptr)"prop_type_DANGEROUS", (hulk_uintptr)"prop_type_DANGEROUS is not defined in RELEASE!");
 properties->FUN_001d1d10();
 return true;
}
} // namespace fn_001caa10


// 0x001cab60 FUN_001cab60 (284 B): equivalent/0x001cab60.cpp [wrapped: conflict: Object]
// sym: ?FUN_001cab60@Object@fn_001cab60@@QAE_NXZ
namespace fn_001cab60 {
// STATUS: equivalent (tools/equiv.py level 3: 20001 inputs, branch coverage 6/6)
// FUN_001cab60 @ 0x001cab60
// cl-flags: /GS

struct Writer_1cab60 {
 void FUN_001d1d10();
};
extern void __cdecl FUN_00096d50(char*, int, unsigned int, unsigned int);
struct Object {
 char pad[0x18];
 unsigned int propLow, propHigh, typeLow, typeHigh;
 int state, increase;
 unsigned int originLow, originHigh;
 Writer_1cab60* FUN_001d4c90();
 bool FUN_001cab60();
};
bool Object::FUN_001cab60() {
 Writer_1cab60* w = FUN_001d4c90();
 if (!w || !((owners::Obj_1d2e80 *)w)->FUN_001d2e80()) {
 return false;
 }
 char buffer[32];
 FUN_00096d50(buffer, 32, propLow, propHigh);
 ((owners::Thing_1d1d50 *)w)->FUN_001d1d50((hulk_uintptr)"prop", (hulk_uintptr)buffer);
 FUN_00096d50(buffer, 32, typeLow, typeHigh);
 ((owners::Thing_1d1d50 *)w)->FUN_001d1d50((hulk_uintptr)"prop_type", (hulk_uintptr)buffer);
 FUN_00096d50(buffer, 32, originLow, originHigh);
 ((owners::Thing_1d1d50 *)w)->FUN_001d1d50((hulk_uintptr)"origin", (hulk_uintptr)buffer);
 ((owners::Thing_1d1d50 *)w)->FUN_001d1d50((hulk_uintptr)"state_desc", (hulk_uintptr)(state == -1 ? "unDEfiNeD - tell Zaven!" : ((const char**)&DAT_004c165c)[state]));
 ((owners::Obj_1d1dd0 *)w)->FUN_001d1dd0((hulk_intptr)"ers_increase", increase);
 ((owners::Thing_1d1d50 *)w)->FUN_001d1d50((hulk_uintptr)"prop_DANGEROUS", (hulk_uintptr)"prop_DANGEROUS is not defined in RELEASE!");
 ((owners::Thing_1d1d50 *)w)->FUN_001d1d50((hulk_uintptr)"prop_type_DANGEROUS", (hulk_uintptr)"prop_type_DANGEROUS is not defined in RELEASE!");
 w->FUN_001d1d10();
 return true;
}
} // namespace fn_001cab60


// 0x001cae90 FUN_001cae90 (119 B): equivalent/0x001cae90.cpp [wrapped: conflict: Object]
// sym: ?target@Object@fn_001cae90@@QAE_NXZ
namespace fn_001cae90 {
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 4/4)
// FUN_001cae90 @ 0x001cae90
// cl-flags: /GS
struct Properties_1cae90 {
    void FUN_001d1d10();
};
extern "C++" __declspec(nothrow) void __cdecl FUN_00096d50(char* buffer, int size, unsigned int low, unsigned int high);
struct Frame_1cae90 {
    char buffer[32];
};
struct Object {
    char padding[0x18];
    unsigned int idLow, idHigh;
    Properties_1cae90* FUN_001d4c90();
    bool target();
};
bool Object::target() {
    Frame_1cae90 fr;
    Properties_1cae90* properties = FUN_001d4c90();
    if (!properties || !((owners::Obj_1d2e80 *)properties)->FUN_001d2e80()) {
        return false;
    }
    FUN_00096d50(fr.buffer, 32, idLow, idHigh);
    ((owners::Thing_1d1d50 *)properties)->FUN_001d1d50((hulk_uintptr)"string", (hulk_uintptr)(fr.buffer));
    properties->FUN_001d1d10();
    return true;
}
} // namespace fn_001cae90

namespace fn_f6c94213 {

// 0x001cbc20 FUN_001cbc20 (139 B): equivalent/0x001cbc20.cpp
// sym: ?FUN_001cbc20@Queue_1cbc20@fn_f6c94213@@QAE_NPBURecord_1cbc20@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 4/4)
// FUN_001cbc20 @ 0x001cbc20
bool Queue_1cbc20::FUN_001cbc20(const Record_1cbc20* source) {
    Record_1cbc20 local;
    local.size = 0;
    unsigned n = source->size;
    const unsigned char* s = reinterpret_cast<const unsigned char*>(source);
    unsigned char* d = reinterpret_cast<unsigned char*>(&local);
    for (unsigned i=0; i<n; ++i) d[i]=s[i];
    Record_1cbc20* dest=next;
    bool result = false;
    if (dest < end) {
        next = dest + 1;
        if (dest) *dest=local;
        result = true;
    }
    return result;
}

} // namespace fn_f6c94213

// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_001ebbc0 @ 0x001ebbc0
#include "decls/data/game/global.h"

struct Path_1ebbc0 {
 char storage[72];
 void FUN_001ef320();
 void FUN_001ef370(const char*);
 void FUN_001ef350();
};
struct Actor_1ebbc0 { char pad[8]; char position[32]; unsigned flags; };
struct Context { void* FUN_00086310(); };
struct Audio_1ebbc0 { void FUN_001efe20(Path_1ebbc0*, void*, const char*, float); };
struct Manager_1ebbc0 { Audio_1ebbc0* audio; char pad[4]; unsigned char enabled; };
extern void __cdecl FUN_001eb440(void*, Path_1ebbc0*);
struct Owner_1ebbc0 {
 char pad[4]; Context* context;
 void target(Actor_1ebbc0*, const char*);
};
void Owner_1ebbc0::target(Actor_1ebbc0* actor, const char* text) {
 if (!actor || !text || !*text) return;
 Path_1ebbc0 path;
 path.FUN_001ef320();
 path.FUN_001ef370("Objects");
 path.FUN_001ef370("Dialogue");
 path.FUN_001ef370((actor->flags & 4) ? "civ_female" : "civ_male");
 void* object = context->FUN_00086310();
 if (object) FUN_001eb440(object, &path);
 if ((*(Manager_1ebbc0**)&DAT_004e36d8)->enabled) (*(Manager_1ebbc0**)&DAT_004e36d8)->audio->FUN_001efe20(&path, actor->position, text, 100.0f);
 path.FUN_001ef350();
}
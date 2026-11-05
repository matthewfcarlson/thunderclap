// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 20/20)
// FUN_000bc5c0 @ 0x000bc5c0
#include "compat/ptr.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"

struct Listener_bc5c0 { void FUN_00093c40(int); };
struct Player_bc5c0 {  void FUN_00089810(int);  void FUN_00089300(const char*); void FUN_00089a20(int); };
struct Object {
 char pad0[0x30]; void* resource; Player_bc5c0* player; char pad38[0x14]; Listener_bc5c0* listener;
 bool FUN_000b4dc0(const char*);
 void FUN_000bc5c0(const char* name, hulk_intptr id, int mode, int unused);
};
void Object::FUN_000bc5c0(const char* name, hulk_intptr id, int mode, int unused) {
 if (!resource || !player) return;
 if (!FUN_000b4dc0(name)) return;
 if (!((owners::K_b4c10 *)this)->FUN_000b4c10((const char *)(hulk_uintptr)(int)id)) return;
 int selected = 0;
 if (((owners::K_b4c10 *)this)->FUN_000b4c10((const char *)(hulk_uintptr)(int)id)) {
 selected = ((int)((owners::NameTable_b4cf0 *)this)->FUN_000b4cf0((const char *)(hulk_uintptr)(int)id));
 if (!selected) return;
 }
 const char* match = "oneshot";
 for (int i=0;i<8;++i) if (name[i]!=match[i]) return;
 if (listener) listener->FUN_00093c40(id);
 ((owners::LevelName_895e0 *)player)->FUN_000895e0((const char *)(hulk_uintptr)(int)selected);
 player->FUN_00089810(id);
 int chosen = DAT_0049cab4;
 if (chosen < 0 || chosen >= 3) chosen = mode;
 ((owners::C_895c0 *)player)->FUN_000895c0(chosen);
 player->FUN_00089300(name);
 player->FUN_00089a20(1);
}

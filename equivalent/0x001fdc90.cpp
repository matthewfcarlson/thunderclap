// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 32/32)
// FUN_001fdc90 @ 0x001fdc90
// cl-flags: /GS
#include "gen/owners.h"
struct Reader {
 bool FUN_001d2ba0(const char*,int,int);
 bool FUN_001d2da0(const char*,int*);
 bool FUN_001d2de0(const char*,int*);
};
extern "C" Reader* __cdecl FUN_001d4c90();
struct Entry_1fdc90 {
 char pad[0x6e0]; int count; char tail[0xc70-0x6e4];
 int FUN_001f93e0(const char*,int,int,int,int,float,float,float,int,int);
};
struct Manager_1fdc90 {
 char pad[0x234]; Entry_1fdc90* entries;
 int FUN_001fcff0(int);
 bool FUN_001fdc90(int,const char*);
};
bool Manager_1fdc90::FUN_001fdc90(int id,const char* file) {
 struct Parameters {
 int script; float kill; int locator,total; float deactivate; int maximum; float radius; int minimum,reset; char name[256];
 } p;
 int index=FUN_001fcff0(id);
 if(index==-1) { return false; }
 if(entries[index].count>=16) { return false; }
 Reader* reader=FUN_001d4c90();
 if(!reader) { return false; }
 if(!reader->FUN_001d2ba0(file,1,0)) { return false; }
 p.script=-1;
 bool ok=false;
 if(((owners::K_1d2c60 *)reader)->FUN_001d2c60((hulk_intptr)"template", (hulk_intptr)(p.name), 256) &&
 reader->FUN_001d2da0("min",&p.minimum) &&
 reader->FUN_001d2da0("max",&p.maximum) &&
 reader->FUN_001d2da0("total",&p.total) &&
 reader->FUN_001d2da0("locator_type",&p.locator) &&
 ((owners::Obj_1d2d40 *)reader)->FUN_001d2d40((hulk_intptr)"kill_distance", &p.kill) &&
 ((owners::Obj_1d2d40 *)reader)->FUN_001d2d40((hulk_intptr)"deactivate_distance", &p.deactivate) &&
 ((owners::Obj_1d2d40 *)reader)->FUN_001d2d40((hulk_intptr)"trigger_radius", &p.radius) &&
 ((owners::C_1d2e10 *)reader)->FUN_001d2e10((hulk_intptr)"script", &p.script) &&
 reader->FUN_001d2de0("reset_on_exit",&p.reset)) {
 ok=entries[index].FUN_001f93e0(p.name,p.minimum,p.maximum,p.total,p.locator,p.kill,p.deactivate,p.radius,p.script,p.reset)!=-1;
 }
 ((owners::Obj_1d19d0 *)reader)->FUN_001d19d0(1);
 if(!ok) ((owners::Obj_1d1900 *)reader)->FUN_001d1900((hulk_intptr)(p.script));
 return ok;
}
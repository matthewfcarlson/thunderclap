// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000245b0 @ 0x000245b0
typedef unsigned __int64 Key;
struct Vec { float x,y,z; };
struct Entry { char pad[0x30]; Vec position; char tail[4]; };
struct Bones { char pad[0x1c]; Entry *entries; unsigned FUN_002843a0(Key key); };
struct Owner { char pad[0x120]; Bones *bones; };
struct Result { void FUN_001c3c10(); };
extern Key __cdecl FUN_002672f0(const char*, int, int);
extern Result* __stdcall FUN_001c3d90(int, Vec*);
struct Target { char pad[0x124]; Owner *owner; void FUN_000245b0(); };
void Target::FUN_000245b0() {
 Vec head = {0,0,0}; Vec pelvis = {0,0,0};
 if (!owner) return;
 Bones *bones = owner->bones;
 if (!bones) return;
 unsigned index = bones->FUN_002843a0(FUN_002672f0("Head",0,0));
 if (index != 0xffff) {
 head = bones->entries[index].position;
 FUN_001c3d90(0,&head)->FUN_001c3c10();
 }
 index = bones->FUN_002843a0(FUN_002672f0("Pelvis",0,0));
 if (index != 0xffff) {
 pelvis = bones->entries[index].position;
 FUN_001c3d90(1,&pelvis)->FUN_001c3c10();
 }
}

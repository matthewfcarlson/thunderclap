// STATUS: equivalent (tools/equiv.py level 3: 12052 inputs, branch coverage 8/8)
// FUN_000245b0 @ 0x000245b0
// FUN_000245b0 @ 0x000245b0
typedef unsigned __int64 Key_245b0;
Key_245b0 __cdecl FUN_002672f0(const char*, int, int);
struct Vec_245b0 { float x,y,z; };
struct Entry_245b0 { char pad[0x30]; Vec_245b0 position; char tail[4]; };
struct Bones_245b0 { char pad[0x1c]; Entry_245b0 *entries; unsigned FUN_002843a0(Key_245b0 key); };
struct Owner_245b0 { char pad[0x120]; Bones_245b0 *bones; };
struct Result_245b0 { void FUN_001c3c10(int, Vec_245b0*); };
// FUN_001c3d90 is the 0-argument singleton getter; the pushed values are arguments of FUN_001c3c10 (ret 8)
extern Result_245b0* __cdecl FUN_001c3d90();
struct Target_245b0 { char pad[0x124]; Owner_245b0 *owner; void FUN_000245b0(); };
void Target_245b0::FUN_000245b0() {
 Vec_245b0 head = {0,0,0}; Vec_245b0 pelvis = {0,0,0};
 if (!owner) return;
 Bones_245b0 *bones = owner->bones;
 if (!bones) return;
 unsigned index = bones->FUN_002843a0(FUN_002672f0("Head",0,0));
 if (index != 0xffff) {
 head = bones->entries[index].position;
 FUN_001c3d90()->FUN_001c3c10(0,&head);
 }
 index = bones->FUN_002843a0(FUN_002672f0("Pelvis",0,0));
 if (index != 0xffff) {
 pelvis = bones->entries[index].position;
 FUN_001c3d90()->FUN_001c3c10(1,&pelvis);
 }
}

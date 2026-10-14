// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 18/18)
// FUN_001b0090 @ 0x001b0090
struct Info { char pad[0x6c]; int blocked; };
struct Mgr { bool FUN_00079950(void* key); };
struct World { char pad[0x4c]; Mgr* mgr; };
extern World* DAT_004dd700;
struct Level { char pad[0x50]; char flag; };
struct Ctx { char pad[0x74]; Level* level; };
struct Unit {
 char pad0[8]; int key;
 char pad1[0xe8 - 0xc]; char hit;
 char pad2[0x114 - 0xe9]; int v114;
 char pad3[0x148 - 0x118]; int v148;
 char v14c; char v14d;
 bool FUN_001d7300();
 Info* FUN_001d72e0();
 bool FUN_001d6a80();
 void FUN_001d7510();
};
int __stdcall UnitUpdate(Unit* u, int unused, Ctx* ctx) {
 if (u->FUN_001d7300()
     && u->FUN_001d72e0()->blocked == 0
     && u->v114 == 0 && u->v148 == 0 && !u->v14d
     && !u->FUN_001d6a80()) {
  if (!u->v14c || !DAT_004dd700->mgr->FUN_00079950(&u->key))
   u->FUN_001d7510();
 }
 if (ctx->level->flag) u->hit = 1;
 return 0;
}

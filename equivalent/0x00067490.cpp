// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// FUN_00067490 @ 0x00067490
struct Vec_67490 { float x,y,z; };
struct Clock_67490 { float FUN_00086080(); };
struct Context { char pad[0x2c]; void* resource; };
extern Context* DAT_004dd700;
struct State_67490 {
 void* resource; Clock_67490* clock;
 char pad0[0x154-8]; Vec_67490 position;
 char pad1[0x2b0-0x160]; int current; int previous;
 char pad2[0x354-0x2b8]; float deadline; float interval;
 bool FUN_000662b0(); bool FUN_00067230(int arg);
 void FUN_00067490(const Vec_67490* pos, int arg);
};
void State_67490::FUN_00067490(const Vec_67490* pos, int arg) {
 if (!clock) return;
 if (!resource) { resource=DAT_004dd700->resource; if (!resource) return; }
 position=*pos;
 float threshold=deadline-interval;
 if (clock->FUN_00086080() < threshold) deadline=clock->FUN_00086080();
 if (previous != current) deadline=clock->FUN_00086080();
 if (!FUN_000662b0()) deadline=clock->FUN_00086080();
 if (clock->FUN_00086080() >= deadline) {
  if (FUN_00067230(arg)) {
   float value=clock->FUN_00086080()+interval;
   previous=current;
   deadline=value;
  }
 }
}
// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 5/6, incomplete)
// FUN_000b5590 @ 0x000b5590
struct Ranking { void FUN_000f8500(const float*, int, int); };
struct Object { virtual void FUN_00000000(); virtual void FUN_00000001(); virtual void FUN_00000002(); virtual void FUN_00000003(); char pad[0x14]; Ranking ranking; };
extern "C" Object* __cdecl FUN_000fc260(const char*);
extern "C" float DAT_003f335c;
void __stdcall FUN_000b5590(unsigned int value) {
    Object* object = FUN_000fc260("side_mission_success_ranking");
    if (!object) return;
    if (value <= 3) {
        object->ranking.FUN_000f8500(&DAT_003f335c, 0, 1);
        object->FUN_00000003();
    }
}
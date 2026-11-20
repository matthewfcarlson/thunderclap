// FUN_00086240 @ 0x00086240
// (integ4, stubexit) must fail: the wrong exit constant (ours ends at -1, the original at 0)
struct Inner { void Step(); };
struct Target { char pad[0x1c]; Inner* platform; void Run(); };
extern int FUN_0008db80();
extern "C" void FUN_0008db90();
void Target::Run() {
    if (platform != 0) {
        while (FUN_0008db80() != -1) {
            FUN_0008db90();
            platform->Step();
        }
    }
}

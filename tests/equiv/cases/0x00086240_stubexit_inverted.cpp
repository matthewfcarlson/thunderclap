// FUN_00086240 @ 0x00086240
// (integ4, stubexit) must fail: the condition inverted (ours ends where the original goes on)
struct Inner { void Step(); };
struct Target { char pad[0x1c]; Inner* platform; void Run(); };
extern bool FUN_0008db80();
extern "C" void FUN_0008db90();
void Target::Run() {
    if (platform != 0) {
        while (!FUN_0008db80()) {
            FUN_0008db90();
            platform->Step();
        }
    }
}

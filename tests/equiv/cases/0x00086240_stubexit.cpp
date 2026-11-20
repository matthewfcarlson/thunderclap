// FUN_00086240 @ 0x00086240
// (integ4, stubexit) a loop drained by real code elsewhere: `while (FUN_0008db80())`, a stub on both sides. The original's run ends the loop after n rounds (0..3 mostly, up to 64), the same results by call index on ours: inputs complete and the body is compared every round
struct Inner { void Step(); };
struct Target { char pad[0x1c]; Inner* platform; void Run(); };
extern bool FUN_0008db80();
extern "C" void FUN_0008db90();
void Target::Run() {
    if (platform != 0) {
        while (FUN_0008db80()) {
            FUN_0008db90();
            platform->Step();
        }
    }
}

// FUN_00086240 @ 0x00086240
// (integ4, stubexit) must fail: ours tests the whole eax where the original tests al (a bool declared int): a result with a zero low byte and other bits set ends the original's loop only
struct Inner { void Step(); };
struct Target { char pad[0x1c]; Inner* platform; void Run(); };
extern int FUN_0008db80();
extern "C" void FUN_0008db90();
void Target::Run() {
    if (platform != 0) {
        while (FUN_0008db80()) {
            FUN_0008db90();
            platform->Step();
        }
    }
}

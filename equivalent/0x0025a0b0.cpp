// STATUS: equivalent (tools/equiv.py level 3: 191 inputs, branch coverage 10/10)
// FUN_0025a0b0 @ 0x0025a0b0
struct Ctrl;

struct Actor {
    char pad00[0x24];
    Ctrl *ctrl;             // 0x24
    char pad28[0xc];
    int state;              // 0x34
};

extern "C" int __cdecl FUN_002416f0(Ctrl *ctrl, Actor *actor);
extern "C" void __cdecl FUN_002416c0(Ctrl *ctrl, Actor *actor, int arg);
extern "C" int __cdecl FUN_00267f80();
extern "C" void __cdecl FUN_00243090(Ctrl *ctrl, float dt);

void FUN_0025a0b0(Actor *actor)
{
    int status = FUN_002416f0(actor->ctrl, actor);
    bool finishing = (status == 1 || status == 2);

    FUN_002416c0(actor->ctrl, actor, 0);
    int last = FUN_00267f80();

    while (status != 0) {
        int now = FUN_00267f80();
        FUN_00243090(actor->ctrl, (float)(now - last));
        status = FUN_002416f0(actor->ctrl, actor);
        last = now;
    }

    if (finishing)
        actor->state = 2;
}

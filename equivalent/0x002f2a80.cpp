// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002f2a80 @ 0x002f2a80
// physics property table defaults @ 0x002f2a80
#include "decls/address.h"
typedef unsigned __int64 Key_2f2a80;
struct PhysicsTable_2f2a80 {
    void FUN_002f27c0(Key_2f2a80, float, float, float, float);
    void FUN_002f2a80();
};
void PhysicsTable_2f2a80::FUN_002f2a80() {
    FUN_002f27c0(FUN_0027b020("defaultPhysicsProperties"), 1.5f, 1.0f, -0.75f, 1.0f);
    FUN_002f27c0(FUN_0027b020("defaultArtPhysicsProperties"), 1.05f, 10.0f, -0.25f, 1.0f);
    FUN_002f27c0(FUN_0027b020("hardwood"), 1.5f, 2.0f, -0.75f, 0.97f);
    FUN_002f27c0(FUN_0027b020("softwood"), 1.2f, 2.0f, -0.75f, 0.5f);
    FUN_002f27c0(FUN_0027b020("hardrubber"), 1.9f, 100.0f, 0.5f, 1.3f);
    FUN_002f27c0(FUN_0027b020("softrubber"), 1.1f, 100.0f, 0.5f, 1.3f);
    FUN_002f27c0(FUN_0027b020("hardmetal"), 1.0f, 100000.0f, -0.5f, 10.0f);
    FUN_002f27c0(FUN_0027b020("softmetal"), 1.0f, 100000.0f, -0.5f, 2.7f);
    FUN_002f27c0(FUN_0027b020("concrete"), 1.01f, 1000.0f, -0.8f, 2.3f);
    FUN_002f27c0(FUN_0027b020("sticky"), 1.05f, 100000.0f, 0.0f, 1.0f);
    FUN_002f27c0(FUN_0027b020("icy"), 1.05f, 0.0f, -1.0f, 1.0f);
}

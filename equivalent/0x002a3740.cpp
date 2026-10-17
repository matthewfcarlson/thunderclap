// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// pure3d::ParticleSystem::vfunc_7 @ 0x002a3740
namespace pure3d {
struct Controller {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual bool slot22();
};
struct DrawableContainer { void vfunc_7(); };
struct ParticleSystem : DrawableContainer {
    char pad[0xa4];
    Controller *controller;
    void vfunc_7();
};
void ParticleSystem::vfunc_7() {
    if (controller && !controller->slot22()) return;
    DrawableContainer::vfunc_7();
}
}
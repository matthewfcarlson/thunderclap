extern "C" char DAT_00421914[];
extern "C" char DAT_00421924[];
extern "C" char DAT_00421934[];
typedef unsigned int u32_1c5840;
struct StoreBase {
    char pad[0x120];
    void Init(unsigned int, int);
};
struct ObjectManager {
    u32_1c5840 vft;
    char pad4[4];
    StoreBase objects;
    StoreBase templates;
    u32_1c5840 value;
};
ObjectManager* __fastcall Target(ObjectManager* self) {
    self->vft = ((int)DAT_00421934);
    self->objects.Init(0x40, 0);
    *(u32_1c5840*)&self->objects = ((int)DAT_00421914);
    self->templates.Init(0x40, 1);
    *(u32_1c5840*)&self->templates = ((int)DAT_00421924);
    self->value = 0;
    return self;
}
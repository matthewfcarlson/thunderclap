void* __cdecl alloc(unsigned int);
struct Param {
    int vft;
    int pad[3];
    int value;
    void Init(const char*);
};
void __cdecl register_params(void*, Param**, int);
extern int counter;
extern void* registry;
void target() {
    if (counter == 0) {
        Param* list[7];
        Param* p;
        p = (Param*)alloc(0x18);
        if (p) {
            p->Init("timeBegin");
            p->vft = 0x40f848;
            p->value = 0x11bd30;
            list[0] = p;
        } else
            list[0] = 0;
        p = (Param*)alloc(0x18);
        if (p) {
            p->Init("timeEnd");
            p->vft = 0x40f848;
            p->value = 0x11bd40;
            list[1] = p;
        } else
            list[1] = 0;
        p = (Param*)alloc(0x18);
        if (p) {
            p->Init("distance");
            p->vft = 0x40f848;
            p->value = 0x11bd50;
            list[2] = p;
        } else
            list[2] = 0;
        p = (Param*)alloc(0x18);
        if (p) {
            p->Init("turnRate");
            p->vft = 0x40f848;
            p->value = 0x11bd60;
            list[3] = p;
        } else
            list[3] = 0;
        p = (Param*)alloc(0x18);
        if (p) {
            p->Init("heightMin");
            p->vft = 0x40f848;
            p->value = 0x11bd90;
            list[4] = p;
        } else
            list[4] = 0;
        p = (Param*)alloc(0x18);
        if (p) {
            p->Init("heightMax");
            p->vft = 0x40f848;
            p->value = 0x11bdb0;
            list[5] = p;
        } else
            list[5] = 0;
        p = (Param*)alloc(0x18);
        if (p) {
            p->Init("speed");
            p->vft = 0x40f848;
            p->value = 0x11bdd0;
            list[6] = p;
        } else
            list[6] = 0;
        register_params(&registry, list, 7);
    }
    ++counter;
}

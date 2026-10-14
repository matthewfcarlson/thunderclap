extern unsigned int DAT_004cf730;
struct Container_29fa30 {
    char pad[0x14];
    int count;
    void FUN_002a0fc0(int index, int value);
    void FUN_002a1180(int value);
};
struct Entry_29fa30 {
    unsigned int value;
    unsigned int color;
    char pad[16];
    unsigned int a;
    unsigned int b;
};
struct Group_29fa30 {
    Container_29fa30* container;
    Entry_29fa30* entries;
};
struct Object {
    char pad[0x24];
    unsigned int generation;
    char pad2[4];
    Group_29fa30* groups[5];
    void FUN_0029fa30();
};
void Object::FUN_0029fa30() {
    Group_29fa30* list[6];
    list[0] = groups[0];
    list[1] = groups[1];
    list[2] = groups[2];
    list[3] = groups[3];
    list[4] = groups[4];
    list[5] = 0;
    for (int j = 0; list[j]; ++j) {
        Group_29fa30* group = list[j];
        for (int i = group->container->count - 1; i >= 0; --i) {
            group->container->FUN_002a0fc0(i, 0);
            group->entries[i].value = 0;
            group->entries[i].color = DAT_004cf730;
            group->entries[i].b = 0;
            group->entries[i].a = 0;
        }
        group->container->FUN_002a1180(0);
    }
    ++generation;
}

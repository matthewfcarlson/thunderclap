extern "C" int strcmp(const char*, const char*);
struct Ent_3370b0 {
    int x;
    const char* name;
    int pad[4];
};
struct T_3370b0 {
    char pad[0x44];
    int count;
    Ent_3370b0 ents[1];
    Ent_3370b0* Find(const char* s);
};
Ent_3370b0* T_3370b0::Find(const char* s) {
    for (int i = 0; i < count; i++) {
        if (strcmp(s, ents[i].name) == 0)
            return &ents[i];
    }
    return 0;
}

extern "C" int strcmp(const char*, const char*);
struct Ent {
    int x;
    const char* name;
    int pad[4];
};
struct T {
    char pad[0x44];
    int count;
    Ent ents[1];
    Ent* Find(const char* s);
};
Ent* T::Find(const char* s) {
    for (int i = 0; i < count; i++) {
        if (strcmp(s, ents[i].name) == 0)
            return &ents[i];
    }
    return 0;
}

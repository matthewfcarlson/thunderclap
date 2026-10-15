extern float defaultValue;
struct Result {
    char pad[0x128];
    float value;
};
struct Manager {
    Result* Find(int, int);
};
struct Owner {
    char pad[4];
    Manager* mgr;
    float Get(const char* name);
};
struct Pair {
    int a, b;
};
Pair Convert(const char*);
float Owner::Get(const char* name) {
    Manager* m = mgr;
    if (!m)
        return defaultValue;
    Pair p = Convert(name);
    Result* r = m->Find(p.a, p.b);
    if (!r)
        return defaultValue;
    return r->value;
}
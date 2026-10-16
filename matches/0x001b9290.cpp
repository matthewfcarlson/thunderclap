struct Obj {
    char pad[0x5c];
    int value;
};
struct Manager {
    Obj* Find(int);
};
struct Root {
    char pad[4];
    Manager* manager;
};
Root* __stdcall GetRoot();
void __stdcall FUN(int key, int v) {
    Root* root = GetRoot();
    Manager* mgr = root->manager;
    Obj* o = mgr->Find(key);
    if (o)
        o->value = v;
}
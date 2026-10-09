extern "C" int __cdecl strcmp(const char*, const char*);
class Obj {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual const char* Name();
};
class Table {
  public:
    char pad[0xc];
    Obj* mItems[64];
    Obj* Find(const char* name);
};
Obj* Table::Find(const char* name) {
    for (int i = 0; i < 64; i++) {
        if (mItems[i] != 0 && strcmp(name, mItems[i]->Name()) == 0)
            return mItems[i];
    }
    return 0;
}

extern "C" int __cdecl strcmp(const char*, const char*);
class Obj_e6490 {
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
class Table_e6490 {
  public:
    char pad[0xc];
    Obj_e6490* mItems[64];
    Obj_e6490* Find(const char* name);
};
Obj_e6490* Table_e6490::Find(const char* name) {
    for (int i = 0; i < 64; i++) {
        if (mItems[i] != 0 && strcmp(name, mItems[i]->Name()) == 0)
            return mItems[i];
    }
    return 0;
}

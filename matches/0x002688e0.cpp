extern "C" int strcmp(const char*, const char*);
class NameHolder {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual const char* GetName();
    char pad[0x30];
};
class ControllerXBox {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual ControllerXBox* Find(const char*, int);
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    char pad[0x10];
    int count;
    NameHolder entries[1];
};
ControllerXBox* ControllerXBox::Find(const char* name, int which) {
    int found = 0;
    for (unsigned i = 0; i < (unsigned)count; ++i) {
        if (strcmp(entries[i].GetName(), name) == 0) {
            if (found == which)
                return (ControllerXBox*)((char*)this + 0x18 + i * 0x34);
            ++found;
        }
    }
    return 0;
}
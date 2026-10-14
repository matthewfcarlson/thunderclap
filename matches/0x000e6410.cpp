extern "C" int strcmp(const char*, const char*);

class Item_e6410 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual const char* GetName();
};

class Container_e6410 {
  public:
    char pad[0x20c];
    Item_e6410* mItems[256];
    Item_e6410* Find(const char* name);
};

Item_e6410* Container_e6410::Find(const char* name) {
    for (int i = 0; i < 256; i++) {
        if (mItems[i]) {
            if (strcmp(name, mItems[i]->GetName()) == 0)
                return mItems[i];
        }
    }
    return 0;
}

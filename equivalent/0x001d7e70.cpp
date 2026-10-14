// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001d7e70 @ 0x001d7e70
struct Source {
    float FUN_001d4ea0(unsigned int key);
};
class Sink {
  public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34();
    virtual void SetValue(float f);
};
struct Mid {
    char pad[0x70];
    Sink* sink;
};
struct Owner {
    char pad[0x10];
    Mid* mid;
};
class Obj {
  public:
    char pad00[0x40];
    unsigned int key;
    char pad44[0xa0 - 0x44];
    Owner* owner;
    char padA4[0xec - 0xa4];
    Source* source;
    void FUN_001d7e70();
};
void Obj::FUN_001d7e70() {
    if (owner == 0)
        return;
    if (owner->mid == 0)
        return;
    if (owner->mid->sink == 0)
        return;
    if (source->FUN_001d4ea0(key) > 0.0f) {
        Sink* sink = owner->mid->sink;
        sink->SetValue(source->FUN_001d4ea0(key));
    }
}

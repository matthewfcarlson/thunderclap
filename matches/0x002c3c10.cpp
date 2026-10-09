class ProximityLight {
  public:
    virtual ~ProximityLight();
    char pad[0x54];
    int a, b;
    float c, d;
    void Init();
};
extern void* lightVftable;
ProximityLight* __fastcall FUN_002c3c10(ProximityLight* self) {
    self->Init();
    self->a = 0;
    self->b = 0;
    *(void**)self = &lightVftable;
    self->c = 1.0f;
    self->d = 10000000.0f;
    return self;
}
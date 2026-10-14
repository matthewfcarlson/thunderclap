void* __cdecl HelperCast(void* p, int a, void* b, void* c, int d);

class DynamicCasterBase {
  public:
    virtual void* Cast(void*);
};

class DynamicCaster : public DynamicCasterBase {
  public:
    virtual void* Cast(void*);
};

void* DynamicCaster::Cast(void* p) {
    return HelperCast(p, 0, (void*)0x48d5bc, (void*)0x4c9268, 0);
}

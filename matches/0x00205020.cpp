extern char DAT_0048d5bc;
extern char DAT_004c9268;
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
    return HelperCast(p, 0, (void*)&DAT_0048d5bc, (void*)&DAT_004c9268, 0);
}

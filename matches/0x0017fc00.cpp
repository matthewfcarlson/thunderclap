class Thing {
  public:
    void* Get() { return ((char*)this) + 0x78; }
};

void* FUN_0017fc00(Thing* p) {
    return p->Get();
}
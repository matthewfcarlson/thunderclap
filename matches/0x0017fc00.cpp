class Thing_17fc00 {
  public:
    void* Get() { return ((char*)this) + 0x78; }
};

void* FUN_0017fc00(Thing_17fc00* p) {
    return p->Get();
}
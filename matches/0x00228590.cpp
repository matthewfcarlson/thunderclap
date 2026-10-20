// Same code shape as 0x00225ef0 (propagated; names are from that function)
class Item_228590 {
  public:
    virtual void a();
    virtual void release();
};
void __fastcall FUN_0022a9c0(void* self);
class LocomotionSteerDriver_228590 {
  public:
    virtual void v();
    char pad[0x2c];
    unsigned count;
    struct Entry {
        Item_228590* item;
        char rest[0x204];
    } entries[1];
    ~LocomotionSteerDriver_228590();
};
LocomotionSteerDriver_228590::~LocomotionSteerDriver_228590() {
    for (unsigned i = 0; i < count; ++i)
        entries[i].item->release();
    FUN_0022a9c0(this);
}

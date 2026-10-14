class Item_225ef0 {
  public:
    virtual void a();
    virtual void release();
};
void __fastcall FUN_0022a9c0(void* self);
class LocomotionStrafeDriver {
  public:
    virtual void v();
    char pad[0x2c];
    unsigned count;
    struct Entry {
        Item_225ef0* item;
        char rest[0x204];
    } entries[1];
    ~LocomotionStrafeDriver();
};
LocomotionStrafeDriver::~LocomotionStrafeDriver() {
    for (unsigned i = 0; i < count; ++i)
        entries[i].item->release();
    FUN_0022a9c0(this);
}

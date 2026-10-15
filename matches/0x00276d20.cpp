namespace core {
class Guard {
  public:
    virtual void enter();
    virtual void leave();
};
class Obj {
  public:
    char ready();
    void* get();
};
class InstanceDrive {
  public:
    char pad[4];
    Guard guard;
    char pad2[4];
    Obj* obj;
    char pad3[8];
    void* value;
    void* vfunc_23();
};
void* InstanceDrive::vfunc_23() {
    guard.enter();
    void* result;
    if (obj->ready())
        result = obj->get();
    else
        result = value;
    guard.leave();
    return result;
}
} // namespace core
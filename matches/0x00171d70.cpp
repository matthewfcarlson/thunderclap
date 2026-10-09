class Locator {
  public:
    char pad[0x10];
    int value;
};
class Helper {
  public:
    int invoke(int);
};
class TeleportToLocatorAction {
  public:
    char pad[0x18];
    Locator* locator;
    int active;
    char pad2[4];
    Helper helper;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool vfunc_3(int, int);
};
bool TeleportToLocatorAction::vfunc_3(int a, int b) {
    if (!active)
        return false;
    helper.invoke(locator->value);
    return true;
}
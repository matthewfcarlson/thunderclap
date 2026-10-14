typedef void(__cdecl* Callback_344f51)();
extern Callback_344f51 gCallback_344f51;
void __cdecl DoThing(int);
class DynamicCasterBase {
  public:
    virtual void Method();
};
void DynamicCasterBase::Method() {
    if (gCallback_344f51)
        gCallback_344f51();
    DoThing(0x19);
}
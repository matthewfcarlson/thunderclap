class Drawable {
  public:
    virtual void fn();
};
class DynamicCaster_f24d0 {
  public:
    virtual void fn();
};
class Inventory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual Drawable* Find(DynamicCaster_f24d0*, unsigned __int64);
};
extern Inventory* gInventory;
extern unsigned __int64 __cdecl Hash(const char*);
class FEAnimation_f24d0 {
  public:
    virtual void a();
    char pad[8];
    Drawable* drawable;
    FEAnimation_f24d0(int, const char*);
};
class FEPoseAnimationInvisible : public FEAnimation_f24d0 {
  public:
    virtual void a();
    FEPoseAnimationInvisible(int, const char*);
};
FEPoseAnimationInvisible::FEPoseAnimationInvisible(int a, const char* name) : FEAnimation_f24d0(a, name) {
    Inventory* inv = gInventory;
    unsigned __int64 h = Hash(name);
    Drawable* p = inv->Find(&DynamicCaster_f24d0(), h);
    if (p) {
        p->fn();
        drawable = p;
    }
}
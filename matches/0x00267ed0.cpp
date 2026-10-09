class BaseObject {
  public:
    virtual void vfunc_0();
};
class Object : public BaseObject {
  public:
    int field;
    virtual Object* vfunc_0(unsigned char);
};
extern volatile int g_saved;
extern void __cdecl FUN_00266f00(int, Object*);
Object* Object::vfunc_0(unsigned char param) {
    g_saved = field;
    *(unsigned long*)this = 0x42af64;
    if (param & 1)
        FUN_00266f00(g_saved, this);
    return this;
}
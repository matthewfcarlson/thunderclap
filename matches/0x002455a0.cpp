extern "C" char DAT_0042918c[];
extern "C" char DAT_004e5f18[];
class Entity {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual Entity* vfunc_2(int);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
};
class Clip : public Entity {
  public:
    virtual Clip* vfunc_2(int);
    virtual void vfunc_3();
    virtual void vfunc_8();
    char pad[0x28 - sizeof(Entity)];
    int mHandle;
    void cleanup();
};
void ReleaseHandle(int);
void RegisterClip(void*, Clip*);
Clip* Clip::vfunc_2(int flag) {
    *(int*)this = ((int)DAT_0042918c);
    if (mHandle)
        ReleaseHandle(mHandle);
    cleanup();
    if (flag & 1)
        RegisterClip((void*)((int)DAT_004e5f18), this);
    return this;
}
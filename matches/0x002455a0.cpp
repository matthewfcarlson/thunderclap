class Entity { public: virtual void vfunc_0(); virtual void vfunc_1(); virtual Entity* vfunc_2(int); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); };
class Clip : public Entity { public: virtual Clip* vfunc_2(int); virtual void vfunc_3(); virtual void vfunc_8(); char pad[0x28-sizeof(Entity)]; int mHandle; void cleanup(); };
void ReleaseHandle(int);
void RegisterClip(void*, Clip*);
Clip* Clip::vfunc_2(int flag) {
    *(int*)this = 0x42918c;
    if (mHandle) ReleaseHandle(mHandle);
    cleanup();
    if (flag & 1) RegisterClip((void*)0x4e5f18, this);
    return this;
}
typedef unsigned int size_t;
void* operator new(size_t) throw();
class CCollisionManager_1b6580 {
  public:
    CCollisionManager_1b6580() throw();
    virtual void Init() throw();
    char pad[0x5a8];
};
extern CCollisionManager_1b6580* gThing;
CCollisionManager_1b6580* GetThing() {
    if (!gThing) {
        gThing = new CCollisionManager_1b6580;
        gThing->Init();
        return gThing;
    }
    return gThing;
}

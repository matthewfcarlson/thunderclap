class Entity {
  public:
    virtual void vfunc_0();
    virtual int vfunc_1(void*, void*);
    virtual void vfunc_2();
    virtual Entity* vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual Entity* vfunc_8();
};
class MetaEntity : public Entity {
  public:
    virtual void vfunc_2();
    virtual int vfunc_3(void*);
};
int MetaEntity::vfunc_3(void* p) {
    Entity* a = this->vfunc_8();
    Entity* b = a->vfunc_3();
    return b->vfunc_1(p, this);
}
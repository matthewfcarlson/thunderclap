namespace om {
class Entity {
  public:
    unsigned long* mVptr;
    Entity* vfunc_2(unsigned char);
};
} // namespace om
extern int gCount;
extern void* gPtr;
void FUN_00244b20(void*, om::Entity*);
void thunk_FUN_00267090(om::Entity*);
om::Entity* om::Entity::vfunc_2(unsigned char param) {
    void* p = gPtr;
    mVptr = (unsigned long*)0x429158;
    FUN_00244b20(p, this);
    --gCount;
    mVptr = (unsigned long*)0x3f6098;
    if (param & 1)
        thunk_FUN_00267090(this);
    return this;
}
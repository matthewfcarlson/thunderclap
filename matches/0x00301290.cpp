struct Owner_301290 {
    char pad[0x30];
    int value;
};
extern Owner_301290* g_owner;
extern int vtable_301290;
struct Ctor_00313500 {
    Ctor_00313500();
};
class CollisionDetector : public Ctor_00313500 {
  public:
    char pad[0x40];
    CollisionDetector();
};
CollisionDetector::CollisionDetector() : Ctor_00313500() {
    *(int*)this = (int)&vtable_301290;
    *(int*)((char*)this + 0x3c) = 0;
    *(int*)((char*)this + 0x10) = *(int*)((char*)g_owner + 0x30);
}
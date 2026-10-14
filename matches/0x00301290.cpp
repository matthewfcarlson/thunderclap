struct Owner_301290 {
    char pad[0x30];
    int value;
};
extern Owner_301290* g_owner;
extern int vtable_301290;
extern void Init();
class CollisionDetector {
  public:
    char pad[0x40];
    CollisionDetector();
};
CollisionDetector::CollisionDetector() {
    Init();
    *(int*)this = (int)&vtable_301290;
    *(int*)((char*)this + 0x3c) = 0;
    *(int*)((char*)this + 0x10) = *(int*)((char*)g_owner + 0x30);
}
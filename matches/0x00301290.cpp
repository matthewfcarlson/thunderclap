struct Owner {
    char pad[0x30];
    int value;
};
extern Owner* g_owner;
extern int vtable;
extern void Init();
class CollisionDetector {
  public:
    char pad[0x40];
    CollisionDetector();
};
CollisionDetector::CollisionDetector() {
    Init();
    *(int*)this = (int)&vtable;
    *(int*)((char*)this + 0x3c) = 0;
    *(int*)((char*)this + 0x10) = *(int*)((char*)g_owner + 0x30);
}
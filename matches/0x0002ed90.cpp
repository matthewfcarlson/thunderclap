class CActorManager {
  public:
    void invoke(const char*);
};
class Closure_2ed90 {
  public:
    char pad[0x1c];
    void (CActorManager::*fn)(const char*);
    CActorManager* object;
    void vfunc_2(void*, const char**, void*);
};
void Closure_2ed90::vfunc_2(void* a, const char** b, void* c) {
    (object->*fn)(*b);
}
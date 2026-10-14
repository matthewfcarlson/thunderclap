// Same code shape as 0x0002ed90 (propagated; names are from that function)
class CActorManager {
  public:
    void invoke(const char*);
};
class Closure_203130 {
  public:
    char pad[0x1c];
    void (CActorManager::*fn)(const char*);
    CActorManager* object;
    void vfunc_2(void*, const char**, void*);
};
void Closure_203130::vfunc_2(void* a, const char** b, void* c) {
    (object->*fn)(*b);
}
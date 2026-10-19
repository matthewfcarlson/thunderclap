class CActorManager;
template <class T, class A, class R> class Closure1 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void* unused, const char** argument, int* result);

  private:
    char padding[0x18];
    int (CActorManager::*method)(const char*);
    CActorManager* object;
};
class CActorManager {};
template <>
void Closure1<CActorManager, const char*, int>::vfunc_2(void* unused, const char** argument, int* result) {
    CActorManager* obj = object;
    int (CActorManager::*fn)(const char*) = method;
    int value = (obj->*fn)(*argument);
    if (result)
        *result = value;
}
class CDHGameObjectCreator {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual const char* f3(void*);
};
class DataHandlerObjectCreator {
  public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual const char* g3(void*);
};
class CRenderManager : public CDHGameObjectCreator, public DataHandlerObjectCreator {
  public:
    const char* f3(void*);
};
const char* CRenderManager::f3(void* p) {
    return (const char*)((p != 0) - 1 & 0x420dd8);
}
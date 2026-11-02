typedef unsigned int size_t;
void* operator new(size_t);
class Obj {
  public:
    Obj* Init() throw();
    char pad[0x7c];
};
Obj* gObj;
extern "C" Obj* FUN_001c3d90() {
    if (!gObj) {
        Obj* p = (Obj*)operator new(sizeof(Obj));
        if (p) {
            gObj = p->Init();
            return gObj;
        }
        gObj = 0;
    }
    return gObj;
}

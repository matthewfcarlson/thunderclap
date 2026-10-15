typedef unsigned int size_t;
void* operator new(size_t);
class Obj {
  public:
    Obj* Init() throw();
    char pad[0x7c];
};
Obj* gObj;
Obj* target() {
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

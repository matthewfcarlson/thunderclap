class Entity {
  public:
    void* vptr;
    int a;
    int b;
    int c;
};
class Derived {
  public:
    void* vptr;
    int a;
    int b;
    int c;
    Derived(void*);
};
extern void* Entity_vftable;
Derived::Derived(void* param) {
    a = 0;
    vptr = &Entity_vftable;
    b = 0;
    c = 0;
    if (param) {
        b = ((int*)param)[2];
        c = ((int*)param)[3];
    }
}
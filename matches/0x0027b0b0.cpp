class Entity {
  public:
    void* vptr;
    int a;
    int b;
    int c;
};
class Derived_27b0b0 {
  public:
    void* vptr;
    int a;
    int b;
    int c;
    Derived_27b0b0(void*);
};
extern void* Entity_vftable;
Derived_27b0b0::Derived_27b0b0(void* param) {
    a = 0;
    vptr = &Entity_vftable;
    b = 0;
    c = 0;
    if (param) {
        b = ((int*)param)[2];
        c = ((int*)param)[3];
    }
}
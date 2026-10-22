class Entity {
  public:
    void* vptr;
    int a;
    int b;
    int c;
};
class Entity_27b0b0 {
  public:
    void* vptr;
    int a;
    int b;
    int c;
    Entity_27b0b0(void*);
};
extern void* Entity_vftable;
Entity_27b0b0::Entity_27b0b0(void* param) {
    a = 0;
    vptr = &Entity_vftable;
    b = 0;
    c = 0;
    if (param) {
        b = ((int*)param)[2];
        c = ((int*)param)[3];
    }
}
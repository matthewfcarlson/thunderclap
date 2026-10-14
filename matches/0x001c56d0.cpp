class Obj_1c56d0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c(int);
};
class Store {
  public:
    virtual void a();
    virtual void b();
    virtual void c(void*);
    char pad[0x118];
    unsigned char flag;
};
void Store::c(void* param) {
    if (flag && param)
        ((Obj_1c56d0*)param)->c(1);
}
class Obj {
  public:
    char pad[0x10];
    struct Inner* p;
};
struct Inner {
    char pad[0x48];
    unsigned int a;
    unsigned int b;
};
void helper1(Obj*);
void helper2(Obj*, int, int*);
void FUN_00213470(Obj* self, int arg) {
    Inner* q = self->p;
    if (q->b >= q->a)
        helper1(self);
    helper2(self, arg, (int*)((char*)&arg + 4));
}
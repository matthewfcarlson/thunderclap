class Obj_213470 {
  public:
    char pad[0x10];
    struct Inner_213470* p;
};
struct Inner_213470 {
    char pad[0x48];
    unsigned int a;
    unsigned int b;
};
void helper1(Obj_213470*);
void helper2(Obj_213470*, int, int*);
void FUN_00213470(Obj_213470* self, int arg) {
    Inner_213470* q = self->p;
    if (q->b >= q->a)
        helper1(self);
    helper2(self, arg, (int*)((char*)&arg + 4));
}
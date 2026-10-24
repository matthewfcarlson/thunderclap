extern "C" void* __cdecl FUN_0008d6d0(unsigned int);
class Entity_2b0060 {
  public:
    Entity_2b0060();
    virtual void f0();
    char pad[0x0c];
};
class ExpressionGroup_2b0060 : public Entity_2b0060 {
  public:
    unsigned int *a, *a2;
    char pad2[8];
    unsigned int *b, *b2;
    unsigned int *c, *c2;
    ExpressionGroup_2b0060(unsigned int n);
    virtual void f1();
};
ExpressionGroup_2b0060::ExpressionGroup_2b0060(unsigned int n) {
    if (n > 0 && (a = (unsigned int*)FUN_0008d6d0(n * 4)) != 0) {
        a2 = a + n;
    } else {
        a = 0;
        a2 = 0;
    }
    b = 0;
    b2 = 0;
    if (n > 0 && (c = (unsigned int*)FUN_0008d6d0(n * 4)) != 0) {
        c2 = c + n;
    } else {
        c = 0;
        c2 = 0;
    }
}

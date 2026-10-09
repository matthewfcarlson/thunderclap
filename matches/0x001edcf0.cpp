extern "C" char Read(int*);
class Obj {
  public:
    void Init(char*, int);
    Obj* Fn(char*, int);
};
struct Layout {
    void* v;
    char pad04[0x0c];
    char b10, b11, b12;
    char pad13[5];
    char b18;
    char pad19[3];
    int m1c;
};
Obj* Obj::Fn(char* p, int x) {
    Layout* s = (Layout*)this;
    Init(p, 3);
    s->v = (void*)0x424398;
    s->m1c = x;
    s->b18 = Read((int*)0x48e100);
    s->b10 = Read((int*)0x49cad8);
    s->b11 = Read((int*)0x49cad8);
    s->b12 = Read((int*)0x49cad8);
    return this;
}
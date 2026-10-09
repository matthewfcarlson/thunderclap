class Obj { public: virtual void a(); virtual void b(); virtual void c(int); };
class Store { public: virtual void a(); virtual void b(); virtual void c(void*); char pad[0x118]; unsigned char flag; };
void Store::c(void* param) { if (flag && param) ((Obj*)param)->c(1); }
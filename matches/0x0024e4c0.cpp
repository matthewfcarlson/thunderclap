extern char g1, g2;
class Attrib {
  public:
    virtual void vf();
    Attrib(void*, void*, int, int) throw();
    char pad[0x44];
};
class TypeT_24e4c0 : public Attrib {
  public:
    virtual void vf();
    TypeT_24e4c0() throw() : Attrib(&g2, &g1, 0x1c, 4) {}
    ~TypeT_24e4c0() throw();
};
extern void process(TypeT_24e4c0*, void*) throw();
void target(void* p) {
    TypeT_24e4c0 t;
    process(&t, p);
}
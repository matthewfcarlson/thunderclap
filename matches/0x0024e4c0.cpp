extern char g1, g2;
class Attrib {
  public:
    virtual void vf();
    Attrib(void*, void*, int, int) throw();
    char pad[0x44];
};
class Type : public Attrib {
  public:
    virtual void vf();
    Type() throw() : Attrib(&g2, &g1, 0x1c, 4) {}
    ~Type() throw();
};
extern void process(Type*, void*) throw();
void target(void* p) {
    Type t;
    process(&t, p);
}
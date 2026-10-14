class RDLObject {
  public:
    char pad[0x10];
    int a;
    int b;
    char pad2[0x1f];
    unsigned char c;
    void Initialize();
    RDLObject();
};
extern int vtable_27a890;
RDLObject::RDLObject() {
    Initialize();
    a = 0;
    b = 0;
    c = 0;
    *(int*)this = (int)&vtable_27a890;
}

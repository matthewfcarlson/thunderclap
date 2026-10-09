extern "C" void* __cdecl Alloc(unsigned int);
extern "C" int NodeVtable;
class Factory {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void* V5();
};
class Node {
  public:
    void Init(int);
};
class Template : public Factory {
  public:
    void* V5();
};
void* Template::V5() {
    Node* p = (Node*)Alloc(0x10);
    if (p) {
        p->Init(0);
        *(unsigned int*)p = (unsigned int)&NodeVtable;
        *((unsigned char*)p + 0xc) = 1;
        return p;
    }
    return 0;
}
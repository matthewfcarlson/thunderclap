class Obj {
  public:
    virtual void Init();
};
class Helper {
  public:
    Obj* Make();
};
extern void __stdcall Base(void*);
extern void* Alloc(unsigned int);
class CMoveAgent {
  public:
    char pad[0x68];
    Obj* p;
    unsigned char b6c;
    char padx[3];
    float scale;
    unsigned char flag;
    unsigned char b75;
    unsigned char b76;
    CMoveAgent(void*);
};
CMoveAgent::CMoveAgent(void* arg) {
    Base(arg);
    *(unsigned int*)this = 0x40d418;
    Helper* h = (Helper*)Alloc(0x38);
    Obj* q;
    if (h)
        q = h->Make();
    else
        q = 0;
    p = q;
    q->Init();
    scale = 1.0f;
    flag = 1;
    b6c = 0;
    b75 = 0;
    b76 = 0;
}

extern "C" char DAT_0040d418[];
class Obj_102ac0 {
  public:
    virtual void Init();
};
class Helper_102ac0 {
  public:
    Obj_102ac0* Make();
};
struct Ctor_000fc760 {
    Ctor_000fc760(void*);
};
extern void* Alloc(unsigned int);
class CMoveAgent : public Ctor_000fc760 {
  public:
    char pad[0x68];
    Obj_102ac0* p;
    unsigned char b6c;
    char padx[3];
    float scale;
    unsigned char flag;
    unsigned char b75;
    unsigned char b76;
    CMoveAgent(void*);
};
CMoveAgent::CMoveAgent(void* arg) : Ctor_000fc760(arg) {
    *(unsigned int*)this = ((int)DAT_0040d418);
    Helper_102ac0* h = (Helper_102ac0*)Alloc(0x38);
    Obj_102ac0* q;
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

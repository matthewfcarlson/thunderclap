extern "C" char DAT_0040eae0[];
extern void* Alloc(unsigned int);
class Obj_11b110 {
  public:
    void Init(int);
};
class Factory_11b110 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Obj_11b110* f();
};
Obj_11b110* Factory_11b110::f() {
    Obj_11b110* p = (Obj_11b110*)Alloc(0x24);
    if (p) {
        p->Init(0);
        *(unsigned int*)p = ((int)DAT_0040eae0);
        *(float*)((char*)p + 12) = 15.0f;
        *(float*)((char*)p + 16) = 100.0f;
        *(float*)((char*)p + 20) = 20.0f;
        *(float*)((char*)p + 24) = 2.0f;
        *((char*)p + 28) = 0;
        *(int*)((char*)p + 32) = 0;
        return p;
    }
    return 0;
}
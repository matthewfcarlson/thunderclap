class FEThingsBase {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48(int);
    char pad[0x17b0 - 4];
    int count;
    char p2[0x2104 - 0x17b4];
    char flag;
};
class Sub_e6f60 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    void helper(int);
};
class Obj_e6f60 {
  public:
    void run();
};
struct Manager_e6f60 {
    char pad[0x20];
    void* obj;
};
extern Manager_e6f60* gManager_e6f60;
extern char gByte;
extern char gFlag_e6f60;
void FEThingsBase::v23() {
    if (count < 0 || (flag == 0 && count == 0)) {
        v48(7);
        return;
    }
    *(int*)((char*)this + 0x1768) = 0;
    *(int*)((char*)this + 0x17f8) = 1;
    *(int*)((char*)this + 0x176c) = 2;
    if (*(Sub_e6f60**)((char*)this + 0x175c)) {
        (*(Sub_e6f60**)((char*)this + 0x175c))->p();
        (*(Sub_e6f60**)((char*)this + 0x175c))->helper(*(int*)((char*)this + 0x176c));
    }
    v24();
    Manager_e6f60* m = gManager_e6f60;
    gByte = 1;
    if (m->obj && *(void**)((char*)m->obj + 0x124) && gFlag_e6f60) {
        gFlag_e6f60 = 0;
        ((Obj_e6f60*)*(void**)((char*)m->obj + 0x124))->run();
    }
}
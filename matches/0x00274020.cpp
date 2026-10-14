extern "C" char DAT_0042b914[];
extern "C" char DAT_0042b99c[];
// Same code shape as 0x002737f0 (propagated; names are from that function)
struct Sub_274020 {
    virtual void f();
    virtual void g();
};
struct V {
    virtual void f();
    virtual void g();
};
struct Inner_274020 {
    void* v;
    Sub_274020 sub;
    char pad[16];
    int ref;
};
struct Request {
    void* v;
    char pad[4];
    Inner_274020* p;
    void run();
};
void Request::run() {
    v = (void*)((int)DAT_0042b99c);
    p->sub.f();
    --p->ref;
    p->sub.g();
    ((V*)p)->g();
    v = (void*)((int)DAT_0042b914);
}

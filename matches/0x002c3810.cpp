class Impl { public: void Helper(); };
class Adj {
public:
    virtual void a();
    virtual void b();
    virtual void c();
};
void Adj::c() {
    Impl* p = (Impl*)((char*)this + (-16));
    p->Helper();
}

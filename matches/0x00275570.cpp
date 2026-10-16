class Base {
  public:
    Base(void*);
    virtual void f();
};
class FileCancelRequest : public Base {
  public:
    FileCancelRequest(void*);
    virtual void f();
};
void __cdecl init();
FileCancelRequest::FileCancelRequest(void* p) : Base(p) {
    init();
}
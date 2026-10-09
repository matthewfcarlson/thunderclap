class Condition {
  public:
    virtual void f();
    int b;
    void* c;
    Condition(void*);
};
Condition::Condition(void* p) {
    b = 0;
    c = p;
}
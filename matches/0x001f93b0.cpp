struct Sub_1f93b0 {
    void f();
};
void destroy(void*);
class X_1f93b0 {
    char pad[0x10];

  public:
    X_1f93b0* run(unsigned char);
};
X_1f93b0* X_1f93b0::run(unsigned char flags) {
    ((Sub_1f93b0*)((char*)this + 0x10))->f();
    if (flags & 1)
        destroy(this);
    return this;
}

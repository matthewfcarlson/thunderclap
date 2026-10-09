struct Sub { void f(); };
void destroy(void*);
class X { char pad[0x10]; public: X* run(unsigned char); };
X* X::run(unsigned char flags) {
    ((Sub*)((char*)this + 0x10))->f();
    if (flags & 1) destroy(this);
    return this;
}

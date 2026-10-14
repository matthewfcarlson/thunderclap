class A {
  public:
    bool Set(void* p);
};

bool A::Set(void* p) {
    *(void**)((char*)this + 0x14) = p;
    return true;
}

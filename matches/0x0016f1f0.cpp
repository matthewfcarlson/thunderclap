class A_16f1f0 {
  public:
    bool Set(void* p);
};

bool A_16f1f0::Set(void* p) {
    *(void**)((char*)this + 0x14) = p;
    return true;
}

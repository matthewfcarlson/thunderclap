class A {
  public:
    char pad[0x28];
    void* mThing;
    bool SetThing(void* p);
};

bool A::SetThing(void* p) {
    mThing = p;
    return true;
}

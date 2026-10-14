class A_15b5d0 {
  public:
    char pad[0x28];
    void* mThing;
    bool SetThing(void* p);
};

bool A_15b5d0::SetThing(void* p) {
    mThing = p;
    return true;
}

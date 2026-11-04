class A_16f1f0 {
  public:
    bool SetMotionState_0016f1f0(void* p);
};

bool A_16f1f0::SetMotionState_0016f1f0(void* p) {
    *(void**)((char*)this + 0x14) = p;
    return true;
}

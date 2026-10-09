class CCollisionTrack;
class ParamFloatPtrConstRange {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool v6(void*, float);
    char pad[0x10 - 4];
    int offset;
};
bool ParamFloatPtrConstRange::v6(void* p, float value) {
    *(float*)((char*)p + offset) = value;
    return true;
}

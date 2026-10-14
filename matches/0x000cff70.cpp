// Same code shape as 0x0002ec60 (propagated; names are from that function)
struct Arg_cff70 {
    const char* s;
    unsigned char b;
};
class Actor_cff70 {
  public:
    void invoke(const char*, unsigned char);
};
class Closure2 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, Arg_cff70* p, void* q);
    char pad[0x18];
    void (Actor_cff70::*fn)(const char*, unsigned char);
    Actor_cff70* obj;
};
void Closure2::vfunc_2(void*, Arg_cff70* p, void*) {
    (obj->*fn)(p->s, p->b);
}

struct Arg { const char* s; unsigned char b; };
class Actor { public: void invoke(const char*, unsigned char); };
class Closure2 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, Arg* p, void* q);
    char pad[0x18];
    void (Actor::*fn)(const char*, unsigned char);
    Actor* obj;
};
void Closure2::vfunc_2(void*, Arg* p, void*) {
    (obj->*fn)(p->s, p->b);
}

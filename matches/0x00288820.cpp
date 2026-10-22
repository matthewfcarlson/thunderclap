extern void* __cdecl FUN_0008d6d0(unsigned int);
struct NonCopyable_288820 {
    int a;
    NonCopyable_288820() { a = 0; }
};
class AnimationMemoryBlock_288820 : public NonCopyable_288820 {
  public:
    virtual void f0();
    unsigned int sz1;
    unsigned int sz2;
    int b;
    int c;
    void* buf1;
    void* buf2;
    AnimationMemoryBlock_288820(unsigned int s1, unsigned int s2);
};
AnimationMemoryBlock_288820::AnimationMemoryBlock_288820(unsigned int s1, unsigned int s2) {
    sz1 = s1;
    b = 0;
    buf1 = s1 > 0 ? FUN_0008d6d0(s1) : 0;
    sz2 = s2;
    c = 0;
    buf2 = s2 > 0 ? FUN_0008d6d0(s2) : 0;
}

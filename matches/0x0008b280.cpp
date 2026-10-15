extern const char gName1[];
extern const char gName2[];
unsigned char Find(const char*);
class Base {
  public:
    virtual void Invoke();
    Base(const char*, int);
    char pad[0xc];
    unsigned char flag2;
    char pad2[7];
    unsigned char flag1;
    char pad3[3];
    void* target;
    void* extra;
};
class Mid : public Base {
  public:
    virtual void Invoke();
    Mid(const char* n, void* m) : Base(n, 1) {
        target = m;
        flag1 = Find(gName1);
        flag2 = Find(gName2);
    }
};
class Closure : public Mid {
  public:
    virtual void Invoke();
    Closure(const char*, void*, void*);
};
Closure::Closure(const char* name, void* ctx, void* method) : Mid(name, method) {
    extra = ctx;
}

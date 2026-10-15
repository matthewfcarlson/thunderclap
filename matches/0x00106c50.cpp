class Base {
  public:
    Base(const char*, int);
    virtual void f();
    char pad[12];
};
extern "C" char check(const void*);
extern char key1[], key2[];
class CPatrolPathManager;
class Method1 : public Base {
  public:
    Method1(const char* s, CPatrolPathManager* p) : Base(s, 1), owner(p) {
        b = check(key1);
        a = check(key2);
    }
    virtual void f();
    char a;
    char pad1[7];
    char b;
    char pad2[3];
    CPatrolPathManager* owner;
};
class Closure1 : public Method1 {
  public:
    Closure1(const char* s, void* x, CPatrolPathManager* p);
    virtual void f();
    void* other;
};
Closure1::Closure1(const char* s, void* x, CPatrolPathManager* p) : Method1(s, p), other(x) {}
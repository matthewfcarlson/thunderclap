class Base_2c8b0 {
  public:
    Base_2c8b0(const char*, int);
    virtual void f();
};
extern "C" char __cdecl lookup(const char*);
extern const char s1[], s2[], s3[];
class Method3 : public Base_2c8b0 {
  public:
    Method3(const char*, int);
    char pad[12];
    char a, b, c;
    char pad2[5];
    char d;
    char pad3[3];
    int val;
};
Method3::Method3(const char* name, int x) : Base_2c8b0(name, 3) {
    val = x;
    d = lookup(s1);
    a = lookup(s2);
    b = lookup(s3);
    c = lookup(s2);
}
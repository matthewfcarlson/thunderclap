class Base_1069c0 {
  public:
    virtual void f();
    Base_1069c0(const char*, int);
};
extern const char s1_1069c0[], s2[], s3[];
extern unsigned char __cdecl get(const char*);
class Method3 : public Base_1069c0 {
  public:
    virtual void f();
    char pad[12];
    unsigned char a, b, c;
    char pad2[5];
    unsigned char d;
    char pad3[3];
    int value;
    Method3(const char*, int);
};
Method3::Method3(const char* p, int v) : Base_1069c0(p, 3) {
    value = v;
    d = get(s1_1069c0);
    a = get(s2);
    b = get(s1_1069c0);
    c = get(s3);
}
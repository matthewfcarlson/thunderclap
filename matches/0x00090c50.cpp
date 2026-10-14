extern char str1[];
extern char str2[];
extern char str3[];
extern char str4[];
char convert(const char*);
class Base {
  public:
    virtual void Invoke();
    Base(char*, int);
    char pad[12];
};
class Method3 : public Base {
  public:
    virtual void Invoke();
    char a;
    char b;
    char c;
    char pad2[5];
    char d;
    char pad3[3];
    char* name;
    Method3(char*, char*);
};
Method3::Method3(char* arg, char* n) : Base(arg, 3) {
    name = n;
    d = convert(str1);
    a = convert(str2);
    b = convert(str3);
    c = convert(str4);
}
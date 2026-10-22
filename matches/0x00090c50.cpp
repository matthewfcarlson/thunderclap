extern char str1_90c50[];
extern char str2_90c50[];
extern char str3[];
extern char str4[];
char convert(const char*);
class Function_90c50 {
  public:
    virtual void Invoke();
    Function_90c50(char*, int);
    char pad[12];
};
class Method3 : public Function_90c50 {
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
Method3::Method3(char* arg, char* n) : Function_90c50(arg, 3) {
    name = n;
    d = convert(str1_90c50);
    a = convert(str2_90c50);
    b = convert(str3);
    c = convert(str4);
}
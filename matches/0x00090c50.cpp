#include "decls/data/game/global.h"
// data: str1_90c50 = DAT_0048e100, str2_90c50 = DAT_0049cad8, str3 = DAT_0049cad8, str4 = DAT_0048e134

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
    d = convert(((char*)&DAT_0048e100));
    a = convert(((char*)&DAT_0049cad8));
    b = convert(((char*)&DAT_0049cad8));
    c = convert(((char*)&DAT_0048e134));
}
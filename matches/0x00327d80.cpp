#include "decls/data/engine/pure3d.h"
// data: g_obj_327d80 = DAT_005555bc

int g_current = -1;
class Target_327d80 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14(int);
    char pad[8];
    int key;
    void run(int, char);
};
void Target_327d80::run(int arg, char flag) {
    if (key != g_current) {
        if ((*(Target_327d80**)&DAT_005555bc))
            (*(Target_327d80**)&DAT_005555bc)->v13();
        g_current = key;
        v12();
        (*(Target_327d80**)&DAT_005555bc) = this;
    }
    if (flag)
        v14(arg);
}
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00014c30..0x00014c80 (kind game, layer game, confidence medium), dominant class CComboMessageAction
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_fe84ac2c {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fe84ac2c {} using namespace fn_fe84ac2c;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fe84ac2c {
class Message {
  public:
    char p[0x40];
};
class Obj {
  public:
    char a[0x10];
    Message message;
    int id;
};
class Lookup {
  public:
    void Get(void**, int);
};
class Sender {
  public:
    void Send(int, Message*, int, void*, float);
};
class SenderHolder {
  public:
    int pad;
    Sender* sender;
};
class Manager {
  public:
    char p[0x20];
    Lookup* lookup;
    char q[0x18];
    SenderHolder* holder;
};
extern Manager* gManager;
class CComboMessageAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual char vfunc_7(int);
    virtual void f8();
    char pad[0x1c];
    Obj* obj;
};


// 0x00014c30 CComboMessageAction::vfunc_7 (66 B): matches/0x00014c30.cpp
// sym: ?vfunc_7@CComboMessageAction@fn_fe84ac2c@@UAEDH@Z
char CComboMessageAction::vfunc_7(int x) {
    Message* message = &obj->message;
    Manager* mgr = gManager;
    void* result;
    mgr->lookup->Get(&result, obj->id);
    mgr->holder->sender->Send(1, message, -1, result, -1.0f);
    return 0;
}

} // namespace fn_fe84ac2c

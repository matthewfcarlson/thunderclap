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
char CComboMessageAction::vfunc_7(int x) {
    Message* message = &obj->message;
    Manager* mgr = gManager;
    void* result;
    mgr->lookup->Get(&result, obj->id);
    mgr->holder->sender->Send(1, message, -1, result, -1.0f);
    return 0;
}
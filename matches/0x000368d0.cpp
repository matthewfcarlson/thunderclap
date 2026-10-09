class Obj {
  public:
    char pad[0x72];
    unsigned char flag;
};
class Holder {
  public:
    char pad[0x74];
    Obj* obj;
};
class Result {
  public:
    char pad[0x74];
    Obj* obj;
};
class Context {
  public:
    Result* Get();
};
class Thing {
  public:
    char pad[0x128];
    Context* context;
    Holder* holder;
    void Set(unsigned char);
};
void Thing::Set(unsigned char value) {
    if (holder && holder->obj)
        holder->obj->flag = value;
    if (context) {
        Result* b = context->Get();
        if (b && b->obj)
            b->obj->flag = value;
    }
}
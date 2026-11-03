#include "gen/owners.h"
class Obj_368d0 {
  public:
    char pad[0x72];
    unsigned char flag;
};
class Holder_368d0 {
  public:
    char pad[0x74];
    Obj_368d0* obj;
};
class Result_368d0 {
  public:
    char pad[0x74];
    Obj_368d0* obj;
};
class Context {
  public:
};
class Thing_368d0 {
  public:
    char pad[0x128];
    Context* context;
    Holder_368d0* holder;
    void Set(unsigned char);
};
void Thing_368d0::Set(unsigned char value) {
    if (holder && holder->obj)
        holder->obj->flag = value;
    if (context) {
        Result_368d0* b = ((Result_368d0 *)((owners::C_1d72e0 *)context)->FUN_001d72e0());
        if (b && b->obj)
            b->obj->flag = value;
    }
}
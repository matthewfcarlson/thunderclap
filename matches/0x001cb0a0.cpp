#include "decls/address.h"
class Writer_1cb0a0 {
  public:
    bool Open();
    void Put(const char* k, const void* v);
    void Close();
};
class Mgr_1cb0a0 {
  public:
    char pad[0x44];
};
class Info_1cb0a0 {
  public:
    const char* Name();
};
class Look_1cb0a0 {
  public:
    Info_1cb0a0* Find(int id);
};
struct World {
    char pad[0x44];
    Look_1cb0a0* look;
};
Writer_1cb0a0* FUN_001d4c90();
class Actor_1cb0a0 {
  public:
    char pad[0x10];
    int mId;
    char mName[4];
    bool Save();
};
bool Actor_1cb0a0::Save() {
    Writer_1cb0a0* w = FUN_001d4c90();
    if (!w)
        return false;
    if (!w->Open())
        return false;
    w->Put("tv", &mName);
    World* g = DAT_004dd700;
    int id = mId;
    if (!g) {
        w->Close();
        return false;
    }
    Look_1cb0a0* l = g->look;
    Info_1cb0a0* i = l->Find(id);
    if (i)
        w->Put("actor", i->Name());
    else
        w->Put("actor", "UNKNOWN");
    w->Close();
    return true;
}

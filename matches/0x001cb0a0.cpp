class Writer {
  public:
    bool Open();
    void Put(const char* k, const void* v);
    void Close();
};
class Mgr {
  public:
    char pad[0x44];
};
class Info {
  public:
    const char* Name();
};
class Look {
  public:
    Info* Find(int id);
};
struct G {
    char pad[0x44];
    Look* look;
};
extern G* g_game;
Writer* GetWriter();
class Actor {
  public:
    char pad[0x10];
    int mId;
    char mName[4];
    bool Save();
};
bool Actor::Save() {
    Writer* w = GetWriter();
    if (!w)
        return false;
    if (!w->Open())
        return false;
    w->Put("tv", &mName);
    G* g = g_game;
    int id = mId;
    if (!g) {
        w->Close();
        return false;
    }
    Look* l = g->look;
    Info* i = l->Find(id);
    if (i)
        w->Put("actor", i->Name());
    else
        w->Put("actor", "UNKNOWN");
    w->Close();
    return true;
}

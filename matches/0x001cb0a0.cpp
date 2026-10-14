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
struct G_1cb0a0 {
    char pad[0x44];
    Look_1cb0a0* look;
};
extern G_1cb0a0* g_game_1cb0a0;
Writer_1cb0a0* GetWriter();
class Actor_1cb0a0 {
  public:
    char pad[0x10];
    int mId;
    char mName[4];
    bool Save();
};
bool Actor_1cb0a0::Save() {
    Writer_1cb0a0* w = GetWriter();
    if (!w)
        return false;
    if (!w->Open())
        return false;
    w->Put("tv", &mName);
    G_1cb0a0* g = g_game_1cb0a0;
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

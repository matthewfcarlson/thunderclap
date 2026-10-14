class Writer_1cafd0 {
  public:
    bool Open();
    void Put(const char* k, const void* v);
    void Close();
};
class Mgr_1cafd0 {
  public:
    char pad[0x44];
};
class Info_1cafd0 {
  public:
    const char* Name();
};
class Look_1cafd0 {
  public:
    Info_1cafd0* Find(int id);
};
struct G_1cafd0 {
    char pad[0x44];
    Look_1cafd0* look;
};
extern G_1cafd0* g_game_1cafd0;
Writer_1cafd0* GetWriter();
class Actor_1cafd0 {
  public:
    char pad[0x10];
    int mId;
    char mName[4];
    bool Save();
};
bool Actor_1cafd0::Save() {
    Writer_1cafd0* w = GetWriter();
    if (!w)
        return false;
    if (!w->Open())
        return false;
    w->Put("tv", &mName);
    G_1cafd0* g = g_game_1cafd0;
    int id = mId;
    if (!g) {
        w->Close();
        return false;
    }
    Look_1cafd0* l = g->look;
    Info_1cafd0* i = l->Find(id);
    if (i)
        w->Put("actor", i->Name());
    else
        w->Put("actor", "UNKNOWN");
    w->Close();
    return true;
}

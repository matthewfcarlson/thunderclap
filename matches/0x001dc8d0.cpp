struct Obj {
    float v[0x44 / 4 + 1];
};
struct Ent {
    char p[0x44];
    float f;
};
struct Slot {
    char p0[0x18];
    Ent* e;
    char p1[4];
    unsigned short cnt;
    char p2[6];
};
struct Rec {
    unsigned flags;
    char p[16];
};
class Mgr {
  public:
    int Find(int key);
    float Get(int key);
    char pad[0x608];
    Slot slots[1];
};
float Mgr::Get(int key) {
    float r = -1.0f;
    int i = Find(key);
    if (i >= 0) {
        Slot* s = &slots[i];
        short idx = *(short*)((char*)s + 0x22);
        if ((((Rec*)this)[idx + 0x104e].flags & 1) && s->e)
            return s->e->f;
        r = (float)s->cnt;
    }
    return r;
}

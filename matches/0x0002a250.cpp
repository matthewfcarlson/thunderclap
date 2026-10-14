struct Pair {
    unsigned a, b;
};
struct Item {
    char pad[8];
    unsigned a, b;
    Item* Check(int);
};
struct Owner {
  public:
    Item* Get(unsigned, unsigned);
    char Match(const char*, const char*);
};
extern "C" Pair __cdecl Parse(const char*, int, int);
extern "C" Pair __cdecl Hash(const char*);
char Owner::Match(const char* s, const char* t) {
    Pair p = Parse(s, 0, 0);
    Item* q = Get(p.a, p.b);
    if (!q)
        return 0;
    q = q->Check(0);
    if (!q)
        return 0;
    unsigned a = q->a, b = q->b;
    Pair h = Hash(t);
    return a == h.a && b == h.b;
}
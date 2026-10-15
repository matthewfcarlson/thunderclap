class Loader {
  public:
    int GetId();
};

struct Pair {
    int a;
    int b;
};

Pair __cdecl GetPair(int a, int b, int c);

extern Loader gLoader;
extern int gFirst;
extern int gSecond;

void FUN_0035fc70() {
    int id = gLoader.GetId();
    Pair p = GetPair(id, 0, 0);
    gFirst = p.a;
    gSecond = p.b;
}

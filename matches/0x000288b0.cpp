typedef __int64 I64;
extern "C" I64 __cdecl Lookup(const char*, int, int);
class Node {
  public:
    void Play(int, int, int, float, int, int);
};
class Owner {
  public:
    Node* Find(I64);
    void Do(const char*, int, int);
};
void Owner::Do(const char* name, int a, int b) {
    I64 id = Lookup(name, 0, 0);
    Node* n = Find(id);
    if (n)
        n->Play(a, 0, 0, 1.0f, b, 0);
}
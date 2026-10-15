typedef unsigned __int64 U64;
extern "C" U64 __cdecl MakeId(int, int, int);
struct Entry {
    char pad[0x1cef];
    char flag;
};
class Obj {
  public:
    Entry* Lookup(U64);
    char Set(int id, char value);
};
char Obj::Set(int id, char value) {
    Entry* e = Lookup(MakeId(id, 0, 0));
    if (!e)
        return 0;
    e->flag = value;
    return 1;
}
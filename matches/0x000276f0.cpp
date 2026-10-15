struct Item {
    char pad[0x11c];
    struct Handler* handler;
};
struct Handler {
    void Run(int);
};
extern "C" __int64 __cdecl Convert(int, int, int);
class Obj {
  public:
    Item* Find(__int64);
    void Func(int id, int value);
};
void Obj::Func(int id, int value) {
    __int64 key = Convert(id, 0, 0);
    Item* item = Find(key);
    if (item && item->handler)
        item->handler->Run(value);
}
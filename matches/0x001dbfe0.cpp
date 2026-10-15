struct Key {
    __int64 value;
    char pad[32];
};
extern "C" __int64 __cdecl FUN_00096d80(int);
class Obj {
    char pad[0x608];
    Key entries[2048];

  public:
    int Find(int);
};
int Obj::Find(int x) {
    __int64 key = FUN_00096d80(x);
    for (int i = 0; i < 2048; i++) {
        if (entries[i].value == key)
            return i;
    }
    return -1;
}
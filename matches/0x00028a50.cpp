extern float zeroFloat1, zeroFloat2;
extern "C" __int64 __cdecl FindKey(int, int, int);
struct Data {
    char pad[0x164];
    float value;
};
struct Item {
    char pad[0x11c];
    Data* data;
};
class Owner {
  public:
    Item* Lookup(__int64 key);
    float Get(int key);
};
float Owner::Get(int key) {
    __int64 id = FindKey(key, 0, 0);
    Item* item = Lookup(id);
    if (!item)
        return zeroFloat1;
    Data* data = item->data;
    if (data)
        return data->value;
    return zeroFloat2;
}
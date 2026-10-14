typedef unsigned int uint_266a30;
struct Stream {
    uint_266a30 FUN_00263fc0();
    void FUN_00264510(uint_266a30 amount);
    void FUN_002647e0(uint_266a30* destination, uint_266a30 a, uint_266a30 b, uint_266a30 c);
};
struct Entry_266a30 {
    uint_266a30 value;
    uint_266a30 second;
    uint_266a30 third;
    uint_266a30 position;
};
struct Object {
    char prefix[0x70];
    Entry_266a30 entries[33];
    uint_266a30 index;
    Stream* stream;
    uint_266a30 FUN_00266a30();
};
uint_266a30 Object::FUN_00266a30() {
    ++index;
    if (index != 0) {
        uint_266a30 end = entries[index].second + entries[index].position;
        if (stream->FUN_00263fc0() < end) {
            uint_266a30 current = stream->FUN_00263fc0();
            stream->FUN_00264510(end - current);
        }
    }
    uint_266a30 pos = stream->FUN_00263fc0();
    entries[index + 1].position = pos;
    uint_266a30 value;
    stream->FUN_002647e0(&value, 1, 4, 1);
    entries[index + 1].value = value;
    stream->FUN_002647e0(&value, 1, 4, 1);
    entries[index + 1].second = value;
    stream->FUN_002647e0(&value, 1, 4, 1);
    entries[index + 1].third = value;
    return entries[index + 1].value;
}
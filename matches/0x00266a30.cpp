typedef unsigned int uint;
struct Stream {
    uint FUN_00263fc0();
    void FUN_00264510(uint amount);
    void FUN_002647e0(uint* destination, uint a, uint b, uint c);
};
struct Entry {
    uint value;
    uint second;
    uint third;
    uint position;
};
struct Object {
    char prefix[0x70];
    Entry entries[33];
    uint index;
    Stream* stream;
    uint FUN_00266a30();
};
uint Object::FUN_00266a30() {
    ++index;
    if (index != 0) {
        uint end = entries[index].second + entries[index].position;
        if (stream->FUN_00263fc0() < end) {
            uint current = stream->FUN_00263fc0();
            stream->FUN_00264510(end - current);
        }
    }
    uint pos = stream->FUN_00263fc0();
    entries[index + 1].position = pos;
    uint value;
    stream->FUN_002647e0(&value, 1, 4, 1);
    entries[index + 1].value = value;
    stream->FUN_002647e0(&value, 1, 4, 1);
    entries[index + 1].second = value;
    stream->FUN_002647e0(&value, 1, 4, 1);
    entries[index + 1].third = value;
    return entries[index + 1].value;
}
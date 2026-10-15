int __cdecl convert(int);
class Queue {
  public:
    char pad[0x200];
    int entries[64];
    int count;
    int index;
    void Add(int value);
};
void Queue::Add(int value) {
    int result = convert(value);
    if (count >= 64) {
        entries[index] = result;
        index = (index + 1) % 64;
        return;
    }
    entries[count] = result;
    ++count;
}

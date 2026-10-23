int __cdecl FUN_000969d0(int);
class Queue {
  public:
    char pad[0x200];
    int entries[64];
    int count;
    int index;
    void Add(int value);
};
void Queue::Add(int value) {
    int result = FUN_000969d0(value);
    if (count >= 64) {
        entries[index] = result;
        index = (index + 1) % 64;
        return;
    }
    entries[count] = result;
    ++count;
}

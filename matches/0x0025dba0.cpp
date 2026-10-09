class Queue {
  public:
    char pad[0x4c];
    int* head;
    int* tail;
    void Add(int* item);
};

void Queue::Add(int* item) {
    int* node = item + 1;
    *node = 0;
    if (tail == 0) {
        head = node;
        tail = node;
    } else {
        *tail = (int)node;
        tail = node;
    }
}

struct Item_304da0 {
    int a, b, c, d, e;
};
class Buffer_304da0 {
  public:
    int count;
    int capacity;
    Item_304da0* data;
    Buffer_304da0& Assign(const Buffer_304da0& other);
    void Reserve(int n);
};
Buffer_304da0& Buffer_304da0::Assign(const Buffer_304da0& other) {
    if (capacity < other.capacity)
        Reserve(other.capacity);
    count = other.count;
    for (int i = 0; i < count; ++i)
        data[i] = other.data[i];
    return *this;
}
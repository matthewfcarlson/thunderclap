struct Item { int a,b,c,d,e; };
class Buffer { public: int count; int capacity; Item* data; Buffer& Assign(const Buffer& other); void Reserve(int n); };
Buffer& Buffer::Assign(const Buffer& other) {
 if (capacity < other.capacity) Reserve(other.capacity);
 count = other.count;
 for (int i=0; i<count; ++i) data[i]=other.data[i];
 return *this;
}
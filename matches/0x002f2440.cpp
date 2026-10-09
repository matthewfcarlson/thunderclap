struct Buffer { int count; int capacity; char* data; void Reserve(int); char* Next(); };
char* Buffer::Next() { if (count >= capacity) Reserve(capacity * 2); ++count; return data + count * 12 - 12; }
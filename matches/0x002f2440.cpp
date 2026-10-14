struct Buffer_2f2440 {
    int count;
    int capacity;
    char* data;
    void Reserve(int);
    char* Next();
};
char* Buffer_2f2440::Next() {
    if (count >= capacity)
        Reserve(capacity * 2);
    ++count;
    return data + count * 12 - 12;
}
struct Container_304e50 {
    int count;
    int capacity;
    char* data;
    void Ensure(int);
    char* Next();
};
char* Container_304e50::Next() {
    int cap = capacity;
    if (count >= cap)
        Ensure(cap * 2);
    ++count;
    return data + count * 20 - 20;
}
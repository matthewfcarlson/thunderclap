struct Inner {
    char pad[4];
    char value;
};

struct Owner {
    char pad[4];
    Inner* p;

    void Set(char c);
};

void Owner::Set(char c) {
    Inner* q = p;
    q->value = c;
}

struct Inner_d6f90 {
    char pad[4];
    char value;
};

struct Owner_d6f90 {
    char pad[4];
    Inner_d6f90* p;

    void Set(char c);
};

void Owner_d6f90::Set(char c) {
    Inner_d6f90* q = p;
    q->value = c;
}

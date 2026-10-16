struct First {
    int a;
    First() : a(-1) {}
};
struct Rest {
    int b, c, d;
    Rest() : b(0), c(0), d(0) {}
};
struct Sub {
    Sub();
    char pad[8];
};
struct Obj {
    Obj();
    First first;
    Rest rest;
    Sub sub;
    int tail;
};
Obj::Obj() : tail(0) {}
struct Triple {
    int a, b, c;
};
class Worker {
  public:
    int Run(int x, Triple t);
};
class Owner {
    char pad[0x88];
    Worker* worker;

  public:
    int Do(int x, Triple t);
};
int Owner::Do(int x, Triple t) {
    Worker* w = worker;
    int result = -1;
    if (w)
        result = w->Run(x, t);
    return result;
}
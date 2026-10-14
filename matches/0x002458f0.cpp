struct Reader {
    char pad[0x0c];
    char(__cdecl* getEnd)(Reader*, int*);
    char(__cdecl* getStart)(Reader*, int*);
};
class Owner_2458f0 {
  public:
    char pad[0x80];
    Reader* r;
    int a, b, c, d, e, diff, h;
    Owner_2458f0* Init(Reader*);
};
Owner_2458f0* Owner_2458f0::Init(Reader* rd) {
    r = rd;
    a = 0;
    b = 0;
    c = 0;
    d = 1;
    e = 0;
    h = 0;
    int end = 0;
    int start = 0;
    if (rd->getStart(rd, &start) && rd->getEnd(rd, &end))
        diff = end - start;
    else
        diff = 0;
    return this;
}

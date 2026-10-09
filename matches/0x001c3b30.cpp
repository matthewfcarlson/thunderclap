class Helper { public: int first(int); void second(int); };
class Obj { public: char pad[8]; Helper *m; void target(int); };
void Obj::target(int param) {
 int r = m->first(param);
 if (r) m->second(r);
}
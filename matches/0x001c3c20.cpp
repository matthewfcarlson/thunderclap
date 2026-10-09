class Inner { public: char pad[0xcc]; char flag; };
class Helper { public: void Stop(); };
class Obj { public: Inner* volatile p; Helper* h; void Set(char value); };
void Obj::Set(char value) {
    if (p->flag) {
        if (value == 0) h->Stop();
        p->flag = value;
    } else {
        p->flag = value;
    }
}
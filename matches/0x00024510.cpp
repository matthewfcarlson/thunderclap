// Same code shape as 0x000244e0 (propagated; names are from that function)
class Helper { public: void Call(int); };
class Owner { public: char pad[0x44]; Helper* mHelper; };
class Outer { public: Owner* mOwner; int pad[2]; int count; int items[1]; void run(); };
void Outer::run() {
  int i = 0;
  if (count > 0) {
    int *p = items;
    do {
      mOwner->mHelper->Call(*p);
      ++i;
      ++p;
    } while (i < count);
  }
}

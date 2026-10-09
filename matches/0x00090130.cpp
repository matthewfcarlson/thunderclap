struct Stats { int Find(const char* n); void SetXp(int v); char p[0x38]; };
void Stats::SetXp(int v) {
  int i = Find("xp");
  if (i != -1) {
    int* q = (int*)((char*)this + i * 0x40 + 0x38);
    *q = v;
    if (v > 999999999) *q = 999999999;
    i = Find("xpaccumulated");
    if (i != -1 && (v == 0 || v > *(int*)((char*)this + i * 0x40 + 0x38))) {
      q = (int*)((char*)this + i * 0x40 + 0x38);
      *q = v;
      if (v > 999999999) *q = 999999999;
    }
  }
}

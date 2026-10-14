// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00328f10 @ 0x00328f10
struct State_328f10 {
 char reserved0[8];
 unsigned values08[4];
 unsigned indices18[4];
 unsigned values28[4];
 unsigned values38[4];
 unsigned enabled48;
 unsigned char flag4c;
 char reserved4d[7];
 unsigned enabled54;
 unsigned value58;
 unsigned char flag5c;
 char reserved5d[3];
 unsigned mode60;
 unsigned values64[4];
 unsigned values74[4];
 unsigned values84[4];
 unsigned values94[4];
 unsigned valuesa4[4];
 unsigned valuesb4[4];
 unsigned valuesc4[4];
 unsigned valuesd4[4];
 unsigned valuese4[4];
 unsigned valuesf4[4];
 unsigned char flag104;
 unsigned char flag105;
 char reserved106[2];
 unsigned value108;
 unsigned value10c;
 unsigned enabled110;
 float scale114;
 unsigned value118;
 unsigned value11c;
 float scale120;
 void FUN_00328bf0();
 void FUN_00328f10();
};
void State_328f10::FUN_00328f10() {
 for (unsigned i = 0; i < 4; ++i) {
  indices18[i] = i;
  values08[i] = 0;
  values38[i] = 0;
  values28[i] = 0;
  values74[i] = 1;
  values64[i] = 1;
  valuesb4[i] = 1;
  values84[i] = 1;
  valuesc4[i] = 2;
  values94[i] = 2;
  valuesd4[i] = 1;
  valuesa4[i] = 1;
  valuese4[i] = 1;
  valuesf4[i] = 0;
 }
 flag4c = 0;
 value58 = 0;
 flag5c = 0;
 flag105 = 0;
 flag104 = 0;
 value108 = 0;
 value10c = 0;
 value118 = 0;
 value11c = 0;
 enabled48 = 1;
 enabled54 = 1;
 mode60 = 5;
 enabled110 = 1;
 scale114 = 1.0f;
 scale120 = 1.0f;
 FUN_00328bf0();
}

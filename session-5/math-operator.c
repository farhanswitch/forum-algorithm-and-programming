#include <stdio.h>

// Function Definition
int isMatchTheValue(int a, int x1, int x2, int x3, int x4, int targetValue);

int main() {
  // Deklarasi variabel
  int a = 10;
  int maxValue = 100;
  int x1, x2, x3, x4;

  // Lakukan pengulangan berasarang (nested looping) untuk menemukan kombinasi
  // yang tepat
  for (x1 = 0; x1 < maxValue; x1++) {
    for (x2 = 0; x2 < maxValue; x2++) {
      for (x3 = 0; x3 < maxValue; x3++) {
        for (x4 = 0; x4 < maxValue; x4++) {
          // Lakukan penegcekan apakah kombinasi nya sesuai
          // Jika sesuai hentikan semua perulangan
          if (isMatchTheValue(a, x1, x2, x3, x4, 10)) {
            maxValue = -1;
            break;
          }
        }
        if (maxValue == -1) break;
      }
      if (maxValue == -1) break;
    }
    if (maxValue == -1) break;
  }

  printf("Nilai a akan kembali ke nilai awalnya yaitu 10, jika...\n");
  printf("x1 = %d\nx2 = %d\nx3 = %d\nx4 = %d\n", x1, x2, x3, x4);
  printf("\n\n--------------------\n\n");
  printf("Pembuktian: \n");
  printf("a = %d\n", a);
  printf("a -= 4   -> a = %d - 4\n", a);
  a -= 4;
  printf("a = %d\n", a);
  printf("a += x1  -> a = %d + %d\n", a, x1);
  a += x1;
  printf("a = %d\n", a);
  printf("a *= x2  -> a = %d * %d\n", a, x2);
  a *= x2;
  printf("a = %d\n", a);
  printf("a /= x3  -> a = %d / %d\n", a, x3);
  a /= x3;
  printf("a = %d\n", a);
  printf("a %%= x4  -> a = %d %% %d\n", a, x4);
  a %= x4;
  printf("a = %d\n", a);

  return 0;
}

// Function Implementation

/**
 * Function untuk melakukan pengecekan apakah setelah dilakukan operasi
 * aritmatika bilai akhir nya sesuai dengan yang diinginkan
 *
 * {int} a - Nilai awal
 * {int} x1 - Angka untuk dilakukan operasi penjumlahan dengan a
 * {int} x2 - Angka untuk dilakukan operasi perkalian dengan a
 * {int} x3 - Angka untuk dilakukan operasi pembagian dengan a
 * {int} x4 - Amgka untuk dilakukan operasi modulo dengan a
 * returns {int}
 * */
int isMatchTheValue(int a, int x1, int x2, int x3, int x4, int targetValue) {
  a -= 4;
  a += x1;
  a *= x2;
  a /= x3;
  a %= x4;

  // Jika nilai a sesuai dengan angka yang diinginkan maka kembalikan 1 (True)
  if (a == targetValue) {
    return 1;
  }
  // Jika a tidak sesuai dengan angka yang diinginkan
  else {
    return 0;
  }
}

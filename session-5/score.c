#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Function Declaration
int getFinalScore(int tugas, int uts, int uas);
char *getGrade(int finalScore);
int checkIsNumberOnly(char nim[100]);
int checkIsLettersAndSpacesOnly(char nama[255]);
int checkIsValidScore(int score);

int main() {
  // Deklarasi variabel
  int tugas = -1, uts = -1, uas = -1, nilaiAkhir;
  char nim[100] = "a", nama[255] = "1", grade[4] = "";

  printf("==================================================\n");
  printf("PROGRAM MENGHITUNG NILAI AKHIR DAN GRADE MAHASISWA\n");
  printf("==================================================\n\n\n");

  // Baca input dari user dan lakukan validasi

  while (checkIsLettersAndSpacesOnly(nama) != 1) {
    printf("Masukkan nama (hanya huruf dan spasi): ");
    scanf("%[^\n]s", nama);
    getchar();
  }

  while (checkIsNumberOnly(nim) != 1) {
    printf("Masukkan NIM (hanya angka): ");
    scanf("%[^\n]s", nim);
    getchar();
  }

  while (checkIsValidScore(tugas) != 1) {
    printf("Masukkan nilai tugas (0-100): ");
    scanf("%d", &tugas);
    getchar();
  }

  while (checkIsValidScore(uts) != 1) {
    printf("Masukkan nilai UTS (0-100): ");
    scanf("%d", &uts);
    getchar();
  }

  while (checkIsValidScore(uas) != 1) {
    printf("Masukkan nilai UAS (0-100): ");
    scanf("%d", &uas);
    getchar();
  }

  // Proses hitung nilai akhir
  nilaiAkhir = getFinalScore(tugas, uts, uas);

  // Proses dapatkan Grade berdasarkan nilaiAkhir
  strcpy(grade, getGrade(nilaiAkhir));

  // Menampilkan hasil
  printf("\n\n--------------------------------------------------\n\n");
  printf("%-30s: ", "Nama Mahasiswa");
  printf("%s\n", nama);
  printf("%-30s: ", "Nomor Induk Mahasiswa");
  printf("%s\n", nim);
  printf("%-30s: ", "Nilai Akhir");
  printf("%d\n", nilaiAkhir);
  printf("%-30s: ", "Grade");
  printf("%s\n", grade);
  return 0;
}

/**
 * Function untuk cek apakah nilai nya valid atau tidak. Nilai yang valid berada
 * di range 0 - 100
 *
 * {int} score - nilai yang akan dicek
 * returns {int}
 * */
int checkIsValidScore(int score) {
  // Jika nilai berada di rang 0 - 100
  if (score >= 0 && score <= 100) {
    return 1;
  }
  // Jika nilai tidak diantara 0 - 100
  else {
    return 0;
  }
}

/**
 * Function untuk cek apakah string nya hanya terdiri dari bilangan
 *
 * {string} nim - Kalimat yang akan dicek
 * returns {int}
 * */
int checkIsNumberOnly(char nim[100]) {
  // Cek per karakter dari kalimat apakah merupakan bilangan
  for (int i = 0; i < strlen(nim); i++) {
    if (!isdigit(nim[i])) {
      return 0;
    }
  }
  return 1;
}

/**
 * Function untuk cek apakah string hanya terdiri dari huruf dan spasi
 *
 * {string} name - kalimat yang akna dicek
 * returns {int}
 * */
int checkIsLettersAndSpacesOnly(char nama[255]) {
  // Karakter yang diizinkan
  char lettersAndSpace[100] =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ \0";
  // Dapatkan panjang dari kalimat yg akan dicek
  int inputLength = strlen(nama);
  int totalValid;

  // cek per karakter dari kalimat apakah valid atau tidak
  for (int x = 0; x < inputLength; x++) {
    for (int y = 0; y < strlen(lettersAndSpace); y++) {
      if (nama[x] == lettersAndSpace[y]) {
        totalValid++;
        break;
      }
    }
  }

  // Jika jumlah karakter yang valid sama dengan panjang kalimat
  if (inputLength == totalValid) {
    return 1;
  }
  // Jika jumlah karakter yang valid tidak sama dengan panjang kalimat
  else {
    return 0;
  }
}

/**
 * Function untuk menghitung nilai akhir
 *
 * {int} tugas - nilai tugas
 * {int} uts - nilai UTS
 * {int} uas - nilai UAS
 * returns {int}
 * */
int getFinalScore(int tugas, int uts, int uas) {
  int finalScore;

  // Hitung berdasarkan bobot nilai tugas yaitu 40%
  int nilaiTugas = tugas * 40 / 100;

  // Hitung berdasarkan bobot nilai uts yaitu 30%
  int nilaiUTS = uts * 30 / 100;
  // Hitung berdasarkan bobot nilai uas yaitu 30%
  int nilaiUAS = uas * 30 / 100;

  finalScore = nilaiTugas + nilaiUTS + nilaiUAS;
  return finalScore;
}

/**
 * Function untuk mendapatkan grade berdasarkan nilai akhir
 *
 * {int} finalScore - Nilai akhir
 * returns {string}
 * */
char *getGrade(int finalScore) {
  if (finalScore >= 90 && finalScore <= 100) {
    return "A";
  } else if (finalScore >= 85 && finalScore < 90) {
    return "A-";
  } else if (finalScore >= 80 && finalScore < 85) {
    return "B+";
  } else if (finalScore >= 75 && finalScore < 80) {
    return "B";
  } else if (finalScore >= 70 && finalScore < 75) {
    return "B-";
  } else if (finalScore >= 65 && finalScore < 70) {
    return "C";
  } else if (finalScore >= 50 && finalScore < 65) {
    return "D";
  }

  return "E";
}

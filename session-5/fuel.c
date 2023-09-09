#include <stdio.h>

// Function Declaration
int getFuelConsumption(int fuelType, int drivingMode);

int main() {
  // Deklarasi variabel
  int fuelType, drivingMode, fuelPerLiter;
  float distance, totalFuel, inputFuel, fuelLeft;

  printf("=========================\n");
  printf("PROGRAM MENGHITUNG PEMAKAIAN BAHAN BAKAR\n");
  printf("=========================\n");

  // Membaca input dari user
  printf("Silahkan input jarak yang akan ditempuh (kilometer): ");
  scanf("%f", &distance);
  getchar();
  printf("Jenis Bahan Bakar\n1. Pertamax\n2. Pertalite\n");
  while (1) {
    printf("Silahkan pilih jenis bahan bakar (1 atau 2): ");
    scanf("%d", &fuelType);
    getchar();
    if (fuelType == 1 || fuelType == 2) {
      break;
    }
    // Jika user menginput data yang tidak sesuai
    else {
      printf("Input yang anda masukkan tidak valid!\n");
    }
  }
  printf("Silahkan input berapa banyak bahan bakar yang akan diisi (liter): ");
  scanf("%f", &inputFuel);
  getchar();
  printf(
      "Tipe Berkendara:\n1. Konstan / Luar Kota\n2. Stop & Go / Dalam Kota\n");
  while (1) {
    printf("Silahkan memilih tipe berkendara (1 atau 2): ");
    scanf("%d", &drivingMode);
    getchar();
    if (drivingMode == 1 || drivingMode == 2) {
      break;
    }
    // Jika user menginput data yang tidak sesuai
    else {
      printf("Input yang andda masukkan tidak valid!\n");
    }
  }

  // Hitung berapa banyak bahan bakar yang digunakan per liter berdasarkan tipe
  // berkendara dan jenis bahan bakar
  fuelPerLiter = getFuelConsumption(fuelType, drivingMode);
  // Hitung jumlah bahan bakar yang dibutuhkan untuk sampai ke tujuan
  totalFuel = (float)distance / fuelPerLiter;

  fuelLeft = inputFuel - totalFuel;
  printf("-------------------------\n");
  printf(
      "Jumlah bahan bakar yang digunakan untuk menempuh jarak %.2f adalah: "
      "%.2f liter\n",
      distance, totalFuel);
  if (fuelLeft < 0) {
    printf("Bahan bakar habis sebelum mencapai tujuan!\n");
  } else {
    printf("Bahan bakar yang tersisa: %.2f\n", fuelLeft);
  }
}

// Function Implementation

/**
 * Function untuk menghitung pemakaian bahan bakar per liter berdasarkan jenis
 * bahan bakar dan mode mengemudi
 *
 * {int} fuelType - Jenis bahan bakar yang digunakan
 * {int} drivingMode - Mode mengemudi
 *
 * returns {int}
 * */
int getFuelConsumption(int fuelType, int drivingMode) {
  int fuelPerLiter;

  // Jika bahan bakarnya Pertamax
  if (fuelType == 1) {
    // Jika tipe berkendara nya konstan
    if (drivingMode == 1) {
      fuelPerLiter = 15;
    }
    // Jika tipe berkendara nya stop & go
    else if (drivingMode == 2) {
      fuelPerLiter = 10;
    }
  } else if (fuelType == 2) {
    // Jika tipe berkendaranya konstan
    if (drivingMode == 1) {
      fuelPerLiter = 12;
    }
    // Jika tipe berkendara nya Stop & Go
    if (drivingMode == 2) {
      fuelPerLiter = 8;
    }
  }

  return fuelPerLiter;
}

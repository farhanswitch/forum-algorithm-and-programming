#include <stdio.h>

/* Inisiasi sebuah struct yang akan menyimpan data dari setiap mahasiswa
  Struct ini memiliki 2 property yaitu code dan name
  Code adalah kode kelulusan mahasiswa, jika Lulus maka 1 dan 2 jika gagal
  Name adalah nama setiap mahasiswa
  Data mahasiswa disimpan dalam struct supaya lebih mudah dalam mengolah data nya
  Refrensi https://www.w3schools.com/c/c_structs.php 
*/
struct StudentData {
  int code;
  char name[255];
};
int main(){
  
  /* Deklarasi variabel
    totalStudent akan menyimpan jumlah mahasiwa
    totalPassed adalah banyaknya mahasiwa yang Lulus
    totalFailed adalah banyaknya mahasiswa yang gagal 
    passPercentage adalah persentase kelulusan mahasiwa
    listStudent adalah array yang menyimpan struct yang berisi data setiap mahasiswa jadi listStudent berisi data seluruh mahasiswa
  */
  int totalStudent, totalPassed = 0, totalFailed = 0;
  float passPercentage;
  struct StudentData listStudent[100];


  // Proses input
  

  //Input Jumlah Mahasiswa
  printf("=============== Program Input Nilai Mata Kuliah Pengelolaan Bisnis Brokering Real-Estate ===============\n");
  printf("Masukkan jumlah mahasiswa: ");
  scanf("%d", &totalStudent);
  getchar();
  printf("\n");

  // Proses input data mahasiswa
  for(int x =0; x < totalStudent; x++){
    struct StudentData currentStudent;
    printf("Masukkan nama mahasiswa %d: ",x+1);
    scanf("%[^\n]s", currentStudent.name);
    getchar();
    printf("Masukkan hasil (1 => Lulus dan 2 => Gagal): ");
    scanf("%d", &currentStudent.code);
    getchar();
    // Masukkan data mahasiswa ke listStudent
    listStudent[x] = currentStudent;
  }

  printf("==============================\n");
  printf("Data Seluruh Mahasiswa\n");
  printf("==============================\n");
  // Menampilkan semua data mahasiswa
  for(int y = 0; y < totalStudent; y++){

    printf("Mahasiswa No. %d\n", y);
    printf("Nama mahasiswa: %s\n", listStudent[y].name);
    // Akan menampilkan hasil Lulus jika code dari mahasiswa adalah 1 dan Gagal jika code nya 2
    // Jika code dari mahasiswa adalah 1 maka, jumlah totalPassed akan bertambah 1
    if(listStudent[y].code == 1){
      totalPassed += 1;
      printf("Hasil: Lulus\n");

    }
    // Jika code dari mahasiswa adalah 2, maka jumlah totalFailed akan bertambah 1
    else{
      totalFailed += 1;
      printf("Hasil: Gagal\n");
    }

    printf("----------\n");
    
  }

  // Proses hitung persentase kelulusan
  passPercentage = (float) totalPassed * 100 / totalStudent;

  // Menampilkan ringkasan
  printf("Ringkasan\n");
  printf("Jumlah seluruh mahasiswa: %d\n", totalStudent);
  printf("Jumlah mahasiswa yang Lulus: %d\n", totalPassed);
  printf("Jumlah mahasiswa yang Gagal: %d\n", totalFailed);
  printf("Persentase kelulusan: %.2f\n\n", passPercentage);

  if(passPercentage > 80){
    printf("Kelulusan Kelas Telah Mencapai Target!\n");
  }else{
    printf("Kelulusan Kelas Belum Mencapai Target!\n");
  }

  return 0;
}

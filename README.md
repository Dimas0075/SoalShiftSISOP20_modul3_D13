# SoalShiftSISOP20_modul3_D13

# Anggota Kelompok
* Herri Purba                     05111840000056
* Nugroho Dimas Ardiyanto         05111840000075

# Soal 3
Buatlah sebuah program dari C untuk mengkategorikan file. Program ini akan
memindahkan file sesuai ekstensinya (tidak case sensitive. JPG dan jpg adalah
sama) ke dalam folder sesuai ekstensinya yang folder hasilnya terdapat di working
directory ketika program kategori tersebut dijalankan.
* Pada opsi -f tersebut, user bisa menambahkan argumen file yang bisa
dikategorikan sebanyak yang user inginkan seperti contoh di atas.
* Pada program kategori tersebut, folder jpg,c,zip tidak dibuat secara manual,
melainkan melalui program c. Semisal ada file yang tidak memiliki ekstensi,
maka dia akan disimpan dalam folder “Unknown”.
# Penyelesaian
```c
if (strcmp(argv[1],"-f") == 0) {
        for(j = 2 ; j < argc ; j++ ){
            pthread_create(&(tid[i]),NULL,moveandmake,argv[j]);
            pthread_join(tid[i],NULL);
            i++;
        }
```
Melakukan passing ke fungsi moveandmake dengan parameternya berasal dari argument
```c
 strcpy(abc,arg);
    char *token,*token1;

	unsigned long i=0;

    token1 = strtok(abc, "/");
    while( token1 != NULL ) {
        arr2[m] = token1;
        m++;
        token1 = strtok(NULL, "/");
    }
    strcpy(arr3,arr2[m-1]);
    token = strtok(arr2[m-1], ".");
    while( token != NULL ) {
        arr[n] = token;
        n++;
        token = strtok(NULL, ".");
    }

    char file[100];
    strcpy(file,arr[n-1]);
    for(int i = 0; file[i]; i++){
        file[i] = tolower(file[i]); //case sensitive
    }
```
Pada baris kode diatas digunakan untuk mengambil ekstensi dari argument dan untuk menangani case sencitive seperti pada soal

```c
DIR *folder, *folderopen;
    struct dirent *entry;
    char st[100];
    folder = opendir(cwd); 
    int available = 0; //flag
    if( n > 1 ){

        if(folder == NULL)
        {
            printf("error\n");
        }
        while( (entry=readdir(folder)) )
        {
            if(strcmp(entry->d_name,file) == 0 && entry->d_type == 4){
                available = 1;
                break;
            }
        }

        if(available == 0){
            strcpy(st,cwd);
            strcat(st,"/");
            strcat(st,file);
            mkdir(st, 0700);
        }
    }else{
        strcpy(st,cwd);
        strcat(st,"/");
        strcat(st,"Unknown");
        mkdir(st, 0700);
    }
```
Baris code diatas digunakan untuk membuat direktori sesuai dengan file ekstensinya

```c
char source[1024], target[1024];
    strcpy(source,arg);
    strcpy(target,cwd);
    strcat(target,"/");
    if(n == 1 ){
        strcat(target,"Unknown");
    }
    else{
        strcat(target,file);
    }
    strcat(target,"/");
    strcat(target,arr3);
    rename(source,target);
    n = 0;
    m = 0;

	return NULL;
}
```
Baris kode diatas digunakan untuk memindahkan file ke folder sesuai dengan ekstensinya


# Soal 4
Norland adalah seorang penjelajah terkenal. Pada suatu malam Norland menyusuri jalan setapak menuju ke sebuah gua dan mendapati tiga pilar yang pada setiap pilarnya ada sebuah batu berkilau yang tertancap. Batu itu berkilau di kegelapan dan setiap batunya memiliki warna yang berbeda. 
Norland mendapati ada sebuah teka-teki yang tertulis di setiap pilar. Untuk dapat mengambil batu mulia di suatu pilar, Ia harus memecahkan teka-teki yang ada di pilar tersebut. Norland menghampiri setiap pilar secara bergantian. 
- Batu mulia pertama. Emerald. Batu mulia yang berwarna hijau mengkilat. Pada batu itu Ia menemukan sebuah kalimat petunjuk. Ada sebuah teka-teki yang berisi: 
1. Buatlah program C dengan nama "4a.c", yang berisi program untuk melakukan perkalian matriks. Ukuran matriks pertama adalah 4x2, dan matriks kedua 2x5. Isi dari matriks didefinisikan di dalam kodingan. Matriks nantinya akan berisi angka 1-20 (tidak perlu dibuat filter angka). 2. Tampilkan matriks hasil perkalian tadi ke layar. 
- Batu kedua adalah Amethyst. Batu mulia berwarna ungu mengkilat. Teka-tekinya adalah: 
1. Buatlah program C kedua dengan nama "4b.c". Program ini akan mengambil variabel hasil perkalian matriks dari program "4a.c" (program sebelumnya), dan tampilkan hasil matriks tersebut ke layar. 
(Catatan!: gunakan shared memory) 2. Setelah ditampilkan, berikutnya untuk setiap angka dari matriks tersebut, carilah nilai faktorialnya, dan tampilkan hasilnya ke layar dengan format seperti matriks. 
Contoh: misal array [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], ...], maka: 
1 2 6 24 120 720 ... ... ... (Catatan! : Harus menggunakan Thread dalam penghitungan faktorial) 
- Batu ketiga adalah Onyx. Batu mulia berwarna hitam mengkilat. Pecahkan teka-teki berikut! 
1. Buatlah program C ketiga dengan nama "4c.c". Program ini tidak 
memiliki hubungan terhadap program yang lalu. 
2. Pada program ini, Norland diminta mengetahui jumlah file dan folder di direktori saat ini dengan command "ls | wc -l". Karena sudah belajar IPC, Norland mengerjakannya dengan semangat. (Catatan! : Harus menggunakan IPC Pipes) 
Begitu batu terakhir berhasil didapatkan. Gemuruh yang semakin lama semakin besar terdengar. Seluruh tempat berguncang dahsyat, tanah mulai merekah. Sebuah batu yang di atasnya terdapat kotak kayu muncul ke atas dengan sendirinya. 
Sementara batu tadi kembali ke posisinya. Tanah kembali menutup, seolah tidak pernah ada lubang merekah di atasnya satu detik lalu. 
Norland segera memasukkan tiga buah batu mulia Emerald, Amethys, Onyx pada Peti Kayu. Maka terbukalah Peti Kayu tersebut. Di dalamnya terdapat sebuah harta karun rahasia. Sampai saat ini banyak orang memburu harta karun tersebut. Sebelum menghilang, dia menyisakan semua petunjuk tentang harta karun tersebut melalui tulisan dalam buku catatannya yang tersebar di penjuru dunia. "One Piece does exist". 



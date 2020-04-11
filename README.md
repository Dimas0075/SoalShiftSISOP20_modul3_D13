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



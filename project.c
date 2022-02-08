#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s1{
  char jnso[100];
  int nomo;
  char cato[100];
  char jnsi[100];
  int nomi;
  char cati[100];
};

struct uang{
  int sld;
  int tgl;
  int bln;
  int thn;
  struct s1 y[100];
};

struct uang x[100];

int datecheck(int a){
  x[0].thn=0;x[0].bln=0;x[0].tgl=0;
  int b=0;
  if(x[a].thn<=0 || x[a].bln<=0 || x[a].tgl<=0){
    return 0;
  }

  if(x[a].bln>12){
    return 0;
  }

  if(x[a].bln==1||x[a].bln==3||x[a].bln==5||x[a].bln==7||x[a].bln==8||x[a].bln==10||x[a].bln==12) if(x[a].tgl<=31) b=1;
  if(x[a].bln==4||x[a].bln==6||x[a].bln==9||x[a].bln==11) if(x[a].tgl<=30) b=1;
  if(x[a].thn%4==0 && x[a].bln==2 && x[a].tgl<=29) b=1;
  if(x[a].thn%4==1 && x[a].bln==2 && x[a].tgl<=28) b=1;

  if(x[a-1].thn<x[a].thn){
    return b;
  }

  if(x[a-1].thn==x[a].thn){
    if(x[a-1].bln<x[a].bln){
      return b;
    }}

  if(x[a-1].thn==x[a].thn){
    if(x[a-1].bln==x[a].bln){
      if(x[a-1].tgl<x[a].tgl && x[a].tgl<=31){
        return b;
      }else return 0;
    }}}

void putinfile(int a, int ent, int pp){
  char entstr[10],nomstr[30];
  FILE *fp;
  char z;
  fp=fopen("keuangan.txt","a");
  if(fp==NULL){
      printf("File Not Found\n");
      exit(0);
    }
  else{
    sprintf(entstr,"%d",ent);
    fputs("\n--Entry: ", fp);
    fputs(entstr, fp);
    if(pp==1){
      sprintf(nomstr,"%d",x[a].y[ent].nomo);
      fputs("\nPengeluaran\nJenis: ", fp);
      fputs(x[a].y[ent].jnso, fp);
      fputs("\nNominal: Rp ", fp);
      fputs(nomstr, fp);
      fputs("\nCatatan: ", fp);
      fputs(x[a].y[ent].cato, fp);
      fputs("\n",fp);
    }
    if(pp==2){
      sprintf(nomstr,"%d",x[a].y[ent].nomi);
      fputs("\nPemasukan\nJenis: ", fp);
      fputs(x[a].y[ent].jnsi, fp);
      fputs("\nNominal: Rp ", fp);
      fputs(nomstr, fp);
      fputs("\nCatatan: ", fp);
      fputs(x[a].y[ent].cati, fp);
      fputs("\n",fp);
    }}
  fclose(fp);
}

void lhttgl(int a, int ent, int c, int maxent, int sldawl){
  int e,dtc,mtc,yrc;
  printf("\nMasukkan tanggal bulan tahun (dd mm yyyy): "); scanf("%d %d %d", &dtc, &mtc, &yrc);
  for(a=1;a<c;a++){
    if(x[a].tgl==dtc && x[a].bln==mtc && x[a].thn==yrc){
      e=a;
      if(e!=1) printf("\n--Saldo awal: Rp %d--", x[e-1].sld);
      printf("\nTanggal %d-%d-%d\n", x[e].tgl, x[e].bln, x[e].thn);
      printf("\n--Pemasukan--");
      if(e==1) printf("\nJenis: Saldo awal\nNominal: Rp %d\n", sldawl);
      if(e>=1){
        for(ent=1;ent<maxent;ent++){
          if(x[e].y[ent].nomi!=0){
            printf("\nJenis: %s\nPemasukan: Rp %d\nCatatan: %s\n",x[e].y[ent].jnsi, x[e].y[ent].nomi, x[e].y[ent].cati);}}}
      printf("\n--Pengeluaran--");
      for(ent=1;ent<maxent;ent++){
        if(x[e].y[ent].nomo!=0){
          printf("\nJenis: %s\nPengeluaran: Rp %d\nCatatan: %s\n",x[e].y[ent].jnso, x[e].y[ent].nomo, x[e].y[ent].cato);}}
      printf("\n--Saldo akhir: Rp %d--\n", x[e].sld);
    }}}

void lhtjns(int a, int ent, int c, int maxent){
  int ac, entc,testii,testoo,testio,testoi; char jenis[100];
  printf("\nPilih: jenis\n");
  for(a=1;a<c;a++){
    for(ent=1;ent<maxent;ent++){
      if(x[a].y[ent].nomi != 0) printf("%d %d %s\n",a,ent,x[a].y[ent].jnsi);
      if(x[a].y[ent].nomo != 0) printf("%d %d %s\n",a,ent,x[a].y[ent].jnso);
    }}
  printf("Masukkan angka(spasi)angka, misal 1 1, 1 2\nPilihan: ");
  scanf("%d %d",&ac,&entc);

  printf("\n--Jenis: ");
  if(x[ac].y[entc].nomi != 0) printf("%s--",x[ac].y[entc].jnsi);
  if(x[ac].y[entc].nomo != 0) printf("%s--",x[ac].y[entc].jnso);

  for(a=1;a<c;a++){
    for(ent=1;ent<maxent;ent++){
      testii=strcmp(x[a].y[ent].jnsi, x[ac].y[entc].jnsi);
      testoo=strcmp(x[a].y[ent].jnso, x[ac].y[entc].jnso);
      testio=strcmp(x[a].y[ent].jnsi, x[ac].y[entc].jnso);
      testoi=strcmp(x[a].y[ent].jnso, x[ac].y[entc].jnsi);
      if(x[a].y[ent].nomi != 0){
        if(testii==0||testio==0) printf("\nTanggal %d-%d-%d\nPemasukan Rp %d\nCatatan: %s\n", x[a].tgl, x[a].bln, x[a].thn, x[a].y[ent].nomi,x[a].y[ent].cati);
      }
      if(x[a].y[ent].nomo != 0){
        if(testoo==0||testoi==0) printf("\nTanggal %d-%d-%d\nPengeluaran Rp %d\nCatatan: %s\n", x[a].tgl, x[a].bln, x[a].thn, x[a].y[ent].nomo,x[a].y[ent].cato);
      }
    }}}

void lhtall(){
  FILE *fp;
  char z;
  fp=fopen("keuangan.txt","r");
  while(1){
    if(fp==NULL){
      printf("File Not Found\n");
      exit(0);
    }
    else{
      z=fgetc(fp);
      if(z==EOF)
      break;
      printf("%c",z);}
  }
  fclose(fp);
  printf("\n");
}

int main(){
  int tmblhtdt, dc, conf, pp, lht, sldawl;
  int a=1, ent=1, c=1, maxent=1, e;
  printf("Program untuk mencatat keuangan untuk bisnis.");
  printf("\nMenu Utama\n1 Masukkan Transaksi\n2 Lihat Transaksi\n3 Keluar\nPilihan (masukkan angka): ");
  scanf("%d",&tmblhtdt);
  do{
    if(tmblhtdt==1){
      if(a>1) printf("\nMasukkan tanggal setelah %d-%d-%d", x[a-1].tgl, x[a-1].bln, x[a-1].thn);
      printf("\nMasukkan tanggal bulan tahun (dd mm yyyy): "); scanf("%d %d %d", &x[a].tgl, &x[a].bln, &x[a].thn);
      dc=datecheck(a);

      if(dc==1){
        printf("\nTanggal %d-%d-%d",x[a].tgl,x[a].bln,x[a].thn);
        if(a==1){
          printf("\nSaldo awal: Rp ");
          scanf("%d", &x[a].sld);sldawl=x[a].sld;
          printf("\nTanggal: %d-%d-%d\nSaldo: Rp %d\nIngin mencatat apa?\n1 Pengeluaran\n2 Pemasukan\n3 Kembali ke Menu Utama\nPilihan (masukkan angka): ",x[a].tgl,x[a].bln,x[a].thn,x[a].sld);}
        if(a>1){
          printf("\nSaldo: Rp %d\nIngin mencatat apa?\n1 Pengeluaran\n2 Pemasukan\n3 Kembali ke Menu Utama\nPilihan (masukkan angka): ",x[a-1].sld);
        }
        scanf("%d", &pp);
        if(ent==1){
          FILE *fp;
          fp=fopen("keuangan.txt","a");
          if(fp==NULL){
              printf("File Not Found\n");
              exit(0);
            }
          else{
            char store[300],dtstr[2],mtstr[2],yrstr[5],sldawlstr[10];;
            sprintf(dtstr,"%d",x[a].tgl);
            sprintf(mtstr,"%d",x[a].bln);
            sprintf(yrstr,"%d",x[a].thn);
            sprintf(sldawlstr,"%d",sldawl);
            fputs("--Tanggal: ",fp);
            fputs(dtstr,fp);
            fputs("-",fp);
            fputs(mtstr,fp);
            fputs("-",fp);
            fputs(yrstr,fp);
            fputs("--",fp);
            if(a==1 && ent==1){
              fputs("\nSaldo awal: Rp ",fp);
              fputs(sldawlstr,fp);
            }
            fputs("\n",fp);
          }
          fclose(fp);
        }
        do{
          if(ent==1 && a>1) x[a].sld=x[a-1].sld;
          if(pp==1){
            conf=2;
            while(conf==2){
              printf("\nTanggal: %d-%d-%d\nEntry ke-%d",x[a].tgl,x[a].bln,x[a].thn,ent);
              printf("\nMasukkkan jenis pengeluaran: ");scanf(" %[^\n]s", x[a].y[ent].jnso);
              printf("Masukkan nominal pengeluaran: Rp ");scanf("%d", &x[a].y[ent].nomo);
              printf("Catatan: ");scanf(" %[^\n]s", x[a].y[ent].cato);
              printf("\nKonfirmasi?\n1 Konfirmasi\n2 Hapus Data\n3 Keluar\nPilihan (masukkan angka): ");scanf("%d", &conf);
              if(conf==1){
                x[a].sld = x[a].sld - x[a].y[ent].nomo;
                putinfile(a,ent,pp);
                ent=ent+1;}}
            }
          if(pp==2){
            conf=2;
            while(conf==2){
              printf("\nTanggal: %d-%d-%d\nEntry ke-%d",x[a].tgl,x[a].bln,x[a].thn,ent);
              printf("\nMasukkkan jenis pemasukan: "); scanf(" %[^\n]s", x[a].y[ent].jnsi);
              printf("Masukkan nominal pemasukan: Rp "); scanf("%d", &x[a].y[ent].nomi);
              printf("Catatan: "); scanf(" %[^\n]s", x[a].y[ent].cati);
              printf("\nKonfirmasi?\n1 Konfirmasi\n2 Hapus Data\n3 Keluar\nPilihan (masukkan angka): ");scanf("%d", &conf);
              if(conf==1){
                x[a].sld = x[a].sld + x[a].y[ent].nomi;
                putinfile(a,ent,pp);
                ent=ent+1;
              }}
            }
          if(pp==1 || pp==2){
            printf("\nTanggal: %d-%d-%d\nSaldo: Rp %d\nIngin mencatat apa?\n1 Pengeluaran\n2 Pemasukan\n3 Selesai mencatat di tanggal ini dan kembali ke Menu Utama\nPilihan (masukkan angka): ",x[a].tgl,x[a].bln,x[a].thn,x[a].sld);
            scanf("%d", &pp);
            if(pp==3){if(ent>maxent) maxent=ent; ent=1;}
          }
        }while(pp==1 || pp==2);
        FILE *fp;fp=fopen("keuangan.txt","a");
        if(fp==NULL){
          printf("File test.txt can't be created\n");
          exit(1);
        }
        char sldakrstr[10];
        sprintf(sldakrstr,"%d",x[a].sld);
        fputs("\nSaldo akhir: Rp ", fp);
        fputs(sldakrstr, fp);
        fputs("\n",fp);
        fclose(fp);
        if(pp==3){a=a+1; c=a;}
      }
      else printf("Error\n");
    }
    if(tmblhtdt==2){
      printf("\nMenu (2) Lihat Transaksi\n1 Lihat transaksi berdasarkan tanggal\n2 Lihat transaksi berdasarkan jenis\n3 Lihat semua transaksi\n4 Ke Menu Utama\nPilihan (masukkan angka): ");
      scanf("%d", &lht);
      do{
        if(lht==1) lhttgl(a,ent,c,maxent,sldawl);
        if(lht==2) lhtjns(a,ent,c,maxent);
        if(lht==3) lhtall();
        if(lht==1 || lht==2 || lht==3){
          printf("\nMenu (2) Lihat Transaksi\n1 Lihat transaksi berdasarkan tanggal\n2 Lihat transaksi berdasarkan jenis\n3 Lihat semua transaksi\n4 Ke Menu Utama\nPilihan (masukkan angka): ");
          scanf("%d", &lht);}
      }while(lht==1 || lht==2 || lht==3);
    }
    if(tmblhtdt==1 || tmblhtdt==2){
      printf("\nMenu Utama\n1 Masukkan Transaksi\n2 Lihat Transaksi\n3 Keluar\nPilihan (masukkan angka): ");
      scanf("%d",&tmblhtdt);}
  }while(tmblhtdt==1 || tmblhtdt==2);

  printf("Terima kasih");
return 0;
}

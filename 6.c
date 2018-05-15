#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mycount{
   int ifs;
   int pass;
} mycounter;





mycounter bubbleSort(int *subarray, int len){
   int i, j, tmp;
   mycounter c = {0, 0};
   for (i = 0; i < len; i++) {

      printf("ソート中... %4d/%d　　　　　　　　　\r", i + 1, len);
      fflush(stdout);

      for (j = len - 1; j >= i + 1; j--) {


         if (subarray[j] < subarray[j - 1]) {
            tmp = subarray[j];
            subarray[j] = subarray[j - 1];
            subarray[j - 1] = tmp;
            c.pass++;
         }
         c.ifs++;
      }

   }

   return c;
}






int main(void) {
   char name[20];
   char y[1];
   int length, i, j, k;
   int *array;
   FILE *sort;
   FILE *random_ifs;
   FILE *up_ifs;
   FILE *down_ifs;
   FILE *random_pass;
   FILE *up_pass;
   FILE *down_pass;
   mycounter c1;

   printf("要素数を入力してください。\n> ");
   scanf("%d", &length);

   printf("ファイル名を入力してください。(拡張子不要)\n> ");
   scanf("%s", name);
   char arrayfile[30];
   sprintf(arrayfile,"%s%s",name, "-sort.txt");
   char ifs_rand[30];
   sprintf(ifs_rand,"%s%s",name, "-random-ifs.csv");
   char ifs_up[30];
   sprintf(ifs_up,"%s%s",name, "-up-ifs.csv");
   char ifs_down[30];
   sprintf(ifs_down,"%s%s",name, "-down-ifs.csv");
   char pass_rand[30];
   sprintf(pass_rand,"%s%s",name, "-random-pass.csv");
   char pass_up[30];
   sprintf(pass_up,"%s%s",name, "-up-pass.csv");
   char pass_down[30];
   sprintf(pass_down,"%s%s",name, "-down-pass.csv");

   do {
      printf("以下のファイルが生成されます。よろしいですか？(y / n)\n");
      printf("・%s\n", arrayfile);
      printf("・%s\n", ifs_rand);
      printf("・%s\n", ifs_up);
      printf("・%s\n", ifs_down);
      printf("・%s\n", pass_rand);
      printf("・%s\n", pass_up);
      printf("・%s\n> ", pass_down);
      scanf("%s", y);
      if (y[0] == 'n') {
         fprintf(stderr, "終了します。\n");
         exit(0);
      }
   } while(y[0] != 'y' && y[0] != 'n');


   if ((sort = fopen(arrayfile, "w")) == NULL) {
      fprintf(stderr, "%sのオープンに失敗しました.\n", arrayfile);
      exit(0);
   }
   printf("\n処理を開始します。最大要素数: %d\n\n", length);
   fprintf(sort,"最大要素数: %d\r\n", length);


   if ((random_ifs = fopen(ifs_rand, "w")) == NULL) {
      fprintf(stderr, "%sのオープンに失敗しました.\n", ifs_rand);
      exit(0);
   }
   if ((random_pass = fopen(pass_rand, "w")) == NULL) {
      fprintf(stderr, "%sのオープンに失敗しました.\n", pass_rand);
      exit(0);
   }
   printf("  ===ランダム===\n");
   fprintf(sort,"  ===ランダム===\r\n");
   fprintf(random_ifs,"データ数,比較回数\n");
   fprintf(random_pass,"データ数,交換回数\n");
   for (i = 0; i < length - 1; i++) {
      array = malloc(sizeof(int) * (i + 2));

      fprintf(sort,"データ数: %d\r\n", i + 2);
      fprintf(sort,"ソート前: ");
      for (j = 0; j < i + 2; j++) {
         array[j] = (rand() % length) + 1;
         fprintf(sort,"%2d,", array[j]);
      }
      fprintf(sort,"\r\n");


      c1 = bubbleSort(array, i + 2);

      fprintf(sort,"ソート後: ");
      for (j = 0; j < i + 2; j++) {
         fprintf(sort,"%2d,", array[j]);
      }
      fprintf(sort,"\r\n");
      fprintf(sort,"\r\n");

      free(array);
      fprintf(random_ifs,"%d,%d\n",i + 2, c1.ifs);
      fprintf(random_pass,"%d,%d\n",i + 2, c1.pass);
   }
   printf("ソート中... 完了                       \n");
   fprintf(sort,"\r\n");
   fclose(random_ifs);
   fclose(random_pass);

   if ((up_ifs = fopen(ifs_up, "w")) == NULL) {
      fprintf(stderr, "%sのオープンに失敗しました.\n", ifs_up);
      exit(0);
   }   if ((up_pass = fopen(pass_up, "w")) == NULL) {
      fprintf(stderr, "%sのオープンに失敗しました.\n", pass_up);
      exit(0);
   }
   printf("  ===昇順データ===\n");
   fprintf(sort,"  ===昇順データ===\r\n");
   fprintf(up_ifs,"データ数,比較回数\n");
   fprintf(up_pass,"データ数,交換回数\n");
   for (i = 0; i < length - 1; i++) {
      array = malloc(sizeof(int) * (i + 2));

      fprintf(sort,"データ数: %d\r\n", i + 2);
      fprintf(sort,"ソート前: ");
      for (j = 0; j < i + 2; j++) {
         array[j] = j;
         fprintf(sort,"%2d,", array[j]);
      }
      fprintf(sort,"\r\n");


      c1 = bubbleSort(array, i + 2);

      fprintf(sort,"ソート後: ");
      for (j = 0; j < i + 2; j++) {
         fprintf(sort,"%2d,", array[j]);
      }
      fprintf(sort,"\r\n");
      fprintf(sort,"\r\n");

      free(array);
      fprintf(up_ifs,"%d,%d\n",i + 2, c1.ifs);
      fprintf(up_pass,"%d,%d\n",i + 2, c1.pass);
   }
   printf("ソート中... 完了                 \n");
   fprintf(sort,"\r\n");
   fclose(up_ifs);
   fclose(up_pass);



   if ((down_ifs = fopen(ifs_down, "w")) == NULL) {
      fprintf(stderr, "%sのオープンに失敗しました.\n", ifs_down);
      exit(0);
   }
   if ((down_pass = fopen(pass_down, "w")) == NULL) {
      fprintf(stderr, "%sのオープンに失敗しました.\n", pass_down);
      exit(0);
   }
   printf("  ===降順データ===\n");
   fprintf(sort,"  ===降順データ===\r\n");
   fprintf(down_ifs,"データ数,比較回数\n");
   fprintf(down_pass,"データ数,交換回数\n");
   for (i = 0; i < length - 1; i++) {
      array = malloc(sizeof(int) * (i + 2));

      fprintf(sort,"データ数: %d\r\n", i + 2);
      fprintf(sort,"ソート前: ");
      for (j = 0; j < i + 2; j++) {
         array[j] = length - j;
         fprintf(sort,"%2d,", array[j]);
      }
      fprintf(sort,"\r\n");


      c1 = bubbleSort(array, i + 2);

      fprintf(sort,"ソート後: ");
      for (j = 0; j < i + 2; j++) {
         fprintf(sort,"%2d,", array[j]);
      }
      fprintf(sort,"\r\n");
      fprintf(sort,"\r\n");

      free(array);
      fprintf(down_ifs,"%d,%d\n",i + 2, c1.ifs);
      fprintf(down_pass,"%d,%d\n",i + 2, c1.pass);
   }
   printf("ソート中... 完了                   \n");
   fprintf(sort,"\r\n");
   fclose(down_ifs);
   fclose(down_pass);


   fclose(sort);
   printf("\n処理が完了しました。\n");
   return 0;
}







/**/

#include <stdio.h>
#include <stdlib.h>
 typedef struct{
 char *elem;
 int size;
 int length;
 }sqlist;

 void Initlist(sqlist *list){
 (*list).elem=(char*)malloc(100*sizeof(char));
 for(int i=0;i<100;i++){
    (*list).elem[i]=0;
 }
 (*list).length=0;
 (*list).size=100;
 return;
 }
 int main(){
 sqlist list;
 Initlist(&list);
 for(int m=0;m<5;m++){
    list.elem[m]=m+1;
    list.length++;
 }
 for(int i=0;i<list.length;i++){
printf("%d\n",list.elem[i]);
 }
 //²åÈë
 int i;
 char e=1;
 if(i<=1||i>=list.length+1)
    return 0;
 for(int j=list.length-1;j>=i-1;j--){
    list.elem[j+1]=list.elem[j];
 }
 list.elem[i-1]=e;
 list.length++;
 printf("%d\n",list.elem[i-1]);
 //É¾³ý
 if(i<1||i>list.length)
    return 0;
for(int k=i;k<=list.length;k++){
    list.elem[k-1]=list.elem[k];
}
list.length--;
printf("%d\n",list.length);
return 0;
}

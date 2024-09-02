#include <stdio.h>
union job{
char name[32];
float salary;
int worker_no;
}u;
struct Sjob1{
char name[32];
float salary;
int worker_no;
}s;
void main(){
printf("size of union:%d\n",sizeof(u));
printf("size of struct:%d",sizeof(s));

}


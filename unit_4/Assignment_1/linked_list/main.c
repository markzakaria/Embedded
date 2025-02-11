/*
author: mark
date: 9/2/2025
linked_list_task
*/
#include <stdio.h>
#include <stdint.h>
#include<string.h>
#include <stdlib.h>
struct Sdata
{
    int id;
    char name[30];
    float hight; 
};

struct Sstudent
{
   struct Sdata student_data;
   struct Sstudent* next_student; 
   //////////////////////////
   struct Sstudent* prev_student; // Added previous pointer
};

struct Sstudent *gpfirst_student = NULL ; // global pointer to first element
//first option
void add_student()
{
    struct Sstudent* pnew_student;
    struct Sstudent* plast_student;
    char temp_text[30];

    //check whether list is empty or not
    if(gpfirst_student == NULL){
        //create first element
        pnew_student = (struct Sstudent*)malloc(sizeof(struct Sstudent));
        gpfirst_student = pnew_student;
        ////////////////////////////
        pnew_student->prev_student = NULL; // Initialize prev pointer
    }
    else{
        //if it already has elements and we want to add a new elemnt
        //navigate until finding last element
        plast_student = gpfirst_student;
        while (plast_student->next_student != NULL)
            plast_student=plast_student->next_student;
            pnew_student = (struct Sstudent*)malloc(sizeof(struct Sstudent));
            // now we want our added element to point to null since it's the last element now
            plast_student->next_student = pnew_student;
            //////////////////////////
            pnew_student->prev_student = plast_student; // Set prev pointer to last student
        
    }

    //fill new element
    printf("enter ID\n");
    gets(temp_text);
    pnew_student->student_data.id = atoi(temp_text);

    printf("enter name\n");
    gets(temp_text);
    strcpy(pnew_student->student_data.name ,temp_text);

    printf("enter hight\n");
    gets(temp_text);
    pnew_student->student_data.hight = atof(temp_text);

    pnew_student->next_student = NULL;
}

//second option
int delete_student (){
    char temp_text[30];
    unsigned int selected_id;
    printf("enter ID of student to be deleted\n");
    gets(temp_text);
    selected_id=atoi(temp_text);

    //if list isn't empty
    if(gpfirst_student){
        struct Sstudent* pselected_student = gpfirst_student;
        while(pselected_student){
            //compare each element with the selected id
            if(pselected_student->student_data.id == selected_id){
                if(pselected_student->prev_student) // first student isn't the selected
                    pselected_student->prev_student->next_student = pselected_student->next_student;
                else // first student is the selected id to be deleted
                    gpfirst_student = pselected_student->next_student;
                free(pselected_student);
                return 1; 
            }
        pselected_student->prev_student = pselected_student;
        pselected_student = pselected_student->next_student;
        }
    
    }
    printf("can't find student id\n");
    return 0;
}

//third option
void view_student (){
    struct Sstudent* pcurrent_student = gpfirst_student;
    int count=0;
    if(gpfirst_student == NULL)
        printf("empty list\n");
    else{
        while(pcurrent_student){
            printf("record no. %d\n",count+1);
            printf("ID %d\n",pcurrent_student->student_data.id);
            printf("name %s\n",pcurrent_student->student_data.name);
            printf("hight %f\n",pcurrent_student->student_data.hight);
            pcurrent_student = pcurrent_student->next_student;  //point to next student
            count++;
        }
    }
}

//forth option
void delete_all(){
    struct Sstudent* pcurrent_student = gpfirst_student;
    if(gpfirst_student == NULL)
        printf("empty list\n");
    else{
        while(pcurrent_student){
            struct Sstudent* ptemp_student = pcurrent_student;
            pcurrent_student = pcurrent_student->next_student;  //point to next student
            free(ptemp_student);
        }
        gpfirst_student=NULL; //since the location is already deleted now
    }
}

//fifth option
void GetNth(uint8_t i){
    struct Sstudent* pcurrent_student = gpfirst_student;
    uint8_t count=0;
    while(pcurrent_student){
        if(i == ++count){
            printf("record no. %d\n",count);
            printf("ID %d\n",pcurrent_student->student_data.id);
            printf("name %s\n",pcurrent_student->student_data.name);
            printf("hight %f\n",pcurrent_student->student_data.hight);
            break;
        }
        else{
            pcurrent_student = pcurrent_student->next_student;  //point to next student
            
        }
    }
}

//sixth option
int get_length(){
    struct Sstudent* pcurrent_student = gpfirst_student;
    uint8_t count=0;
    if(gpfirst_student == NULL)
        printf("empty list\n");
    else{
        while(pcurrent_student){
            count++;
            pcurrent_student = pcurrent_student->next_student;  //point to next student
        }
        printf("number of students equal %x\n",count);
    }
    return 0;
    /* 
    struct Sstudent* pcurrent_student = gpfirst_student;
    uint8_t count=0;
    if(gpfirst_student == NULL)
        return 0;
    else
        return 1 + get_length(pcurrent_student->next_student)  ;*/
}

//seventh option
void reverse(){
    struct Sstudent* pcurrent_student = gpfirst_student;
    struct Sstudent* ptemp_student =NULL;
    if(gpfirst_student == NULL)
        printf("empty list\n");
    else{
        while(pcurrent_student){
            ptemp_student = pcurrent_student->prev_student;
            pcurrent_student->prev_student = pcurrent_student->next_student;  //point to next student
            pcurrent_student->next_student = ptemp_student;
            pcurrent_student = pcurrent_student->prev_student;
        }
    }
    if(ptemp_student)
        gpfirst_student = ptemp_student->prev_student;

}

//test application
void main(){
    char temp_text[40];
    char temp_index[40];
    while(1){
        printf("choose an option\n");
        printf("1:add student\n2:delete student\n3:view students\n4:delete all\n5:get Nth index\n6:get number of elements\n7:reverse elements\n");
        gets(temp_text);
        switch(atoi(temp_text)){
            case 1:
                add_student();
                break;
            case 2:
                delete_student();
                break;
            case 3:
                view_student();
                break;
            case 4:
                delete_all();
                break;
            case 5:
                printf("enter index of desired student:\n");
                gets(temp_index);
                GetNth(atoi(temp_index));
                break;
            case 6:
                get_length();
                break;
            case 7:
                reverse();
                break;
            default:
                printf("not found\n");
        }
    }

}


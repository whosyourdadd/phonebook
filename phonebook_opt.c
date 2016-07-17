#include <stdlib.h>

#include "phonebook_opt.h"
#define DEBUG 0
/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastname[],entry *pHead)
{
    /* TODO: implement */
        entry *Curr = pHead;
        entry *Last = Curr;
        int result;
        if(strlen(pHead->lastName) == 0){
#if DEBUG
            printf("pHead->lastName NULL\n");
#endif
            return pHead;
        }
        while(Curr != NULL){
            result = strcmp(Curr->lastName,lastname);
            Last = Curr;
            if(result >0){// phead length greater than new
                    Curr = Curr->p_Left;
            }else if(result < 0 ){
                    Curr = Curr->p_Right;
            }else{
                //break;
                //printf("Find it !\n");
                return Curr;
            }
        }
        
        if(Last != NULL){
#if DEBUG
            //printf("Last : %x key %s\n",Last,Last->lastName);
#endif
            return Last;
        }
        return NULL;
}

entry *CreateNewNode(char lastname[]){
         if(lastname == NULL){
#if DEBUG
            printf("lastname NULL\n");
#endif
            return NULL;
         }else{
            entry *NewNode = malloc(sizeof(entry));
            strcpy(NewNode->lastName, lastname);
            return NewNode;
         }       
}

entry *append(char lastName[],const entry *pHead)
{
#if DEBUG
    printf("append name: %s\n",lastName);
#endif
    if(pHead == NULL){
#if DEBUG
            printf("NULL HEAD\n");
#endif
            return NULL;
    }else{
            entry *Curr = pHead;
            entry *result_ptr = findName(lastName,Curr);
            entry *NewNode;
            if(result_ptr == NULL) return NULL;
            if(strlen(result_ptr->lastName) == 0){
#if DEBUG
                printf("result_ptr->lastName == 0\n");
#endif
                strcpy(result_ptr->lastName,lastName);
                return result_ptr;
            }
            int cmp_result = strcmp( result_ptr->lastName,lastName);
            if( cmp_result >= 0){//src > dst
                NewNode = CreateNewNode(lastName);    
                result_ptr->p_Left = NewNode;
            }else if(cmp_result < 0){
                NewNode = CreateNewNode(lastName);
                result_ptr->p_Right = NewNode;
            }
            return NewNode;

    }
    //e->pNext = (entry *) malloc(sizeof(entry));
    //e = e->pNext;
    //strcpy(e->lastName, lastName);
    //e->pNext = NULL;   
    //return NULL;
}

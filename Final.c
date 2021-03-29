#include <stdio.h>
#include <string.h>
#define LEN 30
#define MAXSIZE 100

struct Pokemon
{
    int id;
    float height;
    char name[LEN];
    char type1[LEN];
    char type2[LEN];
    struct Pokemon *next;
};


int insert(int id, char *name, float height, char *type, struct Pokemon *pkm);
int delete_id(int i, struct Pokemon *pkm);
void find_height(int param);
void sort_id();
void sort_id_plus(int param);
void group(char* type);
int size = 0;



int main()
{
    FILE *fp;
    fp=freopen("input", "r", stdin);
    int num;
    fscanf(fp,"%d", &num);
    size = num;
    struct Pokemon pkdb[MAXSIZE];
    
    for (int i = 0; i < num;i++){
        fscanf(fp,"%d", &pkdb[i].id);
        getchar();
        fscanf(fp,"%s", &pkdb[i].name);
        getchar();
        fscanf(fp,"%f", &pkdb[i].height);
        getchar();
        fscanf(fp,"%s", &pkdb[i].type1);
        getchar();
        int pivot=0;
        for (int j = 0; j < LEN;j++){
            if (pkdb[i].type1[j]==','){
                pivot = j;
                break;
            }
        }
        if (pivot!=0){
            for (int k = 0; k < LEN && pivot + 1 + k<LEN ;k++){  
                char c = pkdb[i].type1[pivot + 1 + k];
                pkdb[i].type2[k] = c;
                pkdb[i].type1[pivot] = NULL;
                pkdb[i].type1[pivot + 1 + k] = NULL;            
            }
        }   
    }        
    fclose(fp);

    char a[5] = "Tiga";
    char b[10] = "steel";

    int res=insert(10, a, 1.08, b, pkdb);


    for (int i = 0; i < size;i++){
        
        printf("%d\n", pkdb[i].id);        
        printf("%s\n", pkdb[i].name);
        printf("%.2f\n", pkdb[i].height);               
        printf("%s %s\n", pkdb[i].type1,pkdb[i].type2);
        printf("\n");
        
    }
    
   


    return 0;
    getchar();
    getchar();
}

int insert(int id, char *name, float height, char *type, struct Pokemon *pkm){
    struct Pokemon *temps = pkm + size;
    size++;
    if (size>MAXSIZE){
        return -1;
    }else{
        temps->id = id;
        strcpy(temps->name, name);
        temps->height = height;
        strcpy(temps->type1, type); //type 2
        
        return 0;
    }
    
}

int delete_id(int i, struct Pokemon *pkm){
    for (int j=0 ;j < size ;j++){
        struct Pokemon *temps = pkm + j;
        if (i==temps->id){

        }
    }
}

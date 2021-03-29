#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define LEN 30               //length maximum of a name or a type
#define DIMENSION 4          //4 abilities of a Pokemon
#define MAXSIZE 200          //maximum size of the database

typedef struct Pokemon  //definition of the structure
{
    int id;
    float height;
    char name[LEN];
    char type1[LEN];
    char type2[LEN];
    float ability[DIMENSION];
    struct Pokemon *next;
}Pokemon;
Pokemon *first;
Pokemon *last;

//introduced in readme
int insert(int id, char *name, float height, char *type1, char *type2);
int delete_id(int i);
void find_height(int param);
void sort_id();
void sort_id_plus(int param);
void group(char* type);


void readAll(void);
int isEmpty(void);
void printAll(void);
void printName(void);
void sort(Pokemon *begin,int param);
void exchange(Pokemon *a,Pokemon *b);
void duplicate(Pokemon *a,Pokemon *b);
void operations(FILE *fp);
void solve(int option,FILE *fp);


float restriction(char* type1, char* type2);
Pokemon* searchPokemon(char *name);
int insertAbility(char* name, float *ability);
float max(float a, float b);
int battle(char * poke1, char * poke2);


int size = 0;

int main()
{
    readAll();
    return 0;
    getchar();
    getchar();
}

void readAll(){
    FILE *fp;   //read the content of the given file
    fp=freopen("input", "r", stdin);
    int num;
    fscanf(fp,"%d", &num);   
    for (int i = 0; i < num;i++){
        int tempsid;
        float tempsheight;
        char tempsname[LEN];
        char tempstype1[LEN];
        char tempstype2[LEN];
        fscanf(fp,"%d", &tempsid);        
        fscanf(fp,"%s", &tempsname);
        fscanf(fp,"%f", &tempsheight);
        fscanf(fp,"%s", &tempstype1);
        int pivot=0;
        for (int j = 0; j < LEN;j++){
            if (tempstype1[j]==','){
                pivot = j;
                break;
            }
        }
        if (pivot!=0){
            for (int k = 0; k < LEN && pivot + 1 + k<LEN ;k++){  
                char c = tempstype1[pivot + 1 + k];
                tempstype2[k] = c;
                tempstype1[pivot] = NULL;
                tempstype1[pivot + 1 + k] = NULL;            
            }
        }else{
            for (int k = 0; k < LEN; k++)
            {
                tempstype2[k] = NULL;
            }
        }
        insert(tempsid, tempsname, tempsheight, tempstype1, tempstype2);
    }    
    operations(fp);    
    fclose(fp);
    printAll();
    find_height(1);
    // Free Design: introduced in readme
    printf("\n");
    printf("Now the free designs:\n");
    printf("\n");

    float lapras[DIMENSION] = {130, 85, 80, 60};      //ability of different Pokemons
    float charizard[DIMENSION] = {78, 84, 78, 100};
    float pikachu[DIMENSION] = {35, 55, 40, 90};
    insertAbility("Lapras", lapras);                  //insert their abilities
    insertAbility("Charizard", charizard);
    insertAbility("Pikachu", pikachu);    
    Pokemon* monster=searchPokemon("Charizard");      //look for the Pokemon with a given name
    printf("%s\n", monster->name);
    for (int i = 0; i < DIMENSION;i++){
        printf("%.0f ", *(monster->ability + i));
    }
    printf("\n");                                     
    battle("Lapras","Charizard");                     //start a battle
    battle("Pikachu","Pikachu");
}

int insert(int id, char *name, float height, char *type, char *type2){  //based on linkedlist
    if (isEmpty()){                                               //the very first Pokemon in the database
        Pokemon *temps;
        temps = (Pokemon *)malloc(sizeof(Pokemon));        
        temps->id = id;
        strcpy(temps->name, name);
        temps->height = height;
        strcpy(temps->type1, type);
        strcpy(temps->type2, type2);
        for (int i = 0; i < DIMENSION;i++){
            *(temps->ability + i) = 0.0;
        }
        first = temps;
        temps->next = NULL;  //first=last for the first element
        last = temps;
        size++;
        return 0;
    }else{
        size++;
        if (size>MAXSIZE){   //too many Pokemons
            return 1;
        }else{              //common case
            Pokemon *temps;
            temps = (Pokemon *)malloc(sizeof(Pokemon));        
            temps->id = id;
            strcpy(temps->name, name);
            temps->height = height;
            strcpy(temps->type1, type);
            strcpy(temps->type2, type2);
            for (int i = 0; i < DIMENSION;i++){
            *(temps->ability + i) = 0.0;
            }
            temps->next = NULL;
            last->next = temps;
            last = temps;
            return 0;
        }
    }
}

int isEmpty(){
    return size == 0;
}

int delete_id(int i){
    int flag = 1;
    Pokemon *a, *b, *c;
    a = b = first;   //a stands for the previous Pokemon of the one that needs to be deleted
    while (b!=NULL){
        if(i==b->id){
            if(b==first){       //remove the first one
                first = b->next;
            }else{
                c = b;
                a->next = b->next;  
                b = b->next;
                flag = 0;
                free(c);       //free the space
                size--;                
            }
        }else{
            a = b;  
            b = b->next;
        }
    }
    if (flag==0){
        printf("Deleted successfully\n");
    }else{
        printf("Pokemon of id %d doesn’t exist in the database\n",i);
    }
    return flag;
}

void printAll(void){
    Pokemon *temp;
    temp = (Pokemon *)malloc(sizeof(Pokemon));
    temp = first;           //print all the details from the first one (used for testing the code)
    do
    {
        printf("%d ", temp->id);        
        printf("%s ", temp->name);
        printf("%.2f ", temp->height);               
        printf("%s %s ", temp->type1,temp->type2);
        printf("\n");
        temp = temp->next;
    } while (temp != NULL);
}

void printName(void){      //print only the names to show the current information
    Pokemon *temp;
    temp = (Pokemon *)malloc(sizeof(Pokemon));
    temp = first;          
    do
    {    
        printf("%s ", temp->name);
        temp = temp->next;
    } while (temp != NULL);
    printf("\n");
}

void find_height(int param){
    float height = first->height;
    float param1 = param;
    Pokemon *temps;
    temps = first;        
    while (temps!=NULL){
        if ((temps->height-height)*(param1-1.5)<0){  // correspond to the different modes of the function 
                height = temps->height;              // if param=1 than temps->height should be bigger than 
        }                                            // the height recorded, the same if param=2
        temps = temps->next;
    }
    Pokemon *temp;
    temp = first;
    while (temp!=NULL){
        if (temp->height==height){                    //show all the Pokemons that have the extreme height
            printf("%s ", temp->name);                //we have the right to visit every element of the database
        }                                             //since it has the maximum size of 100 elements
        temp = temp->next;
    }
    printf("\n");
}

void sort_id(){
    sort_id_plus(1);
}

void sort_id_plus(int param){                          //sort from the first one
    sort(first,param);
    printName();
}

void sort(Pokemon *begin,int param){                   //sort from a given target
    float param1 = param;
    if (begin==last){                                  //the fondamental case
        return;
    }else{                                             //we use the selection sorting since the database is small
        Pokemon *pivot;        
        Pokemon *temps;
        temps = (Pokemon *)malloc(sizeof(Pokemon));
        pivot = begin;
        temps = begin;
        while (temps!=NULL){
            if ((temps->id-pivot->id)*(param1-1.5)>0){ //the same method
                pivot = temps;
            }
            temps = temps->next;
        }
        exchange(begin, pivot);
    }
    begin = begin->next;
    sort(begin,param);                                 //we use the recurrence
}

void duplicate(Pokemon *a,Pokemon *b){                 //just for simplify the code
    a->id = b->id;
    strcpy(a->name, b->name);
    a->height = b->height;
    strcpy(a->type1, b->type1);
    strcpy(a->type2, b->type2);
}

void exchange(Pokemon *a,Pokemon *b){                   //exchange the information of two nodes instead of 
    Pokemon *temps;                                     //exchanging the whole structure
    temps = (Pokemon *)malloc(sizeof(Pokemon));
    duplicate(temps, a);
    duplicate(a, b);
    duplicate(b, temps);
}

void group(char*type){
    Pokemon *temps;
    temps = first;
    int flag = 0;
    while(temps!=NULL){                               
        if (strcmp(temps->type1,type)==0 || strcmp(temps->type2,type)==0){
            printf("%s ", temps->name, type);
            flag = 1;            
        }
        temps = temps->next;
    }
    if (flag==0){
        printf("No Pokemon in the database has the type %s", type);
    }
    printf("\n");
}

void operations(FILE *fp){         
    int opnum;    
    fscanf(fp, "%d", &opnum);
    getchar();
    for (int i = 0; i < opnum;i++){
        int option;
        fscanf(fp, "%d", &option);
        getchar();
        solve(option,fp);
    }
}

void solve(int option, FILE *fp){                               //devided into different cases
    switch(option){
        case 2:{
            int idToBeDeleted;
            fscanf(fp, "%d", &idToBeDeleted);
            getchar();
            delete_id(idToBeDeleted);
            break;
        }
        case 3:{
            int param;
            fscanf(fp, "%d", &param);
            getchar();
            find_height(param);
            break;
        }
        case 4:
            sort_id();
            break;
        case 5:{
            int param1;
            fscanf(fp, "%d", &param1);
            getchar();
            sort_id_plus(param1);
            break;
        }
        case 6:{
            char *typeparam[LEN];
            fscanf(fp, "%s", typeparam);
            getchar();
            group(typeparam);
            break;
        }
    }
}

float restriction(char* type1, char* type2){                //the relation of restriction: 克制关系
    if (type1==NULL || type2==NULL){                        //a simple version since the relation is quite complexe
        return 1;                                           //and there are curently 18 types in the game
    }else{
    if ((strcmp(type1,"fire")==0&&strcmp(type2,"water")==0) //fire is "restricted" by water: the power is multiplied by 1/2
    || (strcmp(type1,"water")==0&&strcmp(type2,"electric")==0)
    || (strcmp(type1,"ice")==0&&strcmp(type2,"water")==0)
    || (strcmp(type1,"ice")==0&&strcmp(type2,"fire")==0)
    ){
            return 1 / 2;                                   
        }else{
            if ((strcmp(type1,"water")==0&&strcmp(type2,"fire")==0) 
        || (strcmp(type1,"electric")==0&&strcmp(type2,"water")==0) //electric restricts water: the power is doubled
        || (strcmp(type1,"fire")==0&&strcmp(type2,"ice")==0)
        ){
                return 2;
            }else{
                return 1;  
            }
    }
    }
}

int insertAbility(char* name, float *ability){
    Pokemon *temps;
    int flag = 0;
    temps = searchPokemon(name);                         //look for the Pokemon searched
    if (temps!=NULL){
        for (int i = 0; i < DIMENSION;i++){
            *(temps->ability + i) = *(ability + i);
        }
        flag = 1;
    }
    return flag;
}

Pokemon* searchPokemon(char *name){
    Pokemon *temps;
    temps = first;
    int flag = 0;
    while (temps!=NULL){
        if (strcmp(temps->name,name)==0){     //search a Pokemon according to its name: more pratical than serach by id 
            flag = 1;
            break;
        }
        temps = temps->next;
    }
    if (flag==0){
        printf("%s is not in the database\n",name);         
        return NULL;
    }else{return temps;}    
}

int battle(char * poke1, char * poke2){
    Pokemon *Poke1 = searchPokemon(poke1);
    Pokemon *Poke2 = searchPokemon(poke2);
    int flag = 1;
    if (Poke1==NULL){
        printf("Battle Failed: Pokemon %s do not exist in the database",poke1);
        flag = 0;
    }
    if (Poke2==NULL){
        printf("Battle Failed: Pokemon %s do not exist in the database",poke2);
        flag = 0;
    }
    if (*(Poke1->ability)==0.0){
        printf("Please insert the ability of %s first\n",Poke1->name);
        flag = 0;
    }
    if (*(Poke2->ability)==0.0){
        printf("Please insert the ability of %s first\n",Poke2->name);
        flag = 0;
    }
    if (flag==0){
        return flag;                      //lack of information
    }else{
    float ability1[DIMENSION]; 
    float ability2[DIMENSION];
    for (int i = 0; i < DIMENSION;i++){
        ability1[i] = *(Poke1->ability + i);        //we copy the healths to simulate a battle
        ability2[i] = *(Poke2->ability + i);
    }
    float restriction1 = (restriction(Poke1->type1, Poke2->type1) * restriction(Poke1->type1, Poke2->type2) +
                        restriction(Poke1->type2, Poke2->type1) * restriction(Poke1->type2, Poke2->type2)) /
                       2; //we calculate the average of restriction of a double-typed Pokemon to another
                          //double-typed Pokemon, which is not actually the case in the game
    float restriction2 = (restriction(Poke2->type1, Poke1->type1) * restriction(Poke2->type1, Poke1->type2) +
                        restriction(Poke2->type2, Poke1->type1) * restriction(Poke2->type2, Poke1->type2)) /
                       2;
    while (ability1[0]>0 && ability2[0]>0){  //whose health below 0 is defeated
        float damage1 = ((40 * ability1[1] * 22) / ability2[1] / 50 + 2) * restriction1;  //formule of damage
        float damage2 = ((40 * ability2[1] * 22) / ability1[1] / 50 + 2) * restriction2;
        ability1[0] = max(0.0,ability1[0] - damage2);   //the health can't be negative
        ability2[0] = max(0.0,ability2[0] - damage1);        
        printf("%s has caused a damage of %.2f to %s, ", Poke1->name, damage1, Poke2->name);
        printf("%s has %.2f health left\n", Poke2->name, ability2[0]);
        printf("%s has caused a damage of %.2f to %s, ", Poke2->name, damage2, Poke1->name);
        printf("%s has %.2f health left\n", Poke1->name, ability1[0]);
        if (ability1[0]<=0){
            printf("%s faints\n", Poke1->name);
        }
        if (ability2[0]<=0){
            printf("%s faints\n", Poke2->name);
        }
    }
    if (ability1[0]<=0 && ability2[0]>0){
        printf("%s wins\n", Poke2->name);
    }else{
        if (ability1[0]>0 && ability2[0]<=0){
            printf("%s wins\n", Poke1->name);
        }else{
            if (ability1[3]>ability2[3]){
                printf("%s wins\n: Speed is faster", Poke1->name); //if both Pokemon faint, the one with a higher speed wins
            }else{
                if (ability1[3]<ability2[3]){
                    printf("%s wins\n: Speed is faster", Poke2->name);
            }else{
                printf("Tie\n"); //the battle within two identical Pokemons is always a tie
            }        
        }
    }
    return flag;
    }
}
}

float max(float a, float b){
    if (a>b){
        return a;
    }else{
        return b;
    }
}
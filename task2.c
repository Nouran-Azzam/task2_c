#include <stdio.h>
#include <string.h>

struct User {
    char username[50];
    char password[50];  
      };
      
      union User_Activation
    {
    struct booling
    {
        int Is_String;
        _Bool Active_notActive;
    } bl;
    struct character
    {
        int Is_String;
        char Active_notActive[10];
    } ch;
   };
union User_Activation user_activation[50];
struct User users[50];
int counter =0;

void registerUser() {
     
       printf(" Please ,Enter  username: ");
        scanf("%s",users[counter].username);
    
       printf(" Please ,Enter password : ");
       scanf("%s",users[counter].password);
      
       char activation_entered[10];
        printf(" Please ,Enter activation true ,false ,0 or 1 : ");
        scanf("%s",activation_entered );
       
         if (strcmp(activation_entered, "0") == 0 )
        {
            user_activation[counter].bl.Is_String = 0;
            user_activation[counter].bl.Active_notActive = 0;
         
        }else if( strcmp(activation_entered, "1") == 0){
             user_activation[counter].bl.Is_String = 0;
            user_activation[counter].bl.Active_notActive = 1;
         
          
        }else
        {
            user_activation[counter].ch.Is_String = 1;
            
            strcpy(user_activation[counter].ch.Active_notActive, activation_entered);
          
        }
        
         
       counter++;
     
    
}

int loginUser(char* username, char* password) {
    for(int i = 0; i<50; i++) {
        if(strcmp(username,users[i].username)==0 && strcmp(password,users[i].password)==0) {
            return i;  } }
    return 0;  }



int main() {
    int number;
    char username[50];
    char password[50];
      
       while (1) {
        printf(" (1)Register\t (2)Login\t  \n\nEnter your choice of (1 , 2) : ");
        scanf("%d", &number);
        switch (number) {
            case 1:
                registerUser();
                break;
            case 2:
                printf("Enter your username: ");
                scanf("%s",username);
                printf("Enter your password: ");
                scanf("%s",password);
                if(loginUser(username, password) < 50){
                    int i=loginUser(username, password);
                if (user_activation[i].bl.Is_String == 0)
                {
                    if (user_activation[i].bl.Active_notActive ){
                        printf("Login successful \n");
                    }
                    else {
                        printf("\n you are inactivee. \n");
                     
                    }
                }
                else if (user_activation[i].ch.Is_String == 1)
                {

                    if (strcmp(user_activation[i].ch.Active_notActive, "true") == 0)
                         printf("Login successful \n");
                         
                    else if(strcmp(user_activation[i].ch.Active_notActive, "false") == 0)
                        printf("\n you are inactive. \n");
                }
                    
                }else{
                    printf("Login failed. Incorrect username or password.\n try again...");  }
                break;
            default:
                printf("Invalid choice(incorrect).. Try again ,please..\n");
        } } }
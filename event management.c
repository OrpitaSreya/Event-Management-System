#include<stdio.h>
#include<string.h>
#include<math.h>

struct Admin{
char username[100];
char password[100];
};

struct Customer{

   char name[100];
   char phone[100];
   char username[100];
   char password[100];
};
struct Category{

    int id;
    char events[100];
};

struct Service {
    int id;
    char name[100];
    float Price;
};
struct Bill{

    char username[100];
    float totalAmount;
    float EventCost;
    float ServiceCost;
    float VAT;
};




void admindashboard();
void manageCategory();
void manageService();
void addCategory();
void viewCategory();
void updateCategory();
void deleteCategory();

void addService();
void viewService();
void updateService();
void deleteService();

void viewCustomerList();
void generateBill();
void viewReview();

void customerDashboard(char username[]);
void selectCategory();
void selectService();
void addPreference();
void customerReview();
void viewBill();



int main(){
    int choice;
    struct Admin admin;
    struct Customer  customer;
    FILE*fp;
    char user[100];
    char pass[100];

for(; ;)
{

    printf("\n==::MAIN MENU::==\n");
    printf("1.Admin Resgistration\n");
    printf("2.Admin Login\n");
    printf("3.Customer Registration\n");
    printf("4.Customer Login\n");
    printf("5.Exit\n");
    printf("Enter Choice:");
    scanf("%d",&choice);
    getchar();

switch(choice){


 case 1:
     fp=fopen("admin.txt","w");

     printf("\n--Admin Registration--\n");

     printf("Set username:");
     fgets(admin.username,sizeof(admin.username),stdin);
     admin.username[strcspn(admin.username, "\n")]='\0';

     printf("Set Password:");
     fgets(admin.password,sizeof(admin.password),stdin);
     admin.password[strcspn(admin.password, "\n")]='\0';

     fprintf(fp,"%s %s\n",admin.username,admin.password);
     fclose(fp);

     printf("Admin Registered Successfully!\n");
     break;


 case 2:

     fp=fopen("admin.txt","r");

     if(fp==NULL)
    {

      printf("Admin Not Registered yet!\n");
      break;

    }

     fscanf(fp,"%s %s" ,admin.username,admin.password);
     fclose(fp);

     printf("\n---Admin Login---\n");

     for(;;){

    printf("Enter Username:");
    fgets(user,sizeof(user),stdin);
    user[strcspn(user, "\n")]='\0';

    printf("Enter Password:");
    fgets(pass,sizeof(pass),stdin );
    pass[strcspn(pass,"\n")]='\0';

    rewind(fp);

    if(strcmp(user,admin.username)!=0 && strcmp(pass,admin.password)!=0){


        printf("Login Successful!\n");
        admindashboard();

        break;
      }

      else
      {
        printf("Invalid username or password!\n");
      }

     }

     break;

 case 3:

     fp=fopen("customer.txt","a");


     printf("\n==Customer Registration==\n");

     printf("Name:");
     fgets(customer.name,sizeof(customer.name),stdin);
     customer.name[strcspn(customer.name, "\n")]='\0';

     printf("Username:");
     fgets(customer.username,sizeof(customer.username),stdin);
     customer.username[strcspn(customer.username, "\n")]='\0';

     printf("Password:");
     fgets(customer.password,sizeof(customer.password),stdin);
     customer.password[strcspn(customer.password, "\n")]='\0';

     printf("Phone:");
     fgets(customer.phone,sizeof(customer.phone),stdin);
     customer.phone[strcspn(customer.phone, "\n")]='\0';
     fprintf(fp,"%s %s %s %s\n",customer.name,customer.username,customer.password,customer.phone);
     fclose(fp);

     printf("Customer Registered Successfully!\n");

     break;
 case 4:
        fp=fopen("customer.txt","r");
        if(fp==NULL){
            printf("No customer registered yet!\n");
            break;
        }

        fscanf(fp,"%s %s %s %s",customer.name,customer.phone,customer.username,customer.password);
        fclose(fp);

        printf("\n---Customer Login---\n");
        for(;;){

       printf("Enter Username:");
       fgets(user,sizeof(user),stdin);
       user[strcspn(user,"\n")]='\0';

        printf("Enter password:");
       fgets(pass,sizeof(pass),stdin);
       pass[strcspn(pass,"\n")]='\0';
       rewind(fp);

        if(strcmp(user,customer.username)!=0 &&strcmp(pass,customer.password)!=0) {

          printf("Customer Login Successfully!\n");
          printf("Going To customer Dashboard....\n");

          customerDashboard(customer.username);
          break;

        }

       else
       {
         printf("Wrong Username or Password \n");
       }
        }

       break;


   case 5:
        printf("Exit \n");
        return 0;

     default:
        printf("invalid Choice!\n");
     }
    }
}

void admindashboard(){

int choice;
for(;;){
 printf("\n===Admin Dashboard===\n");
 printf("1.Manage Category\n");
 printf("2.Manage Service\n");
 printf("3.View Customer List\n");
 printf("4.Generate Customer Bill\n");
 printf("5.View Customer Review\n");
 printf("6.Logout\n");
 printf("Enter Choice:");
 scanf("%d",&choice);
 getchar() ;

 switch(choice){

 case 1:
     manageCategory();
         break;

 case 2:
   manageService();
         break;

case 3:
     viewCustomerList();
           break;

case 4:
    generateBill();
       break;
case 5:

  viewReview();
     break;
case 6:
 printf("Returning to Main Menu\n");
      return;
default:
    printf("Invalid Choice!\n");

}

}

}
void manageCategory(){

int choice;
for(; ;){

    printf("\n---Manage Category---\n");
    printf("1.Add Category\n");
    printf("2.View Category\n");
    printf("3.Update Category\n");
    printf("4.Delete Category\n");
    printf("5.Back\n");
    printf("Enter Choice:");
    scanf("%d",&choice);
    getchar();



switch(choice){

 case 1:
    addCategory();
         break;

 case 2:
   viewCategory();
         break;
case 3:
     updateCategory();
         break;
case 4:
   deleteCategory();
case 5:

 printf("Returning to Main Menu\n");
return;
    default:
    printf("Invalid Choice!\n");

}

}
}
void addCategory(){

FILE*fp;
fp=fopen("category.txt","a");
if(fp==NULL)
    {
    printf("File Not Found\n");
    return;
   }
struct Category c;
  printf("Serial:");
  scanf("%d",&c.id);
  getchar();

 printf("Name:");
 fgets(c.events,100,stdin);
 c.events[strcspn(c.events,"\n")]='\0';

 fprintf(fp,"%d %s\n",c.id,c.events);
 fclose(fp);
 printf("Category added successfully\n");

}
void viewCategory(){

FILE*fp;
fp=fopen("category.txt","r");
struct Category c;
if(fp==NULL){
    printf("No Category found!\n");
    return;
}

printf("\n---CATEGORY LIST---\n");


for(;fscanf(fp,"%d %s",&c.id,c.events)!=EOF;)
{

  printf("ID:%d\n",c.id);
  printf("Name:%s\n",c.events);
  printf("-------------------\n");
}
fclose(fp);

}

void updateCategory(){

   FILE*fp,*temp;
   fp=fopen("category.txt","r");
   temp=fopen("temp.txt","w");

   if(fp == NULL || temp == NULL)
    {
        printf("File not found\n");
        return;
    }
   struct Category c;
   int id;
   int found=0;

   printf("Enter Id to update:");
   scanf("%d",&id);
   getchar();

for(;fscanf(fp,"%d %s",&c.id,c.events)!=EOF;){

   if(c.id==id)
    {
        found=1;
    printf("New name:");
    fgets(c.events,100,stdin);
    c.events[strcspn(c.events,"\n")]='\0';
   }

    fprintf(temp, "%d %s\n", c.id,c.events);
    }

    fclose(fp);
    fclose(temp);

    remove("category.txt");
    rename("temp.txt", "category.txt");

    if(found)
        printf("Category updated successfully\n");
    else
        printf("Category ID not found\n");
}
void deleteCategory(){

    FILE *fp, *temp;
    struct Category c;
    int id, found = 0;

    fp = fopen("category.txt", "r");
    temp = fopen("temp.txt", "w");

    if(fp == NULL || temp == NULL){
        printf("File not found\n");
        return;
    }

    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for (; fscanf(fp, "%d %[^\n]", &c.id, c.events) != EOF; ) {

        if (c.id != id) {
            fprintf(temp, "%d %s\n", c.id, c.events);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("category.txt");
    rename("temp.txt", "category.txt");

    if(found)
        printf("Category deleted successfully\n");
    else
        printf("Category ID not found\n");
}

void manageService(){

int choice;
for(; ;){

    printf("\n---Manage Service---\n");
    printf("1.Add Service\n");
    printf("2.View Service\n");
    printf("3.Update Service\n");
    printf("4.Delete Service\n");
    printf("5.Back\n");
    printf("Enter Choice:");
    scanf("%d",&choice);
    getchar();



switch(choice){

case 1:
    addService();
         break;

case 2:
    viewService();
         break;
case 3:
    updateService();
         break;
case 4:
    deleteService();
         break;
case 5:

 printf("Returning to Main Menu\n");
return;
    default:
    printf("Invalid Choice!\n");

}
}
}

void addService(){

FILE *fp;
    struct Service s;

    fp = fopen("service.txt", "a");
    if(fp == NULL){
        printf("File not found\n");
        return;
    }

    printf("ID: ");
    scanf("%d", &s.id);
    getchar();

    printf("Name: ");
    fgets(s.name, 100, stdin);
    s.name[strcspn(s.name, "\n")] = '\0';

    printf("Price:");
    scanf("%f",&s.Price);
    getchar();

    fprintf(fp, "%d %s %f\n", s.id,s.name,s.Price);

    fclose(fp);
    printf("Service added successfully\n");
}

void viewService(){
   FILE *fp;
    struct Service s;

    fp = fopen("service.txt", "r");
    if(fp == NULL){
        printf("No Service found!\n");
        return;
    }

    printf("\n--- SERVICE LIST ---\n");

    for (; fscanf(fp, "%d %s %.2f", &s.id, s.name,&s.Price) != EOF; ) {

        printf("ID   : %d\n", s.id);
        printf("Name : %s\n", s.name);
        printf("Price:%f\n",s.Price);
        printf("--------------------\n");
    }

    fclose(fp);
}

void updateService(){
FILE *fp, *temp;
    struct Service s;
    int id, found = 0;

    fp = fopen("category.txt", "r");
    temp = fopen("temp.txt", "w");

    if(fp == NULL || temp == NULL){
        printf("File not found\n");
        return;
    }

    printf("Enter Id to update: ");
    scanf("%d", &id);
    getchar();

    for(; fscanf(fp, "%d %s %f", &s.id,s.name,&s.Price) != EOF; ) {

        if(s.id == id){
            found = 1;
            printf("New name: ");
            fgets(s.name, 100, stdin);
         s.name[strcspn(s.name, "\n")] = '\0';
        }

        fprintf(temp, "%d %s %f\n",s.id,s.name,s.Price );
    }

    fclose(fp);
    fclose(temp);

    remove("service.txt");
    rename("temp.txt", "service.txt");

    if(found)
        printf("Service updated successfully\n");
    else
        printf("Service ID not found\n");
}

void deleteService(){

FILE *fp, *temp;
    struct Service s;
    int id, found = 0;

    fp = fopen("service.txt", "r");
    temp = fopen("temp.txt", "w");

    if(fp == NULL || temp == NULL){
        printf("File not found\n");
        return;
    }

    printf("Enter ID to delete: ");
    scanf("%d", &id);
    getchar();

    for(; fscanf(fp, "%d %[^\n] %f", &s.id,s.name,&s.Price) != EOF; ){

        if(s.id != id){
            fprintf(temp, "%d %s %f",s.id,s.name,s.Price);
        }
         else
            {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("service.txt");
    rename("temp.txt", "service.txt");

    if(found)
        printf("Service deleted successfully\n");
    else
        printf("Service ID not found\n");
}

void viewCustomerList(){
FILE*fp;
fp=fopen("customer.txt","r");
struct Customer c;

if(fp==NULL){

 printf("No Customer found\n");
 return;
}

 printf ("\n---Customer List---\n");
 for(;fscanf(fp,"%s %s %s",c.name,c.username,c.phone)!=EOF;){

 printf("Name:%s\n",c.name);
 printf("Username:%s\n",c.username);
 printf("Phone:%s\n",c.phone);
 printf("---------------------\n");

 }
 fclose(fp);
}
void generateBill(){

FILE*fp;
fp=fopen("bill.txt","a");
if(fp == NULL)
{

        printf("File error\n");
        return;
}


struct Bill b;

printf("Enter Customer Username:");
fgets(b.username,100,stdin);
b.username[strcspn(b.username,"\n")]='\0';

printf("Enter Service Cost: ");
scanf("%f",&b.ServiceCost);

printf("Enter Event Cost:");
scanf("%f",&b.EventCost);

printf("Enter VAT:");
scanf("%f",&b.VAT);

b.totalAmount = b.ServiceCost + b.EventCost + b.VAT;
printf("Enter Total Bill Amount:");
scanf("%f",&b.totalAmount);
getchar();

fprintf(fp,"%s %.2f %.2f %.2f %.2f\n",b.username,b.EventCost,b.ServiceCost,b.VAT,b.totalAmount);
fclose(fp);
getchar();

printf("Bill Generated Successfully!\n");


}

void customerDashboard( char username[]){
int choice;
for(;;){

  printf("\n===CUSTOMER DASHBOARD===\n");
   printf("1.View Event Categories\n");
   printf("2.View Service\n");
   printf("3.Add Personal Preference\n");
   printf("4.View Bill\n");
   printf("5.Customer Review\n");
   printf("6.Logout\n");
   printf("Enter Choice:");
   scanf("%d",&choice);
   getchar();


switch(choice){

case 1:
    viewCategory();

    break;
    case 2:
    viewService();
    break;


   case 3:
   addPreference();
   break;

   case 4:
    viewBill();
    break;
   case 5:
    customerReview();
    break;
   case 6:
    printf("Customer Logged Out Successfullly!\n");
    return;
   default:
    printf("Invalid Choice\n");

    }

}

}

void addPreference(){

char pref[200];
printf("Enter YOur Personal Prefrence:");
fgets(pref,200,stdin);
pref[strcspn(pref,"\n")]='\0';
printf("Preference Saved:%s\n",pref);
}

void viewBill(char username[]){
    FILE*fp;
    fp=fopen("bill.txt","r");
    struct Bill b;
    int found=0;
    if(fp==NULL){

        printf("No Bill found!\n");
     }
     return ;

for(;fscanf(fp,"%s %f %f %f %f" ,b.username,&b.totalAmount,&b.EventCost,&b.ServiceCost,&b.VAT)!=0;){


     if(strcmp(b.username,username)==0){

            printf("\n----YOUR BILL----\n");
            printf("Service Cost : %.2f\n", b.ServiceCost);
            printf("Event Cost   : %.2f\n", b.EventCost);
            printf("VAT          : %.2f\n", b.VAT);
            printf("Total Amount : %.2f\n", b.totalAmount);
            printf("-------------------\n");
            found=1;
        break;
     }
}

 if(!found){
  printf("Bill not generated yet by admin.\n");

}
 fclose(fp);

}

void selectcategory(){

char category[100];
printf("Enter Event category Name:");
fgets(category,100,stdin);
category[strcspn(category,"\n")]='\0';
printf("You selected:%s\n",category);
}

void selectService(){
int sid;
printf("Enter Service Id:");
scanf("%d",&sid);
getchar();
printf("Service ID %d selected\n",sid);
}

void customerReview(){

FILE*fp=fopen("review.txt","a");
char review[300];
if(fp == NULL){
        printf("Unable to open review file\n");
        return;
    }
    getchar();
printf("Write Your Review:");
fgets(review,300,stdin);
review[strcspn(review,"\n")]='\0';
fprintf(fp,"%s\n",review);
fclose(fp);
printf("Thank you!\n");

}

void viewReview() {
    FILE *fp;
    fp = fopen("review.txt", "r");
    char review[300];
    if (fp==NULL) {
        printf("No reviews found.\n");
        return;
    }
    printf("\n--- CUSTOMER REVIEWS ---\n");
    for (;fgets(review, 300, fp)!=NULL;) {
        printf("%s", review);
    }
    fclose(fp);
}































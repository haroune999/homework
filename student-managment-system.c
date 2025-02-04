#include <stdio.h>
#include <stdbool.h>
bool there_exist;
int num_students=0;
int num_module;
enum grade{Fail,pass,Good,Very_Good,Excellent};
enum Specialization {AI,net_security,Not_eligible};

struct student_inf
{
    int ID;
    char First_name[50];
    char Last_name[50];
    char birth_date[10];// to write it with the form XX-XX-XXXX / and beceause "-" is not an integer 
    char Address[50];
    int Mobile;
    char email[50];
    int parent_contact;
    float modules[3][6];/// the number of modules are fixed 
    /// modules(raws) | analyse | algébre | algorithme | "for example" 
    //  columns | Module Average | Weight/Coefficient | Final Exam | Midterm | Labs | Continuous Evaluation
    float average;
    enum grade results;
    enum  Specialization results2; 
};
 struct student_inf students[100];///we write it like this if it's a dynamic array struct students_inf students[num_students] but it's static array

int add_student(){

        printf("First name : ");
    scanf(" %s", students[num_students].First_name);
        printf("Last name : ");
    scanf(" %s", students[num_students].Last_name);
        printf("birth_date : ");
    scanf(" %s", students[num_students].birth_date);
        printf("Address : ");
    scanf(" %s", students[num_students].Address);
        printf("email : ");
    scanf("%s", students[num_students].email);
        printf("mobile : ");
    scanf(" %d", &students[num_students].Mobile);
        printf("parent contact : ");
    scanf(" %d", &students[num_students].parent_contact);
        printf("ID : ");
    scanf(" %d", &students[num_students].ID);
        for(int i=0;i<=2;i++){
            printf("module %d :\n", i+1);
            printf("Weight/Coefficient :");
            scanf("%f", &students[num_students].modules[i][0]);
            printf("Continuous Evaluation :");
            scanf("%f", &students[num_students].modules[i][1]);
            printf("Labs :");
            scanf("%f", &students[num_students].modules[i][2]);
            printf("Midterm :");
            scanf("%f", &students[num_students].modules[i][3]);
            printf("Final Exam :");
            scanf("%f", &students[num_students].modules[i][4]);
            students[num_students].modules[i][5] = (((students[num_students].modules[i][1] + students[num_students].modules[i][2] + students[num_students].modules[i][3])/3) * 0.4 + (students[num_students].modules[i][4]) * 0.6);
        }
        float total_coefficients=students[num_students].modules[0][0] + students[num_students].modules[1][0] + students[num_students].modules[2][0];
    students[num_students].average =(((students[num_students].modules[0][5]) * (students[num_students].modules[0][0])) + (students[num_students].modules[1][5] * students[num_students].modules[1][0]) + (students[num_students].modules[2][5] * students[num_students].modules[2][0])) / total_coefficients;
    printf("%.2f \n",students[num_students].average );
    if (students[num_students].average>=18 && students[num_students].average<=20)
    {
        students[num_students].results=Excellent;
        students[num_students].results2=AI;

    }
    else if (students[num_students].average>=15 && students[num_students].average<=17.99)
    {
        students[num_students].results=Very_Good;
        students[num_students].results2=AI;

    }
    else if (students[num_students].average>=12 && students[num_students].average<=14.99)
    {
        students[num_students].results=Good;
        students[num_students].results2=net_security;
    }
        else if (students[num_students].average>=10 && students[num_students].average<=11.99)
    {
        students[num_students].results=pass;
        students[num_students].results2=net_security;
    }
    else if (students[num_students].average<10 || students[num_students].average>20)
    {
        students[num_students].results=Fail;
        students[num_students].results2=Not_eligible;
    }
    else{
        printf("you're grade is out of the ringe of grades.");
    }
    num_students++;
    return 0;   
}
       int searchStudent(){
            int ID;
            printf("enter the ID :");
            scanf("%d",&ID);
            there_exist=false;
            for (int  i = 0; i < num_students; i++)
            {
                if (ID==students[i].ID)
                {
                    printf("student informations :\n");
                    printf("%s\n",students[i].First_name);
                    printf("%s\n",students[i].Last_name);
                    printf("%s\n",students[i].birth_date);
                    printf("%s\n",students[i].Address);
                    printf("%s\n",students[i].email);
                    printf("%d\n",students[i].Mobile);
                    printf("%d\n",students[i].parent_contact);
                    there_exist=true;
                    switch (students[i].results)
                    {
                    case Excellent:
                    printf("grade : Excellent\n");
                    printf("specialization : eligible for AI.");
                        break;
                    case Very_Good:
                    printf("grade : Very_Good\n");
                    printf("specialization : eligible for AI.");
                        break;
                    case Good:
                    printf("grade : Good\n");
                    printf("specialization : eligible for Network and Security.");
                        break; 
                    case pass:
                    printf("grade : pass\n");
                    printf("specialization : eligible for Network and Security.");
                        break;
                    case Fail:
                    printf("grade : Fail\n");
                    printf("specialization : not allowed to pass to the next year.");
                        break;
                    default:
                    printf("error!!!!!");
                        break;
                    }
                }
            }
            if (!there_exist)
            {
                printf("student not found .\n");
            }
            
            return 0;
        }
        int delete_student(){
          int ID;
            printf("enter the ID of the student that you want to delete :");
            scanf("%d",&ID);
            there_exist=false;
            for (int  i = 0; i < num_students; i++)
            {
                if (ID==students[i].ID)
                {
                   for (int j = i; j <num_students-1; j++)
                   {
                    students[j]=students[j+1];
                   }
                   there_exist=true;
                num_students--;   
                }
            } 
            if (!there_exist)
            {
                printf("student not found .\n");
            }
            return 0;    
            }
            int edit_information(){
            int ID,select,std;
            there_exist=false;
            printf("enter the ID of the student that you want to edit his information :");
            scanf("%d",&ID);
                for (int i = 0; i < num_students; i++)
                {
                    if (ID==students[i].ID)
                    {
                there_exist=true;
                std=i;
                printf("\n 1.First name \n 2.Last name \n 3.email \n 4.address \nchoose what you want to edit :");
                scanf("%d",&select);
                switch (select)
                {
                case 1:
                    printf("enter the new First name :");
                    scanf(" %s",students[std].First_name);
                    break;

                case 2:
                    printf("enter the new Last name :");
                    scanf(" %s",students[std].Last_name);
                    break;
                case 3:
                    printf("enter the new email :");
                    scanf(" %s",students[std].email);
                    break;
                case 4:
                    printf("enter the new address:");
                     scanf(" %s",students[std].Address);// I don't mention all the informations cause it waste so much time
                    break;
                case 5 :
                default:
                printf("you're out of selectors");
                break;
                }
                
                }
                }
                if (!there_exist)
                {
                printf("student not found.\n");
                }
                return 0;
                }
            void Display_AI_List(){
                    printf("Students eligible for AI specialization :\n ");
                    there_exist=false;
                    for (int i = 0; i < num_students; i++)
                    {
                        if (students[i].results2==AI)
                        {
                            printf("%s %s\n",students[i].First_name,students[i].Last_name);
                            there_exist=true;
                        }
                        
                    }
                    if (!there_exist)
                    {
                        printf("empty list.");
                    }
                }
                 void Display_Net_security_List(){
                    printf("Students eligible for Network and Security specialization :\n ");
                    there_exist=false;
                    for (int i = 0; i < num_students; i++)
                    {
                        if (students[i].results2==net_security)
                        {
                            printf("%s %s\n",students[i].First_name,students[i].Last_name);
                            there_exist=true;
                        }
                        
                    }
                    if (!there_exist)
                    {
                        printf("empty list.");
                    }
                    
                }
                 void Display_not_eligible_List(){
                    printf("Students not allowed to pass to the next year :\n ");
                    there_exist=false;
                    for (int i = 0; i < num_students; i++)
                    {
                        if (students[i].results2==Not_eligible)
                        {
                            printf("%s %s\n",students[i].First_name,students[i].Last_name);
                            there_exist=true;
                        }
                    }
                    if (!there_exist)
                    {
                        printf("empty list.");
                    }
                }
int main(){
    int op;
/*menu*/   printf("1.add student\n2.Display student information\n3.show the number of student\n4.Delete a student\n5.Edit a specific student's information\n6.View the list of students eligible for the AI specialization\n7.View the list of students eligible for the Network and Security specialization\n8.View the list of students not eligible to pass to the next year\n9.exit");
// the menu will apears just in the first iteration.
 do
    {   
        printf("\n select your operation :");
        scanf("%d",&op);
    switch (op)
    {
    case 1:
        add_student();
        break;
    case 2:
        searchStudent();
        break;
    case 3:
       printf("the number of students is %d \n",num_students);
        break;
    case 4:
        delete_student();
        break;
    case 5:
        edit_information();
        break;
    case 6:
        Display_AI_List();
        break;
    case 7:
        Display_Net_security_List();
        break;
    case 8:
        Display_not_eligible_List();
        break;
    case 9:
        printf("exiting....");
        break;
    default:
        printf("you are out of selectors. \n");
        break;
    }
    } while (op>0 && op<9);
}
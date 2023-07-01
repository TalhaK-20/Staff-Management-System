// Office/Business/Staff Management Software 
// Developed by TALHA KHALID

#include<iostream>
#include<string>  
using namespace std;

struct node {
   int data;
   struct node* next;
   string role;
   string name;
   double id;
   double salary; 
};

struct node* new_node;
struct node* head=NULL;


void create(string role, string name, double id, double salary){

   new_node = (struct node*) malloc(sizeof(struct node));
   new_node->role = role;
   new_node->name = name;
   new_node->id = id;
   new_node->salary = salary;
   
   new_node->next = head;
   head = new_node;
}


void insert_start(string role, string name, double id, double salary){

   new_node = (struct node*) malloc(sizeof(struct node));
   new_node->role = role;
   new_node->name = name;
   new_node->id = id;
   new_node->salary = salary;
   
   new_node->next = head;
   head = new_node;
}


void insert_at_end(string role, string name, double id, double salary){

    new_node = (struct node*) malloc(sizeof(struct node));
    struct node* temp;
    temp=head; 
   
    new_node->role = role;
    new_node->name = name;
    new_node->id = id;
    new_node->salary = salary;
    new_node->next=NULL;
   
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
}


void insert_specific(string role, string name, double id, double salary, int pos){

    new_node = (struct node*) malloc(sizeof(struct node));
    struct node* temp;
    temp=head; 
     
    new_node->role = role;
    new_node->name = name;
    new_node->id = id;
    new_node->salary = salary;
    new_node->next=NULL;

    int i = 1;
    if(pos==1){
        insert_start(role, name, id, salary);
    }
    
    else{
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
    
        new_node->next=temp->next;
        temp->next=new_node;
    }
}







 
void del_begin(){
    struct node* temp;
    temp=head;
    head=head->next;
    delete(temp);
}

void del_end(){
    struct node* temp;
    struct node* previous_node;
    temp=head;
    while(temp->next!=NULL){
        previous_node=temp;
        temp=temp->next;
    }

    if(temp==head)
       head=NULL;
    
    else
    previous_node->next=0;

    delete(temp);
}

void del_specific(int id){

    struct node* temp;
    struct node* next_node; 
    temp=head;
      
    while(temp->next->id != id){
        temp=temp->next;
    }
     
    
    next_node = temp->next;
    temp->next = next_node->next;
    delete(next_node); 
}

 






void searching(int id){
    
    struct node* temp;
    temp=head;
    int found=0;

    if(temp==NULL){
        cout<<"LIST is empty !"<<endl;
    }

    else{
    while(temp!=NULL){
        if(temp->id==id){
            cout<<"That ID has been found in system." <<endl;
            cout<<" --->  "<<"Role = "<<temp->role<<" , "<<"Name = "<<temp->name<<" , "<<"ID = "<<temp->id<<" , "<<"Salary = "<<temp->salary<<" "<<endl; 
            found++;
            break;
        }
        temp=temp->next;
    }
    if(found==0){
        cout<<"OOPS ! ID not found." <<endl;
    }

    } //else ends
}








void updating_role(int id, string present_role, string new_role){
    struct node* temp;
    temp=head;
    
    if(temp==NULL){ 
       cout<<"LIST IS EMPTY MAN ! "<<endl;
    }

    if(temp->next==NULL){    // Only one node  
        if(temp->role == present_role || temp->id == id ){
            temp->role= new_role;
            cout<<"Previous Role = "<<present_role<<" having the ID "<<id<< " is transfer to "<<new_role<<endl;
            return;
        }
    }


    while(temp!=NULL){
        if(temp->role == present_role || temp->id == id ){
            temp->role= new_role;
            cout<<"Previous Role = "<<present_role<<" having the ID "<<id<< " is transfer to "<<new_role<<endl;
            return;
        }
        temp=temp->next;
    }

    if(temp->role != present_role){
        cout<<present_role<< " Role doesn't exists sir. "<<endl;
    }
}


 
void updating_Salary(int id, double prev_salary, double new_salary){

    struct node* temp;
    temp=head;
    
    if(temp==NULL){ 
       cout<<"LIST IS EMPTY MAN ! "<<endl;
    }

    if(temp->next==NULL){  
        if(temp->salary == prev_salary || temp->id == id ){
            
            int salar=(temp->salary * new_salary)/100;
            int new_sala=temp->salary + salar;

            temp->salary= new_sala;

            cout<<"Previous salary = "<<prev_salary<<" of "<<id<< " is updated to "<<new_sala<<endl;
            return;
        }
    }


    while(temp!=NULL){
        if(temp->salary == prev_salary || temp->id == id ){
            
            int salar=(temp->salary * new_salary)/100;
            int new_sala=temp->salary + salar;

            temp->salary= new_sala;

            cout<<"Previous salary = "<<prev_salary<<" of "<<id<< " is updated to "<<new_sala<<endl;
            return;
        }

        temp=temp->next;
    }

    if(temp->salary != prev_salary){
        cout<<prev_salary<< "Previous salary doesn't match. "<<endl;
    }
}



void updating_Salary_all_staff(double new_salary){
    struct node* temp;
    temp=head;
    
    if(temp==NULL){ 
       cout<<"LIST IS EMPTY MAN ! "<<endl;
    }
    while(temp!=NULL){
        
        int salar=(temp->salary * new_salary)/100;
        int new_sala=salar+temp->salary;
        temp->salary= new_sala;
        temp=temp->next;
    }

    cout<<"Previous salaries of all the employees is updated "<<endl;
}
 







void sortList() {  
        struct node* present;
        present = head; 
        struct node* next_node; 
        next_node = NULL;  

        string temp_role;  
        string temp_name;  
        double temp_id;  
        double temp_salary;  
               
        if(head == NULL){  
            cout<<"Empty"<<endl;  
        }  
        else{  
            while(present != NULL){  
                next_node = present->next;  
                while(next_node != NULL){  
                    if(present->id > next_node->id) {  
                    
                    temp_role = present->role;  
                    temp_name = present->name;  
                    temp_id = present->id;  
                    temp_salary = present->salary;  
                    
                    present->role = next_node->role;  
                    present->name = next_node-> name;  
                    present->id = next_node->id;  
                    present->salary = next_node->salary;  
                    
                    next_node->role = temp_role;
                    next_node->name = temp_name;
                    next_node->id = temp_id;
                    next_node->salary = temp_salary;  
                    
                    }  
                    next_node = next_node->next;  
                }  
                present = present->next;  
            }      
        }  
    }  
   


void display_all_staff(){
   struct node* temp;
   temp = head;
    while (temp != NULL) {
       cout<<"Role = "<<temp->role <<" , ";
       cout<<"Name = " <<temp->name <<" , ";
       cout<<"ID = " <<temp->id <<" , ";
       cout<<"Salary = " <<temp->salary <<" "<<endl;
       temp = temp->next;
    }
}

  
int main(){
    int number,number_1,option,value,pos;
    string role, role_1, name; 
    double id, salary, salary_1;

       
   do{
   cout<<"Welcome to the Staff Management Software "<<endl;

   cout<<"1. Add a New Employee"<<endl;
   cout<<"2. Remove an Employee who has been LEFT"<<endl;
   cout<<"3. Display Staff Members"<<endl;
   cout<<"4. Search Staff Members"<<endl;
   cout<<"5. Salary/Role Updatation of Staff Members"<<endl;
   cout<<"PRESS 0 TO EXIT FROM THE SOFTWARE ! "<<endl;   
    
   cout<<"Press the number/option = ";
   cin>>option;


   switch (option){

   case 1:
        cout<<"Where you want to Add"<<endl; 
        cout<<"1. Start"<<endl; 
        cout<<"2. End"<<endl;
        cout<<"3. At Specific Position "<<endl;
        cout<<"Enter the option number = ";
        cin>>value;
        
        if(value==1){
            cout<<"Enter the details you want to insert at the start "<<endl; 
            cout<<"Enter the role = ";
            cin>>role;

            cout<<"Enter the name = ";
            cin>>name;

            cout<<"Enter ID = ";
            cin>>id;

            cout<<"Enter the salary = ";
            cin>>salary;

            // ofstream myFile(role,ios::app);  
            // myFile<<"Role: " << role <<" , ";
            // myFile<<"Name: " << name <<" , ";
            // myFile<<"ID: " << id <<" , ";
            // myFile<<"Salary: " << salary <<"  "<<endl;  

            // myFile.close();
              
            insert_start(role, name, id, salary);    
        }

        else if(value==2){
            cout<<"Enter the details you want to insert at the end "<<endl; 
            cout<<"Enter the role = ";
            cin>>role;
 
            cout<<"Enter the name = ";
            cin>>name;
  
            cout<<"Enter ID = ";
            cin>>id;
   
            cout<<"Enter the salary = ";
            cin>>salary;
            // string role; 
            // ofstream myFile(role,ios :: app);  
            // myFile<<"Role: " << role <<" , ";
            // myFile<<"Name: " << name <<" , ";
            // myFile<<"ID: " << id <<" , ";
            // myFile<<"Salary: " << salary <<"  "<<endl;  

            // myFile.close();
     
            insert_at_end(role, name, id, salary);    
        }

        else if(value==3){
            cout<<"Enter the details you want to insert "<<endl; 
            cout<<"Enter the role = ";
            cin>>role;
     
            cout<<"Enter the name = ";
            cin>>name;
      
            cout<<"Enter ID = ";
            cin>>id;
       
            cout<<"Enter the salary = ";
            cin>>salary;
  
            cout<<"Enter the position where you want to insert = ";
            cin>>pos;

            // ofstream myFile(role,ios :: app);  
            // myFile<<"Role: " << role <<" , ";
            // myFile<<"Name: " << name <<" , ";
            // myFile<<"ID: " << id <<" , ";
            // myFile<<"Salary: " << salary <<"  "<<endl; 

            // myFile.close();
            
            insert_specific(role, name, id, salary,pos);    
        }
    break;
            
    
    case 2:
        cout<<"From where you want to delete "<<endl;
        cout<<"1. Start"<<endl; 
        cout<<"2. End"<<endl;
        cout<<"3. Anywhere (Except start and end) "<<endl;
        cout<<"Enter the option number = ";
        cin>>value;

        if(value==1){
           del_begin();
           cout<<"Record is removed from the starting "<<endl;
        }

        else if(value==2){
            del_end();
            cout<<"Record is removed from the end "<<endl;
        }

        else if(value==3){
            cout<<"Enter the ID you want to delete = ";
            cin>>id;  
            del_specific(id);             
        }
    break;
         
    
    case 3:
        cout<<"Displaying all Staff Members without Sorting ID's"<<endl;
        display_all_staff();
        cout<<endl;
        cout<<endl; 
        cout<<"Displaying all Staff Members w.r.t Sorted ID's "<<endl;
        sortList();
        display_all_staff();
        break;

    
    case 4:
        cout<<"Enter the ID you want to search = ";
        cin>>id;
        searching(id);
        break;

    
    case 5:
        int option_1=1;
        int option_2=2;

        cout<<"What do you want to update/change "<<endl;
        cout<<"1. ROLE "<<endl;
        cout<<"2. SALARY "<<endl;
        cout<<"Please enter the number = ";
        cin>>number;
        
        while(number!= option_1 && number!=option_2){ 
            cout<<"OOPS ! Entered invalid option. Please enter again = ";
            cin>>number;
        }
        
        if(number==1){
            cout<<"Enter the ID from the STAFF you want to upgrade the role = ";
            cin>>id;
            cout<<"Enter the current role = ";
            cin>>role;
            cout<<"Now ! Enter new role  = ";
            cin>>role_1;
            
            updating_role(id,role,role_1);
        }

        if(number==2){ 

            cout<<"1. Update salary with a specific percentage for all employees"<<endl;
            cout<<"2. Update salary with a specific percentage for a single employee"<<endl;
            
            int option_for_salary;
            cout<<"Select an Option"<<endl;
            cin>>option_for_salary;
            
            if(option_for_salary==1){

                double perc;
                double new_sal;
                               
                cout<<"Now ! Enter the percentage you want to increment  = ";
                cin>>perc;
 
                updating_Salary_all_staff(perc);    
            } 


            if(option_for_salary==2){

                double perc;
                double new_sal;

                cout<<"Enter the ID from the STAFF you want to change the salary = ";
                cin>>id;
                cout<<"Enter the previous salary = ";
                cin>>salary;
                cout<<"Now ! Enter the percentage you want to increment  = ";
                cin>>perc;
 
                updating_Salary(id, salary, perc);
            } 
        }
        break; 
     } //switch ends
  
} // loop ends  
   
   while(option!=0);
   
   return 0;
}   
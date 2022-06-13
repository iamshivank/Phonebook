#include <iostream>
#include<cstring>
using namespace std;
class dnode
{
    public:
        char number[50];
        char gmail[40];
        char name[30];
        dnode *prev,*next;
        dnode(char n[],char r[],char g[])
{
               strcpy(name,n);
                strcpy(number,r);
               strcpy(gmail,g);
                next=NULL;
                prev=NULL;
}
	friend class dlist;
};
class dlist
{
    dnode *head,*temp,*ptr;
    
    dnode *ptr1, *ptr2, *dup;
    public:
    dnode *prevn;
        
    void insert();
    void sort();
    void deletecontact(char n[20]);
    void deletesamenumber();
    void deletesamename();
    void deletesamegmail();
    void searchbyname(char p[20]);
    void searchbynumber(char no[30]);
    void searchbygmail(char g[20]);

        // dnode *head,*temp,*ptr;
        // friend class apply;
        void accept();
        void display();
        void update(char ch[10]);
        dlist()
                {
                        head=NULL;
                        temp=NULL;
                        ptr=NULL;
                        ptr1=NULL;
                        ptr2=NULL;
                        dup=NULL;
                }
};
// class apply()
// {
    
// }
void dlist::accept()
{
        char number[50];
        char gmail[40];
        char name[30];
    char ans;
      do
        {
    cout<<"Enter Name      :";
    cin>>name;
    // cin.getline (name,30);
    cout<<"Enter Number    :";
    cin>>number;
    while(strlen(number)!=10)
    {
    cout<<"Enter Valid Number  :";
    cin>>number;
    }
    cout<<"Enter your Email    :";
    cin>>gmail;
    temp=new dnode(name,number,gmail);
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
       ptr=head;
		while(ptr->next!=NULL)
		{
ptr=ptr->next;
		}
		ptr->next=temp;
		temp->prev=ptr;
    }
	    cout<<"Do you want to add more?";
    cin>>ans;
}while(ans=='y');

}
void dlist::display()
{
    ptr=head;//start the node
	while(ptr!=NULL)//traverse till last
	{
			cout<<"\n\nName  ::\t"<<ptr->name;
			cout<<"\nNumber::\t+91-"<<ptr->number;
			cout<<"\nEmail::\t"<<ptr->gmail;
			ptr=ptr->next;
	}
}

    void dlist::insert()
    {
        accept();
    }
    void dlist::sort()
    {
        dnode *i,*j;
        int temp;
        char n[10];
        for(i=head;i->next!=NULL;i=i->next)
        {
            for(j=i->next;j!=NULL;j=j->next)
            {
                temp=strcmp(i->name,j->name);
                if(temp>0)
                {
                   strcpy(n,i->name);
                   strcpy(i->name,j->name);
                   strcpy(j->name,n);
                }
            }
        }
     
    }
    void dlist::deletecontact(char s[20])
    {
        int c=0;
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(s,ptr->name)==0)
            {
                c=1;
                break;
            }
            else
            {
                c=2;
            }
            ptr=ptr->next;
        }
        if(c==1 && ptr!=head && ptr->next!=NULL)
        {
            ptr->prev->next=ptr->next;
           ptr->next->prev=ptr->prev;
           delete(ptr);
           cout<<"Your contact has been successfully deleted\n\n";
        }
        if(ptr==head)
        {
            head=head->next;
            head->prev=NULL;
            delete(ptr);
           cout<<"Your contact has been successfully deleted\n\n";
        }
        if(ptr->next==NULL)
        {
            ptr->prev->next=NULL;
            ptr->prev=NULL;
            delete(ptr);
           cout<<"Your contact has been successfully deleted\n\n";
        }
        if(c==2)
        {
            cout<<"Your entered name is not on contact";
        }
    }
    void dlist::deletesamename()
    {
        ptr1=head;
        while (ptr1 != NULL && ptr1->next != NULL) 
    { 
        ptr2 = ptr1; 
        while (ptr2->next != NULL) 
        { 
            if (strcmp(ptr1->name,ptr2->next->name)==0)
            { 
                dup = ptr2->next; 
                ptr2->next = ptr2->next->next; 
                delete(dup); 
            } 
            else
            {
                ptr2 = ptr2->next; 
        }
        }
        ptr1 = ptr1->next; 
    } 
    }
    void dlist::deletesamegmail()
    {
        ptr1=head;
        while (ptr1 != NULL && ptr1->next != NULL) 
    { 
        ptr2 = ptr1; 
        while (ptr2->next != NULL) 
        { 
            if (strcmp(ptr1->gmail,ptr2->next->gmail)==0)
            { 
                dup = ptr2->next; 
                ptr2->next = ptr2->next->next; 
                delete(dup); 
            } 
            else
            {
                ptr2 = ptr2->next; 
        }
        }
        ptr1 = ptr1->next; 
    } 
    }
    void dlist::deletesamenumber()
    {
     ptr1=head;
        while (ptr1 != NULL && ptr1->next != NULL) 
    { 
        ptr2 = ptr1; 
        while (ptr2->next != NULL) 
        { 
            if (strcmp(ptr1->number,ptr2->number)==0)
            { 
                dup = ptr2->next; 
                ptr2->next = ptr2->next->next; 
                delete(dup); 
            } 
            else
            {
                ptr2 = ptr2->next; 
        }
        }
        ptr1 = ptr1->next; 
    }    
    }
    void dlist::searchbyname(char na[10])
    {
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(na,ptr->name)==0)
            {
                cout<<"Name found"<<endl;
                cout<<"Contact details are below:\n"<<endl;
        	cout<<"\n\nName  ::\t"<<ptr->name;
			cout<<"\nNumber::\t+91-"<<ptr->number;
			cout<<"\nEmail::\t"<<ptr->gmail;
		        
            }
            ptr=ptr->next;
        }
    }
    void dlist::searchbynumber(char num[20])
    {
     ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(num,ptr->number)==0)
            {
                cout<<"Number found\n"<<endl;
                cout<<"Contact details are below:\n"<<endl;
        	cout<<"\n\nName  ::\t"<<ptr->name;
			cout<<"\nNumber::\t+91-"<<ptr->number;
			cout<<"\nEmail::\t"<<ptr->gmail;
		        
            }
            ptr=ptr->next;
        }   
    }
    void dlist::searchbygmail(char gm[20])
    {
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(gm,ptr->gmail)==0)
            {
                cout<<"Email found\n"<<endl;
                cout<<"Contact details are below:\n"<<endl;
        	cout<<"\n\nName  ::\t"<<ptr->name;
			cout<<"\nNumber::\t+91-"<<ptr->number;
			cout<<"\nEmail::\t"<<ptr->gmail;
		        
            }
            ptr=ptr->next;
        }
    }
    void dlist::update(char n[20])
    {
        char ans;
        int c;
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(n,ptr->name)==0)
            {
                
                do
                {
                    cout<<"\nWhat do you want to update?\n1.Name\n2.Phone Number\n3.Email\n";
                cin>>c;
                switch(c)
                {
                    case 1:
                    cout<<"Enter your name=";
                    cin>>ptr->name;
                    break;
                    case 2:
                    cout<<"Enter phone number?";
                    cin>>ptr->number;
                    while(strlen(ptr->number)!=10)
    {
    cout<<"Enter valid number  :";
    cin>>ptr->number;
    }
                    break;
                    case 3:
                    cout<<"Enter new email";
                    cin>>ptr->gmail;
                    break;
                }
                cout<<"Do you want to update more?";
                cin>>ans;
                }while(ans=='y');
            }
            ptr=ptr->next;
        }
    }
int main()
{
    char n[20];
    char nam[20];
    char name[10];
    char number[10];
    char gmail[20];
    dlist d1;
    // apply d;
    char ans;
    int ch,a;
    cout<<"**************                                PHONE BOOK                          ********************";
    cout<<"\n\nWhat is your name?\n";
    cin.getline(name,20);
    cout<<"\n\n!!!!!!!!!!!!!!!!!!!!!!!   Welcome "<<name<<"   !!!!!!!!!!!!!!!!!!!!!";
    cout<<"\n\n\nLet's create our PHONEBOOK! "<<name<<"  \n\n";
    d1.accept();
    d1.sort();
    do
    {
    cout<<"\n\n\n\n1) Display your Phonebook\n2) Insert new contact\n3) Update details on existing contacts\n4) Delete contact\n5) Delete same name in phonebook\n6) Delete same numbers in phonebook\n7) Search\n";
    cin>>ch;
    switch(ch)
    {
    case 2:
    d1.insert();
    d1.sort();
    break;
    
    case 1:
    // d1.sort();
    d1.display();
    break;
    case 3:
    
        cout<<"\n\nEnter the name of person whose details you want to update\n";
        cin>>n;
    d1.update(n);
    d1.sort();
    break;
    case 4:
    cout<<"\nEnter the name you want to delete from phonebook\n";
    cin>>name;
    d1.deletecontact(name);
    break;
     case 5:
    d1.deletesamename();
    d1.display();
    break;
    case 6:
    d1.deletesamenumber();
    d1.display();
    break;
    case 7:
    do
    {
    cout<<"1.Search by name\n2.Search by number\n3.Search by email";
    cin>>a;
    switch(a)
    {
        case 1:
        cout<<"Enter name to be searched\n";
        cin>>name;
        d1.searchbyname(name);
        break;
        case 2:
        cout<<"Enter name to be searched\n";
        cin>>number;
        d1.searchbynumber(number);
        break;
        case 3:
        cout<<"Enter name to be searched\n";
        cin>>gmail;
        d1.searchbygmail(gmail);
        break;
        default:cout<<"\nNo proper input given\n";
    }
    cout<<"Do you want to continue searching?";
    cin>>ans;
}while(ans=='y');

    break;
    case 8:d1.deletesamegmail();
    d1.display();
    break;
    default:cout<<"\nNo Proper input given.\n";
    }
    cout<<"\n\nDo you want to close this program?";
    cin>>ans;
}while(ans=='y');
}
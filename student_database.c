#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
typedef enum  {FALSE,TRUE} status_code;
typedef struct node_tag
{
	int roll_no,marks;
	char   name[MAX],  subject_code[MAX];
	struct node_tag * next;
	int status;
}node;
typedef struct aggregate_marklist_node_tag
{
	int roll_no;
	char name[MAX];
	int total_marks;
	struct aggregate_marklist_node_tag * next;
} marklist;
status_code insert(node **,node *);
status_code deleteNode(node **, int ,char * );
void print_list(node *);
void print_list_toppers(marklist *);
node * create_new_node(char * , int ,char * ,int );
marklist * create_node_with_total_marks(int ,char *,int);
int  getnumrecords(node * );
status_code isempty(node * );
status_code isfull(node * );
node * getmaxmarks(node * ,char * );
marklist * topper(node * );
node * create_union(node * ,node *  );
node * symmetric_difference(node * ,node *  );
node* create_intersection(node * ,node * );
void get_failures(int ,int ,node * );
status_code unique(node ** );
node* create_difference(node * ,node * );
void k_th_popular_subject(node *,int);


/*-------------------------------------MAIN FUNCTION---------------------------------------------------*/
int main()
{
	int option,roll_no,marks,go_on,records,l1=1,l2=1,p,k;
	char   name[MAX], subject_code[MAX];
	marklist * toppers;
	status_code status;
	node * list,* nptr, * temp,* list1 ,* list2, *list3;
	list=NULL;
	do
	{
		printf("-------------------M E N U-----------------------\n");
		printf("0: TO PRINT THE LIST\n");
		printf("1: TO INSERT A STUDENT RECORD\n");
		printf("2:TO DELETE A STUDENT RECORD\n");
		printf("3:TO GET THE TOTAL NO OF RECORDS\n");
		printf("4:TO CHECK IF THE LIST IS EMPTY OR NOT\n");
		printf("5:TO CHECK IF THE LIST IS FULL OR NOT\n");
		printf("6:TO GET MAX MARKS IN A SUBJECT AND LIST OF SUBJECT TOPPERS\n");
		printf("7:TO GET THE TOPPER\n");
		printf("8:TO GET THE Kth POPULAR SUBJECT\n");
		printf("9:TO GET THE FAILURES\n");
		printf("10:TO GET THE UNIQUE LIST\n");
		printf("11:TO GET THE UNION OF THE TWO LIST\n");
		printf("12:TO GET THE INTERSECTION OF THE TWO LIST\n");
		printf("13:TO GET THE DIFFERENCE OF THE TWO LIST\n");
		printf("14:TO GET THE SYMMETRIC DIFFERENCE OF THE TWO LIST\n");
		
		scanf("%d",&option);
		
	
		switch(option)
		{
			case 0:
				print_list(list);
				printf("DO YOU WANT TO CONTINUE PRESS 1 TO CONINUE AND 0 TO EXIT\n");
				scanf("%d",&go_on);
				break;
				
			case 1:
				printf("ENTER THE NAME,ROLL NO,SUBJECT CODE, MARKS IN THIS SUBJECT \n");
				scanf("%s %d %s %d",name,&roll_no,subject_code,&marks);
				nptr=create_new_node(name,roll_no,subject_code,marks);	
				status=insert(&list,nptr);
				if(status==TRUE)
				{
					printf("THE INSERTION IS SUCCESSFULL AND THE LIST IS AS GIVEN BELOW\n");
					print_list(list);
				}
				else
				{
					printf("INSERTION UNSUCCESSFULL YOU ARE LOW ON SPACE\n");
				}
				
				printf("DO YOU WANT TO CONTINUE PRESS 1 TO CONINUE AND 0 TO EXIT\n");
				scanf("%d",&go_on);
				break;
			case 2:
			                    
                printf("ENTER THE ROLL NO AND THE CORRESPONDING SUBJECT CODE WHOSE RECORD YOU WANT TO DELETE");
		        scanf("%d %s",&roll_no,subject_code);
		        status=deleteNode( &list,  roll_no, subject_code);
		        if(status==TRUE)
		        {
		        	printf("THE RECORD WITH ROLL NO AS %d AND SUBJECT CODE AS %s IS NOW DELETED\n",roll_no,subject_code);
				}
				else
				{
					printf("SORRY FOR INCONVINIENCE\n");
				}
			    
				printf("DO YOU WANT TO CONTINUE PRESS 1 TO CONINUE AND 0 TO EXIT\n");
				scanf("%d",&go_on);
				break;
			case 3:
				records=  getnumrecords(list);
				printf("THE NO OF DIFFERENT RECORDS PRESENT IN THE DATABASE ARE %d\n",records);
				printf("DO YOU WANT TO CONTINUE PRESS 1 TO CONINUE AND 0 TO EXIT\n");
				scanf("%d",&go_on);
				break;
			case 4:
				status= isempty( list);
				if(status==TRUE)
				{
					printf("THE LIST IS EMPTY\n");
				}
				else
				{
					printf("THE LIST IS NOT EMPTY\n");
				}
				printf("DO YOU WANT TO CONTINUE PRESS 1 TO CONINUE AND 0 TO EXIT\n");
				scanf("%d",&go_on);
				break;
			case 5:
				status=isfull(list );
				if(status==TRUE)
				{
					printf("THE LIST IS FULL\n");
				}
				else
				{
					printf("THE LIST IS NOT FUL\n");
				}
				printf("DO YOU WANT TO CONTINUE PRESS 1 TO CONINUE AND 0 TO EXIT\n");
				scanf("%d",&go_on);
				break;
			case 6:
				 if(list!=NULL)
				 
				 {
					 printf("ENTER THE SUBJECT CODE OF WHICH YOU WANT TO FIND MAX MARKS \n");
					 scanf("%s",subject_code);
					 temp=getmaxmarks(list, subject_code);
					 if(temp!=NULL)
					 {
					 	printf("THE TOPPERS OS % s SUJECT ARE :\n",subject_code);
				   	    
					 }
					 print_list(temp);
					 
				 }
				 else
				 {
				 	printf("THE LIST IS EMPTY\n");
				 }
				 printf("DO YOU WANT TO CONTINUE PRESS 1 TO CONINUE AND 0 TO EXIT\n");
				 scanf("%d",&go_on);
				 break;
	 		 case 7:
				toppers = topper(list);
				printf("THE TOPPER LIST IS: \n");
				print_list_toppers(toppers);
				printf("DO YOU WANT TO CONTINUE PRESS 1 TO CONINUE AND 0 TO EXIT\n");
				scanf("%d",&go_on);
				break;
			case 8:
				printf("ENTER THE VALUE OF k\n");
				scanf("%d",&k);
				k_th_popular_subject(list,k);
				printf("DO YOU WANT TO CONTINUE PRESS 1 TO CONINUE AND 0 TO EXIT\n");
				scanf("%d",&go_on);
				break;
			case 10:
				status= unique(&list);
				if(status==TRUE)
				{
					printf("THE DUPLICATES WERE PRESENT AND ARE NOW REMOVED\n");
					printf("THE UNIQUE LIST IS:\n");
					print_list(list);
				}
				else
				{
					printf("NO DUPLICATES PRESENT THE LIST IS UNIQUE\n");
				}
				printf("DO YOU WANT TO CONTINUE PRESS 1 TO CONINUE AND 0 TO EXIT\n");
				scanf("%d",&go_on);
				break;
			    
			case 11:
				//creating list 1
				list1=NULL;
				list2=NULL;
			    printf("CREATE LIST 1\n");
				do
				{
				  	printf("ENTER THE NAME,ROLL NO,SUBJECT CODE, MARKS IN THIS SUBJECT \n");
					scanf("%s %d %s %d",name,&roll_no,subject_code,&marks);
					nptr=create_new_node(name,roll_no,subject_code,marks);	
					insert(&list1,nptr);
					printf("STOP LIST:0 CONTINUE LIST:1 \n");
			    	scanf("%d",&l1);			
    		    }
    		    while(l1==1);
    		    //creating list 2
    		    printf("CREATE LIST 2\n");
    		    do
				{				
					printf("ENTER THE NAME,ROLL NO,SUBJECT CODE, MARKS IN THIS SUBJECT \n");
					scanf("%s %d %s %d",name,&roll_no,subject_code,&marks);
					nptr=create_new_node(name,roll_no,subject_code,marks);	
					insert(&list2,nptr);
					printf("STOP LIST:0 CONTINUE LIST:1 \n");
			    	scanf("%d",&l2);	
    		    }
    		    while(l2==1);
    		    printf("CREATING LIST 3 FROM 1 AND 2\n");
    		    list3=create_union( list1,list2);
    		    print_list(list3);
    		    printf("DO YOU WANT TO CONTINUE PRESS 1 TO CONINUE AND 0 TO EXIT\n");
				scanf("%d",&go_on);
				break;
			case 12:
				//creating list 1
				list1=NULL;
				list2=NULL;
			    printf("CREATE LIST 1\n");
				do
				{
				  	printf("ENTER THE NAME,ROLL NO,SUBJECT CODE, MARKS IN THIS SUBJECT \n");
					scanf("%s %d %s %d",name,&roll_no,subject_code,&marks);
					nptr=create_new_node(name,roll_no,subject_code,marks);	
					insert(&list1,nptr);
					printf("STOP LIST:0 CONTINUE LIST:1 \n");
			    	scanf("%d",&l1);			
    		    }
    		    while(l1==1);
    		    //creating list 2
    		    printf("CREATE LIST 2\n");
    		    do
				{				
					printf("ENTER THE NAME,ROLL NO,SUBJECT CODE, MARKS IN THIS SUBJECT \n");
					scanf("%s %d %s %d",name,&roll_no,subject_code,&marks);
					nptr=create_new_node(name,roll_no,subject_code,marks);	
					insert(&list2,nptr);
					printf("STOP LIST:0 CONTINUE LIST:1 \n");
			    	scanf("%d",&l2);	
    		    }
    		    while(l2==1);
    		    printf("CREATING LIST 3 FROM 1 AND 2\n");
    		    list3=create_intersection(list1,list2);
    		    print_list(list3);
    		    printf("DO YOU WANT TO CONTINUE PRESS 1 TO CONINUE AND 0 TO EXIT\n");
				scanf("%d",&go_on);
				break;
			case 13:
				//creating list 1
				list1=NULL;
				list2=NULL;
			    printf("CREATE LIST 1\n");
				do
				{
				  	printf("ENTER THE NAME,ROLL NO,SUBJECT CODE, MARKS IN THIS SUBJECT \n");
					scanf("%s %d %s %d",name,&roll_no,subject_code,&marks);
					nptr=create_new_node(name,roll_no,subject_code,marks);	
					insert(&list1,nptr);
					printf("STOP LIST:0 CONTINUE LIST:1 \n");
			    	scanf("%d",&l1);			
    		    }
    		    while(l1==1);
    		    //creating list 2
    		    printf("CREATE LIST 2\n");
    		    do
				{				
					printf("ENTER THE NAME,ROLL NO,SUBJECT CODE, MARKS IN THIS SUBJECT \n");
					scanf("%s %d %s %d",name,&roll_no,subject_code,&marks);
					nptr=create_new_node(name,roll_no,subject_code,marks);	
					insert(&list2,nptr);
					printf("STOP LIST:0 CONTINUE LIST:1 \n");
			    	scanf("%d",&l2);	
    		    }
    		    while(l2==1);
    		    printf("CREATING LIST 3 FROM 1 AND 2\n");
    		    list3=create_difference(list1,list2);
    		    print_list(list3);
    		    printf("DO YOU WANT TO CONTINUE PRESS 1 TO CONINUE AND 0 TO EXIT\n");
				scanf("%d",&go_on);
				break;
				
			case 14:
				//creating list 1
				list1=NULL;
				list2=NULL;
			    printf("CREATE LIST 1\n");
				do
				{
				  	printf("ENTER THE NAME,ROLL NO,SUBJECT CODE, MARKS IN THIS SUBJECT \n");
					scanf("%s %d %s %d",name,&roll_no,subject_code,&marks);
					nptr=create_new_node(name,roll_no,subject_code,marks);	
					insert(&list1,nptr);
					printf("STOP LIST:0 CONTINUE LIST:1 \n");
			    	scanf("%d",&l1);			
    		    }
    		    while(l1==1);
    		    //creating list 2
    		    printf("CREATE LIST 2\n");
    		    do
				{				
					printf("ENTER THE NAME,ROLL NO,SUBJECT CODE, MARKS IN THIS SUBJECT \n");
					scanf("%s %d %s %d",name,&roll_no,subject_code,&marks);
					nptr=create_new_node(name,roll_no,subject_code,marks);	
					insert(&list2,nptr);
					printf("STOP LIST:0 CONTINUE LIST:1 \n");
			    	scanf("%d",&l2);	
    		    }
    		    while(l2==1);
    		    printf("CREATING LIST 3 FROM 1 AND 2\n");
    		    list3=symmetric_difference(list1,list2);
    		    print_list(list3);
    		    printf("DO YOU WANT TO CONTINUE PRESS 1 TO CONINUE AND 0 TO EXIT\n");
				scanf("%d",&go_on);
				break;
				
			case 9:
				printf("ENTER THE VALUE OF MIN MARKS\n");
				scanf("%d",&p);
				printf("ENTER THE VALUE OF MAX NO OF SUBJECTS\n");
				scanf("%d",&k);
			    get_failures( p, k,list);
			    printf("DO YOU WANT TO CONTINUE PRESS 1 TO CONINUE AND 0 TO EXIT\n");
				scanf("%d",&go_on);
				break;
			
			    
				
    		    
				    
   	    }				
	}
	while(go_on==1);
	return(0);
}
/*------------------------------------CREATING NEW NODE-------------------------------------------------*/
node * create_new_node(char * name, int roll_no,char * subject_code,int marks)
{
	node * new_node;
	new_node=(node*)malloc(sizeof(node));
	if(new_node!=NULL)
	{
		new_node->roll_no=roll_no;
		new_node->marks=marks;
		strcpy(new_node->subject_code,subject_code);
		strcpy(new_node->name,name);
		new_node->next=NULL;
	}
	return(new_node);
}
/*--------------------------------------INSERTION------------------------------------------------------*/
// insertion in the list assuming the the list is sorted
status_code insert(node ** head,node * new_node)
{
	
	node * store_head,* prev,* current;
	store_head=*head;
	status_code retval;
	if(new_node!=NULL)//new node is not null so continue
	{
		if((* head)==NULL)//if the list is empty or the roll no to be inserted is smallest then insert at start
		{
		
			(* head)=new_node;
			
		}
		else if((* head)->roll_no > new_node->roll_no)//smallest roll no to be inserted
		{
			new_node->next=(* head);
			(* head)=new_node;
			
		}
		else if((* head)->roll_no < new_node->roll_no)//if roll no to be inserted is greater than the head then
		{
			prev=NULL;
			current=(* head);
		
			while((current!=NULL)&&(current->roll_no < new_node->roll_no))//find a suitable place to insert it
			{
				prev=current;
				current=current->next;
				
			}
			if(current==NULL)//greatest node to be added
			{
				prev->next=new_node;
			}
			else if(new_node->roll_no == current->roll_no)// if while doing so roll no becomes equal then checking for subject
			{
				if((strcmp(current->subject_code,new_node->subject_code)>0))//if the to be inserted subject is smallest insert at start
				{
					new_node->next=current;
					prev->next=new_node;
				}
				else if((strcmp(current->subject_code,new_node->subject_code))<0)//if the to be inserted subject is greatest then findind the appropriate place
				{
			
					
					while(current!=NULL&&current->roll_no == new_node->roll_no&&(strcmp(current->subject_code,new_node->subject_code))<0)//if while doing so if the roll no changes then stop
					//one more condition current!=NULL
					{
						prev=current;
				 		current=current->next;
				 			
				 	}
				 	if(current==NULL)
				 	{
				 		prev->next=new_node;
					 }
				 	
				    else if((strcmp(current->subject_code,new_node->subject_code))==0)//if the subject matches that in the list the update the list and free the new node  
				 	{
				 		strcpy(current->name,new_node->name);
						current->marks=new_node->marks;
						free(new_node);	
					 }
				    
				 	else//otherwise you have found the appropriate place to place the node
				 	{
				 		new_node->next=current;
						prev->next=new_node;
				 	}
				 }
				 else//if the sub and roll no matches the very first place of the same roll no node the update that node free new node
				 {
				 	strcpy(current->name,new_node->name);
					current->marks=new_node->marks;
					free(new_node);
				 }
					
			}
			else//while finding the appropriate place according to roll no we do not get same roll no case then insert the node in between the prev and current 
			{
				new_node->next=current;
				prev->next=new_node;
			}
			
			
		}
			
		else//is the very first node roll no same as that to the new node then update at start 
		{
			if(strcmp(new_node->subject_code,(* head)->subject_code)==0)
			{
				
				 	strcpy((* head)->name,new_node->name);
					(* head)->marks=new_node->marks;
					free(new_node);
			}
			else
			{
				
			
						prev=NULL;
						current=(*head);

		                while(current!=NULL&&current->roll_no==new_node->roll_no&&strcmp(new_node->subject_code,current->subject_code)>0)
		                {
		                  prev=current;
		                  current=current->next;
		                }
		                if(current==NULL)
		                {
		                    prev->next=new_node;
                  		}
		                else if(strcmp(new_node->subject_code,current->subject_code)==0)
						{
						   strcpy(current->name,new_node->name);
						   current->marks=new_node->marks;
						   free(new_node);
   			            }
   			            
		                else if(prev==NULL)
		                {
		                  new_node->next=(*head);
		                  *head=new_node;
		                }								
		                else
		                {
		                  
		                    prev->next=new_node;
		                    new_node->next=current;
		                  
		                }
			}
		
		}
		/*printf("SUCCESSFULL INSERTION\n");*/
		retval=TRUE;
	}
	else//if the new node gets null from the malloc error 
	{
		/*printf("NO AVAILABLE SPACE \n");
		printf("INSERTION NOT SUCCESSFULL\n");*/
		retval=FALSE;		
	}
	return(retval);
	
}
/*----------------------------------------DELETION------------------------------------------------------*/

status_code deleteNode( node **head, int roll_no,char * subject_code)
{
    // Store head node
	node * temp , * prev,* current;
	status_code retval;
	prev=NULL;
	int flag=0;
	current=(* head);
	if((* head )!=NULL)
	{
		while(current!=NULL&&flag==0)
		{
			if((current->roll_no==roll_no)&&(strcmp(current->subject_code,subject_code)==0))
			{
				flag=1;
			}
			else
			{
				prev=current;
				current=current->next;
			}
		}
		if(flag==1)
		{
			if(prev==NULL)
			{
				prev=current;
				current=prev->next;
				*head=current;
				free(prev);
				/*printf("SUCCESSFULL DELETION!\n");*/  
				retval=TRUE;
			}
			else
			{
				temp=current;
				prev->next=current->next;
				free(temp);
				/*printf("SUCCESSFULL DELETION!\n");*/
				retval=TRUE;
			}
		}	
		else
		{
			printf("RECORD NOT FOUND\n");
			retval=FALSE;
		}
	}
	else
	{
		printf("CANNOT DELETE LIST IS EMPTY\n");
		retval=FALSE;
	}
	return(retval);
	
}

 
  /*-----------------------------------------PRINTING THE LIST------------------------------------------*/ 
//printing the list
void print_list(node * head)
{
	node * store_head;
	store_head=head;
	if(store_head==NULL)
	{
	 	printf("THIS LIST IS EMPTY\n");	
	}
	else
	{	
		while(store_head!=NULL)
		{
			printf("name:%s\t roll_no:%d\t subject:%s\t marks in %s subject:%d\t----->\n",store_head->name,store_head->roll_no,store_head->subject_code,store_head->subject_code,store_head->marks);
			store_head=store_head->next;
		}
	}
	
	
}
/*-----------------------------------------PRINTING LIST WITH TOTAL MARKS------------------------------*/
void print_list_toppers(marklist * head)
{
	marklist * store_head;
	store_head=head;
	if(store_head==NULL)
	{
	 	printf("THIS LIST IS EMPTY\n");	
	}
	else
	{
		while(store_head!=NULL)
		{
			printf("NAME:%s\t ROLL NO:%d\t TOTAL MARKS :%d\t----->\n",store_head->name,store_head->roll_no,store_head->total_marks);
			store_head=store_head->next;
		}
	}	
	
	
}
/*-----------------------------------------GET NO OF RECORDS--------------------------------------------*/
int  getnumrecords(node * head)
{
	node *temp;
	temp=head;
	int count=0;
	if(temp==NULL)
	{
		count=0;
	}
	else
	{
		while(temp!=NULL)
		{
			count++;
			temp=temp->next;
		}
	}
	return(count);
}
/*----------------------------------IS LIST EMPTY------------------------------------------------------*/
status_code isempty(node * head)
{
	if(head==NULL)
	{
	 	return(TRUE);
		 	
	}
	else
	{
	 	return(FALSE);
	}
}
/*-----------------------------------------IS LIST FULL-------------------------------------------------*/
status_code isfull(node * head)
{
	node * temp;
	temp=(node*)malloc(sizeof(node));
	if(temp==NULL)
	{
		return(TRUE);
	}
	else
	{
		return(FALSE);
	}
}
/*----------------------------------------GET MAX MARKS IN A GIVEN SUBJECT------------------------------*/
node * getmaxmarks(node * head,char * subject_code)
{
	node * temp,* subjectlist,* new_node,* last,* temp2;	
	int maxmarks=-1;
	subjectlist=NULL;
    temp=head;
	while(temp!=NULL)
	{
		if(strcmp(temp->subject_code,subject_code)==0)
		{
		 	new_node= create_new_node(temp->name , temp->roll_no ,temp->subject_code ,temp->marks );
	 		insert( &subjectlist,new_node);
		}
		temp=temp->next;
	}	
	if(subjectlist!=NULL)
	{
		temp=subjectlist;
		while(temp!=NULL)
		{
		 	if(temp->marks>= maxmarks)
			{
			 	maxmarks=temp->marks;						
		    } 
		    temp=temp->next;
	    }
 	}   
	if(subjectlist!=NULL)
	{
	 	temp=subjectlist;
		 while(temp->marks!=maxmarks)
		 {
		  	 temp=temp->next;	
		 }
		 subjectlist=temp;
		 last=subjectlist;
		 while(temp!=NULL)
		 {
		 	if(temp->marks==maxmarks)
		 	{
		 		temp2=temp;
		 		temp=temp->next;
			    last->next=temp2;
			    last=temp2;
			 }
			 else
			 {
			 	temp=temp->next;
			 }
		 }
		 if(temp==NULL)	
		 {
		 	last->next=NULL;
		 }
    }
    if(subjectlist==NULL)
	{
		printf("NO RECORD PRESENT FOR THE GIVEN SUBJECT\n");
	}
	return(subjectlist);
}
/*--------------------------------------CREATING NODE WITH TOTAL MARKS--------------------------------*/
marklist * create_node_with_total_marks(int roll_no,char * name, int total_marks)
{
	marklist * new_node;
	new_node=(marklist*)malloc(sizeof(marklist));
	if(new_node!=NULL)
	{
		new_node->roll_no=roll_no;
		strcpy(new_node->name,name);
		new_node->total_marks=total_marks;
		new_node->next=NULL;
	}
	
	return(new_node);
}
/*----------------------------------FIND TOPPER---------------------------------------------------------*/
marklist * topper(node * head)
{
	node * current;
	marklist * toplist,* new_node,* last,* temp,* temp2;
	current= head ;
	int total_marks=0;
	int maxmarks=-1;
	toplist=NULL;
	if(head==NULL)
	{
		printf("THE DATABASE IS EMPTY\n");
	}
	else
	{
	 	while(current!=NULL)
	    {
	    	if(toplist==NULL)
	    	{
	    	 	new_node=create_node_with_total_marks(current->roll_no,current->name,total_marks+current->marks);
	    	 	if(new_node==NULL)
	    	 	{
	    	 	 	("ERROR NO SPACE FOR CREATING THE TOPPERS LIST\n");	
	 			}
	 			else
	 			{
	 			 	new_node->next=toplist;
					last=new_node;
					toplist=new_node;	
		        }
		        	
			}
			else
			{
				if(last->roll_no==current->roll_no)
				{
					last->total_marks=last->total_marks+current->marks;
				}
				else
				{
					new_node=create_node_with_total_marks(current->roll_no,current->name,total_marks+current->marks);
	    	 		if(new_node==NULL)
	    	 		{
	 	 				 ("ERROR NO SPACE FOR CREATING THE TOPPERS LIST\n");	
				    }
	 			    else
	 			    {
	 			 	 	last->next=new_node;
						last=new_node;	
 					} 
				}				
			}
			current=current->next;	
	    }
	    /*print_list_toppers(toplist);*/
		temp=toplist;
		while(temp!=NULL)
		{
			if(temp->total_marks>=maxmarks)
			{
				maxmarks=temp->total_marks;
			}
			temp=temp->next;
			
		}
		
		if(toplist!=NULL)
		{
		 	temp=toplist;
			 while(temp->total_marks!=maxmarks)
			 {
			  	 temp=temp->next;	
			 }
			 toplist=temp;
			 last=temp;
			 temp=temp->next;
			 while(temp!=NULL)
			 {
			 	if(temp->total_marks==maxmarks)
			 	{
			 		temp2=temp;
			 		temp=temp->next;
				    last->next=temp2;
				    last=temp2;
				 }
				 else
				 {
				 	temp=temp->next;
				 }
			 }
			 if(temp==NULL)	
			 {
			 	last->next=NULL;
			 }
	    }
				
	}
	return(toplist);	
}

/*----------------------------------CREATE UNION-------------------------------------------------------*/
node * create_union(node * list1,node * list2)
{
	node * result;
	
	if(list1==NULL)
	{
		return(list2);
	}
	else if(list2==NULL)
	{
		return(list1);
	}
	else
	{
		if(list1->roll_no<list2->roll_no)
		{
			result=list1;
			result->next=create_union(list1->next,list2);
		}
		else if(list1->roll_no>list2->roll_no)
		{
	        result=list2;
			result->next=create_union(list1,list2->next);
			
		}
		else
		{
			if(strcmp(list1->subject_code,list2->subject_code)<0)
			{
				result=list1;
				result->next=create_union(list1->next,list2);
				
			}
			else if(strcmp(list1->subject_code,list2->subject_code)>0)
			{
				result=list2;
				result->next=create_union(list1,list2->next);
				
			}
			else
			{
				result=list1;
				result->next=create_union(list1->next,list2->next);
				
			}
		}
		return(result);
   }
   
}
/*-----------------------------------SYMMETRIC DIFFERENCE---------------------------------------------*/
node * symmetric_difference(node * list1,node * list2 )
{
	node * head1,* head2,* head3 , * head4,* union_head,* intersection_head,* result;
	head1=list1;
	head2=list1;
	head3=list2;
	head4=list2;

	intersection_head=create_intersection(head1,head3);
	printf("THE INTERSECTION IS\n");
	print_list(intersection_head);
	printf("\n");
	printf("\n");
	union_head=create_union(head2,head4);
	printf("THE UNION IS\n");
	print_list(union_head);
	printf("\n");
	printf("\n");
	printf("THE SYMMETRIC DIFFERENCE IS\n");
	result=create_difference(union_head,intersection_head);	
	return(result);	
}
	
/*-----------------------------------CREATE INTERSECTION------------------------------------------------*/
node* create_intersection(node * list1,node * list2)
{
	node * head1,* head2,* head3,* last,* temp;
	head1=list1;
	head2= list2;
	if((head1==NULL)||(head2==NULL))
	{
		head3=NULL;
    }
	else
	{
		if(head1->roll_no<head2->roll_no)
		{
			head3=create_intersection(head1->next,head2);
		}
		else if(head1->roll_no>head2->roll_no)
		{
		 	 head3=create_intersection(head1,head2->next);	
		}
		else
		{
			if(strcmp(head1->subject_code,head2->subject_code)<0)
			{
			 	head3=create_intersection(head1->next,head2);	
			}
			else if(strcmp(head1->subject_code,head2->subject_code)>0)
			{
				head3=create_intersection(head1,head2->next);
			}
			else
			{
			 	head3=head1;
				last=head1;
				last->next=create_intersection(head1->next,head2->next);
					
			}
		}		
    } 
    return(head3);
}
/*------------------------------------------CREATE DIFFERENCE------------------------------------------*/
node* create_difference(node * list1,node* list2)
{
	node * head1,* head2,* head3,* temp,* prev;
	head1=list1;
	head2=list2;       
	if(list1==NULL||list2==NULL)
	{
		head3=list1;
	}
	else
	{
	 	while(head2!=NULL&&head1!=NULL)
	 	{
	 		if(head1->roll_no==head2->roll_no&&strcmp(head1->subject_code,head2->subject_code)==0)
	 		{
	 		 	 temp=head1;
				   head1=head1->next;
				   list1=head1;
				   free(temp);
				   prev=NULL;	
		    }
		    head2=head2->next;
	    }
	    head2=list2;
	    prev=NULL;
	    while(head1!=NULL&&head2!=NULL)
	    {
	    	if(head1->roll_no>head2->roll_no)
	    	{
	    		head2=head2->next;
			}
			else if(head1->roll_no<head2->roll_no)
			{
				prev=head1;
				head1=head1->next;
			}
			else
			{
				if(strcmp(head1->subject_code,head2->subject_code)>0)
				{
					head2=head2->next;
				}
				else if(strcmp(head1->subject_code,head2->subject_code)<0)
				{
					prev=head1;
					head1=head1->next;
				}
				else
				{
					temp=head1;
					prev->next=head1->next;
					head1=head1->next;
					free(temp);
					head2=head2->next;
				}
			}
		}
		head3=list1;  
	}
	return(head3);
}
/*----------------------------------------GET FAILURES--------------------------------------------------*/
void get_failures(int p,int k,node * head)
{
	node * current,* prev, * failures,* new_node;
	int sub_count=1;
	failures=NULL;
	if(head==NULL)
	{
		printf("THE DATABASE IS EMPTY\n");
	}
	else
	{
		current=head;
		while(current!=NULL)
		{
			if(current->marks<p)
			{
			 	new_node=create_new_node(current->name, current->roll_no,current->subject_code,current->marks);
		 		insert(&failures,new_node);	
			}
			current=current->next;
		}
	}
	if(failures==NULL)
	{
		printf("NO FAILURES ACCORDING TO THE MENTIONED CRITERIA\n");
	}
	else if(failures->next==NULL)
	{
		if(k==0)
		{
			printf("NAME:%s\t ROLL NO:%d\t IS A FAILURE\n",failures->name,failures->roll_no);
		}
		else
		{
			printf("NO FAILURES ACCORDING TO THE MENTIONED CRITERIA\n");
		}
		
	}
	else
	{
		prev=failures;
		current=prev->next;
		while(current!=NULL)
		{
			if(prev->roll_no==current->roll_no)
			{
				sub_count++;
				if(sub_count>k)
				{
					sub_count=1;
					printf("NAME:%s\t ROLL NO:%d\t IS A FAILURE\n",prev->name,prev->roll_no);
					while(current!=NULL&&prev->roll_no==current->roll_no)
					{
						prev=current;
						current=current->next;
					}
				}
				else
				{
				 	prev=current;
					current=current->next;	
				}
			}
			else
			{
				prev=current;
				current=current->next;
			}
			
		}
	}
	free(failures);
}
		
/*--------------------------------------------GET UNIQUE------------------------------------------------*/
status_code  unique(node ** head)
{
 	 node * temp,* prev,*current;
 	 status_code status=FALSE;
 	 if(((* head)!=NULL)&&((* head)->next!=NULL))
 	 {
	     prev=*head;
	     current=prev->next;
		 
		 while(current!=NULL)
		 {
			     if((prev->roll_no==current->roll_no)&&(strcmp(prev->subject_code,current->subject_code)==0))
				 {
				 	temp=current;
				 	current=current->next;
				 	prev->next=current;
				 	free(temp);
				 	status=TRUE;
	             } 
				 else
				 {
				 	prev=current;
			     	current=current->next;
				 } 
	      } 
	      if(current==NULL&&status==FALSE)
	      {
	      	 status=FALSE;
		  }
	      
	  }
	  else
	  {
	  	  printf("TO REMOVE THE DUPLICATES ATLEAST 2 RECORDS MUST BE ENTERED\n");
	  	  status=FALSE;
	  }
	return(status);
}
/*------------------------------------------k_th_popular_subject-----------------------------------------*/

void k_th_popular_subject(node * list,int k)
{
	int no_of_records;
	int sum;
	int i;
	int avg;
	int count=0;
	node * iptr,* jptr,* new_node,* popular,* p,* mp,* result,*t;
	popular=NULL;
	if(list==NULL)
	{
		printf("THE LIST IS EMPTY\n");
	}
	else if(list->next==NULL)
	{
		printf("THE K TH POPULAR SUBJECT IS %s\n",list->subject_code);
	}
	else if((list!=NULL)&&(list->next!=NULL))
	{
		for(iptr=list;iptr!=NULL;iptr=iptr->next)
		{
			iptr->status=0;
		}
		for(iptr=list;iptr!=NULL;iptr=iptr->next)
		{
	 	    no_of_records=1;
	 	    sum=iptr->marks;
			if(iptr->status!=-1)
			{	         
				for(jptr=iptr->next;jptr!=NULL;jptr=jptr->next)
				{
				 	if(strcmp(iptr->subject_code,jptr->subject_code)==0&&jptr->status!=-1)
                    {
				          sum=sum+jptr->marks;
				          no_of_records++;
				          jptr->status=-1;
					 	
			        }	
				}				
				new_node= create_new_node(iptr->subject_code,sum/no_of_records,iptr->subject_code,no_of_records);
				insert(&popular,new_node);			
			}
			
		}		
	}
	no_of_records=getnumrecords(popular);
	//print_list(popular);
	if(k>no_of_records)
	{
		printf("ENTER A VALID K\n");
	}
	
	else
	{
		if(popular!=NULL)
		{
			p=popular;
			while(p!=NULL&&(p->next)!=NULL&&count<(no_of_records-k-1))
			{
				if(p->roll_no!=(p->next)->roll_no)
				{
					count++;
				}
				p=p->next;
			}
		}
		avg=p->roll_no;
		iptr=popular;
		while(iptr!=NULL)
		{
			if(iptr->roll_no==avg)
			{
				printf("avg:%d\t subject:%s\t records:%d\t----->\n",iptr->roll_no,iptr->subject_code,iptr->marks);
				
			}
			iptr=iptr->next;
		}
		
	}
		
}

/*----------------------------------END--------------------------------------------------------------*/

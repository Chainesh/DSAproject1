#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//   declarations of functions
int search(int);
int display();
int back();
int check(int);       //   for checking quantity
int value=0;
 //   build a node
struct node {
	int ID;
	char proName[100];
	double prePrice;            //   product price
	int quantity;
struct    node* next;
};
struct node *head=NULL;
//      for entering(saving) 1st record in list
 void beg()
{
	system("cls");
	int id,quant;           //  quant    for quantity
	char name[100];
	double pre;            //  pre for price
	struct node *t =(struct node*) malloc(sizeof(struct node));

	printf("\t\t\tEnter product ID:-");
	scanf("%d",&id);
	t->ID=id;
	printf("\t\t\tEnter product Name:-");
	scanf("%s",name);
	for(int i=0;i<100;i++){
	t->proName[i]=name[i];}
	printf("\t\t\tEnter product price:-");
	scanf("%lf",&pre);
	t->prePrice=pre;
	printf("\t\t\tEnter product quantity:-");
	scanf("%d",&quant);
	t->quantity=quant;
	t->next=head;
	head=t;
	system("cls");
		printf("\n\n\t\t\t\tThis product is Inserted!\n\n\n");
	}
// for entering(saving) 2nd and onward records in list
	void end()
	{
	system("cls");
	int id,quant;      //   quant for quantity
	char name[100];
	double pre;            //  pre for price
	struct node *t=(struct node*) malloc(sizeof(struct node));
	struct node *p=head;
	printf("\t\t\tEnter product ID:-");
	scanf("%d",&id);
	t->ID=id;
	printf("\t\t\tEnter product Name:-");
	scanf("%s",name);
	for(int i=0;i<100;i++){
	t->proName[i]=name[i];}
	printf("\t\t\tEnter product price:-");
	scanf("%lf",&pre);
	t->prePrice=pre;
	printf("\t\t\tEnter product quantity:-");
	scanf("%d",&quant);
	t->quantity=quant;
		while(p->next!=NULL)
		{
		p=p->next;
		}
			p->next=t;
			t->next=NULL;
		system("cls");
		printf("\n\n\t\t\t\tThis product is Inserted!\n\n\n");
	}
	void delPro()
	{
		system("cls");
		display();
		int id;
		struct node *cur=head;
		struct node *pre=head;
		printf("\n\nEnter ID to delete that product:\n\n");
		scanf("%d",&id);
		 if (head == NULL)
        {
            system("cls");
            printf("List is empty\n");
        }
	int pos=0;
	int count=display();               //   for load no of nodes
	pos=search(id);                        //   for check weather desire node is exist or not
	if(pos<=count){

		while(cur->ID!=id){                //  for delete middle area products
			pre=cur;
			cur=cur->next;
}
		pre->next=cur->next;
		system("cls");
		printf("\n<<item is deleted>>\n");
	}else{
		printf("\n<<<Not found>>\n\n");
	}
	}
	void modify(){
		int id;
		double pre;        //    pre for price
		char pName[100];      //   pName for new name
		if (head == NULL)
    {
    	system("cls");
        printf("List is empty\n");
    }else
	{
		printf("\n\nEnter ID to modify product Name and its price:\n");
		scanf("%d",&id);
		struct node *cur=head;
		int pos=0;
		int count=display();               //   for load no of nodes
	pos=search(id);                        //   for check weather desire node is exist or not
	if(pos<=count){

		while(cur->ID!=id){
			cur=cur->next;
		}
		printf("\nOld Name : ");
		printf("%s",cur->proName);
		printf("\nOld Price : ");
		printf("%lf\n",cur->prePrice);
		printf("Enter new Name: ");
		scanf("%s",pName);
		for(int i=0;i<100;i++){
		cur->proName[i]=pName[i];}
		printf("Enter new Price:");
		scanf("%lf",&pre);
		cur->prePrice=pre;
	}else{
	    printf("%d is <<Not found>>\n\n",id);
	}
	}
}
int display(){
		system("cls");
		int c=0;             //   c for count products
		struct node *p=head;
		printf("Existing products are:\n");
		printf("ID\t\tProduct Name\t\tPrice\t\tQuantity\n");
		while(p!=NULL)
		{
		    printf("%d\t\t%s\t\t\t%lf\t",p->ID,p->proName,p->prePrice);//    call   check func and pass quantity
            if(check(p->quantity)<=0)
                printf("OUT OF STOCK!\n");
            else
                printf("%d\n",check(p->quantity));
			p=p->next;
			c=c+1;
		}
		printf("\nTotal products in our store is : %d\n\n\n",c);
		return c;
	    }
int check(int quant){              //        check function
    int a = quant;
        if(quant<=0)
            return 0;
        else
	    	return quant;
		}
void buy(){
		system("cls");
		int pay=0,no,price,id,i=1;
    if(head==NULL) {
        printf("\n<<<<There is no items to buy>>>>\n\n");
	}
	else{
		printf("How many items you want to buy!\n");
		scanf("%d",&no);
			int count=display();           //   for store no of nodes  in c
    while (i<=no){
        struct node *cur=head;

        int quant;              //   quant   for quantity
        printf("Enter id of item that you want to buy: ");
        int id,pos=0;
        scanf("%d",&id);
        pos=search(id);
        if(pos<=count){
	                        //     item is available in store
		while(cur->ID!=id){
			cur=cur->next;
		}
        printf("How many quantities you want:");
        scanf("%d",&quant);
        pay=pay+(cur->prePrice*quant);         //     calculate Bill
        cur->quantity=cur->quantity-quant;           //    change quantity
        i++;
        printf("\n\n\t\t\tYou have bought : ");
        printf("%s\n\n",cur->proName);
	}
	else{
		printf("\n<<<<<<<<<This item is not available in our store at this time>>>>\n\n");
	    }
}
}
    price=pay*(0.90);           //    with 5% discount
	printf("\n\n\t\t\t\t\tOriginal price : %d\n",pay);
    printf("\t\t\t\t\twith 10 percent discount:   %d\n\t\t\t\t\tThank you! for the shopping\n\n",price);
}


	int search(int id)                     //    for search item in list
 {
 	int count=1;
 	struct node *p=head;
 	while(p!=NULL)
 	{
 		if(p->ID==id)
 			break;
 		else
 			count++;
 			p=p->next;
	}
 	return count;
 }
 int back()
 {
     int no,i=1,give=0;
     printf("How many items you want to return!\n");
		scanf("%d",&no);
		int count=display();
		while (i<=no){
			struct node *cur=head;
			int quant,cho;              //   quant   for quantity  and cho for choice
    printf("Enter the id of product you want to return");
    int id,pos=0;
	scanf("%d",&id);
	pos=search(id);
	if(pos<=count){
	                        //     item is available in store
		while(cur->ID!=id){
			cur=cur->next;
		}
    printf("\n\nHow many quantities you want to return\n\n");
	scanf("%d",&quant);
    give=give+(cur->prePrice*quant);         //     calculate Bill
	cur->quantity=cur->quantity+quant;
	i++;
	}
		}
		printf("\n\n\t\t\t\tYou will get %d rs back",give);
 }
	                        //        Main function
int main(){
    int flag,flag1;
    printf("<<<<<<<<<<<<<<<<<<<<<<<<   SuperMarket   >>>>>>>>>>>>>>>>>>>>\n");              //  \xB2  is for styling
	printf("<<<<<<<<<<<<<<<<<<<<<<<<   Store         >>>>>>>>>>>>>>>>>>>>\n\n\n");
	int temp=1;
	while(1)
    {
    int cm;
    flag=1;
    flag1=1;
	printf("\t\tEnter 1 for Shopkeeper portal \n\n\t\tEnter 2 for Customer portal\n\n\t\tEnter 0 for exit\n\n");
	printf("*********>>>>>***********>>>>>>>>");
	scanf("%d",&cm);
	switch(cm)
	{
    case 1 :
    while(flag){
	int ch;                     //            choice for below message
	printf("\t\tEnter 1 for ADD a new product \n\n\t\tEnter 2 to display all products \n\n\t\tEnter 3 for MODIFY Existing product\n\n");
	printf("\t\tEnter 4 for Delete a particular product item\n\n\t\tEnter 0 for exit\n\n");
	printf("*********>>>>>***********>>>>>>>>");
    scanf("%d",&ch);
	switch(ch){
	case 1:
	if (temp==0){              //    Second time and on ward this is only executed
	end();
	}
	if(temp==1){
    value++;                   //    this will be executed only one time
	beg();
	temp=0;
	}
	break;
    case 2:
	system("cls");
	display();
    break;
    case 3:
	modify();
	break;
    case 4:
	delPro();
	break;
    case 0:
        printf("Exiting...\n");
	    flag=0;                //   exit from while loop
        break;
    default:
         system("cls");
         printf("\t\t<<<Wrong choice>>>\n\n");
         break;
	}
	}
break;
case 2:
    while(flag1)
    {
        int cd;
      printf("\n\n\t\tEnter 1 To buy something\n\n\t\tEnter 2 to return something\n\n\t\tEnter 0 for exit\n\n");
      printf("*********>>>>>***********>>>>>>>>");
      scanf("%d",&cd);
       switch(cd)
       {
       case 1 :
           buy();
	       break;
       case 2 :
        back();
        break;
       case 0 :
        printf("Exiting...\n");
	    flag1 = 0;                    //   exit from while loop
        break;
        default: system("cls");
           printf("\t\t<<<Wrong choice>>>\n\n");
           break;
       }
    }break;
    case 0 :
        printf("Exiting...\n");
	    exit(1);                    //   exit from while loop
        break;
    default: system("cls");
        printf("\t\t<<<Wrong choice>>>\n\n");
        break;

}
    }
}


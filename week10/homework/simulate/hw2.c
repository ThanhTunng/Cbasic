#include "queueHw2.h"
pro func[10];
int main(){
	queue* Q;
	Init_q(Q);
	int num, mem, remain;
	

	printf("Number of parallel processes: "); scanf("%d", &num);
	for(int  i = 0; i<num; i++) func[i].mark = 0;

	printf("Memory capacity(MB): "); scanf("%d", &mem);
	remain = mem ;
	int num_q = -1;
	int option;
	do
	{
		printf("==================MENU==================\n\n * 1.Create new program\n * 2.Kill program\n * 3.Show the status of running and waiting processes\n * 4.Quit\n\n");
		printf("----------------------------------------\n");
		printf("Your choice: "); scanf("%d", &option);
		switch(option){
			case 1:
			if(num_q==-1){
				printf("* 1. Create new program (1st time)\n");
			}
			else if(num_q==0) printf("* 1. Create program (2nd time)\n");
			else printf("* 1. Create waiting program in queue\n");
			int idi, size;
			printf(" - The memory size of program: "); scanf("%d",&size);
			printf(" - Program ID: "); scanf("%d", &idi);
			if(size <= remain && num_q < num-1){
				printf("=> Successful. Program created\n");
				num_q++;
				func[num_q].mark = 1;
				func[num_q].id = idi; func[num_q].memory = size;
				remain = remain - size;
			}
			else{
				printf("=> In queue\n");
				Enqueue(Q, idi, size);
			}
			break;

			case 2:
			printf("* 2. Kill a program\n\n");
			if(num_q==-1) printf("No running program\n");
			else{
				printf("ID: ");
				int idk, count = 0;
				scanf("%d", &idk);
				
				for(int i=0; i<=num; i++){
					if(func[i].mark==1){
						if(idk==func[i].id) {
							func[i].mark =0;
							remain += func[i].memory;
							count =1;
							num_q --;
							if(!isEmpty_q(*Q) && remain >= Q->front->next->data2){
								func[i].id = Q->front->next->data1;
								func[i].memory = Q->front->next->data2;
								func[i].mark = 1;
								num_q++;
								Dequeue(Q);
							}
						}
					}

				}
				
				if(count==0) printf("ID not match!!!\n");
				else printf("Success\n");
			}
			break;

			case 3:
			printf("* 3. Show the status\n\n");
			if(isEmpty_q(*Q) && num_q==-1) printf("No running program\n\n");
			else if(!isEmpty_q(*Q) && num_q==-1 ){
				printf("%-10s%-10s\n\n","ID", "QUEUE");
				node* t = Q->front->next;
				while(t!=NULL){
					printf("%-10d%-10d\n",t->data1, t->data2);
					t = t->next;
				}
			}
			else if(isEmpty_q(*Q) && num_q!= -1){
				printf("%-10s%-10s\n\n","ID","MEMORY");
				for(int i = 0; i<num;i++){
					if(func[i].mark==1) printf("%-10d%-10d\n",func[i].id, func[i].memory );
				}				
			}

			else{
				printf("%-10s%-10s%-10s\n\n", "ID", "MEMORY", "QUEUE");
				for(int i = 0; i<num;i++){
					if(func[i].mark==1) printf("%-10d%-10d\n",func[i].id, func[i].memory );
				}				
				node* t1 = Q->front->next;
				while(t1!=NULL){
					printf("%-10d%-10s%-10d\n",t1->data1," ", t1->data2);
					t1 = t1->next;
				}

			}

			break; 
		case 4:{
		  printf("You've exit the application\n");
		  break;
		}
		default: {
		  printf("Try again!!\n\n");
		  getchar();
		  break;
		}
	} while (option!=4);
}


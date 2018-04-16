//*************************** question 8*********************************

#include<stdio.h>
struct processDetails{
	int pid,burst, wtt, art,rtt,trt,prio,visit;
};

void sort(struct processDetails pros[], int N){
	int i,j;
	struct processDetails p;
	for(i=0;i<N;i++){
		for(j=i;j<N;j++){
			if(pros[i].prio<pros[j].prio){
				p = pros[i];
				pros[i] = pros[j];
				pros[j] = p;
			}else if(pros[i].prio==pros[j].prio && pros[i].pid>pros[j].pid){
				p = pros[i];
				pros[i] = pros[j];
				pros[j] = p;				
			}
		}
	}
}


int main(){
	
	struct processDetails pros[20];
	int flag,Npro,remain,quantum,time,tmpquant,noiter,tmpwt,threshold;
	int i,j,track,m;
	m=0;
	
	printf("Enter Number of Processes: ");
	scanf("%d",&Npro);
	remain = Npro;
	for(i=0;i<Npro;i++){
		printf("Priority | Arival Time | Burst Time for process %d: ",i+1);
		scanf("%d%d%d",&pros[i].prio,&pros[i].art,&pros[i].burst);
		pros[i].pid = i+1;
		pros[i].wtt = 0;
		pros[i].rtt = pros[i].burst;
		pros[i].visit = 0;
	}
		
	printf("Enter quantum time: ");
	scanf("%d",&quantum);
	tmpquant = quantum;
	i=0;
	time=0;
	flag=0;
	noiter=0;
	threshold=0;
	track = 0;
	while(remain!=0){
		if(pros[i].rtt>0 && pros[i].art<=time){
			printf("%d P%d ",time,pros[i].pid);
			if(pros[i].rtt<=quantum){
				tmpquant = pros[i].rtt;
				flag = 1;
			}
			pros[i].rtt -= tmpquant;
			tmpwt = time - pros[i].art;
			if(tmpwt<0)
				tmpwt = 0;
			pros[i].wtt = pros[i].wtt + tmpwt;
			time = time + tmpquant;	
			pros[i].art = time;
			noiter=1;
			if(pros[i].rtt<=0){
				pros[i].trt = time;
			}
			pros[i].visit = 1;
		}
		if(flag==1){
			remain--;
			flag = 0;
		}
		i++;		
		tmpquant = quantum;
		if(i>=Npro){
			track++;
			i = 0;
			if(noiter==0){
				time++;
			}
			noiter=0;
			for(j=0;j<Npro;j++){
				if(pros[j].visit == 1)
					threshold++;
			}
			sort(pros, threshold);
			threshold=0;
		}
	}
	printf("%d",time);


	printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");
	for(i=0;i<Npro;i++){
		printf("\n%d\t%d\t\t\t%d\t\t%d",pros[i].pid,pros[i].burst,pros[i].wtt,pros[i].trt);
	}
	printf("\nTotal time: %d",time);
	
	sort(pros, 9);
	return 0;
}
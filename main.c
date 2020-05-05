#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int c,char*v[])
{
	return c
	?
		v[0]=v[1],
		v[1]=malloc(strlen(v[0])+1),
		strcpy(v[1],v[0]),
		v[0]=malloc(sizeof(int)*10),
		(*(int**)v)[1]=atoi((char*)v[2]),//read start state from second arg and put in 1
		(*(int**)v)[2]=0,//put zero into tape pos in 2
		(*(int**)v)[3]=3,//start current instruction in 3
		(*(int**)v)[4]=c,//save number of instructions in 4
		(*(int**)v)[5]=0,//set target_state to 0 in 5
		(*(int**)v)[6]=0,//set target_char to 0 in 6
		(*(int**)v)[7]=0,//set next_state to 0 in 7
		(*(int**)v)[8]=0,//set next_char to 0 in 8
		(*(int**)v)[9]=0,//set direction to 0 in 9
		//print tape (2)
		**(int**)v=2,main(0,v),

		//call search function (0)
		**(int**)v=0,main(0,v),

		free(v[0]),
		free(v[1]),
	0:
		(**(int**)v==0?//check this instruction
			(*(int**)v)[3]>=(*(int**)v)[4]//check if current instruction is in bounds
			?
				puts("done"),
				exit(0),
				//if it is not in bounds, we just do nothing and function returns which ends program through massive stack rewind
			0:
//				puts("scan called"),
				//read in this instruction
				sscanf(v[(*(int**)v)[3]],"%d%c%d%c%c",*(int**)v+5,(char*)(*(int**)v+6),*(int**)v+7,(char*)(*(int**)v+8),(char*)(*(int**)v+9)),
//				printf("cs:%d, ts:%d, tc:%c, cc:%c\n",(*v)[1], (*v)[5], *(char*)(*v+6), ((char*)v[1])[(*v)[2]]),
				(*(char*)(*(int**)v+6)==(v[1])[(*(int**)v)[2]])&&((*(int**)v)[1]==(*(int**)v)[5])//if current state equals target state and tape at head equals target char we have a match
				?
//					puts("match gotten"),
					**(int**)v=1,main(0,v),//call step function
//					puts("finished step"),
					(*(int**)v)[3]=3,//reset current instruction
//					puts("About to call check again"),
					**(int**)v=0,main(0,v),//call check again
				0:
//					puts("miss had"),
					(*(int**)v)[3]++,//increment current instruction
					**(int**)v=0,main(0,v),//call check again
//				0,
//			0,
		**(int**)v=-1:0),
		(**(int**)v==1?//run a step
//			puts("step called"),
//			printf("cs: %d,ns: %d\n",(*v)[1],(*v)[7]),
			(*(int**)v)[1]=(*(int**)v)[7],//update state
//			printf("cs: %d\n",(*v)[1]),
			v[1][(*(int**)v)[2]] = *((char*)((*(int**)v)+8)),//update tape
//			printf("cs:%d, ts:%d, tc:%c, cc:%c\n",(*v)[1], (*v)[5], *(char*)(*v+6), ((char*)v[1])[(*v)[2]]),
			*(char*)((*(int**)v)+9)=='r'//check movement
			?
				(*(int**)v)[2]++,//if it is right, increment pos
			0:
				(*(int**)v)[2]--,//if it is left, decrement pos
//			0,
			(*(int**)v)[2]<0//check if new pos is below zero
			?
				puts("Fell off left side of tape"),
				exit(1),//if it is we bail
			0:
				//otherwise we do nothing
			0,
			v[1][(*(int**)v)[2]]=='\0' //check if new pos has led us to null char
			?
				puts("Fell off right side of tape"),
				exit(1),//if it was we bail
			0:
				//otherwise do nothing
			0,
			**(int**)v=2,main(0,v),//call print tape
		**(int**)v=-1:0),
		(**(int**)v==2?//print state and tape
			printf("s:%d, t:%s\n",(*(int**)v)[1],v[1]),
		**(int**)v=-1:0),
	0;
}

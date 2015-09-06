#include<sys/sem.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<sys/types.h>
int obtain_sem(int key,int nums)
{return semget(key,nums,IPC_CREAT|0777);
}
void up(int semid)
{struct sembuf SOPS[1]={{0,1,0}};
 semop(semid,SOPS,1);
}
void down(int semid)
{struct sembuf SOPS[1]={{0,-1,0}};
 semop(semid,SOPS,1);
}
sem_init(int semid,int semnum,int val)
{semctl(semid,semnum,SETVAL,val);
}
int obtain_shm(int key,int size)
{return shmget(key,size,IPC_CREAT|0777);
}
void *shm_at(int shmid)
{shmat(shmid,0,0);
}
int *buf,*lock;
int lock_id,buf_id,eslots,fslots;
producer()
{int head=0; 
 buf=shm_at(buf_id);
 while(1)
 {if(lock[0])
  {down(eslots);
   buf[head]=rand()%100;
   printf("\n%d produced\n",buf[head]);
   head=(head+1)%10;
   up(fslots);
  }
 }
}
consumer()
{int tail=0;
 buf=shm_at(buf_id);
 while(1)
 {if(lock[1])
  {sleep(1);
   down(fslots);
   printf("\nconsumed %d\n",buf[tail]);
   tail=(tail+1)%10;
   up(eslots);
  }
 }
}
suspend()
{char ch;
 while(1)
 {ch=getchar();
  if(ch=='p') 
  lock[0]=0;
  else if(ch=='c') 
  lock[1]=0;
  else if(ch=='r')
  lock[0]=lock[1]=1;
  else if(ch=='q')
  system("killall a.out");
  }
}
main()
{buf_id=obtain_shm(10,10);
 lock_id=obtain_shm(11,2);
 lock=shm_at(lock_id);
 lock[0]=lock[1]-1;
 eslots=obtain_sem(110,1);
 fslots=obtain_sem(120,1);
 sem_init(eslots,0,10);
 sem_init(fslots,0,0);
 if(fork()==0)
 suspend();
 else 
 {if(fork()==0)
   producer();
  else 
   consumer();
 }
}

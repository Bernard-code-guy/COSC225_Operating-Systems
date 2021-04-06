// Question: Write a C++ program to simulate the following contiguous memory allocation techniques
//a) Worst-fit b) Best-fit c) First-fit

 //ID               -                  NAME
 //219CS01000078                       Blege Bright Edem
 //219CS01000037                       Mensah Bernard
 //219EI01000036                       Kodom Stephen



#include <iostream>
#include <stdio.h>
#include<conio.h>
#include <cstdlib>
#include <string>

using namespace std;

// Menu choice declaration
int choice;

// All the functions in the program declaration
void menu();
void start();
void worstFit();
void bestFit();
void firstFit();
void MFT();
void MVT();
void pagingTechnique();
void firstComeFirstServe();
void shortestJobNext();
void roundRobin();
void priority();
void banker_sAlgorithm();

// Main function
int main()
{
    // The program starts from here
    system("color 1f");
    start();

    // Returns no value to operating system
    return 0;
}

// Menu function for selecetion
void menu(){

// Displays a message in the console
cout <<"************************************OS MANAGEMENT SYSTEM***********************************";
    cout <<"\n*******************************************************************************************";
    cout <<"\n*********************************MENU**********************************************************";
    cout << "\n\n1. \t\tFIRST-FIT" ;
    cout << "\n\n2. \t\tBEST-FIT";
    cout << "\n\n3. \t\tWORST-FIT";
    cout << "\n\n4. \t\tMFT" ;
    cout << "\n\n5. \t\tMVT";
    cout << "\n\n6. \t\tPAGING SYSTEM";
    cout << "\n\n7. \t\tFIRST-COME-FIRST-SERVE";
    cout << "\n\n8. \t\tSHORTEST-JOB-FIRST/NEXT";
    cout << "\n\n9. \t\tROUND ROBIN";
    cout << "\n\n10. \t\tPRIORITY";
    cout << "\n\n11. \t\tBANKER'S ALGORITHM";
    cout << "\n\n12.  \t\tEXIT";

    //  Selection
    cout << "\n\nChoice: ";
    cin >> choice;

    // The choice switch statement
    switch(choice){

    // When user selects "1" from menu
case 1:
    // Worst-Fit method is called
        firstFit();
        break;
    // When user selects "2" from menu
case 2:
    // Best-Fit method is called
        bestFit();
        break;
     // When user selects "3" from menu
case 3:
    // First-Fit method is called
        worstFit();
        break;
     // When user selects "4" from menu
case 4:
        MFT();
        break;
        // When user selects "5" from menu
case 5:
        MVT();
        break;
        // When user selects "6" from menu
case 6:
        pagingTechnique();
        break;
case 7:
         firstComeFirstServe();
        break;

case 8:
        shortestJobNext();
        break;

case 9:
        roundRobin();
        break;

case 10:
        priority();
        break;

case 11:
        banker_sAlgorithm();
        break;
case 12:
    // The program terminates suddenly
        cout << "\n\nClosing application.....";
        exit(0);
        break;
     // When user selects wrong number from menu
default:
            cout << "\n\nPlease you entered wrong input..";
            cout <<"\n\nEnter between (1-7)..";
            cout <<"\n\nPress any key..";
            getch();
// The program goes back to the main menu
menu();

}
}


void start(){
// The main menu is called when program starts
 menu();
}


// Worst-Fit function processing
void firstFit(){
    // Maximum fragmentation size
    const int max = 25;

    // All the variables used in the method declaration
    int frag[max],blockSize[max],fileSize[max],i,j,numBlocks,numFiles,temp;

         static int bf[max],ff[max];

        // Clears the console screen
        system("cls");

        // Displays a message
        cout <<"***********************MEMORY MANAGEMENT SCHEME***************************";
        cout <<"\n**************************************************************************";
        cout <<"\n*******************************FIRST-FIT**********************************";
        cout <<"\n**************************************************************************";

        // Requesting and getting input
        cout << "\n\nPlease enter the number of memory blocks... ";
        cin >> numBlocks;
        cout << "\nEnter the number of files... ";
        cin >> numFiles;

        //Prompt for entering size of each block
        cout << "\nEnter the size of the blocks below:";

        // Loops through each block to receive its size
        for(i=1;i<=numBlocks;i++){
            cout <<"\nBlock "<<i<<": ";
            cin >> blockSize[i];
        }

        cout << "\nEnter the size of the files below:";

        // Loops through each file to receive its size
        for(i=1;i<=numFiles;i++){
            cout <<"\nFile "<<i<<": ";
            cin >> fileSize[i];
        }

        for(i=1;i<=numFiles;i++){
            for(j=1;j<=numBlocks;j++){
                if(bf[j]!=1){
                    temp=blockSize[j]-fileSize[i];
                    if(temp>=0){
                        ff[i]=j;
                         break;
                    }
                }
            }

            frag[i]=temp;
            bf[ff[i]]=1;
        }

    cout <<"\n*************************************************************************************";
    cout << "\nFILE NO:\tFILE SIZE:\tBLOCK NO:\tBLOCK SIZE:\tFRAGMENTATION";
    for(i=1;i<=numFiles;i++){
         cout <<"\n"<<i<<"\t\t"<<fileSize[i]<<"\t\t"<<ff[i]<<"\t\t"<<blockSize[ff[i]]<<"\t\t"<<frag[i];
    }

    cout <<"\n*************************************************************************************";
    cout << "\n\nPress any key to go back to menu...... ";
    getch();
    system("cls");
menu();
}

// Best-Fit function processing
void bestFit(){
    // Maximum fragmentation size
    const int max = 25;

    // All the variables used in the method declaration
    int frag[max],blockSize[max],fileSize[max],i,j,numBlocks,numFiles,temp,lowest = 10000;
    static int bf[max],ff[max];

    // Clears the console screen
    system("cls");

    // Displays a message
        cout <<"***********************MEMORY MANAGEMENT SCHEME***************************";
        cout <<"\n**************************************************************************";
        cout <<"\n*******************************BEST-FIT**********************************";
        cout <<"\n**************************************************************************";

        // Requesting and getting input
        cout << "\n\nPlease enter the number of memory blocks... ";
        cin >> numBlocks;
        cout << "\nEnter the number of files... ";
        cin >> numFiles;

        //Prompt for entering size of each block
        cout << "\nEnter the size of the blocks below:";

        // Loops through each block to receive its size
        for(i=1;i<=numBlocks;i++){
            cout <<"\nBlock "<<i<<": ";
            cin >> blockSize[i];
        }

        cout << "\nEnter the size of the files below:";

        // Loops through each file to receive its size
        for(i=1;i<=numFiles;i++){
            cout <<"\nFile "<<i<<": ";
            cin >> fileSize[i];
        }

        // Loops through each file to receive its size
        for(i=1;i<=numFiles;i++){

            for(j=1;j<=numBlocks;j++){

                 if(bf[j]!=1){

                    temp=blockSize[j]-fileSize[i];
                        if(temp >= 0){
                            if(lowest > temp){
                                ff[i] = j;
                                lowest = temp;
                            }
                        }

                 }


            }

                frag[i]=lowest;
                bf[ff[i]]=1;
                lowest=10000;
        }


    cout <<"\n\n*************************************************************************************";
    cout << "\nFILE NO:\tFILE SIZE:\tBLOCK NO:\tBLOCK SIZE:\tFRAGMENTATION";
    for(i=1;i<=numFiles;i++){
         cout <<"\n"<<i<<"\t\t"<<fileSize[i]<<"\t\t"<<ff[i]<<"\t\t"<<blockSize[ff[i]]<<"\t\t"<<frag[i];
    }
    cout <<"\n\n*************************************************************************************";

    cout <<"\nPress any key to go back to main menu...";
    getch();
    system("cls");
menu();
}

// First-Fit function processing
void worstFit(){
    // Maximum fragmentation size
    const int max = 25;

    // All the variables used in the method declaration
    int frag[max],blockSize[max],fileSize[max],i,j,numBlocks,numFiles,temp,highest = 0;
    static int bf[max],ff[max];

     // Clears the console screen
    system("cls");

    // Displays a message
        cout <<"***********************MEMORY MANAGEMENT SCHEME***************************";
        cout <<"\n**************************************************************************";
        cout <<"\n*******************************WORST-FIT**********************************";
        cout <<"\n**************************************************************************";

        // Requesting and getting input
        cout << "\n\nPlease enter the number of memory blocks... ";
        cin >> numBlocks;
        cout << "\nEnter the number of files... ";
        cin >> numFiles;

        //Prompt for entering size of each block
        cout << "\nEnter the size of the blocks below:";

        // Loops through each block to receive its size
        for(i=1;i<=numBlocks;i++){
            cout <<"\nBlock "<<i<<": ";
            cin >> blockSize[i];
        }

        cout << "\nEnter the size of the files below:";

        // Loops through each file to receive its size
        for(i=1;i<=numFiles;i++){
            cout <<"\nFile "<<i<<": ";
            cin >> fileSize[i];
        }

        // Loops through each file to receive its size
        for(i=1;i<=numFiles;i++){

            for(j=1;j<=numBlocks;j++){

                 if(bf[j]!=1){

                    temp=blockSize[j]-fileSize[i];
                        if(temp >= 0){
                            if(highest < temp){
                                ff[i] = j;
                                highest = temp;
                            }
                        }

                 }


            }

                frag[i]=highest;
                bf[ff[i]]=1;
                highest=0;
        }

    cout <<"\n\n*************************************************************************************";
    cout << "\nFILE NO:\tFILE SIZE:\tBLOCK NO:\tBLOCK SIZE:\tFRAGMENTATION";
    for(i=1;i<=numFiles;i++){
         cout <<"\n"<<i<<"\t\t"<<fileSize[i]<<"\t\t"<<ff[i]<<"\t\t"<<blockSize[ff[i]]<<"\t\t"<<frag[i];
    }
    cout <<"\n\n*************************************************************************************";


    cout <<"\nPress any key to go back to main menu...";
    getch();
    system("cls");
    menu();

}


void MFT(){
    // Variables (i.e Memory size, Number of blocks , External Fragmentation, Number of processes, Memory Processes, Internal fragmentation
int memSize,blockSize,numBlocks,exFragmentation,numProcess,memProcess[10],totalInFragmentation=0;

    // Counter & p
    int i,p=0;

     //Screen clear
        system("CLS");

    // Displays a message
        cout <<"***********************MEMORY MANAGEMENT SCHEME***************************";
        cout <<"\n**************************************************************************";
        cout <<"\n*******************************MFT**********************************";
        cout <<"\n**************************************************************************";



    // Memory size input prompt
    cout << "\nPlease enter the total memory available(in Bytes).... ";
    cin >> memSize;

    // Block size input prompt
    cout << "Enter the block size( in Bytes)... ";
    cin >> blockSize;

    //Number of Blocks
    numBlocks = memSize/blockSize;
    // External Fragmentation
    exFragmentation = memSize - numBlocks * blockSize;

        // Process Input Prompt
    cout << "Enter the number of processes....... ";
    cin >> numProcess;

    // Looping through the number of processes
    for(i = 0; i < numProcess ; i++){
    // Memory required input prompt
        cout << "Enter memory required for process "<<i+1<<" (in Bytes).... ";
        cin >> memProcess[i];
    }

        cout << "\n NUMBER OF BLOCKS AVAILABLE IN MEMORY...... " <<numBlocks;
        cout << "\n\nPROCESS\tMEMORY REQUIRED\t ALLOCATED\tINTERNAL FRAGMENTATION";

        for (i=0; i < numProcess && p < numBlocks ; i++){

            cout << "\n "<<i+1<<"\t\t"<<memProcess[i];

            if( memProcess[i] > blockSize ){
                cout << "\t   NO\t\t\t---";
            }else{
                cout <<"\t   YES\t\t\t"<<blockSize-memProcess[i];
                totalInFragmentation = totalInFragmentation + blockSize-memProcess[i];
                p++;

            }
        }
            // Displays a message
            if(i < numProcess){
                cout << "\n\n\n MEMORY IS FULL!!!, REMAINING PROCESS CANNOT BE ACCOMODATED";

            }
            // Display total internal fragmentation and External fragmentation
                cout <<" \n\n TOTAL INTERNAL FRAGMENTATION IS "<<totalInFragmentation;
                cout <<" \n TOTAL EXTERNAL FRAGMENTATION IS "<<exFragmentation;

           cout <<"\n*************************************************************************************";
    cout << "\n\nPress any key to go back to menu...... ";
    getch();
    system("cls");
menu();

}

void MVT(){


// Variables (i.e Memory size, Memory Processes, Total external fragmentation
int memSize,memProcess[10],i,temp,n=0;

    // Prompt input reply
    char ch = 'y';

     //Screen clear
    system("CLS");

    // Displays a message
        cout <<"***********************MEMORY MANAGEMENT SCHEME***************************";
        cout <<"\n**************************************************************************";
        cout <<"\n*******************************MVT**********************************";
        cout <<"\n**************************************************************************";



    // Prompt memory size input
    cout << "\nPlease enter the total memory available(in Bytes)-- ";
    cin >> memSize;
    temp = memSize;

    // Looping through processes
   for(i=0;ch=='y';i++,n++){

    // Prompt for memory required input
    cout << "\n Enter memory required for process "<<i+1<<" (in Bytes)";
    cin >> memProcess[i];

    // Decision to alert the user for input
    if(memProcess[i]<=temp){

        //
        cout << "\nMemory is allocated for Process "<<i+1<<"";
        temp = temp - memProcess[i];
    }else{

        cout << "\n Memory is Full!!";
        break;
    }
        cout <<"\nDo you want to continue(y/n)? -- ";
        cin >> ch;
   }

   cout << "\n\nTotal Memory Available -- "<<memSize;
   cout << "\n\n\tPROCESS\t\t MEMORY ALLOCATED";
        for(i=0;i<n;i++){
            cout <<"\n \t"<<i+1<<"\t\t"<<memProcess[i];
        }
    cout << "\n\nTotal Memory Allocated is "<<memSize-temp;
    cout << "\nTotal External Fragmentation is "<<temp;

    cout <<"\n*************************************************************************************";
    cout << "\n\nPress any key to go back to menu...... ";
    getch();
    system("cls");
menu();


}


void pagingTechnique(){
 int memSize,pageSize,numPages,numProcess,remPages,i,j,x,y,pa,offset;
    int s[10],fno[10][20];

        //Clearing the screen for processing
         system("CLS");

        // Displays a message

        cout <<"***********************MEMORY MANAGEMENT SCHEME***************************";
        cout <<"\n**************************************************************************";
        cout <<"\n*******************************PAGING TECHNIQUE**********************************";
        cout <<"\n**************************************************************************";



    cout <<"\nPlease enter the memory size-- ";
    cin >> memSize;

    cout << "\nEnter the page size-- ";
    cin >> pageSize;

    numPages = memSize/pageSize;

    cout << "\nThe number of pages available in memory are -- "<<numPages;

    cout << "\nEnter number of processes-- ";
    cin >> numProcess;

    remPages = numPages;

    for(i=1;i<=numProcess;i++){
        cout << "\nEnter number of pages required for p["<<i<<"] -- ";
        cin >> s[i];

        if(s[i]>remPages){
            cout << "\nMEMORY FULL!!";
            break;
        }
        remPages = remPages - s[i];
        cout << "\nEnter page table for p["<<i<<"] -- ";
        for(j=0;j<s[i];j++){
            cin >> fno[i][j];
        }
    }

    cout <<"\nEnter Logical Address to find Physical Address";
    cout << "\nEnter process number , Page number and Offset(Eg. 3  6  54) -- ";
    cin >> x >> y >> offset;
    if(x>numProcess || y>s[i] || offset>=pageSize){
        cout << "\nINVALID PROCESS OR PAGE NUMBER OR OFFSET";
    }else{
        pa = fno[x][y]*pageSize+offset;
        cout <<"\nThe Physical Address is -- "<<pa;
    }
    cout <<"\n*************************************************************************************";
    cout << "\n\nPress any key to go back to menu...... ";
    getch();
    system("cls");
menu();

}


void firstComeFirstServe(){

int burstTime[20],waitingTime[20],turnAroundTime[20],i,n;
float avgWaitingTime,avgTurnAroudTime;

system("CLS");


// Displays a message

        cout <<"***********************PROCESS MANAGEMENT SCHEME***************************";
        cout <<"\n**************************************************************************";
        cout <<"\n******************FIRST-COME-FIRST-SERVE******************";
        cout <<"\n**************************************************************************";


        printf("\n\nEnter the number of processes -- ");
        scanf("%d", &n);
        printf("%d",n);

        for(i=0;i<n;i++){
            printf("\nEnter Burst Time for Process %d -- ", i+1);
            scanf("%d", &burstTime[i]);
        }
        waitingTime[0] = avgWaitingTime = 0;
        turnAroundTime[0] = avgTurnAroudTime = burstTime[0];

        for(i=1;i<n;i++){
            waitingTime[i] = waitingTime[i-1] +burstTime[i-1];
            turnAroundTime[i] = turnAroundTime[i-1] +burstTime[i];
            avgWaitingTime = avgWaitingTime + waitingTime[i];
            avgTurnAroudTime = avgTurnAroudTime + turnAroundTime[i];
        }

        cout <<"\n*************************************************************************************";
        printf("\n\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
        for(i=0;i<n;i++){
            printf("\n\t Process%d \t\t %d \t\t %d \t\t %d", i+1, burstTime[i], waitingTime[i], turnAroundTime[i]);
        }
        printf("\nAverage Waiting Time -- %f", avgWaitingTime/n);
        printf("\nAverage Turnaround Time -- %f", avgTurnAroudTime/n);

    cout <<"\n*************************************************************************************";
    cout << "\n\nPress any key to go back to menu...... ";
    getch();
    system("cls");
menu();


}


//Shortest Job Next
void shortestJobNext(){


int p[20], bt[20], wt[20], tat[20], i, k, n, temp;

float wtavg, tatavg;

system("cls");

cout <<"***********************PROCESS MANAGEMENT SCHEME***************************";
        cout <<"\n**************************************************************************";
        cout <<"\n******************SHORTEST-JOB-FIRST/NEXT******************";
        cout <<"\n**************************************************************************";


printf("\n\nEnter the number of processes -- ");
scanf("%d", &n);
for(i=0;i<n;i++){
    p[i]=i;
    printf("Enter Burst Time for Process %d -- ", i+1);
    scanf("%d", &bt[i]);
}


for(i=0;i<n;i++)
    for(k=i+1;k<n;k++)
     if(bt[i]>bt[k]) {
          temp=bt[i];
          bt[i]=bt[k];
          bt[k]=temp;
          temp=p[i];
          p[i]=p[k];
          p[k]=temp;
        }
        wt[0] = wtavg = 0;
        tat[0] = tatavg = bt[0];

        for(i=1;i<n;i++) {
                wt[i] = wt[i-1] +bt[i-1];
                tat[i] = tat[i-1] +bt[i];
                wtavg = wtavg + wt[i];
                tatavg = tatavg + tat[i];
            }

        cout <<"\n*************************************************************************************";
        printf("\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
        for(i=0;i<n;i++){
            printf("\n\t P%d \t\t %d \t\t %d \t\t %d", p[i]+1, bt[i], wt[i], tat[i]);
        }
        printf("\nAverage Waiting Time -- %f", wtavg/n);
        printf("\nAverage Turnaround Time -- %f", tatavg/n);

    cout <<"\n*************************************************************************************";
    cout << "\n\nPress any key to go back to menu...... ";
    getch();
    system("cls");
menu();

}



void roundRobin(){
    int i,j,n,bu[10],wa[10],tat[10],t,ct[10],maxi;
    float awt=0,att=0,temp=0;



    system("CLS");

    cout <<"***********************PROCESS MANAGEMENT SCHEME***************************";
    cout <<"\n**************************************************************************";
    cout <<"\n********************************ROUND ROBIN********************************";
    cout <<"\n**************************************************************************";

    printf("\n\nEnter the no of processes -- ");
    scanf("%d",&n);

    for(i=0;i<n;i++) {
            printf("\nEnter Burst Time for process %d -- ", i+1);
            scanf("%d",&bu[i]);
            ct[i]=bu[i];
        }
    printf("\nEnter the size of time slice -- ");
    scanf("%d",&t);
    maxi=bu[0];

    for(i=1;i<n;i++)
        if(maxi<bu[i])
            maxi=bu[i];
    for(j=0;j<(maxi/t)+1;j++)
        for(i=0;i<n;i++)
            if(bu[i]!=0)
                if(bu[i]<=t) {
                    tat[i]=temp+bu[i];
                    temp=temp+bu[i];
                    bu[i]=0;
                } else {
                    bu[i]=bu[i]-t;
                    temp=temp+t;
                }

                for(i=0;i<n;i++) {
                        wa[i]=tat[i]-ct[i];
                        att+=tat[i];
                        awt+=wa[i];
                    }

    printf("\nThe Average Turnaround time is -- %f",att/n);
    printf("\nThe Average Waiting time is -- %f ",awt/n);
    printf("\n\tPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME\n");
    for(i=0;i<n;i++)
        printf("\t%d \t %d \t\t %d \t\t %d \n",i+1,ct[i],wa[i],tat[i]);

    cout <<"\n*************************************************************************************";
    cout << "\n\nPress any key to go back to menu...... ";
    getch();
    system("cls");
menu();

}


void priority(){

    int p[20],bt[20],pri[20], wt[20],tat[20],i, k, n, temp;
    float wtavg, tatavg;

    system("CLS");

    cout <<"***********************PROCESS MANAGEMENT SCHEME***************************";
    cout <<"\n**************************************************************************";
    cout <<"\n*****************************PRIORITY SCHEME******************************";
    cout <<"\n**************************************************************************";

    printf("\n\nEnter the number of processes --- ");
    scanf("%d",&n);

    for(i=0;i<n;i++) {

        p[i] = i;
        printf("Enter the Burst Time & Priority of Process %d --- ",i+1);
        scanf("%d %d",&bt[i], &pri[i]);

    }
    for(i=0;i<n;i++)
        for(k=i+1;k<n;k++)
            if(pri[i] > pri[k]) {

                temp=p[i];
                p[i]=p[k];
                p[k]=temp;

                temp=bt[i];
                bt[i]=bt[k];
                bt[k]=temp;

                temp=pri[i];
                pri[i]=pri[k];
                pri[k]=temp;
        }
        wtavg = wt[0] = 0;
        tatavg = tat[0] = bt[0];

        for(i=1;i<n;i++) {
            wt[i] = wt[i-1] + bt[i-1];
            tat[i] = tat[i-1] + bt[i];
            wtavg = wtavg + wt[i];
            tatavg = tatavg + tat[i];

        }

        printf("\nPROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
            for(i=0;i<n;i++)
                printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d ",p[i]+1,pri[i],bt[i],wt[i],tat[i]);
            printf("\nAverage Waiting Time is --- %f",wtavg/n);
            printf("\nAverage Turnaround Time is --- %f",tatavg/n);

    cout <<"\n*************************************************************************************";
    cout << "\n\nPress any key to go back to menu...... ";
    getch();
    system("cls");
menu();


}

// Banker's Algorithm
void banker_sAlgorithm(){

struct file {
    int all[10];
    int maxi[10];
    int need[10];
    int flag;
    };

    // Variables declaration
    struct file f[10];
    int fl;
    int i, j, k, p, b, n, r, g, cnt=0, id, newr;

    int avail[10],seq[10];

    //Clearing the screen for processing
    system("CLS");



        // Displays a message

        cout <<"***********************PROCESS MANAGEMENT SCHEME***************************";
        cout <<"\n**************************************************************************";
        cout <<"\n******************BANKER'S ALGORITHM(DEADLOCK AVOIDANCE)******************";
        cout <<"\n**************************************************************************";

        // Operation request
        printf("\n\nEnter number of processes -- ");
        scanf("%d",&n);

        printf("Enter number of resources -- ");
        scanf("%d",&r);

// Looping through requests
    for(i=0;i<n;i++) {
        cout << "Process "<<i+1<<" Details:";
        printf("\nEnter allocation\t -- \t");
        for(j=0;j<r;j++){
            scanf("%d",&f[i].all[j]);
        }
        printf("Enter Max\t\t -- \t");

        for(j=0;j<r;j++){
            scanf("%d",&f[i].maxi[j]);
        }

        f[i].flag=0;
    }

    printf("\nEnter Available Resources\t -- \t");

    for(i=0;i<r;i++){
        scanf("%d",&avail[i]);
    }

    cout <<"New Request Details:";
    printf("\nEnter pid \t -- \t");
    scanf("%d",&id);

    printf("Enter Request for Resources \t -- \t");
    for(i=0;i<r;i++){
        scanf("%d",&newr);
        f[id].all[i] += newr;
        avail[i]=avail[i] - newr;
    }

    for(i=0;i<n;i++){
        for(j=0;j<r;j++){
            f[i].need[j]=f[i].maxi[j]-f[i].all[j];
            if(f[i].need[j]<0){
                f[i].need[j]=0;
            }
        }
    }

    cnt=0;
    fl=0;
    while(cnt!=n){
        g=0;
        for(j=0;j<n;j++){
            if(f[j].flag==0){
                b=0;
                for(p=0;p<r;p++){
                    if(avail[p]>=f[j].need[p])
                        b=b+1;
                    else
                        b=b-1;
                }
                if(b==r){
                    printf("\nProcess%d is visited",j);
                    seq[fl++]=j;
                    f[j].flag=1;
                    for(k=0;k<r;k++)
                        avail[k]=avail[k]+f[j].all[k];
                    cnt=cnt+1;
                    printf("(");
                    for(k=0;k<r;k++)
                        printf("%3d",avail[k]);
                    printf(")");
                    g = 1;
                }
            }
        }
       if(g == 0){
            printf("\n REQUEST NOT GRANTED -- DEADLOCK OCCURRED");
            printf("\n SYSTEM IS IN UNSAFE STATE");
            goto y;
       }
    }
    printf("\nSYSTEM IS IN SAFE STATE");
    printf("\nThe Safe Sequence is -- (");
    for(i=0;i<fl;i++){
        printf("Process%d ",seq[i]);
    }
    printf(")");
    y:printf("\nProcess\t\t       Allocation\t\t       Max\t\t\t Need\n");

    // Looping through to display results after operation
        for(i=0;i<n;i++){
            printf("Process%d\t",i);
            for(j=0;j<r;j++)
                printf("%6d",f[i].all[j]);
                cout <<"\t";

            for(j=0;j<r;j++)
                    printf("%6d",f[i].maxi[j]);
                    cout <<"\t";

            for(j=0;j<r;j++)
                printf("%6d",f[i].need[j]);
            printf("\n");
        }

    cout <<"\n*************************************************************************************";
    cout << "\n\nPress any key to go back to menu...... ";
    getch();
    system("cls");
menu();


}

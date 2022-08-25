//student result

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//struct first sem
typedef struct bca
{
	char subject[50];
	int theory;
	int practical;
	int internal;
	int atkt;
}b;

int atktcount1[6]={1,1,1,1,1,1};

//common function
void final_degree(int[],char[],char[],char[],char[],char[],char[]);
void  display(char university[50],char course[50],char fname[30],char name[30],char status[10],char rollno[40],int n,struct bca f[]);
int check_pass_fail(struct bca[6],int);

//all first sem function
void get_first_sem_subject_marks(char[6][50],int,struct bca[],struct bca[]);
int give_atkt_exam(char[6][50],struct bca[],int);


//all second sem function
void get_second_sem_subject_marks(char[7][50],int,struct bca[],struct bca[]);
int give_atkt_exam_second(char[7][50],struct bca[],int);

//all third sem function
void get_third_sem_subject_marks(char[7][50],int,struct bca[],struct bca[]);
int give_atkt_exam_third(char[7][50],struct bca[],int);

//all four sem function
void get_four_sem_subject_marks(char[6][50],int,struct bca[],struct bca[]);
int give_atkt_exam_four(char[6][50],struct bca[],int);

//all five sem function
void get_five_sem_subject_marks(char[6][50],int,struct bca[],struct bca[]);
int give_atkt_exam_five(char[6][50],struct bca[],int);

//all six sem function
void get_six_sem_subject_marks(char[6][50],int,struct bca[],struct bca[]);
int give_atkt_exam_six(char[6][50],struct bca[],int);


//gotoxy function
void gotoxy(int x,int y)
{
	printf("%c[%d;%df",0x1B,y,x);
}
 

//main function
int main()
{
	struct bca first[6];
	struct bca second[7];
	struct bca third[6];
	struct bca four[6];
	struct bca five[6];
	struct bca six[6];
	
	struct bca first_atkt[6];
	struct bca second_atkt[7];
	struct bca third_atkt[6];
	struct bca four_atkt[6];
	struct bca five_atkt[6];
	struct bca six_atkt[6];
	
	
	//first sem subject
	char first_sem_subject[6][50]={"Mathematics-I","Statistical","Prog.& Problem","P.C.Software","English","DIG.Computer"};
	
	//second sem subject
	char second_sem_subject[7][50]={"Mathematics-I","Statistical","Internet","Problem-Solve-By-C-II","Intro-To-Info.Sys","Hindi","Operating-System"};
	
	//third sem subject
	char third_sem_subject[6][50]={"Discretc-Mathemat","Unix-Operating-Sys","Oops&C++","Acc.& Financial","Data Structure","Communication Skill"};
	
	//four sem subject
	char four_sem_subject[6][50]={"C-Language","Software-Engineer","DBMS","Java","Awarness & Green computing","Enterepreneurship"};
	
	//five sem subject
	char five_sem_subject[6][50]={"Linear-Algebra","Computer-Network","Human-Value","Information-Tecnology","Intro to Cloud","Intro.Data-Science"};
	
	
	//six sem subject
	char six_sem_subject[6][50]={"Pr.Intr.&Web.Te","Operation Research","Project","Computer-Graphics&Multi","Pricncipal Of Practice","Graphics&Multi"};
	
	
	char name[30],fname[30],status[10],university[80],course[50],rollno[30];
	
	int ch,semestercount=1,i;
	

	printf("enter your university name \n");
	fgets(university, 80, stdin);
	
	printf("enter your course name \n");
	fgets(course, 50, stdin);
	
	printf("enter your name\n");
	fgets(name, 30, stdin);
   
	
	printf("enter your father name\n");
	fgets(fname, 30, stdin);
	
	printf("enter your status [private/regular]\n");
	fgets(status, 10, stdin);
	
	printf("enter your roll number \n");
	fgets(rollno, 30, stdin);
	
	int c=0,sum[6]={0},atktcount=1;
	while(semestercount<=6)
	{
		printf("enter your semester[1-6]\n");
		scanf("%d",&ch);
		
		if(ch==semestercount)
		{
			switch(ch)
			{
				case 1:
					
					get_first_sem_subject_marks(first_sem_subject,6,first,first_atkt);
					
					system("clear");
					display(university,course,fname,name,status,rollno,6,first);
					
					c=check_pass_fail(first,6);
					
					
					if(c>2)
					{
						system("clear");
						display(university,course,fname,name,status,rollno,6,first);
						printf("\n --------------------------------------------------------------------------------------------------------------\n");
						printf("    You Failed Please Repeat 1st Semester\n");
						printf("\n --------------------------------------------------------------------------------------------------------------\n");
						continue;
						
					}
					if(c)
					{
						while(c)
						{
							atktcount++;
							system("clear");
							display(university,course,fname,name,status,rollno,6,first);
							c=give_atkt_exam(first_sem_subject,first,6);
						}
						if(c==0)
						{
							system("clear");
							display(university,course,fname,name,status,rollno,6,first);
							printf("    Cleared 1st Semester\n");
							printf("\n --------------------------------------------------------------------------------------------------------------\n");
							for(i=0;i<6;i++)
							{
								sum[0]=sum[0]+first[i].practical+first[i].theory+first[i].internal;
							}
							
							printf("    Total Number %d | 315",sum[0]);
							printf("\n --------------------------------------------------------------------------------------------------------------\n");
							printf("    Your Total Attempt | %d",atktcount);
							printf("\n --------------------------------------------------------------------------------------------------------------\n");
							printf("    PASS\n");
							printf("\n --------------------------------------------------------------------------------------------------------------\n");
							semestercount++;
							atktcount1[0]=atktcount;
							atktcount=1;
						}
					}
					else
					{
						system("clear");
						
						display(university,course,fname,name,status,rollno,6,first);
						printf("    Cleared 1st Semester\n");
						printf("\n --------------------------------------------------------------------------------------------------------------\n");
						for(i=0;i<6;i++)
								sum[0]=sum[0]+first[i].practical+first[i].theory+first[i].internal;
							
						printf("    Total Number %d | 315",sum[0]);
						printf("\n --------------------------------------------------------------------------------------------------------------\n");
						printf("    Your Total Attempt | %d ",atktcount);
						printf("\n --------------------------------------------------------------------------------------------------------------\n");
						printf("    PASS\n");
						printf("\n --------------------------------------------------------------------------------------------------------------\n");
						semestercount++;
					}
					break;
				
				case 2:
					get_second_sem_subject_marks(second_sem_subject,7,second,second_atkt);
					system("clear");
					display(university,course,fname,name,status,rollno,7,second);
					c=check_pass_fail(second,7);
					
					if(c>2)
					{
						system("clear");
						display(university,course,fname,name,status,rollno,7,second);
						printf("\n---------------------------------------------------------------------------------------------------------------\n");
						printf("    You Failed Please Repeat 2nd Semester\n");
						printf("\n---------------------------------------------------------------------------------------------------------------\n");
						continue;
						
					}
					
					if(c)
					{
						while(c)
						{
							atktcount++;
							system("clear");
							display(university,course,fname,name,status,rollno,7,second);
							c=give_atkt_exam_second(second_sem_subject,second,7);
						}
						if(c==0)
						{
							system("clear");
							
							display(university,course,fname,name,status,rollno,7,second);
							printf("    Cleared 2nd Semester\n");
							printf("\n---------------------------------------------------------------------------------------------------------------\n");
							for(i=0;i<7;i++)
								sum[1]=sum[1]+second[i].practical+second[i].theory+second[i].internal;
							
							printf("    Total Number %d | 290",sum[1]);
							printf("\n---------------------------------------------------------------------------------------------------------------\n");
							printf("    Your Total Attempt | %d",atktcount);
							printf("\n --------------------------------------------------------------------------------------------------------------\n");
							printf("    PASS\n");
							printf("\n---------------------------------------------------------------------------------------------------------------\n");
							semestercount++;
							atktcount1[1]=atktcount;
							atktcount=1;
						}
					}
					else
					{
						system("clear");
						
						display(university,course,fname,name,status,rollno,7,second);
						printf("    Cleare 2nd Semester\n");
						printf("\n---------------------------------------------------------------------------------------------------------------\n");
						for(i=0;i<6;i++)
								sum[1]=sum[1]+second[i].practical+second[i].theory+second[i].internal;
							
						printf("    Total Number %d | 290",sum[1]);
						printf("\n---------------------------------------------------------------------------------------------------------------\n");
						printf("    Your Total Attempt | %d ",atktcount);
						printf("\n --------------------------------------------------------------------------------------------------------------\n");
						printf("    PASS\n");
						printf("\n---------------------------------------------------------------------------------------------------------------\n");
						semestercount++;
						
					}
					break;
					
					case 3:
						get_third_sem_subject_marks(third_sem_subject,6,third,third_atkt);
						system("clear");
						display(university,course,fname,name,status,rollno,6,third);
						c=check_pass_fail(third,6);
					
						if(c>2)
						{
							system("clear");
							display(university,course,fname,name,status,rollno,6,third);
							printf("\n---------------------------------------------------------------------------------------------------------------\n");
							printf("    You Failed Please Repeat 3rd Semester\n");
							printf("\n---------------------------------------------------------------------------------------------------------------\n");
							continue;
							
						}
						
						if(c)
						{
							while(c)
							{
								atktcount++;
								system("clear");
								display(university,course,fname,name,status,rollno,6,third);
								c=give_atkt_exam_third(third_sem_subject,third,6);
							}
							if(c==0)
							{
								system("clear");
								
								display(university,course,fname,name,status,rollno,6,third);
								printf("    Cleared 3rd Semester\n");
								printf("\n---------------------------------------------------------------------------------------------------------------\n");
								for(i=0;i<6;i++)
									sum[2]=sum[2]+third[i].practical+third[i].theory+third[i].internal;
								
								printf("    Total Number %d | 320",sum[2]);
								printf("\n---------------------------------------------------------------------------------------------------------------\n");
								printf("    Your Total Attempt | %d",atktcount);
printf("\n --------------------------------------------------------------------------------------------------------------\n");
								printf("PASS\n");
								printf("\n---------------------------------------------------------------------------------------------------------------\n");
								semestercount++;
								atktcount1[2]=atktcount;
								atktcount=1;
							}
						}
						else
						{
							system("clear");
							
							display(university,course,fname,name,status,rollno,6,third);
							printf("    Cleared 3rd Semester\n");
							printf("\n---------------------------------------------------------------------------------------------------------------\n");
							for(i=0;i<6;i++)
									sum[2]=sum[2]+third[i].practical+third[i].theory+third[i].internal;
								
							printf("    Total Number %d | 320",sum[2]);
							printf("\n---------------------------------------------------------------------------------------------------------------\n");
							printf("    Your Total Attempt | %d ",atktcount);
							printf("\n --------------------------------------------------------------------------------------------------------------\n");
							printf("    PASS\n");
							printf("\n---------------------------------------------------------------------------------------------------------------\n");
							semestercount++;
							
						}
						break;
						
						case 4:
							get_four_sem_subject_marks(four_sem_subject,6,four,four_atkt);
							
							system("clear");
							display(university,course,fname,name,status,rollno,6,four);
							c=check_pass_fail(four,6);
				
					
							if(c>2)
							{
								system("clear");
								display(university,course,fname,name,status,rollno,6,four);
								printf("    You Failed Please Repeat 4th Semester\n");
								printf("\n---------------------------------------------------------------------------------------------------------------\n");
								continue;
								
							}
						
							if(c)
							{
								while(c)
								{
									atktcount++;
									system("clear");
									display(university,course,fname,name,status,rollno,6,four);
									c=give_atkt_exam_four(four_sem_subject,four,6);
								}
								if(c==0)
								{
									system("clear");
									
									display(university,course,fname,name,status,rollno,6,four);
									printf("    Cleared 4th Semester\n");
									printf("\n---------------------------------------------------------------------------------------------------------------\n");
									for(i=0;i<6;i++)
										sum[3]=sum[3]+four[i].practical+four[i].theory+four[i].internal;
									
									printf("    Total Number %d | 330",sum[3]);
									printf("\n---------------------------------------------------------------------------------------------------------------\n");
									printf("    Your Total Attempt | %d",atktcount);
printf("\n --------------------------------------------------------------------------------------------------------------\n");
									printf("    PASS\n");
									printf("\n---------------------------------------------------------------------------------------------------------------\n");
									semestercount++;
									atktcount1[3]=atktcount;
									atktcount=1;
									}
								}
							else
							{
								system("clear");
								
								display(university,course,fname,name,status,rollno,6,four);
								printf("    Cleared 4th Semester\n");
								printf("\n---------------------------------------------------------------------------------------------------------------\n");
								for(i=0;i<6;i++)
										sum[3]=sum[3]+four[i].practical+four[i].theory+four[i].internal;
									
								printf("    Total Number %d | 330",sum[3]);
								printf("\n---------------------------------------------------------------------------------------------------------------\n");
								printf("    Your Total Attempt | %d ",atktcount);
printf("\n --------------------------------------------------------------------------------------------------------------\n");
								printf("PASS\n");
								printf("\n---------------------------------------------------------------------------------------------------------------\n");
								semestercount++;
								
							}
							break;
							
							case 5:
								get_five_sem_subject_marks(five_sem_subject,6,five,five_atkt);
							
								system("clear");
								display(university,course,fname,name,status,rollno,6,five);
								c=check_pass_fail(five,6);
				
					
								if(c>2)
								{
									system("clear");
									display(university,course,fname,name,status,rollno,6,five);
									printf("    You Failed Please Repeat 5th Semester\n");
									printf("\n---------------------------------------------------------------------------------------------------------------\n");
									continue;
									
								}
						
								if(c)
								{
									while(c)
									{
										atktcount++;
										system("clear");
										display(university,course,fname,name,status,rollno,6,five);
										c=give_atkt_exam_five(five_sem_subject,five,6);
									}
									if(c==0)
									{
										system("clear");
										
										display(university,course,fname,name,status,rollno,6,five);
										printf("    Cleared 5th Semester\n");
										printf("\n---------------------------------------------------------------------------------------------------------------\n");
										for(i=0;i<6;i++)
											sum[4]=sum[4]+five[i].practical+five[i].theory+five[i].internal;
										
										printf("    Total Number %d | 390",sum[4]);
										printf("\n---------------------------------------------------------------------------------------------------------------\n");
										printf("    Your Total Attempt | %d",atktcount);
printf("\n --------------------------------------------------------------------------------------------------------------\n");
										printf("PASS\n");
										printf("\n---------------------------------------------------------------------------------------------------------------\n");
										semestercount++;
										atktcount1[4]=atktcount;
										atktcount=1;
										}
									}
								else
								{
									system("clear");
									
									display(university,course,fname,name,status,rollno,6,five);
									printf("    Cleared 5th Semester\n");
									printf("\n---------------------------------------------------------------------------------------------------------------\n");
									for(i=0;i<6;i++)
											sum[4]=sum[4]+five[i].practical+five[i].theory+five[i].internal;
										
									printf("    Total Number %d | 390",sum[4]);
									printf("\n---------------------------------------------------------------------------------------------------------------\n");
									printf("    Your Total Attempt | %d ",atktcount);
printf("\n --------------------------------------------------------------------------------------------------------------\n");
									printf("    PASS\n");
									printf("\n---------------------------------------------------------------------------------------------------------------\n");
									semestercount++;
									
								}
							break;
							case 6:
								get_six_sem_subject_marks(six_sem_subject,6,six,six_atkt);
								system("clear");
								display(university,course,fname,name,status,rollno,6,six);
								c=check_pass_fail(six,6);
				
					
								if(c>2)
								{
									system("clear");
									display(university,course,fname,name,status,rollno,6,six);
									printf("    You Failed Please Repeat 6th Semester\n");
									printf("\n---------------------------------------------------------------------------------------------------------------\n");
									continue;
									
								}
							
								if(c)
								{
									while(c)
									{
										atktcount++;
										system("clear");
										display(university,course,fname,name,status,rollno,6,six);
										c=give_atkt_exam_six(five_sem_subject,six,6);
									}
									if(c==0)
									{
										system("clear");
										
										display(university,course,fname,name,status,rollno,6,six);
										printf("\n---------------------------------------------------------------------------------------------------------------\n");
										printf("    Cleared 6th Semester\n");
										for(i=0;i<6;i++)
											sum[5]=sum[5]+six[i].practical+six[i].theory+six[i].internal;
										
										printf("    Total Number %d | 315",sum[5]);
										printf("\n---------------------------------------------------------------------------------------------------------------\n");
										printf("    Your Total Attempt | %d",atktcount);
printf("\n --------------------------------------------------------------------------------------------------------------\n");
										printf("    PASS\n");
										printf("\n---------------------------------------------------------------------------------------------------------------\n");
										semestercount++;
										atktcount1[5]=atktcount;
										atktcount=1;
										}
									}
								else
								{
									system("clear");
									
									display(university,course,fname,name,status,rollno,6,six);
									printf("\n---------------------------------------------------------------------------------------------------------------\n");
									printf("    Cleared 6th Semester\n");
									for(i=0;i<6;i++)
											sum[5]=sum[5]+six[i].practical+six[i].theory+six[i].internal;
										
									printf("    Total Number %d | 315",sum[5]);
									printf("\n---------------------------------------------------------------------------------------------------------------\n");
									printf("    Your Total Attempt | %d ",atktcount);
printf("\n --------------------------------------------------------------------------------------------------------------\n");
									printf("    PASS\n");
									printf("\n---------------------------------------------------------------------------------------------------------------\n");
									semestercount++;
									
								}
								
								break;
			}
		}
		else if(semestercount>ch)
			printf("you cleared %d-semester please take admission in %d-semeters\n\n",ch,semestercount);
		else
			printf("you did not cleared semester-%d \n",semestercount);
				
	}
	
	printf("Enter 1 to see Final Degree\n");
	scanf("%d",&ch);
	
	if(ch)
	{
		final_degree(sum,university,course,fname,name,status,rollno);
	}
	else
	{
		system("clear");
		gotoxy(50,20);
		printf("sorry you pressed wrong key enter again\n");
	}
	
	printf("\n\n\n");
	
	while(1)
	{
		printf("do you want to see marksheet of any semester /enter [1-6]\n");
		printf("do you want to see marksheet of ATKT then enter/[7-12]");
		printf("press 13 to see final degree or certificate\n");
		printf("enter 14 for exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				system("clear");
				display(university,course,fname,name,status,rollno,6,first);
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				printf("    Your Total Attempt | %d",atktcount1[0]);
				printf("\n --------------------------------------------------------------------------------------------------------------\n");
				printf("    PASS\n");																  					printf("\n---------------------------------------------------------------------------------------------------------------\n");
				break;
			case 2:
				system("clear");
				display(university,course,fname,name,status,rollno,6,second);
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				printf("    Your Total Attempt | %d",atktcount1[1]);
				printf("\n --------------------------------------------------------------------------------------------------------------\n");
				printf("    PASS\n");																  					printf("\n---------------------------------------------------------------------------------------------------------------\n");
				break;
			case 3:
				system("clear");
				display(university,course,fname,name,status,rollno,6,third);
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				printf("    Your Total Attempt | %d",atktcount1[2]);
				printf("\n --------------------------------------------------------------------------------------------------------------\n");
				printf("    PASS\n");																  					printf("\n---------------------------------------------------------------------------------------------------------------\n");
				break;
			case 4:
				system("clear");
				display(university,course,fname,name,status,rollno,6,four);
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				printf("    Your Total Attempt | %d",atktcount1[3]);
				printf("\n --------------------------------------------------------------------------------------------------------------\n");
				printf("    PASS\n");																  					printf("\n---------------------------------------------------------------------------------------------------------------\n");
				break;
			case 5:
				system("clear");
				display(university,course,fname,name,status,rollno,6,five);
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				printf("    Your Total Attempt | %d",atktcount1[4]);
				printf("\n --------------------------------------------------------------------------------------------------------------\n");
				printf("    PASS\n");																  					printf("\n---------------------------------------------------------------------------------------------------------------\n");
				break;
			case 6:
				system("clear");
				display(university,course,fname,name,status,rollno,6,six);
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				printf("    Your Total Attempt | %d",atktcount1[5]);
				printf("\n --------------------------------------------------------------------------------------------------------------\n");
				printf("    PASS\n");																  					printf("\n---------------------------------------------------------------------------------------------------------------\n");
				break;
				
			case 7:
				if(atktcount1[0]>1)
				{
					system("clear");
					display(university,course,fname,name,status,rollno,6,first_atkt);
					printf("\n---------------------------------------------------------------------------------------------------------------\n");
					printf("    Your Total Attempt | %d",atktcount1[0]);
					printf("\n --------------------------------------------------------------------------------------------------------------\n");
					printf("    PASS\n"); 															  						printf("\n---------------------------------------------------------------------------------------------------------------\n");
				}
				else
				{
					system("clear");
					gotoxy(65,10);
					printf("you cleared your 1st semester in 1st attempt\n\n\n\n\n");
				}
				break;
			case 8:
				if(atktcount1[1]>1)
				{
					system("clear");
					display(university,course,fname,name,status,rollno,7,second_atkt);
					printf("\n---------------------------------------------------------------------------------------------------------------\n");
					printf("    Your Total Attempt | %d",atktcount1[1]);
					printf("\n --------------------------------------------------------------------------------------------------------------\n");
					printf("    PASS\n"); 															  						printf("\n---------------------------------------------------------------------------------------------------------------\n");
				}
				else
				{
					system("clear");
					gotoxy(65,10);
					printf("you cleared your 2nd semester in 1st attempt\n\n\n\n\n");
				}
				break;
			case 9:
				if(atktcount1[2]>1)
				{
					system("clear");
					display(university,course,fname,name,status,rollno,6,third_atkt);
					printf("\n---------------------------------------------------------------------------------------------------------------\n");
					printf("    Your Total Attempt | %d",atktcount1[2]);
					printf("\n --------------------------------------------------------------------------------------------------------------\n");
					printf("    PASS\n"); 															  						printf("\n---------------------------------------------------------------------------------------------------------------\n");
				}
				else
				{
					system("clear");
					gotoxy(65,10);
					printf("you cleared your 3rd semester in 1st attempt\n\n\n\n\n");
				}
				break;
			case 10:
				if(atktcount1[3]>1)
				{
					system("clear");
					display(university,course,fname,name,status,rollno,6,four_atkt);
					printf("\n---------------------------------------------------------------------------------------------------------------\n");
					printf("    Your Total Attempt | %d",atktcount1[3]);
					printf("\n --------------------------------------------------------------------------------------------------------------\n");
					printf("    PASS\n"); 															  						printf("\n---------------------------------------------------------------------------------------------------------------\n");
				}
				else
				{
					system("clear");
					gotoxy(65,10);
					printf("you cleared your 4th semester in 1st attempt\n\n\n\n\n");
				}
				break;
			case 11:
				if(atktcount1[4]>1)
				{
					system("clear");
					display(university,course,fname,name,status,rollno,6,five_atkt);
					printf("\n---------------------------------------------------------------------------------------------------------------\n");
					printf("    Your Total Attempt | %d",atktcount1[4]);
					printf("\n --------------------------------------------------------------------------------------------------------------\n");
					printf("    PASS\n"); 															  						printf("\n---------------------------------------------------------------------------------------------------------------\n");
				}
				else
				{
					system("clear");
					gotoxy(65,10);
					printf("you cleared your 5th semester in 1st attempt\n\n\n\n\n");
				}
				break;
			case 12:
				if(atktcount1[5]>1)
				{
					system("clear");
					display(university,course,fname,name,status,rollno,6,six_atkt);
					printf("\n---------------------------------------------------------------------------------------------------------------\n");
					printf("    Your Total Attempt | %d",atktcount1[5]);
					printf("\n --------------------------------------------------------------------------------------------------------------\n");
					printf("    PASS\n"); 															  						printf("\n---------------------------------------------------------------------------------------------------------------\n");
				}
				else
				{
					system("clear");
					gotoxy(65,10);
					printf("you cleared your 6th semester in 1st attempt\n\n\n\n\n");
				}
				break;
			case 13:
				system("clear");
				final_degree(sum,university,course,fname,name,status,rollno);
				break;
			case 14:
				exit(0);
		}
	}
	return 0;
}

/*----------------------------------------------------------------------final-degree-start-----------------------------------------------------------------*/

void final_degree(int sum[],char university[50],char course[50],char fname[30],char name[30],char status[10],char rollno[40])
{
	int total_marks[6]={315,290,320,330,390,315};
	int i,total_sum=0,total_marks_sum=0,j;
	
	system("clear");
	printf("\n---------------------------------------------------------------------------------------------------------\n");
	
	gotoxy(40,3);
	printf("%s",university);
	gotoxy(5,7);
	printf("Course:%s",course);
	gotoxy(5,8);
	printf("Name:%s",name);
	gotoxy(5,9);
	printf("Fname:%s",fname);
	gotoxy(92,7);
	printf("Roll no:%s",rollno);
	gotoxy(92,8);
	printf("Status:%s",status);
	printf("\n---------------------------------------------------------------------------------------------------------\n");
	gotoxy(5,12);
	printf("All-Semesters");
	gotoxy(30,12);
	printf("Max-marks");
	gotoxy(55,12);
	printf("Marks-Obtained");
	gotoxy(80,12);
	printf("\n");
	
	int x=5,y=15;
	for(i=0;i<6;i++)
	{
		x=5;
		
		gotoxy(x,y+i);
		printf("Semester- %d",i+1);
		
		x=x+25;
		
		gotoxy(x,y+i);
		printf("  %d",total_marks[i]);
		
		
		x=x+25;
		
		gotoxy(x,y+i);
		printf("   %d",sum[i]);
		
	}
	
	printf("\n---------------------------------------------------------------------------------------------------------\n");
	
	for(i=0;i<6;i++)
		total_sum=total_sum+sum[i];
		
	for(i=0;i<6;i++)
		total_marks_sum=total_marks_sum+total_marks[i];
		
	printf("    %d | TOTAL : %d",total_marks_sum,total_sum);
	printf("\n---------------------------------------------------------------------------------------------------------\n");
	printf("    PASS");
	printf("\n---------------------------------------------------------------------------------------------------------\n");
	
	printf("\n\n\n Here Is Your Certificate\n");
	
	for(i=0;i<12;i++)
	{
		
		for(j=0;j<50;j++)
		{
			if(i==0||j==0||i==11||j==49)
				printf(" *");
			else
				printf("  ");
		}
		if(i==2)
			printf("\r                                     %s",university);
		if(i==5)
			printf("\r                                           %s",name); 
		if(i==7)
		{
			printf("\r             Has successfully completed the required course of study approve by the  \n ");
			printf("                  education for the state of M.P and is therefore awarded this.");
		}
		if(i==9)
			printf("\r                                  %s",course);
		
		printf("\n");
	}
	
}

/*----------------------------------------------------------------------final-degree-end-------------------------------------------------------------------*/


/*----------------------------------------------------------------------sem6-start---------------------------------------------------------------------*/

//six_sem_subject_marks function
void get_six_sem_subject_marks(char fsubject[6][50],int n,struct bca f[6],struct bca six_atkt[])
{

	int i,c=0;
	for(i=0;i<n;i++)
	{
		f[i].atkt=0;
		f[i].theory=0;
		f[i].practical=0;
		f[i].internal=0;
	}
	
	printf("enter all subject marks\n");
	for(i=0;i<n;i++)
	{
		printf("enter the theory marks of %s out of 40\n",fsubject[i]);
		strcpy(f[i].subject,fsubject[i]);
		scanf("%d",&f[i].theory);
		if(f[i].theory>40||f[i].theory<0)
		{
			printf("invalid marks please enter again\n");
			printf("enter the theory marks of %s out of 40\n",fsubject[i]);
			scanf("%d",&f[i].theory);
		}
		if(f[i].theory<13)
			f[i].atkt=1;
			
		if(strcmp(fsubject[i],"Pr.Intr.&Web.Te")==0)
		{
			strcpy(f[i].subject,fsubject[i]);
			printf("enter the practicals marks of pr.intr.&web.te out of 25\n");
			scanf("%d",&f[i].practical);
			if(f[i].practical>25||f[i].practical<0)
			{
				printf("invalid marks please enter again\n");
				printf("enter the practicals marks of pr.intr.&web.te out of 25\n");
				scanf("%d",&f[i].practical);
			}
			if(f[i].practical<9)
				f[i].atkt=1;
			continue;
		}
		
		if(strcmp(fsubject[i],"Operation Research")==0)
		{
			strcpy(f[i].subject,fsubject[i]);
			printf("enter the practicals marks of operation research out of 25\n");
			scanf("%d",&f[i].practical);
			if(f[i].practical>25||f[i].practical<0)
			{
				printf("invalid marks please enter again\n");
				printf("enter the practicals marks of operation research out of 25\n");
				scanf("%d",&f[i].practical);
			}
			if(f[i].practical<9)
				f[i].atkt=1;
			continue;
		}
		if(strcmp(fsubject[i],"Pricncipal Of Practice")==0)
		{
			strcpy(f[i].subject,fsubject[i]);
			printf("enter the practicals marks of pricncipal of practice out of 25\n");
			scanf("%d",&f[i].practical);
			if(f[i].practical>25||f[i].practical<0)
			{
				printf("invalid marks please enter again\n");
				printf("enter the practicals marks of pricncipal of practice out of 25\n");
				scanf("%d",&f[i].practical);
			}
			if(f[i].practical<9)
				f[i].atkt=1;
			continue;
		}
		
	}

	for(i=0;i<n;i++)
	{
		six_atkt[i].atkt=f[i].atkt;
		six_atkt[i].theory=f[i].theory;
		six_atkt[i].practical=f[i].practical;
		strcpy(six_atkt[i].subject,f[i].subject)	;
		six_atkt[i].internal=f[i].internal;
	}
	
}

//give atkt function
int give_atkt_exam_six(char fsubject[6][50],struct bca f[6],int n)
{
	int i,c=0;
	for(i=0;i<n;i++)
	{
		if(f[i].atkt==1)
		{
			if(f[i].theory<13)
			{
				
				printf("enter the theory marks of %s 40\n",fsubject[i]);
				scanf("%d",&f[i].theory);
				if(f[i].theory<13)
				{
					f[i].atkt=1;
					c++;
				}
				else
					f[i].atkt=0;
			}
			if(f[i].practical<9&&f[i].practical>0)
			{
				printf("enter the practicals marks of %s 25\n",fsubject[i]);
				scanf("%d",&f[i].practical);
				if(f[i].practical<9)
				{
					f[i].atkt=1;
					c++;
				}
				else
					f[i].atkt=0;
			}
		}
		
	}
	return c;
}


/*----------------------------------------------------------------------sem6-end-----------------------------------------------------------------------*/


/*----------------------------------------------------------------------sem5-start---------------------------------------------------------------------*/

//four_sem_subject_marks function
void get_five_sem_subject_marks(char fsubject[6][50],int n,struct bca f[6],struct bca five_atkt[])
{

	int i,c=0;
	for(i=0;i<n;i++)
	{
		f[i].atkt=0;
		f[i].theory=0;
		f[i].practical=0;
		f[i].internal=0;
	}
	
	printf("enter all subject marks\n");
	for(i=0;i<n;i++)
	{
		printf("enter the theory marks of %s out of 40\n",fsubject[i]);
		strcpy(f[i].subject,fsubject[i]);
		scanf("%d",&f[i].theory);
		if(f[i].theory>40||f[i].theory<0)
		{
			printf("invalid marks please enter again\n");
			printf("enter the theory marks of %s out of 40\n",fsubject[i]);
			scanf("%d",&f[i].theory);
		}
		if(f[i].theory<13)
			f[i].atkt=1;
			
		printf("enter the practicals marks of %s out of 25\n",fsubject[i]);
		strcpy(f[i].subject,fsubject[i]);
		scanf("%d",&f[i].practical);
		if(f[i].practical>25||f[i].practical<0)
		{
			printf("invalid marks please enter again\n");
			printf("enter the practicals marks of %s out of 25\n",fsubject[i]);
			scanf("%d",&f[i].practical);
		}
		if(f[i].practical<9)
			f[i].atkt=1;
		
	}
	for(i=0;i<n;i++)
	{
		five_atkt[i].atkt=f[i].atkt;
		five_atkt[i].theory=f[i].theory;
		five_atkt[i].practical=f[i].practical;
		five_atkt[i].internal=f[i].internal;
		strcpy(five_atkt[i].subject,f[i].subject);
	}
	
}

//give atkt function
int give_atkt_exam_five(char fsubject[6][50],struct bca f[6],int n)
{
	int i,c=0;
	for(i=0;i<n;i++)
	{
		if(f[i].atkt==1)
		{
			if(f[i].theory<13)
			{
				printf("enter the theory marks of %s out of 40\n",fsubject[i]);
				scanf("%d",&f[i].theory);
				if(f[i].theory<13)
				{
					f[i].atkt=1;
					c++;
				}
				else
					f[i].atkt=0;
			}
			if(f[i].practical<9&&f[i].practical>0)
			{
				printf("enter the practicals marks of %s out of 25\n",fsubject[i]);
				scanf("%d",&f[i].practical);
				if(f[i].practical<9)
				{
					f[i].atkt=1;
					c++;
				}
				else
					f[i].atkt=0;
			}
		}
		
	}
	return c;
}




/*----------------------------------------------------------------------sem5-end-----------------------------------------------------------------------*/


/*----------------------------------------------------------------------sem4-start---------------------------------------------------------------------*/

//four_sem_subject_marks function
void get_four_sem_subject_marks(char fsubject[6][50],int n,struct bca f[6],struct bca four_atkt[])
{

	int i,c=0;
	for(i=0;i<n;i++)
	{
		f[i].atkt=0;
		f[i].theory=0;
		f[i].practical=0;
		f[i].internal=0;
	}
	
	printf("enter all subject marks\n");
	for(i=0;i<n;i++)
	{
		printf("enter the theory marks of %s out of 40\n",fsubject[i]);
		strcpy(f[i].subject,fsubject[i]);
		scanf("%d",&f[i].theory);
		if(f[i].theory>40||f[i].theory<0)
		{
			printf("invalid marks please enter again\n");
			printf("enter the theory marks of %s out of 40\n",fsubject[i]);
			scanf("%d",&f[i].theory);
		}
		if(f[i].theory<13)
			f[i].atkt=1;
			
		if(strcmp(fsubject[i],"DBMS")==0)
		{
			strcpy(f[i].subject,fsubject[i]);
			printf("enter the practicals marks of dbms out of 25\n");
			scanf("%d",&f[i].practical);
			if(f[i].practical>25||f[i].practical<0)
			{
				printf("invalid marks please enter again\n");
				printf("enter the practicals marks of dbms out of 25\n");
				scanf("%d",&f[i].practical);
			}
			if(f[i].practical<9)
				f[i].atkt=1;
			continue;
		}
		if(strcmp(fsubject[i],"Java")==0)
		{
			printf("enter the practicals marks of java out of 25\n");
			scanf("%d",&f[i].practical);
			if(f[i].practical>25||f[i].practical<0)
			{
				printf("invalid marks please enter again\n");
				printf("enter the practicals marks of java out of 25\n");
				scanf("%d",&f[i].practical);
			}
			if(f[i].practical<9)
				f[i].atkt=1;
			continue;
		}
	
		printf("enter the internal marks of %s out of 10\n",fsubject[i]);
		scanf("%d",&f[i].internal);
		if(f[i].internal>10||f[i].internal<0)
		{
			printf("invalid marks please enter again\n");
			printf("enter the internal marks of %s out of 10\n",fsubject[i]);
			scanf("%d",&f[i].internal);
		}
		if(f[i].internal<4)
			f[i].atkt=1;
	}

	for(i=0;i<n;i++)
	{
		four_atkt[i].atkt=f[i].atkt;
		four_atkt[i].theory=f[i].theory;
		four_atkt[i].practical=f[i].practical;
		four_atkt[i].internal=f[i].internal;
		strcpy(four_atkt[i].subject,f[i].subject);
	}
	
}


//give atkt function
int give_atkt_exam_four(char fsubject[6][50],struct bca f[6],int n)
{
	int i,c=0;
	for(i=0;i<n;i++)
	{
		if(f[i].atkt==1)
		{
			if(f[i].theory<13)
			{
				printf("enter the theory marks of %s out of 40\n",fsubject[i]);
				scanf("%d",&f[i].theory);
				if(f[i].theory<13)
				{
					f[i].atkt=1;
					c++;
				}
				else
					f[i].atkt=0;
			}
			if(f[i].internal<4&&f[i].internal>0)
			{
				printf("enter the internal marks of %s out of 10\n",fsubject[i]);
				scanf("%d",&f[i].internal);
				if(f[i].internal<4)
				{
					f[i].atkt=1;
					c++;
				}
				else
					f[i].atkt=0;
			}
			if(f[i].practical<9&&f[i].practical>0)
			{
				printf("enter the practicals marks of %s out of 25\n",fsubject[i]);
				scanf("%d",&f[i].practical);
				if(f[i].practical<9)
				{
					f[i].atkt=1;
					c++;
				}
				else
					f[i].atkt=0;
			}
		}
		
	}
	return c;
}


/*----------------------------------------------------------------------sem4-end-----------------------------------------------------------------------*/




/*----------------------------------------------------------------------sem3-start---------------------------------------------------------------------*/

//four_sem_subject_marks function
void get_third_sem_subject_marks(char fsubject[6][50],int n,struct bca f[6],struct bca third_atkt[])
{

	int i,c=0;
	for(i=0;i<n;i++)
	{
		f[i].atkt=0;
		f[i].theory=0;
		f[i].practical=0;
		f[i].internal=0;
	}
	
	printf("enter all subject marks\n");
	for(i=0;i<n;i++)
	{
		if(strcmp(fsubject[i],"Communication Skill")==0)
		{
			strcpy(f[i].subject,fsubject[i]);
			printf("enter the practicals marks of communication skill out of 25\n");
			scanf("%d",&f[i].practical);
			if(f[i].practical>25||f[i].practical<0)
			{
				printf("invalid marks please enter again\n");
				printf("enter the practicals marks of communication skill out of 25\n");
				scanf("%d",&f[i].practical);
			}
			if(f[i].practical<9)
				f[i].atkt=1;
			continue;
		}
		printf("enter the theory marks of %s out of 40\n",fsubject[i]);
		strcpy(f[i].subject,fsubject[i]);
		scanf("%d",&f[i].theory);
		if(f[i].theory>40||f[i].theory<0)
		{
			printf("invalid marks please enter again\n");
			printf("enter the theory marks of %s out of 40\n",fsubject[i]);
			scanf("%d",&f[i].theory);
		}
		if(f[i].theory<13)
			f[i].atkt=1;
			
		if(strcmp(fsubject[i],"Unix-Operating-Sys")==0)
		{
			strcpy(f[i].subject,fsubject[i]);
			printf("enter the practicals marks of unix-operating out of 25\n");
			scanf("%d",&f[i].practical);
			if(f[i].practical>25||f[i].practical<0)
			{
				printf("invalid marks please enter again\n");
				printf("enter the practicals marks of unix-operating out of 25\n");
				scanf("%d",&f[i].practical);
			}
			if(f[i].practical<9)
				f[i].atkt=1;
			continue;
		}
		if(strcmp(fsubject[i],"Oops&C++")==0)
		{
			strcpy(f[i].subject,fsubject[i]);
			printf("enter the practicals marks of oop&c++ out of 25\n");
			scanf("%d",&f[i].practical);
			if(f[i].practical>25||f[i].practical<0)
			{
				printf("invalid marks please enter again\n");
				printf("enter the practicals marks of oop&c++ out of 25\n");
				scanf("%d",&f[i].practical);
			}
			if(f[i].practical<9)
				f[i].atkt=1;
			continue;
		}
		if(strcmp(fsubject[i],"Data Structure")==0)
		{
			strcpy(f[i].subject,fsubject[i]);
			printf("enter the practicals marks of data structure out of 25\n");
			scanf("%d",&f[i].practical);
			if(f[i].practical>25||f[i].practical<0)
			{
				printf("invalid marks please enter again\n");
				printf("enter the practicals marks of data structure out of 25\n");
				scanf("%d",&f[i].practical);
			}
			if(f[i].practical<9)
				f[i].atkt=1;
			continue;
		}
		printf("enter the internal marks of %s out of 10\n",fsubject[i]);
		scanf("%d",&f[i].internal);
		if(f[i].internal>10||f[i].internal<0)
		{
			printf("invalid marks please enter again\n");
			printf("enter the internal marks of %s out of 10\n",fsubject[i]);
			scanf("%d",&f[i].internal);
		}
		if(f[i].internal<4)
			f[i].atkt=1;
		
	}
	for(i=0;i<n;i++)
	{
		third_atkt[i].atkt=f[i].atkt;
		strcpy(third_atkt[i].subject,f[i].subject);
		third_atkt[i].theory=f[i].theory;
		third_atkt[i].practical=f[i].practical;
		third_atkt[i].internal=f[i].internal;
	}
	
}



//give atkt function
int give_atkt_exam_third(char fsubject[6][50],struct bca f[6],int n)
{
	int i,c=0;
	for(i=0;i<n;i++)
	{
		if(f[i].atkt==1)
		{
			if(f[i].theory<13)
			{
				printf("enter the theory marks of %s out of 40\n",fsubject[i]);
				scanf("%d",&f[i].theory);
				if(f[i].theory<13)
				{
					f[i].atkt=1;
					c++;
				}
				else
					f[i].atkt=0;
			}
			if(f[i].internal<4&&f[i].internal>0)
			{
				printf("enter the internal marks of %s out of 10\n",fsubject[i]);
				scanf("%d",&f[i].internal);
				if(f[i].internal<4)
				{
					f[i].atkt=1;
					c++;
				}
				else
					f[i].atkt=0;
			}
			if(f[i].practical<9&&f[i].practical>0)
			{
				printf("enter the practicals marks of %s out of 25\n",fsubject[i]);
				scanf("%d",&f[i].practical);
				if(f[i].practical<9)
				{
					f[i].atkt=1;
					c++;
				}
				else
					f[i].atkt=0;
			}
		}
		
	}
	return c;
}



/*----------------------------------------------------------------------sem3-end-----------------------------------------------------------------------*/

/*----------------------------------------------------------------------sem1-start---------------------------------------------------------------------*/

//first_sem_subject_marks function
void get_first_sem_subject_marks(char fsubject[6][50],int n,struct bca f[6],struct bca first_atkt[])
{
	int i,c=0;
	for(i=0;i<n;i++)
	{
		f[i].atkt=0;
		f[i].theory=0;
		f[i].practical=0;
		f[i].internal=0;
	}
	printf("enter all subject marks\n");
	for(i=0;i<n;i++)
	{
		printf("enter the theory marks of %s out of 40\n",fsubject[i]);
		strcpy(f[i].subject,fsubject[i]);
		scanf("%d",&f[i].theory);
		if(f[i].theory>40||f[i].theory<0)
		{
			printf("invalid marks please enter again\n");
			printf("enter the theory marks of %s out of 40\n",fsubject[i]);
			scanf("%d",&f[i].theory);
		}
		
		if(strcmp(fsubject[i],"P.C.Software")==0)
		{
			printf("enter the practicals marks of p.c.software out of 25\n");
			scanf("%d",&f[i].practical);
			if(f[i].practical>25||f[i].practical<0)
			{
				printf("invalid marks please enter again\n");
				printf("enter the practicals marks of p.c.software out of 25\n");
				scanf("%d",&f[i].practical);
			}
			if(f[i].practical<9)
				f[i].atkt=1;
			continue;
		}
		printf("enter the internal marks of %s out of 10\n",fsubject[i]);
		scanf("%d",&f[i].internal);
		if(f[i].internal>10||f[i].internal<0)
		{
			printf("invalid marks please enter again\n");
			printf("enter the internal marks of %s out of 10\n",fsubject[i]);
			scanf("%d",&f[i].internal);
		}
		if(f[i].internal<4)
			f[i].atkt=1;
	}
	for(i=0;i<n;i++)
	{
		first_atkt[i].atkt=f[i].atkt;
		strcpy(first_atkt[i].subject,f[i].subject);
		first_atkt[i].theory=f[i].theory;
		first_atkt[i].practical=f[i].practical;
		first_atkt[i].internal=f[i].internal;
	}
}




//give atkt function
int give_atkt_exam(char fsubject[6][50],struct bca f[6],int n)
{
	int i,c=0;
	for(i=0;i<n;i++)
	{
		if(f[i].atkt==1)
		{
			if(f[i].theory<13)
			{
				printf("enter the theory marks of %s out of 40\n",fsubject[i]);
				scanf("%d",&f[i].theory);
				if(f[i].theory<13)
				{
					f[i].atkt=1;
					c++;
				}
				else
					f[i].atkt=0;
			}
			if(f[i].internal<4&&f[i].internal>0)
			{
				printf("enter the internal marks of %s out of 10\n",fsubject[i]);
				scanf("%d",&f[i].internal);
				if(f[i].internal<4)
				{
					f[i].atkt=1;
					c++;
				}
				else
					f[i].atkt=0;
			}
			if(f[i].practical<9&&f[i].practical>0)
			{
				printf("enter the practicals marks of %s out of 25\n",fsubject[i]);
				scanf("%d",&f[i].practical);
				if(f[i].practical<9)
				{
					f[i].atkt=1;
					c++;
				}
				else
					f[i].atkt=0;
			}
		}
		
	}
	return c;
}


/*----------------------------------------------------------------------sem1-end-----------------------------------------------------------------------*/




/*----------------------------------------------------------------------sem2-start---------------------------------------------------------------------*/

//second_sem_subject_marks function
void get_second_sem_subject_marks(char fsubject[7][50],int n,struct bca f[7],struct bca second_atkt[])
{

	int i,c=0;
	for(i=0;i<n;i++)
	{
		f[i].atkt=0;
		f[i].theory=0;
		f[i].practical=0;
		f[i].internal=0;
	}
	
	printf("enter all subject marks\n");
	for(i=0;i<n;i++)
	{
		if(strcmp(fsubject[i],"Internet")==0)
		{
			strcpy(f[i].subject,fsubject[i]);
			printf("enter the practicals marks of internet out of 25\n");
			scanf("%d",&f[i].practical);
			if(f[i].practical>25||f[i].practical<0)
			{
				printf("invalid marks please enter again \n");
				printf("enter the practicals marks of internet out of 25\n");
				scanf("%d",&f[i].practical);
			}
			if(f[i].practical<9)
				f[i].atkt=1;
			continue;
		}
		printf("enter the theory marks of %s out of 40\n",fsubject[i]);
		strcpy(f[i].subject,fsubject[i]);
		scanf("%d",&f[i].theory);
		if(f[i].theory>40||f[i].theory<0)
		{
			printf("invalid marks please enter again \n");
			printf("enter the theory marks of %s out of 40 \n",fsubject[i]);
			scanf("%d",&f[i].theory);
		}
		if(f[i].theory<13)
			f[i].atkt=1;
		if(strcmp(fsubject[i],"Problem-Solve-By-C-II")==0)
		{
			printf("enter the practicals marks of problem-solve-by-c-II out of 25\n");
			scanf("%d",&f[i].practical);
			if(f[i].practical>25||f[i].practical<0)
			{
				printf("invalid marks please enter again\n");
				printf("enter the practicals marks of problem-solve-by-c-II out of  out of 25\n");
				scanf("%d",&f[i].practical);
			}
			if(f[i].practical<9)
				f[i].atkt=1;
			continue;
		}
		
		printf("enter the internal marks of %s out of 10\n",fsubject[i]);
		scanf("%d",&f[i].internal);
		if(f[i].internal>10||f[i].internal<0)
		{
			printf("invalid marks please enter again\n");
			printf("enter the internal marks of %s out of 10\n",fsubject[i]);
			scanf("%d",&f[i].internal);
		}
		if(f[i].internal<4)
			f[i].atkt=1;
	}
	for(i=0;i<n;i++)
	{
		second_atkt[i].atkt=f[i].atkt;
		strcpy(second_atkt[i].subject,f[i].subject);
		second_atkt[i].theory=f[i].theory;
		second_atkt[i].practical=f[i].practical;
		second_atkt[i].internal=f[i].internal;
	}
	
}

//give atkt function
int give_atkt_exam_second(char fsubject[7][50],struct bca f[7],int n)
{
	int i,c=0;
	for(i=0;i<n;i++)
	{
		if(f[i].atkt==1)
		{
			if(f[i].practical<9&&f[i].practical>0)
			{
				printf("enter the practicals marks of %s out of 25\n",fsubject[i]);
				scanf("%d",&f[i].practical);
				if(f[i].practical<9)
				{
					f[i].atkt=1;
					c++;
				}
				else
					f[i].atkt=0;
				continue;
			}
			if(f[i].internal<4&&f[i].internal>0)
			{
				printf("enter the internal marks of %s out of 10\n",fsubject[i]);
				scanf("%d",&f[i].internal);
				if(f[i].internal<4)
				{
					f[i].atkt=1;
					c++;
				}
				else
					f[i].atkt=0;
			}
			
			if(f[i].theory<13)
			{
				printf("enter the theory marks of %s out of40\n",fsubject[i]);
				scanf("%d",&f[i].theory);
				if(f[i].theory<13)
				{
					f[i].atkt=1;
					c++;
				}
				else
					f[i].atkt=0;
			}
		}
		
	}
	return c;
}






/*----------------------------------------------------------------------sem2-end-----------------------------------------------------------------------*/



//display function for second sem
void  display(char university[50],char course[50],char fname[30],char name[30],char status[10],char rollno[40],int n,struct bca f[])
{
	int i;
	int x=0,y;
	printf("\n --------------------------------------------------------------------------------------------------------------\n");
	for(i=3;i<23;i++)
	{
		y=i;
		gotoxy(x,y);
		printf("|");
	}
	gotoxy(40,3);
	printf("%s",university);
	gotoxy(5,7);
	printf("Course:%s",course);
	gotoxy(5,8);
	printf("Name:%s",name);
	gotoxy(5,9);
	printf("Father name:%s",fname);
	gotoxy(92,7);
	printf("Roll no:%s",rollno);
	gotoxy(92,8);
	printf("Status:%s",status);
	printf("\n --------------------------------------------------------------------------------------------------------------\n");
	gotoxy(5,12);
	printf(" Subject");
	gotoxy(30,12);
	printf("Theory");
	gotoxy(55,12);
	printf("Internal");
	gotoxy(80,12);
	printf("Practical\n");
	printf("\n --------------------------------------------------------------------------------------------------------------\n");
	x=5;
	y=16;
	for(i=0;i<n;i++)
	{
		x=5;
		gotoxy(x,y+i);
		printf("%s",f[i].subject);
		x=x+25;
		if(f[i].theory>0)
		{
			gotoxy(x,y+i);
			printf("  %d",f[i].theory);
		}
		x=x+25;
		if(f[i].internal>0)
		{
			gotoxy(x,y+i);
			printf("   %d",f[i].internal);
		}
		x=x+25;
		if(f[i].practical>0)
		{
			gotoxy(x,y+i);
			printf("    %d",f[i].practical);
		}
		if(f[i].atkt==1)
		{
			x=x+25;
			gotoxy(x,y+i);
			printf("ATKT");
		}	
	}
	x=111;
	for(i=3;i<23;i++)
	{
		y=i;
		gotoxy(x,y);
		printf("|");
	}
	printf("\n --------------------------------------------------------------------------------------------------------------\n");
}


//check pass fail function
int check_pass_fail(struct bca f[7],int n)
{
	int i,c=0;
	for(i=0;i<n;i++)
	{
		if(f[i].atkt==1)
			c++;
	}
	return c;
}



































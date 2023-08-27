#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
struct file
{
	char fname[10];
}s[100];
struct journalName
{
	char jname[10];
}jo[10];

void editPassword()
{
	char name[10];
	FILE *fr;
	fr=fopen("password","w");
	printf("\nEnter the password");
	fflush(stdin);
	gets(name);
	fputs(name,fr);
	fclose(fr);


	
}
void checkPassword()
{
	char password[10],name[10],ch;
	int i=0,count=3;
	FILE *fr;
	fr=fopen("password","r");
	if(fr==NULL)
	{
		printf("Cannot open file");
	}
	else
	{
	
	

	do
	{
		ch=fgetc(fr);
		
		if(ch!=EOF)
		{
		
		name[i]=ch;
		
	}
		i++;
	}while(ch!=EOF);
while(count>0)
{
	printf("\nEnter your password");
	fflush(stdin);
	gets(password);
	i=strcmp(name,password);
	
if(i==0)
{
	printf("\nAccess granted");
	fclose(fr);
	break;
}
else
{
	printf("\nWrong password you have %d attempts left",--count);
}
	
}
if(count==0)
	{
		printf("\nAll attempts wasted access denied");
		fclose(fr);
		
		exit(0);
	}
}
}
int viewJournal()
{
	FILE *fr,*fw;
	int i=0,ch;
	char c;
	fr=fopen("Files","r");
	fw=fopen("Copy","w");
	printf("Select which one you would like to read");
	while(fread(&s[i],sizeof(struct file),1,fr))
	{
		strcpy(jo[i].jname,s[i].fname);
		fwrite(&jo[i],sizeof(struct journalName),1,fw);
		printf("\n%d Name=",i+1);
		fflush(stdin);
		puts(jo[i].jname);
		
		i++;
	}
	fclose(fr);
	fclose(fw);
	printf("\nEnter your choice");
	scanf("%d",&ch);
	return ch;
	
	
	
	
}
void viewJournalName(k)
{

int i=0;
	FILE *fw,*fr;
	fw=fopen("Files","w");
	fr=fopen("Copy","r");
	while(fread(&jo[i],sizeof(struct journalName),1,fr))
	{
		if(i!=k-1)
		{
			strcpy(s[i].fname,jo[i].jname);
			fwrite(&s[i],sizeof(struct file),1,fw);
			fflush(stdin);
			puts(s[i].fname);
		}
		i++;
	}
fclose(fr);
fclose(fw);
	
		

}

void writeFile(char name[10])
{
	int i;
	
	
	FILE *fl;
	fl=fopen("Files","a+");
	strcpy(s[i].fname,name);
	
	fwrite(&s[i],sizeof(struct file),1,fl);

	
	
	
	fclose(fl);
	printf("\nNamed saved succesfully");
}

void readJournal()
{
	int choice,word=0,letter=0,vowel=0,conso=0;
	checkPassword();
	choice=viewJournal();
	char ch;
	FILE *fr;
	fr=fopen(jo[choice-1].jname,"r");
	if(fr==NULL)
	{
		printf("\nCannot read the file");
		exit(0);
	}
		while(ch!=EOF)
		{
		
		ch=fgetc(fr);
		
		if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
		{
			vowel++;
			letter++;
		}
		else
		{
			if(ch==' ')
			{
				word++;
			}
			else
			{
				conso++;
				letter++;
			}
		}
		printf("%c",ch);
}
printf("\nThe total number of letter=%d",letter);
	printf("\nThe total number of words=%d",word);
	printf("\nThe total number of vowels=%d",vowel);
	printf("\nThe total number of consonants=%d",conso);
	fclose(fr);

	
}
void editJournal()
{
	
	char ch,data[100];
	int choice;
	checkPassword();
	choice=viewJournal();
	FILE *fe;
	fe=fopen(jo[choice-1].jname,"a+");
	if(fe==NULL)
	{
		printf("Cannot create new file ");
		exit(0);
	}
	while(ch!=EOF)
		{
		
		ch=fgetc(fe);
		printf("%c",ch);
}

	fputs("\n",fe);
	fflush(stdin);
	printf("\nEnter the data you want to add");
	fflush(stdin);
	gets(data);
	fputs(data,fe);
	printf("Data appended scussefully");
	fclose(fe);
		
	
}

	

void writeJournal()
{
	char name[10],f[10],date[10];
	int i=0,x,word=0,letter=0,vowel=0,conso=0;
	checkPassword();
	FILE *fp;
	char ch;
	printf("\nEnter the date to save diary entry ");
	fflush(stdin);
	gets(name);
writeFile(name);

	fp=fopen(name,"w");
	
	if(fp==NULL)
	{
		printf("\nCannot create new file writing impossible");
		exit(0);
	}
	else
	{

		fputs("Dear Diary ",fp);
		
		fputs(name,fp);
		fputs("\n",fp);
		
		printf("\nDear Diary\n");
		word=3;
		letter=19;
		vowel=4;
		conso=5;
		do
		{
		
		
		ch=getche();
		letter++;
		if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
		{
			vowel++;
		}
		else
		{
			if(ch==' ')
			{
				word++;
			}
			else
			{
				conso++;
			}
		}
		fputc(ch,fp);
	}while(ch!='$');
	
	
		
	
	printf("\nData saved succesfully");
	printf("\nThe total number of letter=%d",letter);
	printf("\nThe total number of words=%d",word);
	printf("\nThe total number of vowels=%d",vowel);
	printf("\nThe total number of consonants=%d",conso);
	fclose(fp);
	
	
}
}

void main()
{
	int ch,k;
printf("\n\t\t\t\t\t\t\t\t\t\t************Welcome to your diary journal************");
do
{
	printf("\nPress 1 to write your diary journal");
	printf("\nPress 2 to read your diary journal");
	printf("\nPress 3 to edit your diary journal");
	printf("\nPress 4 to delete diary journal");
	printf("\nPress 5 to give new password");
	printf("\nPress 6 to exit");
	printf("\nEnter your choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			writeJournal();
			break;
		case 2:
		readJournal();
		break;	
		case 3:
			editJournal();
			break;
			case 4:
				k=viewJournal();
			viewJournalName(k);	
				
				break;
				
			case 5:
				checkPassword();
				editPassword();
				break;
				case 6:
					exit(0);
					break;
					default:
						printf("Enter correct choice");
					
			
		
			
	}
}while(1);
getch();
}



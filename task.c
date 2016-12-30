#include <stdio.h>
#include <stdlib.h>  
#include <string.h>  

typedef struct
{
	char title[100];
	char content[100];
	int year;
	int mouth;
	int day;
	int finish;
	int prior;
}task;

int taskCount = 0;

task taskList[100];

int mouthList[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void menu(void);
void addTask(task temp[]);
void displayTask(task temp[]);
void finishTask(task temp[]);
void queryTask(task temp[]);
void sortTask(task temp[]);
void saveFile(task temp[]);
void addTaskTime(task temp[]);
void setPrior(task temp[]);

int main(int argc, char const *argv[])
{
	int menuCode = 9;
	while(1)
	{
		menuCode = 9;
		menu();
		printf("Enter the code you want to do: ");
		scanf("%d", &menuCode);
		char c = getchar();                 //scanf does not handle \n   gets handle \n
		switch(menuCode)
		{
			case 1 : 
			displayTask(taskList);
			finishTask(taskList);
			break;

			case 2 :
			addTask(taskList);
			break;

			case 3 :
			queryTask(taskList);
			break;

			case 4 :
			sortTask(taskList);
			break;

			case 5:
			saveFile(taskList);
			break;

			case 6:
			addTaskTime(taskList);
			break;

			case 7:
			setPrior(taskList);

			case 0 :
			break;
		}
		if (menuCode == 0)
		{
			break;
		}
	}

	return 0;
}

void menu(void)
{
	printf(" ------------------------- ******************** -------------------------\n");
	printf("|                                                                       |\n");
	printf("|                            To Do List Menu                            |\n");
	printf("|                                                                       |\n");
	printf(" ------------------------- ******************** -------------------------\n");
	printf("|                                                                       |\n");
	printf("|                                                                       |\n");
	printf("|                         1. Display Task                               |\n");
	printf("|                                                                       |\n");
	printf("|                         2. Add New Task                               |\n");
	printf("|                                                                       |\n");
	printf("|                         3. Query   Task                               |\n");
	printf("|                                                                       |\n");
	printf("|                         4. Sort    Task                               |\n");
	printf("|                                                                       |\n");
	printf("|                         5. Save    Task                               |\n");
	printf("|                                                                       |\n");
	printf("|                         6. Add Task Time                              |\n");
	printf("|                                                                       |\n");
	printf("|                         7. Set Task Prior                             |\n");
	printf("|                                                                       |\n");
	printf("|                         0. Exit                                       |\n");
	printf("|                                                                       |\n");
	printf("|                                                                       |\n");
	printf(" ------------------------- ******************** -------------------------\n");

}

void addTask(task temp[])
{
	int temYear, temMouth, temDay;
	char temTitle[100];
	char temContent[100];

	printf("Enter the title   of new task: ");
	gets(temTitle);
	printf("Enter the content of new task: ");
	gets(temContent);
	printf("Enter the year    of new task: ");
	scanf("%d", &temYear);
	printf("Enter the mouth   of new task: ");
	scanf("%d", &temMouth);
	printf("Enter the day     of new task: ");
	scanf("%d", &temDay);

	strcpy(temp[taskCount].title, temTitle);
	strcpy(temp[taskCount].content, temContent);
	temp[taskCount].year = temYear;
	temp[taskCount].mouth = temMouth;
	temp[taskCount].day = temDay;
	taskCount++;

	printf("Add new task finished.\n");
	printf("Back to menu...\n");
}

void displayTask(task temp[])
{

	printf(" ------------------------- ******************** -------------------------\n");
	printf("|                                                                       |\n");
	printf("|                               To Do List                              |\n");
	printf("|                                                                       |\n");
	printf(" ------------------------- ******************** -------------------------\n");
	printf("|                                                                       |\n");
	printf("|                                                                       |\n");
	printf("  order  title  cotent  date  finish(1)  prior\n");
	for (int i = 0; i < taskCount; ++i)
	{
		printf("  %d.  %s  %s  %d--%d--%d  %d  %d\n", 
			(i+1), temp[i].title, temp[i].content, temp[i].year, temp[i].mouth, temp[i].day, temp[i].finish, temp[i].prior);
	}
	printf("|                                                                       |\n");
	printf("|                                                                       |\n");
	printf(" ------------------------- ******************** -------------------------\n");
}

void finishTask(task temp[])
{
	int id;
	printf("Enter the code of task you want to finish(Enter 0 back to menu) : ");
	scanf("%d", &id);
	if (id == 0)
	{
		return;
	}
	temp[id-1].finish = 1;
	printf("The task has been marked with finish.\n");
	printf("Back to menu...\n");
}

void queryTask(task temp[])
{
	char charTmp[100];
	printf("Enter the key word: ");
	gets(charTmp);
	printf("Searching...\n");
	printf(" ------------------------- ******************** -------------------------\n");
	printf("|                                                                       |\n");
	printf("|                           Searching Result                            |\n");
	printf("|                                                                       |\n");
	printf(" ------------------------- ******************** -------------------------\n");
	printf("|                                                                       |\n");
	printf("|                                                                       |\n");
	int j = 0;
	for (int i = 0; i < taskCount; ++i)
	{
		if (strcmp(charTmp, temp[i].title) == 0 || strcmp(charTmp, temp[i].content) == 0)
		{
			printf("  %d.  %s  %s  %d--%d--%d  %d  %d\n", 
				(j+1), temp[i].title, temp[i].content, temp[i].year, temp[i].mouth, temp[i].day, temp[i].finish, temp[i].prior);
			j++;
		}
	}
	printf("|                                                                       |\n");
	printf("|                                                                       |\n");
	printf(" ------------------------- ******************** -------------------------\n");
	printf("\n");
	printf("query task has been finished.\n");
	printf("Back to menu...\n");
}

void sortTask(task temp[])
{
	int id;
	printf("title(1)  content(2)  date(3)  finish(4)\n");
	printf("Enter the code you want to sort by: ");
	scanf("%d", &id);

	switch(id)
	{
		case 1:
		for (int i = 0; i < taskCount; ++i)
		{
			for (int j = i; j < taskCount; ++j)
			{
				if (strcmp(temp[i].title, temp[j].title) > 0)
				{
					task tempTask = temp[i];
					temp[i] = temp[j];
					temp[j] = tempTask;
				}
			}
		}
		break;

		case 2:
		for (int i = 0; i < taskCount; ++i)
		{
			for (int j = i; j < taskCount; ++j)
			{
				if (strcmp(temp[i].content, temp[j].content) > 0)
				{
					task tempTask = temp[i];
					temp[i] = temp[j];
					temp[j] = tempTask;
				}
			}
		}
		break;

		case 3:
		for (int i = 0; i < taskCount; ++i)
		{
			for (int j = 0; j < taskCount; ++j)
			{
				int state = 0;
				if (temp[i].year > temp[j].year)
				{
					state = 1;
				}
				else if (temp[i].year < temp[j].year)
				{
					state = 0;
				}
				else
				{
					if (temp[i].mouth > temp[j].mouth)
					{
						state = 1;
					}
					else if (temp[i].mouth < temp[j].mouth)
					{
						state = 0;
					}
					else
					{
						if (temp[i].day > temp[j].day)
						{
							state = 1;
						}
						else if (temp[i].day < temp[j].day)
						{
							state = 0;
						}
						else 
						{
							state = 0;
						}
					}
				}

				if (!state)
				{
					task tempTask = temp[i];
					temp[i] = temp[j];
					temp[j] = tempTask;
				}
			}

		}
		break;

		case 4:
		for (int i = 0; i < taskCount; ++i)
		{
			for (int j = i; j < taskCount; ++j)
			{
				if ((temp[i].finish - temp[j].finish) > 0)
				{
					task tempTask = temp[i];
					temp[i] = temp[j];
					temp[j] = tempTask;
				}
			}
		}
		break;
	}

	displayTask(taskList);
	printf("Sort task has been finished.\n");
	printf("Back to menu...\n");

}

void saveFile(task temp[])
{
	FILE *fp;
    if ((fp = fopen("tasks_dat.txt", "w")) == NULL)
    {
        printf("cannot open file\n");
     	return;
    }
    for (int i = 0; i<taskCount; i++)
    {
    	fprintf(fp, "%s\t%s\t%d\t%d\t%d\t%d\t%d\n", 
    		temp[i].title, temp[i].content, temp[i].year, temp[i].mouth, temp[i].day, temp[i].finish, temp[i].prior);
    }    
    fclose(fp);
    printf("Task data has been saved to file: tasks_dat.txt\n");
}

void addTaskTime(task temp[])
{
	displayTask(temp);
	int id;
	int days;
	printf("Enter the code you want to add deadline time: ");
	scanf("%d", &id);
	printf("Enter the days you want to add: ");
	scanf("%d" , &days);

	if (days + temp[id-1].day > mouthList[id-1])
	{
		temp[id-1].day = (temp[id-1].day + days) % mouthList[id-1];
		temp[id-1].mouth++;
		if (temp[id-1].mouth > 12)
		{
			temp[id-1].mouth = temp[id-1].mouth % 12;
			temp[id-1].year++;
		}
	}
	else
	{
		temp[id-1].day = temp[id-1].day + days;
	}

	printf("Add task time has been finished.\n");
	displayTask(temp);

}


void setPrior(task temp[])
{
	displayTask(temp);
	printf("Enter the task you want to set: ");
	int id;
	scanf("%d", &id);
	printf("Set prior(1 - 5), 1 is the most important and 0 is not set\n");
	printf("Enter the prior order you want to set(1-5): ");
	scanf("%d", &temp[id-1].prior);
	displayTask(temp);
}

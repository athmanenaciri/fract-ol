
#include<stdio.h>
#include<stdlib.h>

typedef struct s_user
{
	char	name[20];
	int age;
	float hh;

} t_user;


void ft_scan(char *pr, char *format, void *ptr)
{
	printf("%s", pr);
	scanf(format, ptr);
}


int main()
{
	t_user *user;
	user  = malloc(sizeof(t_user));

	ft_scan("Name :", "%s", user->name);
	ft_scan("Age :",  "%d", &user->age);
	ft_scan("Height :", "%f", &user->hh);

	printf("%s %d %0.2f", user->name, user->age, user->hh);
}

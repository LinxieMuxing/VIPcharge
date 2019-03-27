#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct member{
	char name[20];
	char num[20];
	int total;
	struct member *next;
}VIP;

VIP *Creat(void);
void Print(VIP *head);
void Find(VIP *head);
void Free(VIP *head);
int main(int argc, char *argv[]) {
	VIP *head = Creat();
	Find(head);
	Free(head);
	return 0;
}
VIP *Creat(void)
{
	VIP *head = NULL, *p = NULL, *pre = NULL;
	int i;
	char ch;
	while(1){
		p = (VIP*)malloc(sizeof(VIP));
		p->next = NULL;
		printf("����������ÿ����Ա�ı�š����������֣� \n");
		scanf("%s %s %d",p->num,p->name,&p->total);
		if(head==NULL){
			head = p;
			pre = p;
		}
		else{
			pre->next = p;
			pre = p;
		}
		pre->next = NULL;
		printf("�Ƿ��������,��Y���������룬�������ͽ���.\n");
		scanf(" %c",&ch);
		if(ch!='Y'){
			break;
		}
	}
	getchar();
	return head;
}
void Print(VIP *head)
{
	VIP *pre = head;
	printf("���������ÿ����Ա�ı�š����������֣� \n");
	while(pre!=NULL){
		printf("%s %s %d\n",pre->num,pre->name,pre->total);
		pre = pre->next;
	}
}
void Find(VIP *head)
{
	VIP *pre = head;
	char num[20];
	char name[20];
	int total;
	int find = 0;
	printf("������Ҫ�޸ĵĻ�Ա��ţ�\n");
	gets(num);
	while(pre!=NULL){
		if(strcmp(num,pre->num)==0){
			find = 1;
			printf("������Ҫ�޸ĵı�ţ�");
			gets(num);
			printf("������Ҫ�޸ĵ�������");
			gets(name);
			printf("������Ҫ�޸ĵĻ��֣�");
			scanf("%d",&total);
			strcpy(pre->num,num);
			strcpy(pre->name,name);
			pre->total = total;
		}
		pre = pre->next;
	}
	if(!find){
		printf("�޸�ʧ��.\n�����ڴ���ϵ��.\n");
	}
	else{
		Print(head);
	}
}
void Free(VIP *head)
{
	VIP *p = head, *pre = NULL;
	while(p!=NULL){
		pre = p;
		p = p->next;
		free(pre);
	}
}

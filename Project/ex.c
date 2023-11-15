#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>

#define NUMBER 50

typedef struct {
	char subject[20]; // ���� �̸�
	char day;		  // ���� ����
	int time;		  // ���� �ð�
	int credit;		  // ���� ����
	int hour;		  // ���� �ð���
}Memo;

Memo data[NUMBER];

void gotoxy(int x, int y); // ��ǥ
void menu(); // ���θ޴�
void apply(); // ������û
void change(); // ������û ����
void schedule();// �ð�ǥ ���
void credit(); // ������

int num = 1; // ���� ��ȣ �������� ����
int ALL_Credit = 0; // ������ �������� ����
char A[10] = "EMPTY"; // ������û ���濡�� ���� ������ �� ���
int z = 1; //�޸��忡�� ������ ���ϱ� ���� �Լ�

void main() {
	FILE* fp;
	fp = fopen("Memory.txt", "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Memory.txt file �� �� �����ϴ�.\n3���� ���� ȭ������ ���ư��ϴ�.\n");
		Sleep(3000);
		system("cls");
		goto main;
	}
	while (!feof(fp)) {
		fscanf(fp, "%d %s %c %d %d %d", &num, data[num].subject, &data[num].day, &data[num].time, &data[num].credit, &data[num].hour);
		num++;
	}
	num--;
	fclose(fp);
	for (z = 1; z <= num; z++) {
		ALL_Credit += data[z].credit;
	}
main:
	menu();
}

void menu() {
	int m_num; // �޴����� �Է� ��
	int i;
	gotoxy(14, 3);
	printf("����������������������������������������������������������������������������������������������������������");
	for (i = 4; i < 23; i++) {
		gotoxy(14, i);
		printf("��                                                   ��");
	}
	gotoxy(14, 23);
	printf("����������������������������������������������������������������������������������������������������������");
	gotoxy(33, 8);
	printf("������û ���α׷�");
	gotoxy(28, 10);
	printf("---------------------------");
	gotoxy(28, 12);
	printf("1. ������û");
	gotoxy(28, 13);
	printf("2. ������û ����");
	gotoxy(28, 14);
	printf("3. �ð�ǥ ���");
	gotoxy(28, 15);
	printf("4. �� ����");
	gotoxy(28, 16);
	printf("5. ���α׷� ����");
	gotoxy(25, 18);
	printf("1~5�� �߿��� �����Ͽ� �ּ��� : ");
	scanf("%d", &m_num);
	switch (m_num) {
	case 1:
		system("cls");
		apply();
		break;
	case 2:
		system("cls");
		change();
		break;
	case 3:
		system("cls");
		schedule();
		break;
	case 4:
		system("cls");
		credit();
		break;
	case 5:
		system("cls");
		gotoxy(22, 6);
		printf("������������������������������������������������������������������������������");
		for (i = 7; i < 12; i++) {
			gotoxy(22, i);
			printf("��                                     ��");
		}
		gotoxy(22, 12);
		printf("������������������������������������������������������������������������������");
		gotoxy(26, 9);
		printf("�ء� ���α׷��� �����մϴ� �ء�");
		gotoxy(1, 18);
		FILE* fp1;
		fp1 = fopen("Memory.txt", "w");
		if (fp1 == NULL)
		{
			fprintf(stderr, "Memory.txt file �� �� �����ϴ�.\n");
			exit(1);
		}
		for (i = 1; i < num; i++) {
			fprintf(fp1, "%d %s %c %d %d %d\n", i, data[i].subject, data[i].day, data[i].time, data[i].credit, data[i].hour);
		}
		fclose(fp1);
		exit(1);
		break;
	default:
		system("cls");
		menu();
		break;
	}
}
// ���θ޴�
void apply() {
	int i;
	gotoxy(14, 3);
	printf("����������������������������������������������������������������������������������������������������������");
	for (i = 4; i < 23; i++) {
		gotoxy(14, i);
		printf("��                                                   ��");
	}
	gotoxy(14, 23);
	printf("����������������������������������������������������������������������������������������������������������");
	gotoxy(34, 9);
	printf("��  ��  ��  û");
	gotoxy(29, 11);
	printf("------------------------");
	gotoxy(30, 13);
	printf("���� ��ȣ %d", num);
	gotoxy(30, 14);
	printf("���� �̸� : ");
	scanf("%s", data[num].subject); // ���� �̸� �߰�
	fflush(stdin);

loop: {
	gotoxy(30, 15);
	printf("���� ����(a~e) :        ");
	gotoxy(47, 15);
	scanf("%c", &data[num].day); // ���� ���� �߰�
	if (data[num].day >= 'a' && data[num].day <= 'e') // a~e���� �Է°��� �ƴϸ� ���Է�
		goto times;
	else
		goto loop;
	}
//���� ����
times: {
gotoxy(30, 16);
printf("���� �ð�(1~8) :        ");
gotoxy(47, 16);
scanf("%d", &data[num].time); // ���� �ð� �߰�
if (data[num].time >= 1 && data[num].time <= 8) { // 1~8���� �Է°��� �ƴϸ� ���Է�
	for (i = 1; i < num; i++) { // �ߺ��� �ð��밡 �ִ��� �˻�
		if (data[num].day == data[num - i].day) {
			if (data[num].time == data[num - i].time) {
				gotoxy(21, 19);
				printf("�ء� �̹� ��ϵǾ� �ִ� �ð����Դϴ� �ء�");
				gotoxy(21, 20);
				printf("�ء�        �ٽ� ����� �ּ���       �ء�");
				Sleep(2000);
				system("cls");
				apply();
			}
		}
	}
	goto credits;
}
else {
	goto times;
}
}
//���� �ð�
credits: {
gotoxy(30, 17);
printf("���� ����(1~3) :        ");
gotoxy(47, 17);
scanf("%d", &data[num].credit); // ���� ���� �߰�
if (data[num].credit < 1 || data[num].credit > 3) // 1~3���� �Է°��� �ƴϸ� ���Է�
goto credits;
else
goto hours;
}
//���� ����
hours: {
gotoxy(30, 18);
printf("���� �ð���(1~4) :       ");
gotoxy(49, 18);
scanf("%d", &data[num].hour);
if (data[num].hour < 1 || data[num].hour > 4)
goto hours;
}
//���� �ð���
ALL_Credit += data[num].credit; // �������� ���� �߰�
if (ALL_Credit > 19) { // �������� 19������ ������ ���� �޴� ���
	gotoxy(25, 20);
	printf("�ء� 19������ �ʰ��Ͽ����ϴ�. �ء�");
	gotoxy(25, 21);
	printf("�ء� ���� �޴��� ���ư��ϴ�.  �ء�");
	ALL_Credit -= data[num].credit;
	Sleep(2000);
	system("cls");
	menu();
}
num++;
Sleep(1000); // ���� ȭ������ 1�� ����
system("cls");
menu();
}
// ������û
void change() {
	int x; // ������ ���� ��ȣ ��
	int i;
	char* d_day = " ";
	for (i = 1; i < num; i++) {
		switch (data[i].day) { // ���� ���� ��Ÿ���� ��
		case 'a':
			d_day = "��";
			break;
		case 'b':
			d_day = "ȭ";
			break;
		case 'c':
			d_day = "��";
			break;
		case 'd':
			d_day = "��";
			break;
		case 'e':
			d_day = "��";
			break;
		}
		printf("���� ��ȣ%2d\n���� �̸� : %s\n���� ���� : %s\n���� �ð� : %d\n���� ���� : %d\n���� �ð��� : %d\n\n",
			i, data[i].subject, d_day, data[i].time, data[i].credit, data[i].hour);
	}
	printf("-------------------------------\n");
	printf("���� ���Ͽ��� x �Է��ϸ� �ð�ǥ���� ����\n");
	printf("������ ���� ��ȣ �Է�( 0 �Է½� ���θ޴��� ���ư�) : ");
	scanf("%d", &x);
	ALL_Credit -= data[x].credit;
	data[x].time = 0;
	data[x].hour = 0;
	if (x == 0) {
		system("cls");
		menu();
	}
	//0�� �ԷµǸ� ���� �޴���
	while (x > num - 1) {
		printf("���� ��ȣ�� �������� �ʽ��ϴ�.\n");
		printf("�ٽ� �Է��� �ּ��� : ");
		scanf("%d", &x);
	}
	// ������ ���� ��ȣ�� �������� ���� ��
	printf("���� ��ȣ %d\n", x);
	printf("���� �̸� : ");
	scanf("%s", data[x].subject); // ���� �̸� �߰�
	getchar();

loop: {
	printf("���� ����(a~e) : ");
	scanf("%c", &data[x].day); // ���� ���� �߰�
	if (data[x].day == 'x') { // x �Է� �� �ð�ǥ���� ����
		data[x].credit = 0;
		data[x].time = 0;
		data[x].hour = 0;
		strcpy(data[x].subject, A);
		printf("�ء� �����Ǿ����ϴ�. �ء�");
		Sleep(1000);
		system("cls");
		menu();
	}
	if (data[x].day >= 'a' && data[x].day <= 'e') // a~e���� �Է°��� �ƴϸ� ���Է�
		goto times;
	else
		goto loop;
	}
//���� ����
times: {
printf("���� �ð�(1~8) : ");
scanf("%d", &data[x].time); // ���� �ð� �߰�
if (data[x].time >= 1 && data[x].time <= 8) // 1~8���� �Է°��� �ƴϸ� ���Է�
	goto credits;
else
	goto times;
}
//���� �ð�
credits: {
printf("���� ����(1~3) : ");
scanf("%d", &data[x].credit); // ���� ���� �߰�
ALL_Credit += data[x].credit;
if (ALL_Credit > 19) { // �������� 19������ ������ ���� �޴� ���
	printf("�ء� 19������ �ʰ��Ͽ����ϴ�. �ء�\n");
	ALL_Credit -= data[x].credit;
	goto credits;
}
if (data[x].credit < 1 || data[x].credit > 3) // 1~3���� �Է°��� �ƴϸ� ���Է�
goto credits;
else
goto hours;
}
//���� ����
hours: {
printf("���� �ð��� : ");
scanf("%d", &data[x].hour);
if (data[x].hour < 1 || data[x].hour > 4) {
	goto hours;
}
printf("\n�ء� ����Ǿ����ϴ� �ء�");
}
//���� �ð���
Sleep(2000);
system("cls");
menu();
}
// ������û ����
void schedule() {
	int s_num;
	int a; // ���θ޴��� ���ư� �� �Է�
	int i;
	int n;

	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��      ��      ��      ȭ      ��      ��      ��      ��      ��      ��      ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��              ��              ��              ��              ��              ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��              ��              ��              ��              ��              ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��              ��              ��              ��              ��              ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��              ��              ��              ��              ��              ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��              ��              ��              ��              ��              ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��              ��              ��              ��              ��              ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��              ��              ��              ��              ��              ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��              ��              ��              ��              ��              ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������\n");

	for (s_num = 1; s_num < num; s_num++) {
		int x = 0;
		int y;
		n = data[s_num].hour;
		for (i = 1; i <= n; i++) {
			x += 2;
			y = 0;
			y = data[s_num].time * 2 + x; // 8���� �̻��� �ð�ǥ�� ǥ����� �ʰԲ� ����
			if (y < 20) {
				if (data[s_num].day == 'a') { //ǥ��� ��
					switch (data[s_num].time) {
					case 1:
						gotoxy(2, 2 + x);
						printf("%s", data[s_num].subject);
						break;
					case 2:
						gotoxy(2, 4 + x);
						printf("%s", data[s_num].subject);
						break;
					case 3:
						gotoxy(2, 6 + x);
						printf("%s", data[s_num].subject);
						break;
					case 4:
						gotoxy(2, 8 + x);
						printf("%s", data[s_num].subject);
						break;
					case 5:
						gotoxy(2, 10 + x);
						printf("%s", data[s_num].subject);
						break;
					case 6:
						gotoxy(2, 12 + x);
						printf("%s", data[s_num].subject);
						break;
					case 7:
						gotoxy(2, 14 + x);
						printf("%s", data[s_num].subject);
						break;
					case 8:
						gotoxy(2, 18);
						printf("%s", data[s_num].subject);
						break;
					default:
						break;
					}
				}
				else if (data[s_num].day == 'b') {
					switch (data[s_num].time) {
					case 1:
						gotoxy(17, 2 + x);
						printf("%s", data[s_num].subject);
						break;
					case 2:
						gotoxy(17, 4 + x);
						printf("%s", data[s_num].subject);
						break;
					case 3:
						gotoxy(17, 6 + x);
						printf("%s", data[s_num].subject);
						break;
					case 4:
						gotoxy(17, 8 + x);
						printf("%s", data[s_num].subject);
						break;
					case 5:
						gotoxy(17, 10 + x);
						printf("%s", data[s_num].subject);
						break;
					case 6:
						gotoxy(17, 12 + x);
						printf("%s", data[s_num].subject);
						break;
					case 7:
						gotoxy(17, 14 + x);
						printf("%s", data[s_num].subject);
						break;
					case 8:
						gotoxy(17, 18);
						printf("%s", data[s_num].subject);
						break;
					default:
						break;
					}
				}
				else if (data[s_num].day == 'c') {
					switch (data[s_num].time) {
					case 1:
						gotoxy(32, 2 + x);
						printf("%s", data[s_num].subject);
						break;
					case 2:
						gotoxy(32, 4 + x);
						printf("%s", data[s_num].subject);
						break;
					case 3:
						gotoxy(32, 6 + x);
						printf("%s", data[s_num].subject);
						break;
					case 4:
						gotoxy(32, 8 + x);
						printf("%s", data[s_num].subject);
						break;
					case 5:
						gotoxy(32, 10 + x);
						printf("%s", data[s_num].subject);
						break;
					case 6:
						gotoxy(32, 12 + x);
						printf("%s", data[s_num].subject);
						break;
					case 7:
						gotoxy(32, 14 + x);
						printf("%s", data[s_num].subject);
						break;
					case 8:
						gotoxy(32, 18);
						printf("%s", data[s_num].subject);
						break;
					default:
						break;
					}
				}
				else if (data[s_num].day == 'd') {
					switch (data[s_num].time) {
					case 1:
						gotoxy(47, 2 + x);
						printf("%s", data[s_num].subject);
						break;
					case 2:
						gotoxy(47, 4 + x);
						printf("%s", data[s_num].subject);
						break;
					case 3:
						gotoxy(47, 6 + x);
						printf("%s", data[s_num].subject);
						break;
					case 4:
						gotoxy(47, 8 + x);
						printf("%s", data[s_num].subject);
						break;
					case 5:
						gotoxy(47, 10 + x);
						printf("%s", data[s_num].subject);
						break;
					case 6:
						gotoxy(47, 12 + x);
						printf("%s", data[s_num].subject);
						break;
					case 7:
						gotoxy(47, 14 + x);
						printf("%s", data[s_num].subject);
						break;
					case 8:
						gotoxy(47, 18);
						printf("%s", data[s_num].subject);
						break;
					default:
						break;
					}
				}
				else if (data[s_num].day == 'e') {
					switch (data[s_num].time) {
					case 1:
						gotoxy(62, 2 + x);
						printf("%s", data[s_num].subject);
						break;
					case 2:
						gotoxy(62, 4 + x);
						printf("%s", data[s_num].subject);
						break;
					case 3:
						gotoxy(62, 6 + x);
						printf("%s", data[s_num].subject);
						break;
					case 4:
						gotoxy(62, 8 + x);
						printf("%s", data[s_num].subject);
						break;
					case 5:
						gotoxy(62, 10 + x);
						printf("%s", data[s_num].subject);
						break;
					case 6:
						gotoxy(62, 12 + x);
						printf("%s", data[s_num].subject);
						break;
					case 7:
						gotoxy(62, 14 + x);
						printf("%s", data[s_num].subject);
						break;
					case 8:
						gotoxy(62, 18);
						printf("%s", data[s_num].subject);
						break;
					default:
						break;
					}
				}
				else
					break;
			}
		}
	}
	//8���� �ʰ� �Էµ��� �ʰ� ����

loop:
	gotoxy(3, 21);
	printf("�������� ���ư����� 1 �Է� :             ");
	gotoxy(32, 21);
	scanf("%d", &a);

	if (a == 1) {
		system("cls");
		menu();
	}
	// �Է°��� 1�� �ƴϸ� �ٽ� �Է�
	else
		goto loop;
}
// �ð�ǥ ���
void credit() {
	int i;
	gotoxy(14, 3);
	printf("����������������������������������������������������������������������������������������������������������");
	for (i = 4; i < 23; i++) {
		gotoxy(14, i);
		printf("��                                                   ��");
	}
	gotoxy(14, 23);
	printf("����������������������������������������������������������������������������������������������������������");
	gotoxy(38, 9);
	printf("�� ����");
	gotoxy(30, 11);
	printf("------------------------");
	gotoxy(30, 13);
	printf("��û�� �� ���� : %2d", ALL_Credit);
	gotoxy(30, 15);
	printf("------------------------");
	Sleep(2000);
	menu();
}
// ������
void gotoxy(int x, int y) //(80, 24)
{
	COORD Pos = { x - 1,y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
// ��ǥ
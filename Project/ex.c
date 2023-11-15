#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>

#define NUMBER 50

typedef struct {
	char subject[20]; // °ú¸ñ ÀÌ¸§
	char day;		  // °ú¸ñ ¿äÀÏ
	int time;		  // °ú¸ñ ½Ã°£
	int credit;		  // °ú¸ñ ÇÐÁ¡
	int hour;		  // °­ÀÇ ½Ã°£·®
}Memo;

Memo data[NUMBER];

void gotoxy(int x, int y); // ÁÂÇ¥
void menu(); // ¸ÞÀÎ¸Þ´º
void apply(); // ¼ö°­½ÅÃ»
void change(); // ¼ö°­½ÅÃ» º¯°æ
void schedule();// ½Ã°£Ç¥ Ãâ·Â
void credit(); // ÃÑÇÐÁ¡

int num = 1; // °ú¸ñ ¹øÈ£ Àü¿ªº¯¼ö ¼³Á¤
int ALL_Credit = 0; // ÃÑÇÐÁ¡ Àü¿ªº¯¼ö ¼³Á¤
char A[10] = "EMPTY"; // ¼ö°£½ÅÃ» º¯°æ¿¡¼­ °ú¸ñ »èÁ¦ÇÒ ¶§ »ç¿ë
int z = 1; //¸Þ¸ðÀå¿¡¼­ ÃÑÇÐÁ¡ ´õÇÏ±â À§ÇÑ ÇÔ¼ö

void main() {
	FILE* fp;
	fp = fopen("Memory.txt", "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Memory.txt file ¿­ ¼ö ¾ø½À´Ï´Ù.\n3ÃÊÈÄ ¸ÞÀÎ È­¸éÀ¸·Î µ¹¾Æ°©´Ï´Ù.\n");
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
	int m_num; // ¸Þ´º¼±ÅÃ ÀÔ·Â °ª
	int i;
	gotoxy(14, 3);
	printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
	for (i = 4; i < 23; i++) {
		gotoxy(14, i);
		printf("¦¢                                                   ¦¢");
	}
	gotoxy(14, 23);
	printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
	gotoxy(33, 8);
	printf("¼ö°­½ÅÃ» ÇÁ·Î±×·¥");
	gotoxy(28, 10);
	printf("---------------------------");
	gotoxy(28, 12);
	printf("1. ¼ö°­½ÅÃ»");
	gotoxy(28, 13);
	printf("2. ¼ö°­½ÅÃ» º¯°æ");
	gotoxy(28, 14);
	printf("3. ½Ã°£Ç¥ Ãâ·Â");
	gotoxy(28, 15);
	printf("4. ÃÑ ÇÐÁ¡");
	gotoxy(28, 16);
	printf("5. ÇÁ·Î±×·¥ Á¾·á");
	gotoxy(25, 18);
	printf("1~5¹ø Áß¿¡¼­ ¼±ÅÃÇÏ¿© ÁÖ¼¼¿ä : ");
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
		printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
		for (i = 7; i < 12; i++) {
			gotoxy(22, i);
			printf("¦¢                                     ¦¢");
		}
		gotoxy(22, 12);
		printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
		gotoxy(26, 9);
		printf("¡Ø¡Ø ÇÁ·Î±×·¥À» Á¾·áÇÕ´Ï´Ù ¡Ø¡Ø");
		gotoxy(1, 18);
		FILE* fp1;
		fp1 = fopen("Memory.txt", "w");
		if (fp1 == NULL)
		{
			fprintf(stderr, "Memory.txt file ¿­ ¼ö ¾ø½À´Ï´Ù.\n");
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
// ¸ÞÀÎ¸Þ´º
void apply() {
	int i;
	gotoxy(14, 3);
	printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
	for (i = 4; i < 23; i++) {
		gotoxy(14, i);
		printf("¦¢                                                   ¦¢");
	}
	gotoxy(14, 23);
	printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
	gotoxy(34, 9);
	printf("¼ö  °­  ½Å  Ã»");
	gotoxy(29, 11);
	printf("------------------------");
	gotoxy(30, 13);
	printf("°ú¸ñ ¹øÈ£ %d", num);
	gotoxy(30, 14);
	printf("°ú¸ñ ÀÌ¸§ : ");
	scanf("%s", data[num].subject); // °ú¸ñ ÀÌ¸§ Ãß°¡
	fflush(stdin);

loop: {
	gotoxy(30, 15);
	printf("°ú¸ñ ¿äÀÏ(a~e) :        ");
	gotoxy(47, 15);
	scanf("%c", &data[num].day); // °ú¸ñ ¿äÀÏ Ãß°¡
	if (data[num].day >= 'a' && data[num].day <= 'e') // a~e»çÀÌ ÀÔ·Â°ªÀÌ ¾Æ´Ï¸é ÀçÀÔ·Â
		goto times;
	else
		goto loop;
	}
//°ú¸ñ ¿äÀÏ
times: {
gotoxy(30, 16);
printf("°ú¸ñ ½Ã°£(1~8) :        ");
gotoxy(47, 16);
scanf("%d", &data[num].time); // °ú¸ñ ½Ã°£ Ãß°¡
if (data[num].time >= 1 && data[num].time <= 8) { // 1~8»çÀÌ ÀÔ·Â°ªÀÌ ¾Æ´Ï¸é ÀçÀÔ·Â
	for (i = 1; i < num; i++) { // Áßº¹µÈ ½Ã°£´ë°¡ ÀÖ´ÂÁö °Ë»ç
		if (data[num].day == data[num - i].day) {
			if (data[num].time == data[num - i].time) {
				gotoxy(21, 19);
				printf("¡Ø¡Ø ÀÌ¹Ì µî·ÏµÇ¾î ÀÖ´Â ½Ã°£´ëÀÔ´Ï´Ù ¡Ø¡Ø");
				gotoxy(21, 20);
				printf("¡Ø¡Ø        ´Ù½Ã µî·ÏÇØ ÁÖ¼¼¿ä       ¡Ø¡Ø");
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
//°ú¸ñ ½Ã°£
credits: {
gotoxy(30, 17);
printf("°ú¸ñ ÇÐÁ¡(1~3) :        ");
gotoxy(47, 17);
scanf("%d", &data[num].credit); // °ú¸ñ ÇÐÁ¡ Ãß°¡
if (data[num].credit < 1 || data[num].credit > 3) // 1~3»çÀÌ ÀÔ·Â°ªÀÌ ¾Æ´Ï¸é ÀçÀÔ·Â
goto credits;
else
goto hours;
}
//°ú¸ñ ÇÐÁ¡
hours: {
gotoxy(30, 18);
printf("°­ÀÇ ½Ã°£·®(1~4) :       ");
gotoxy(49, 18);
scanf("%d", &data[num].hour);
if (data[num].hour < 1 || data[num].hour > 4)
goto hours;
}
//°­ÀÇ ½Ã°£·®
ALL_Credit += data[num].credit; // ÃÑÇÐÁ¡¿¡ ÇÐÁ¡ Ãß°¡
if (ALL_Credit > 19) { // ÃÑÇÐÁ¡ÀÌ 19ÇÐÁ¡À» ³ÑÀ¸¸é ¸ÞÀÎ ¸Þ´º Ãâ·Â
	gotoxy(25, 20);
	printf("¡Ø¡Ø 19ÇÐÁ¡À» ÃÊ°úÇÏ¿´½À´Ï´Ù. ¡Ø¡Ø");
	gotoxy(25, 21);
	printf("¡Ø¡Ø ¸ÞÀÎ ¸Þ´º·Î µ¹¾Æ°©´Ï´Ù.  ¡Ø¡Ø");
	ALL_Credit -= data[num].credit;
	Sleep(2000);
	system("cls");
	menu();
}
num++;
Sleep(1000); // ´ÙÀ½ È­¸éÀ¸·Î 1ÃÊ Áö¿¬
system("cls");
menu();
}
// ¼ö°­½ÅÃ»
void change() {
	int x; // º¯°æÇÒ °ú¸ñ ¹øÈ£ °ª
	int i;
	char* d_day = " ";
	for (i = 1; i < num; i++) {
		switch (data[i].day) { // °ú¸ñ ¿äÀÏ ³ªÅ¸³»ÁÙ °ª
		case 'a':
			d_day = "¿ù";
			break;
		case 'b':
			d_day = "È­";
			break;
		case 'c':
			d_day = "¼ö";
			break;
		case 'd':
			d_day = "¸ñ";
			break;
		case 'e':
			d_day = "±Ý";
			break;
		}
		printf("°ú¸ñ ¹øÈ£%2d\n°ú¸ñ ÀÌ¸§ : %s\n°ú¸ñ ¿äÀÏ : %s\n°ú¸ñ ½Ã°£ : %d\n°ú¸ñ ÇÐÁ¡ : %d\n°­ÀÇ ½Ã°£·® : %d\n\n",
			i, data[i].subject, d_day, data[i].time, data[i].credit, data[i].hour);
	}
	printf("-------------------------------\n");
	printf("°ú¸ñ ¿äÀÏ¿¡¼­ x ÀÔ·ÂÇÏ¸é ½Ã°£Ç¥¿¡¼­ Á¦¿Ü\n");
	printf("º¯°æÇÒ °ú¸ñ ¹øÈ£ ÀÔ·Â( 0 ÀÔ·Â½Ã ¸ÞÀÎ¸Þ´º·Î µ¹¾Æ°¨) : ");
	scanf("%d", &x);
	ALL_Credit -= data[x].credit;
	data[x].time = 0;
	data[x].hour = 0;
	if (x == 0) {
		system("cls");
		menu();
	}
	//0ÀÌ ÀÔ·ÂµÇ¸é ¸ÞÀÎ ¸Þ´º·Î
	while (x > num - 1) {
		printf("°ú¸ñ ¹øÈ£°¡ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n");
		printf("´Ù½Ã ÀÔ·ÂÇØ ÁÖ¼¼¿ä : ");
		scanf("%d", &x);
	}
	// »èÁ¦ÇÒ °ú¸ñ ¹øÈ£°¡ Á¸ÀçÇÏÁö ¾ÊÀ» ¶§
	printf("°ú¸ñ ¹øÈ£ %d\n", x);
	printf("°ú¸ñ ÀÌ¸§ : ");
	scanf("%s", data[x].subject); // °ú¸ñ ÀÌ¸§ Ãß°¡
	getchar();

loop: {
	printf("°ú¸ñ ¿äÀÏ(a~e) : ");
	scanf("%c", &data[x].day); // °ú¸ñ ¿äÀÏ Ãß°¡
	if (data[x].day == 'x') { // x ÀÔ·Â ½Ã ½Ã°£Ç¥¿¡¼­ Á¦¿Ü
		data[x].credit = 0;
		data[x].time = 0;
		data[x].hour = 0;
		strcpy(data[x].subject, A);
		printf("¡Ø¡Ø »èÁ¦µÇ¾ú½À´Ï´Ù. ¡Ø¡Ø");
		Sleep(1000);
		system("cls");
		menu();
	}
	if (data[x].day >= 'a' && data[x].day <= 'e') // a~e»çÀÌ ÀÔ·Â°ªÀÌ ¾Æ´Ï¸é ÀçÀÔ·Â
		goto times;
	else
		goto loop;
	}
//°ú¸ñ ¿äÀÏ
times: {
printf("°ú¸ñ ½Ã°£(1~8) : ");
scanf("%d", &data[x].time); // °ú¸ñ ½Ã°£ Ãß°¡
if (data[x].time >= 1 && data[x].time <= 8) // 1~8»çÀÌ ÀÔ·Â°ªÀÌ ¾Æ´Ï¸é ÀçÀÔ·Â
	goto credits;
else
	goto times;
}
//°ú¸ñ ½Ã°£
credits: {
printf("°ú¸ñ ÇÐÁ¡(1~3) : ");
scanf("%d", &data[x].credit); // °ú¸ñ ÇÐÁ¡ Ãß°¡
ALL_Credit += data[x].credit;
if (ALL_Credit > 19) { // ÃÑÇÐÁ¡ÀÌ 19ÇÐÁ¡À» ³ÑÀ¸¸é ¸ÞÀÎ ¸Þ´º Ãâ·Â
	printf("¡Ø¡Ø 19ÇÐÁ¡À» ÃÊ°úÇÏ¿´½À´Ï´Ù. ¡Ø¡Ø\n");
	ALL_Credit -= data[x].credit;
	goto credits;
}
if (data[x].credit < 1 || data[x].credit > 3) // 1~3»çÀÌ ÀÔ·Â°ªÀÌ ¾Æ´Ï¸é ÀçÀÔ·Â
goto credits;
else
goto hours;
}
//°ú¸ñ ÇÐÁ¡
hours: {
printf("°­ÀÇ ½Ã°£·® : ");
scanf("%d", &data[x].hour);
if (data[x].hour < 1 || data[x].hour > 4) {
	goto hours;
}
printf("\n¡Ø¡Ø º¯°æµÇ¾ú½À´Ï´Ù ¡Ø¡Ø");
}
//°­ÀÇ ½Ã°£·®
Sleep(2000);
system("cls");
menu();
}
// ¼ö°­½ÅÃ» º¯°æ
void schedule() {
	int s_num;
	int a; // ¸ÞÀÎ¸Þ´º·Î µ¹¾Æ°¥ °ª ÀÔ·Â
	int i;
	int n;

	printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
	printf("¦¢      ¿ù      ¦¢      È­      ¦¢      ¼ö      ¦¢      ¸ñ      ¦¢      ±Ý      ¦¢\n");
	printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©\n");
	printf("¦¢              ¦¢              ¦¢              ¦¢              ¦¢              ¦¢\n");
	printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©\n");
	printf("¦¢              ¦¢              ¦¢              ¦¢              ¦¢              ¦¢\n");
	printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©\n");
	printf("¦¢              ¦¢              ¦¢              ¦¢              ¦¢              ¦¢\n");
	printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©\n");
	printf("¦¢              ¦¢              ¦¢              ¦¢              ¦¢              ¦¢\n");
	printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©\n");
	printf("¦¢              ¦¢              ¦¢              ¦¢              ¦¢              ¦¢\n");
	printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©\n");
	printf("¦¢              ¦¢              ¦¢              ¦¢              ¦¢              ¦¢\n");
	printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©\n");
	printf("¦¢              ¦¢              ¦¢              ¦¢              ¦¢              ¦¢\n");
	printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©\n");
	printf("¦¢              ¦¢              ¦¢              ¦¢              ¦¢              ¦¢\n");
	printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");

	for (s_num = 1; s_num < num; s_num++) {
		int x = 0;
		int y;
		n = data[s_num].hour;
		for (i = 1; i <= n; i++) {
			x += 2;
			y = 0;
			y = data[s_num].time * 2 + x; // 8±³½Ã ÀÌ»óÀº ½Ã°£Ç¥¿¡ Ç¥ÃâµÇÁö ¾Ê°Ô²û ¼³Á¤
			if (y < 20) {
				if (data[s_num].day == 'a') { //Ç¥ÃâµÉ °ª
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
	//8±³½Ã ÃÊ°ú ÀÔ·ÂµÇÁö ¾Ê°Ô ¼³Á¤

loop:
	gotoxy(3, 21);
	printf("¸ÞÀÎÀ¸·Î µ¹¾Æ°¡·Á¸é 1 ÀÔ·Â :             ");
	gotoxy(32, 21);
	scanf("%d", &a);

	if (a == 1) {
		system("cls");
		menu();
	}
	// ÀÔ·Â°ªÀÌ 1ÀÌ ¾Æ´Ï¸é ´Ù½Ã ÀÔ·Â
	else
		goto loop;
}
// ½Ã°£Ç¥ Ãâ·Â
void credit() {
	int i;
	gotoxy(14, 3);
	printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
	for (i = 4; i < 23; i++) {
		gotoxy(14, i);
		printf("¦¢                                                   ¦¢");
	}
	gotoxy(14, 23);
	printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
	gotoxy(38, 9);
	printf("ÃÑ ÇÐÁ¡");
	gotoxy(30, 11);
	printf("------------------------");
	gotoxy(30, 13);
	printf("½ÅÃ»µÈ ÃÑ ÇÐÁ¡ : %2d", ALL_Credit);
	gotoxy(30, 15);
	printf("------------------------");
	Sleep(2000);
	menu();
}
// ÃÑÇÐÁ¡
void gotoxy(int x, int y) //(80, 24)
{
	COORD Pos = { x - 1,y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
// ÁÂÇ¥
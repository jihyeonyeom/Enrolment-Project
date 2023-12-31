#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>

#define NUMBER 50

typedef struct {
	char subject[20]; // 婁跡 檜葷
	char day;		  // 婁跡 蹂橾
	int time;		  // 婁跡 衛除
	int credit;		  // 婁跡 з薄
	int hour;		  // 鬼曖 衛除榆
}Memo;

Memo data[NUMBER];

void gotoxy(int x, int y); // 謝ル
void menu(); // 詭檣詭景
void apply(); // 熱鬼褐羶
void change(); // 熱鬼褐羶 滲唳
void schedule();// 衛除ル 轎溘
void credit(); // 識з薄

int num = 1; // 婁跡 廓�� 瞪羲滲熱 撲薑
int ALL_Credit = 0; // 識з薄 瞪羲滲熱 撲薑
char A[10] = "EMPTY"; // 熱除褐羶 滲唳縑憮 婁跡 餉薯й 陽 餌辨
int z = 1; //詭賅濰縑憮 識з薄 渦ж晦 嬪и л熱

void main() {
	FILE* fp;
	fp = fopen("Memory.txt", "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Memory.txt file 翮 熱 橈蝗棲棻.\n3蟾�� 詭檣 �飛橉虞� 給嬴骨棲棻.\n");
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
	int m_num; // 詭景摹鷗 殮溘 高
	int i;
	gotoxy(14, 3);
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
	for (i = 4; i < 23; i++) {
		gotoxy(14, i);
		printf("弛                                                   弛");
	}
	gotoxy(14, 23);
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
	gotoxy(33, 8);
	printf("熱鬼褐羶 Щ煎斜極");
	gotoxy(28, 10);
	printf("---------------------------");
	gotoxy(28, 12);
	printf("1. 熱鬼褐羶");
	gotoxy(28, 13);
	printf("2. 熱鬼褐羶 滲唳");
	gotoxy(28, 14);
	printf("3. 衛除ル 轎溘");
	gotoxy(28, 15);
	printf("4. 識 з薄");
	gotoxy(28, 16);
	printf("5. Щ煎斜極 謙猿");
	gotoxy(25, 18);
	printf("1~5廓 醞縑憮 摹鷗ж罹 輿撮蹂 : ");
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
		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
		for (i = 7; i < 12; i++) {
			gotoxy(22, i);
			printf("弛                                     弛");
		}
		gotoxy(22, 12);
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
		gotoxy(26, 9);
		printf("≦≦ Щ煎斜極擊 謙猿м棲棻 ≦≦");
		gotoxy(1, 18);
		FILE* fp1;
		fp1 = fopen("Memory.txt", "w");
		if (fp1 == NULL)
		{
			fprintf(stderr, "Memory.txt file 翮 熱 橈蝗棲棻.\n");
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
// 詭檣詭景
void apply() {
	int i;
	gotoxy(14, 3);
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
	for (i = 4; i < 23; i++) {
		gotoxy(14, i);
		printf("弛                                                   弛");
	}
	gotoxy(14, 23);
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
	gotoxy(34, 9);
	printf("熱  鬼  褐  羶");
	gotoxy(29, 11);
	printf("------------------------");
	gotoxy(30, 13);
	printf("婁跡 廓�� %d", num);
	gotoxy(30, 14);
	printf("婁跡 檜葷 : ");
	scanf("%s", data[num].subject); // 婁跡 檜葷 蹺陛
	fflush(stdin);

loop: {
	gotoxy(30, 15);
	printf("婁跡 蹂橾(a~e) :        ");
	gotoxy(47, 15);
	scanf("%c", &data[num].day); // 婁跡 蹂橾 蹺陛
	if (data[num].day >= 'a' && data[num].day <= 'e') // a~e餌檜 殮溘高檜 嬴棲賊 營殮溘
		goto times;
	else
		goto loop;
	}
//婁跡 蹂橾
times: {
gotoxy(30, 16);
printf("婁跡 衛除(1~8) :        ");
gotoxy(47, 16);
scanf("%d", &data[num].time); // 婁跡 衛除 蹺陛
if (data[num].time >= 1 && data[num].time <= 8) { // 1~8餌檜 殮溘高檜 嬴棲賊 營殮溘
	for (i = 1; i < num; i++) { // 醞犒脹 衛除渠陛 氈朝雖 匐餌
		if (data[num].day == data[num - i].day) {
			if (data[num].time == data[num - i].time) {
				gotoxy(21, 19);
				printf("≦≦ 檜嘐 蛔煙腎橫 氈朝 衛除渠殮棲棻 ≦≦");
				gotoxy(21, 20);
				printf("≦≦        棻衛 蛔煙п 輿撮蹂       ≦≦");
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
//婁跡 衛除
credits: {
gotoxy(30, 17);
printf("婁跡 з薄(1~3) :        ");
gotoxy(47, 17);
scanf("%d", &data[num].credit); // 婁跡 з薄 蹺陛
if (data[num].credit < 1 || data[num].credit > 3) // 1~3餌檜 殮溘高檜 嬴棲賊 營殮溘
goto credits;
else
goto hours;
}
//婁跡 з薄
hours: {
gotoxy(30, 18);
printf("鬼曖 衛除榆(1~4) :       ");
gotoxy(49, 18);
scanf("%d", &data[num].hour);
if (data[num].hour < 1 || data[num].hour > 4)
goto hours;
}
//鬼曖 衛除榆
ALL_Credit += data[num].credit; // 識з薄縑 з薄 蹺陛
if (ALL_Credit > 19) { // 識з薄檜 19з薄擊 剩戲賊 詭檣 詭景 轎溘
	gotoxy(25, 20);
	printf("≦≦ 19з薄擊 蟾婁ж艘蝗棲棻. ≦≦");
	gotoxy(25, 21);
	printf("≦≦ 詭檣 詭景煎 給嬴骨棲棻.  ≦≦");
	ALL_Credit -= data[num].credit;
	Sleep(2000);
	system("cls");
	menu();
}
num++;
Sleep(1000); // 棻擠 �飛橉虞� 1蟾 雖翱
system("cls");
menu();
}
// 熱鬼褐羶
void change() {
	int x; // 滲唳й 婁跡 廓�� 高
	int i;
	char* d_day = " ";
	for (i = 1; i < num; i++) {
		switch (data[i].day) { // 婁跡 蹂橾 釭顫頂還 高
		case 'a':
			d_day = "錯";
			break;
		case 'b':
			d_day = "��";
			break;
		case 'c':
			d_day = "熱";
			break;
		case 'd':
			d_day = "跡";
			break;
		case 'e':
			d_day = "旎";
			break;
		}
		printf("婁跡 廓��%2d\n婁跡 檜葷 : %s\n婁跡 蹂橾 : %s\n婁跡 衛除 : %d\n婁跡 з薄 : %d\n鬼曖 衛除榆 : %d\n\n",
			i, data[i].subject, d_day, data[i].time, data[i].credit, data[i].hour);
	}
	printf("-------------------------------\n");
	printf("婁跡 蹂橾縑憮 x 殮溘ж賊 衛除ル縑憮 薯諼\n");
	printf("滲唳й 婁跡 廓�� 殮溘( 0 殮溘衛 詭檣詭景煎 給嬴馬) : ");
	scanf("%d", &x);
	ALL_Credit -= data[x].credit;
	data[x].time = 0;
	data[x].hour = 0;
	if (x == 0) {
		system("cls");
		menu();
	}
	//0檜 殮溘腎賊 詭檣 詭景煎
	while (x > num - 1) {
		printf("婁跡 廓�ㄟ� 襄營ж雖 彊蝗棲棻.\n");
		printf("棻衛 殮溘п 輿撮蹂 : ");
		scanf("%d", &x);
	}
	// 餉薯й 婁跡 廓�ㄟ� 襄營ж雖 彊擊 陽
	printf("婁跡 廓�� %d\n", x);
	printf("婁跡 檜葷 : ");
	scanf("%s", data[x].subject); // 婁跡 檜葷 蹺陛
	getchar();

loop: {
	printf("婁跡 蹂橾(a~e) : ");
	scanf("%c", &data[x].day); // 婁跡 蹂橾 蹺陛
	if (data[x].day == 'x') { // x 殮溘 衛 衛除ル縑憮 薯諼
		data[x].credit = 0;
		data[x].time = 0;
		data[x].hour = 0;
		strcpy(data[x].subject, A);
		printf("≦≦ 餉薯腎歷蝗棲棻. ≦≦");
		Sleep(1000);
		system("cls");
		menu();
	}
	if (data[x].day >= 'a' && data[x].day <= 'e') // a~e餌檜 殮溘高檜 嬴棲賊 營殮溘
		goto times;
	else
		goto loop;
	}
//婁跡 蹂橾
times: {
printf("婁跡 衛除(1~8) : ");
scanf("%d", &data[x].time); // 婁跡 衛除 蹺陛
if (data[x].time >= 1 && data[x].time <= 8) // 1~8餌檜 殮溘高檜 嬴棲賊 營殮溘
	goto credits;
else
	goto times;
}
//婁跡 衛除
credits: {
printf("婁跡 з薄(1~3) : ");
scanf("%d", &data[x].credit); // 婁跡 з薄 蹺陛
ALL_Credit += data[x].credit;
if (ALL_Credit > 19) { // 識з薄檜 19з薄擊 剩戲賊 詭檣 詭景 轎溘
	printf("≦≦ 19з薄擊 蟾婁ж艘蝗棲棻. ≦≦\n");
	ALL_Credit -= data[x].credit;
	goto credits;
}
if (data[x].credit < 1 || data[x].credit > 3) // 1~3餌檜 殮溘高檜 嬴棲賊 營殮溘
goto credits;
else
goto hours;
}
//婁跡 з薄
hours: {
printf("鬼曖 衛除榆 : ");
scanf("%d", &data[x].hour);
if (data[x].hour < 1 || data[x].hour > 4) {
	goto hours;
}
printf("\n≦≦ 滲唳腎歷蝗棲棻 ≦≦");
}
//鬼曖 衛除榆
Sleep(2000);
system("cls");
menu();
}
// 熱鬼褐羶 滲唳
void schedule() {
	int s_num;
	int a; // 詭檣詭景煎 給嬴陞 高 殮溘
	int i;
	int n;

	printf("忙式式式式式式式式式式式式式式成式式式式式式式式式式式式式式成式式式式式式式式式式式式式式成式式式式式式式式式式式式式式成式式式式式式式式式式式式式式忖\n");
	printf("弛      錯      弛      ��      弛      熱      弛      跡      弛      旎      弛\n");
	printf("戍式式式式式式式式式式式式式式托式式式式式式式式式式式式式式托式式式式式式式式式式式式式式托式式式式式式式式式式式式式式托式式式式式式式式式式式式式式扣\n");
	printf("弛              弛              弛              弛              弛              弛\n");
	printf("戍式式式式式式式式式式式式式式托式式式式式式式式式式式式式式托式式式式式式式式式式式式式式托式式式式式式式式式式式式式式托式式式式式式式式式式式式式式扣\n");
	printf("弛              弛              弛              弛              弛              弛\n");
	printf("戍式式式式式式式式式式式式式式托式式式式式式式式式式式式式式托式式式式式式式式式式式式式式托式式式式式式式式式式式式式式托式式式式式式式式式式式式式式扣\n");
	printf("弛              弛              弛              弛              弛              弛\n");
	printf("戍式式式式式式式式式式式式式式托式式式式式式式式式式式式式式托式式式式式式式式式式式式式式托式式式式式式式式式式式式式式托式式式式式式式式式式式式式式扣\n");
	printf("弛              弛              弛              弛              弛              弛\n");
	printf("戍式式式式式式式式式式式式式式托式式式式式式式式式式式式式式托式式式式式式式式式式式式式式托式式式式式式式式式式式式式式托式式式式式式式式式式式式式式扣\n");
	printf("弛              弛              弛              弛              弛              弛\n");
	printf("戍式式式式式式式式式式式式式式托式式式式式式式式式式式式式式托式式式式式式式式式式式式式式托式式式式式式式式式式式式式式托式式式式式式式式式式式式式式扣\n");
	printf("弛              弛              弛              弛              弛              弛\n");
	printf("戍式式式式式式式式式式式式式式托式式式式式式式式式式式式式式托式式式式式式式式式式式式式式托式式式式式式式式式式式式式式托式式式式式式式式式式式式式式扣\n");
	printf("弛              弛              弛              弛              弛              弛\n");
	printf("戍式式式式式式式式式式式式式式托式式式式式式式式式式式式式式托式式式式式式式式式式式式式式托式式式式式式式式式式式式式式托式式式式式式式式式式式式式式扣\n");
	printf("弛              弛              弛              弛              弛              弛\n");
	printf("戌式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式戎\n");

	for (s_num = 1; s_num < num; s_num++) {
		int x = 0;
		int y;
		n = data[s_num].hour;
		for (i = 1; i <= n; i++) {
			x += 2;
			y = 0;
			y = data[s_num].time * 2 + x; // 8掖衛 檜鼻擎 衛除ル縑 ル轎腎雖 彊啪莠 撲薑
			if (y < 20) {
				if (data[s_num].day == 'a') { //ル轎腆 高
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
	//8掖衛 蟾婁 殮溘腎雖 彊啪 撲薑

loop:
	gotoxy(3, 21);
	printf("詭檣戲煎 給嬴陛溥賊 1 殮溘 :             ");
	gotoxy(32, 21);
	scanf("%d", &a);

	if (a == 1) {
		system("cls");
		menu();
	}
	// 殮溘高檜 1檜 嬴棲賊 棻衛 殮溘
	else
		goto loop;
}
// 衛除ル 轎溘
void credit() {
	int i;
	gotoxy(14, 3);
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
	for (i = 4; i < 23; i++) {
		gotoxy(14, i);
		printf("弛                                                   弛");
	}
	gotoxy(14, 23);
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
	gotoxy(38, 9);
	printf("識 з薄");
	gotoxy(30, 11);
	printf("------------------------");
	gotoxy(30, 13);
	printf("褐羶脹 識 з薄 : %2d", ALL_Credit);
	gotoxy(30, 15);
	printf("------------------------");
	Sleep(2000);
	menu();
}
// 識з薄
void gotoxy(int x, int y) //(80, 24)
{
	COORD Pos = { x - 1,y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
// 謝ル
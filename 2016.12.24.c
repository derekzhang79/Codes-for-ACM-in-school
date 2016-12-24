/*#include<stdio.h>                                           #1
int main() {
	int N, enemy[1000] = { 0 }, ally[1000] = { 0 };
	while (1) {
		scanf("%d", &N);
		if (N == 0) {
			return 0;
		}
		int i;
		for (i = 0; i < N; i++) {
			scanf("%d", &ally[i]);
		}
		for (i = 0; i < N; i++) {
			scanf("%d", &enemy[i]);
		}
		int j, min, tag;
		for (i = 0; i < N - 1; i++) {
			min = i;
			for (j = i + 1; j < N; j++) {
				if (ally[i] > ally[j]) {
					min = j;
				}
			}
			tag = ally[i];
			ally[i] = ally[min];
			ally[min] = tag;
		}
		for (i = 0; i < N - 1; i++) {
			min = i;
			for (j = i + 1; j < N; j++) {
				if (enemy[i] > enemy[j]) {
					min = j;
				}
			}
			tag = enemy[i];
			enemy[i] = enemy[min];
			enemy[min] = tag;
		}
		tag = enemy[0];
		int sum = 0;
		for (i = 0; i < N; i++) {
			if (ally[i] > tag) {
				break;
			}
		}
		j = 0;
		for (i; i < N; i++) {
			if (ally[i] > enemy[j]) {
				sum++;
				j++;
			}
			else {
				continue;
			}
		}
		if (sum > N / 2) {
			printf("YES\n", sum);
		}
		else
		{
			printf("NO\n", sum);
		}
	}
	return 0;
}*/
/*#include<stdio.h>                                        #2 递归迷宫
#include<string.h>
char map[100][100], map2[100][100], map3[100][100], map4[100][100];
int mazeleft(int y, int x) {
	int i, j,sum=1;
	map[y][x] = '*';
	if (map[y][x - 1] == 'P') {
		return sum;
	}
	else if (map[y - 1][x] == 'P') {
		return sum;
	}
	else if (map[y][x + 1] == 'P') {
		return sum;
	}
	else if (map[y + 1][x] == 'P') {
		return sum;
	}
	if (map[y][x - 1] == '.') {
		sum += mazeleft(y, x - 1);
	}
	else if (map[y - 1][x] == '.') {
		sum += mazeleft(y-1, x );
	}
	else if (map[y][x + 1] == '.') {
		sum += mazeleft(y, x + 1);
	}
	else if (map[y + 1][x] == '.') {
		sum += mazeleft(y+1, x);
	}
	else {
		return -1;
	}
}
int mazeup(int y, int x) {
	int i, j, sum = 1;
	map[y][x] = '*';
	if (map[y][x - 1] == 'P') {
		return sum;
	}
	else if (map[y - 1][x] == 'P') {
		return sum;
	}
	else if (map[y][x + 1] == 'P') {
		return sum;
	}
	else if (map[y + 1][x] == 'P') {
		return sum;
	}
	if (map[y-1][x] == '.') {
		sum += mazeup(y-1, x);
	}
	else if (map[y][x+1] == '.') {
		sum += mazeup(y, x+1);
	}
	else if (map[y+1][x] == '.') {
		sum += mazeup(y+1, x);
	}
	else if (map[y][x-1] == '.') {
		sum += mazeup(y, x-1);
	}
	else {
		return -1;
	}
}
int mazeright(int y, int x) {
	int i, j, sum = 1;
	map[y][x] = '*';
	if (map[y][x - 1] == 'P') {
		return sum;
	}
	else if (map[y - 1][x] == 'P') {
		return sum;
	}
	else if (map[y][x + 1] == 'P') {
		return sum;
	}
	else if (map[y + 1][x] == 'P') {
		return sum;
	}
	if (map[y][x +1] == '.') {
		sum += mazeright(y, x + 1);
	}
	else if (map[y + 1][x] == '.') {
		sum += mazeright(y + 1, x);
	}
	else if (map[y][x - 1] == '.') {
		sum += mazeright(y, x - 1);
	}
	else if (map[y - 1][x] == '.') {
		sum += mazeright(y - 1, x);
	}
	else {
		return -1;
	}
}
int mazedown(int y, int x) {
	int i, j, sum = 1;
	map[y][x] = '*';
	if (map[y][x - 1] == 'P') {
		return sum;
	}
	else if (map[y - 1][x] == 'P') {
		return sum;
	}
	else if (map[y][x + 1] == 'P') {
		return sum;
	}
	else if (map[y + 1][x] == 'P') {
		return sum;
	}
	if (map[y+1][x] == '.') {
		sum += mazedown(y+1, x);
	}
	else if (map[y][x-1] == '.') {
		sum += mazedown(y, x-1);
	}
	else if (map[y-1][x] == '.') {
		sum += mazedown(y-1, x);
	}
	else if (map[y][x+1] == '.') {
		sum += mazedown(y, x+1);
	}
	else {
		return -1;
	}
}
int main() {
	int N, M, T,min;
	int i, j;
	int sum1=0, sum2=0, sum3=0, sum4=0;
	while (1) {
		min = 0;
		scanf("%d %d %d", &N, &M, &T);
		getchar();
		if (N == 0 && M == 0 && T == 0) {
			break;
		}
		for (i = 0; i < M; i++) {
			for (j = 0; j <N; j++) {
				scanf("%c", &map[i][j]);
			}
			getchar();
		}
		memcpy(&map2, &map,sizeof(map));
		memcpy(&map3, &map, sizeof(map));
		memcpy(&map4, &map, sizeof(map));
		for (i = 0; i < M; i++) {
			for (j = 0; j <N; j++) {
				if (map[i][j] == 'S') {
					sum1=mazeleft(i,j);
				}
			}
		}
		memcpy(&map, &map2, sizeof(map2));
		for (i = 0; i < M; i++) {
			for (j = 0; j <N; j++) {
				if (map[i][j] == 'S') {
					sum2 = mazeup(i, j);
				}
			}
		}
		memcpy(&map, &map3, sizeof(map3));
		for (i = 0; i < M; i++) {
			for (j = 0; j <N; j++) {
				if (map[i][j] == 'S') {
					sum3 = mazeright(i, j);
				}
			}
		}
		memcpy(&map, &map4, sizeof(map4));
		for (i = 0; i < M; i++) {
			for (j = 0; j <N; j++) {
				if (map[i][j] == 'S') {
					sum4 = mazedown(i, j);
				}
			}
		}
		min = sum1;
		if(sum2<min){
			min = sum2;
		}
		if (sum3<min) {
			min = sum3;
		}
		if (sum4<min) {
			min = sum4;
		}
		if (min <= T) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}*/
/*#include<stdio.h>                                          #3

int isPrime(int);

int main() {
	int i, input, sum=0;
	while (1) {
		scanf("%d", &input);
		if (input == 0) {
			return 0;
		}
		for (i = 0; i < input; i++) {
			sum += isPrime(i);
		}
		printf("%d\n", sum);
		sum = 0;
	}
	return 0;
}

int isPrime(int in) {
	int i=0;
	if (in == 1 || in == 0) {
		return 0;
	}
	for (i = 2; i < in; i++) {
		if (in%i == 0) {
			return 0;
		}
	}
	return 1;
}*/
/*#include<stdio.h>                                         #4 斐波那契数列

int main() {
	int N, i;
	long f[40];
	while (1) {
		scanf("%d", &N);
		if (N == 0) {
			return 0;
		}
		f[0] = f[1] = 1;
		for (i = 2; i <= N; ++i)
			f[i] = f[i - 1] + f[i - 2];	//后一项=前两项和
		printf("%d\n", f[N]);
	}
	return 0;
}*/
/*#include<stdio.h>                                    #5
int main() {
	int i,j,k;
	char in,target[1000];
	char bef[] = "abcdefghijklmnopqrstuvwxyz";
	char aft[] = "erwqtyghbnuiopsjkdlfazxcvm";
	char BEF[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char AFT[] = "ECFAJKLBDGHIVWZYMNOPQRSTUX";
	while (1) {
		gets(target);
		if (target[0] == '#') {
			return 0;
		}
		for (i = 0; i < 1000; i++) {
			if (target[i] == ' ') {
				continue;
			}
			else if (target[i] == '/0') {
				break;
			}
			for (j = 0; j < 26; j++) {
				if (target[i] == bef[j]) {
					target[i] = aft[j];
					break;
				}
				else if (target[i] == BEF[j]) {
					target[i] = AFT[j];
					break;
				}
			}
		}
		printf("%s\n", target);
	}
	return 0;
}*/
/*#include<stdio.h>                            #6
float fact(int);
int main() {
	int n,i;
	float sum = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		sum += 1 / fact(i);
	}
	printf("%.4f\n", sum);
	return 0;
}
float fact(int n) {
	int i,sum=1;
	for (i = 1; i <= n; i++) {
		sum *= i;
	}
	return sum;
}*/
/*#include<stdio.h>                      #7
int main() {
	int i, in[10] = { 0 }, sum = 0;
	float ave;
	for (i = 0; i < 10; i++) {
		scanf("%d", &in[i]);
		sum += in[i];
	}
	ave = sum / 10;
	sum = 0;
	for (i = 0; i < 10; i++) {
		if (in[i] > ave) {
			sum += 1;
		}
	}
	printf("%d\n", sum);
	return 0;
}*/
/*#include<stdio.h>          #8
int main() {
	int n, in, sum=0;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &in);
		if (in % 2 == 0) {
			sum += in;
		}
	}
	printf("%d\n", sum);
	return 0;
}*/
/*#include<stdio.h>                  #9
#include<math.h>
int prime(int in) {
	int j, tag = 1;
	for (j = 2; j < in; j++) {
		if (in%j == 0) {
			return 0;
		}
	}
	return 1;
}
int main() {
	int n, i, j, tag = 1;
	scanf("%d", &n);
	A:
	for (i = 2; i < sqrt(n) + 1; i++) {
		if (n%i == 0) {
			if (prime(i) ==1) {
				printf("%d ", i);
				n /= i;
				goto A;
			}
		}	
	}
	if (prime(n) == 1) {
		printf("%d ", n);
	}
	return 0;
}*/
/*#include<stdio.h>             #10
#define PI 3.1415926535
int main() {
	int r;
	double area;
	for (r = 1; r <= 10; r++) {
		area = r*r*PI;
		if (40 <= area&&area <= 90) {
			printf("r=%d area=%.2lf\n", r, area);
		}
	}
	system("pause");
	return 0;
}*/
/*#include<stdio.h>                   #11 选择排序
int main() {
	int i,target[10];
	for (i = 0; i < 10; i++) {
		scanf("%d", &target[i]);
	}
	int j, min, tag;
	for (i = 0; i < 9; i++) {
		min = i;
		for (j = i + 1; j < 10; j++) {
			if (target[min] > target[j]) {
				min = j;
			}
		}
		if (min != i) {
			tag = target[min];
			target[min] = target[i];
			target[i] = tag;
		}
	}
	for (i = 0; i < 10; i++) {
		printf("%d\n", target[i]);
	}
	return 0;
}*/
/*#include<stdio.h>                   #12
int main() {
	int i, target[20], j;
	for (i = 0; i < 20; i++) {
		scanf("%d", &target[i]);
	}
	for (i = 0; i < 20; i++) {
		for ( j = 0; j <20; j++)
		{
			if (i != j) {
				if (target[i] % target[j] == 0) {
					printf("%d\n", target[i]);
					break;
				}
			}
		}
	}
	return 0;
}*/
/*#include<stdio.h>               #13
int main() {
	int i, j, in[3][3],sum=0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			scanf("%d", &in[i][j]);
		}
	}
	sum = in[0][0] + in[1][1] + in[2][2];
	printf("%d\n", sum);
	return 0;
}*/
/*#include<stdio.h>           #14
int main() {
	int a[6], b[8], i, j,tag[6],k=0,z,q=1;
	for (i = 0; i < 6; i++) {
		scanf("%d", &a[i]);
	}
	for (j = 0; j < 8; j++) {
		scanf("%d", &b[j]);
	}
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 8; j++) {
			q = 1;
			if (a[i] == b[j]) {
				for (z = 0; z < 6; z++) {
					if (a[i] == tag[z]) {
						q = 0;
						break;
					}
				}
				if (q == 1) {
					tag[k] = a[i];
					k++;
				}
			}
		}
	}
	for (i = 0; i < k; i++) {
		printf("%d\n", tag[i]);
	}
	return 0;
}*/
/*#include<stdio.h>                #15
int main() {
	int T, A[3], B[3], i;
	int j, min, tag;
	scanf("%d", &T);
	while (T--) {
		for (i = 0; i < 3; i++) {
			scanf("%d", &A[i]);
		}
		for (i = 0; i < 3; i++) {
			scanf("%d", &B[i]);
		}
		for (i = 0; i < 2; i++) {
			min = i;
			for (j = i + 1; j < 3; j++) {
				if (A[min] > A[j]) {
					min = j;
				}
			}
			if (min != i) {
				tag = A[min];
				A[min] = A[i];
				A[i] = tag;
			}
		}
		tag = 0;
		for (i = 0; i < 2; i++) {
			min = i;
			for (j = i + 1; j < 3; j++) {
				if (B[min] > B[j]) {
					min = j;
				}
			}
			if (min != i) {
				tag = B[min];
				B[min] = B[i];
				B[i] = tag;
			}
		}
		tag = 0;
		for (i = 0; i < 3; i++) {
			if (A[i] < B[i]) {
				tag=1;
				break;
			}
		}
		if (tag == 1) {
			tag = 0;
			for (i = 0; i < 3; i++) {
				if (B[i] < A[i]) {
					tag=1;
					break;
				}
			}
		}
		if (tag ==0) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}
	return 0;
}*/
/*#include<stdio.h>           #16
int main() {
	int t,in,tag=1,j;
	scanf("%d", &t);
	while (t--) {
		tag = 1;
		scanf("%d", &in);
		j = in;
		while (1) {
			if (j / 10 == 0) {
				break;
			}
			tag ++;
			j /= 10;
		}
		if (in % 6 == 0) {
			printf("Yes\n");
		}
		else if (in % 10 == 6) {
			printf("Yes\n");
		}
		else if (tag % 6 == 0) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
	return 0;
}*/
/*#include<stdio.h>              #17
int main() {
	int T,tag,in,flag=0,sum,i=0;
	scanf("%d", &T);
	while (T--) {
		flag = 0;
		i = 0;
		scanf("%d %d", &sum, &tag);
		while (sum--) {
			flag++;
			scanf("%d", &in);
			if (in == tag) {
				i = 1;
				printf("%d\n", flag);
				break;
			}
		}
		if (i == 0) {
			printf("-1\n");
		}
	}
	system("pause");
	return 0;
}*/
/*#include<stdio.h>                          #18
int main() {
	int T, A, B,in[100][100],i,j;
	scanf("%d", &T);
	while (T--)
	{	
		scanf("%d %d", &A, &B);
		for (i = 0; i < A; i++) {
			for (j = 0; j < B; j++) {
				scanf("%d", &in[i][j]);
			}
		}
		int max[100] = { 0,0,0,0,0 }, min[100] = { 10000,10000,10000,10000,10000 }, k = 0, h = 0, tag = 0;
		
		for (i = 0; i < A; i++) {
			for (j = 0; j < B; j++) {
				if (in[i][j] > max[k]) {
					max[k] = in[i][j];
				}
			}
			k++;
		}
		for (j = 0; j < B; j++) {
			for (i = 0; i < A; i++) {
				if (in[i][j] < min[h]) {
					min[h] = in[i][j];
				}
			}
			h++;
		}
		for (k = 0; k < A; k++) {
			for (h = 0; h < B; h++) {
				if (max[k] == min[h]) {
					tag = 1;
					printf("%d %d\n", k, h);
					break;
				}
			}
		}
		if (tag == 0) {
			printf("-1");
		}
	}
	return 0;
}*/
/*#include<stdio.h>                       #19
int main() {
	int T, i;
	char in[1000];
	scanf("%d", &T);
	getchar();
	while (T--) {
		gets(in);
		for (i = 0; i < 1000; i++) {
			if (in[i] == '\0') {
				printf("\n");
				break;;
			}
			if (in[i] == ' ') {
				continue;
			}
			printf("%c", in[i]);
		}
	}
	return 0;
}*/
/*#include<stdio.h>                             #20
int cifang(int n) {
	int i,sum=1;
	for (i = 0; i < n; i++) {
		sum *= 16;
	}
	return sum;
}
int main() {
	int T, sum, i,tag=0;
	char a[6], b[6];
	scanf("%d", &T);
	getchar();
	while (T--) {
		tag = 0;
		sum = 0;
		gets(a);
		for (i = 0; i < 6; i++) {
			if ('0' <= a[i] && a[i] <= '9' || 'A' <= a[i] && a[i] <= 'F') {
				tag++;
			}
			else if (a[i] == '\0'){
				break;
			}
			else {
				a[0] = '0';
				break;
			}
		}
		i = 0;
		while(tag--) {
			if ('A' <= a[i] && a[i] <= 'F') {
				sum += ((int)a[i] - 'A' + 10)*cifang(tag);
			}
			else if ('0' <= a[i] && a[i] <= '9') {
				sum += ((int)a[i] - '0')*cifang(tag);
			}
			i++;
		}
		gets(b);
		tag = 0;
		for (i = 0; i < 6; i++) {
			if ('0' <= b[i] && b[i] <= '9' || 'A' <= b[i] && b[i] <= 'F') {
				tag++;
			}
			else if (b[i] == '\0') {
				break;
			}
			else {
				a[0] == '0';
				break;
			}
		}
		if (a[0] == '0') {
			printf("-1\n");
			continue;
		}
		i = 0;
		while (tag--) {
			if ('A' <= b[i] && b[i] <= 'F') {
				sum += ((int)b[i] - 'A' + 10)*cifang(tag);
			}
			else if ('0' <= b[i] && b[i] <= '9') {
				sum += ((int)b[i] - '0')*cifang(tag);
			}
			i++;
		}
		printf("%d\n", sum);
	}
	return 0;
}*/
/*#include<stdio.h>                #21
int main() {
	int T, N, M,in[10][10],i,j;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				scanf("%d", &in[i][j]);
			}
		}
		for (j = M - 1; j >= 0; j--) {
			for (i = 0; i <N; i++) {
				printf("%d", in[i][j]);
				if (i != N-1) {
					printf(" ");
				}
			}
			printf("\n");
		}
	}
	return 0;
}*/
/*#include<stdio.h>                           $22
int main() {
	int day = 0, i;
	double sum = 0, in, a[100], *p;
	p = &a[0];
	while (1) {
		scanf("%lf", &in);
		if (in == 0) {
			break;
		}
		a[day] = in;
		day++;
	}
	printf("%d ", day);
	for (i = 0; i < day; i++) {
		sum += *p;
		p++;
	}
	printf("%.1lf\n", sum / day);
	return 0;
}*/
/*#include<stdio.h>                             #23
char *swap(char *in);

int main() {
	int i;
	char a[100],*p;
	scanf("%s", a);
	p = swap(a);
	for (i = 0; i < 100; i++) {
		if (*p == '\0') {
			break;
		}
		printf("%c", *p);
		p++;
	}
	return 0;
}
char *swap(char*in) {
	int i, j = 0;
	char out[100];
	for (i = 99; i >= 0; i--) {
		if (in[i] == '\0') {
			i--;
			break;
		}
	}
	for (i; i >= 0; i--) {
		out[j] = in[i];
		j++;
	}
	out[j] = '\0';
	for (i = 0; i < 100; i++) {
		in[i] = out[i];
		if (out[i] == '\0') {
			break;
		}
	}
	return in;
}*/
/*#include<stdio.h>                        #24
int cifang(int n) {
	int i, sum = 1;
	for (i = 0; i < n; i++) {
		sum *= 16;
	}
	return sum;
}
long change(char s[]);
int main() {
	int T;
	char s[1000];
	scanf("%d", &T);
	getchar();
	while (T--) {
		gets(s);
		printf("%ld\n",change(s));
	}
	return 1;
}
long int change(char s[]) {
	int i,tag=0;
	long sum = 0;
	for (i = 0; i < 6; i++) {
		if ('0' <= s[i] && s[i] <= '9' || 'A' <= s[i] && s[i] <= 'F') {
			tag++;
		}
		else if (s[i] == '\0') {
			break;
		}
	}
	i = 0;
	while (tag--) {
		if ('A' <= s[i] && s[i] <= 'F') {
			sum += ((int)s[i] - 'A' + 10)*cifang(tag);
		}
		else if ('0' <= s[i] && s[i] <= '9') {
			sum += ((int)s[i] - '0')*cifang(tag);
		}
		i++;
	}
	return sum;
}*/
/*#include<stdio.h>                #25
int main() {
	int t, i, j, numa=0,numb=0;
	char a[100], b[100],*S,*T;
	scanf("%d", &t);
	getchar();
	while (t--) {
		numa = 0, numb = 0;
		gets(a);
		gets(b);
		S = &a[0];
		T = &b[0];
		while (1) {
			if (*S == '\0') {
				if (*T == '\0') {
					break;
				}
				else
				{
					numb += 100;
					break;
				}
			}
			else if (*T == '\0') {
				if (*S == '\0') {
					break;
				}
				else
				{
					numb += 100;
					break;
				}
			}
			if (*S > *T) {
				numa++;
			}
			else if (*T > *S) {
				numb++;
			}
			else if (*T == *S) {
				;
			}
			S++;
			T++;
		}
		if (numa > numb) {
			printf("1\n");
		}
		else if (numa == numb) {
			printf("0\n");
		}
		else if (numa < numb) {
			printf("-1\n");
		}
	}
	return 0;
}*/
/*#include<stdio.h>                   #26
#include<math.h>
int interger(int in) {
	in = in*in;
	return in;
}
float FFF(float in) {
	in = sqrt(in);
	return in;
}
char *string(char *in) {
	int i;
	for (i = 0; i < 100; i++) {
		if (in[i] == '\0') {
			break;
		}
		if ('a' <= in[i] && in[i] <= 'z') {
			in[i] = in[i] - 32;
		}
	}
	return in;
}
int main()
{
	char choose, c[100], *p;
	int a, t;
	float b;
	scanf("%d", &t);
	int(*i)(int in);
	float(*f)(float in);
	char*(*s)(char *in);
	i = &interger;
	f = &FFF;
	s = &string;
	while (t--) {
		getchar();
		scanf("%c", &choose);
		switch (choose)
		{
		case 'I':
			scanf("%d", &a);
			a = (*i)(a);
			printf("%d\n", a);
			break;
		case 'F':
			scanf("%f", &b);
			b = (*f)(b);
			printf("%.1f\n", b);
			break;
		case 'S':
			scanf("%s",c);
			p = c;
			p = (*s)(c);
			puts(p);
			break;
		}
	}
	return 0;
}*/
#include<stdio.h>
#include<string.h>
char map[100][100], map1[100][100], map2[100][100], map3[100][100],map4[100][100];
int right(int x, int y)
{
	int sum = 1;
	map[x][y] = '*';
	if (map[x][y + 1] == 'P')
	{
		return sum;
	}
	else if (map[x + 1][y] == 'P')
	{
		return sum;
	}
	else if (map[x][y - 1] == 'P')
	{
		return sum;
	}
	else if (map[x - 1][y] == 'P')
	{
		return sum;
	}
	if (map[x][y + 1] == '.')
	{
		sum += right(x, y + 1);
	}
	else if (map[x + 1][y] == '.')
	{
		sum += right(x + 1, y);
	}
	else if (map[x][y - 1] == '.')
	{
		sum += right(x, y - 1);
	}
	else if (map[x - 1][y] == '.')
	{
		sum += right(x - 1, y);
	}
	else
		return -1;
}
int down(int x, int y)
{
	int sum = 1;
	map[x][y] = '*';
	if (map[x + 1][y] == 'P')
	{
		return sum;
	}
	else if (map[x][y - 1] == 'P')
	{
		return sum;
	}
	else if (map[x - 1][y] == 'P')
	{
		return sum;
	}
	else if (map[x][y + 1] == 'P')
	{
		return sum;
	}
	if (map[x + 1][y] == '.')
	{
		sum += down(x + 1, y);
	}
	else if (map[x][y - 1] == '.')
	{
		sum += down(x, y - 1);
	}
	else if (map[x - 1][y] == '.')
	{
		sum += down(x - 1, y);
	}
	else if (map[x][y + 1] == '.')
	{
		sum += down(x, y + 1);
	}
	else
		return -1;
}
int left(int x, int y)
{
	int sum = 1;
	map[x][y] = '*';
	if (map[x][y - 1] == 'P')
	{
		return sum;
	}
	else if (map[x - 1][y] == 'P')
	{
		return sum;
	}
	else if (map[x][y + 1] == 'P')
	{
		return sum;
	}
	else if (map[x + 1][y] == 'P')
	{
		return sum;
	}
	if (map[x][y - 1] == '.')
	{
		sum += left(x, y - 1);
	}
	else if (map[x - 1][y] == '.')
	{
		sum += left(x - 1, y);
	}
	else if (map[x][y + 1] == '.')
	{
		sum += left(x, y + 1);
	}
	else if (map[x + 1][y] == '.')
	{
		sum += left(x + 1, y);
	}
	else
		return -1;
}
int up(int x, int y)
{
	int sum = 1;
	map[x][y] = '*';
	if (map[x - 1][y] == 'P')
	{
		return sum;
	}
	else if (map[x][y + 1] == 'P')
	{
		return sum;
	}
	else if (map[x + 1][y] == 'P')
	{
		return sum;
	}
	else if (map[x][y - 1] == 'P')
	{
		return sum;
	}
	if (map[x - 1][y] == '.')
	{
		sum += up(x - 1, y);
	}
	else if (map[x][y + 1] == '.')
	{
		sum += up(x, y + 1);
	}
	else if (map[x + 1][y] == '.')
	{
		sum += up(x + 1, y);
	}
	else if (map[x][y - 1] == '.')
	{
		sum += up(x, y - 1);
	}
	else
		return -1;
}
int main()
{
	int N, M, T, i, j, x, y, sum1, sum2, sum3, sum4, min;
	while(1)
	{
		scanf("%d%d%d", &N, &M, &T);
		if (N == 0 && M == 0 && T == 0) {
			break;
		}
		for (i = 0; i < M; i++) {
			for (j = 0; j <N; j++) {
				scanf("%c", &map[i][j]);
			}
			getchar();
		}
		memcpy(&map2, &map, sizeof(map));
		memcpy(&map3, &map, sizeof(map));
		memcpy(&map4, &map, sizeof(map));
		for (i = 0; i < M; i++) {
			for (j = 0; j <N; j++) {
				if (map[i][j] == 'S') {
					sum1 = left(i, j);
				}
			}
		}
		memcpy(&map, &map2, sizeof(map2));
		for (i = 0; i < M; i++) {
			for (j = 0; j <N; j++) {
				if (map[i][j] == 'S') {
					sum2 = up(i, j);
				}
			}
		}
		memcpy(&map, &map3, sizeof(map3));
		for (i = 0; i < M; i++) {
			for (j = 0; j <N; j++) {
				if (map[i][j] == 'S') {
					sum3 = right(i, j);
				}
			}
		}
		memcpy(&map, &map4, sizeof(map4));
		for (i = 0; i < M; i++) {
			for (j = 0; j <N; j++) {
				if (map[i][j] == 'S') {
					sum4 = down(i, j);
				}
			}
		}
		min = sum1;
		if (sum2<min) {
			min = sum2;
		}
		if (sum3<min) {
			min = sum3;
		}
		if (sum4<min) {
			min = sum4;
		}
		if (min <= T) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}

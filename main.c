#include<stdio.h>
int juzhenquyuansu(int a[], int juzhenkuandu, int hang, int lie);
void juzhenxieyuansu(int a[], int juzhenkuandu, int hang, int lie, int xieruzhi);
void juzhenzhuanzhi(int a[], int hang, int lie, int b[]);
void print_juzhen(int a[], int hang, int lie);
void juzhenchengfa(int a[], int b[], int c[], int hang, int lie);
void main(void)
{
	int m23[2][3] =
	{
		{1,2,3},
		{4,5,6}
	};
	int m32[3][2] =
	{
		{1,2},
		{3,4},
		{5,6}
	};
	int m22[2][2];
	int m122[2][2];
	int m33[3][3];
	printf("矩阵a:\n");
	print_juzhen(m23, 2, 3);
	printf("矩阵b:\n");
	print_juzhen(m32, 3, 2);
	printf("a*b=c：\n");
	juzhenchengfa(m23, m32, m22, 2, 3);
	print_juzhen(m22, 2, 2);
	printf("b*a=d：\n");
	juzhenchengfa(m32, m23, m33, 3, 2);
	print_juzhen(m33, 3, 3);
	juzhenzhuanzhi(m22, 2, 2, m122);
	print_juzhen(m122, 2, 2);
	print_juzhen(m23, 2, 3);
	juzhenzhuanzhi(m23, 3, 2, m32);
	print_juzhen(m32, 3, 2);
}
int juzhenquyuansu(int a[], int juzhenkuandu, int hang, int lie)//取得宽度为juzhenkuandu的a矩阵的a[lie][hang]元素;
{
	return a[lie + (hang * juzhenkuandu)];
}
void juzhenxieyuansu(int a[], int juzhenkuandu, int hang, int lie, int xieruzhi)//写入宽度为juzhenkuandu的a矩阵的a[lie][hang]元素;
{
	a[lie + (hang * juzhenkuandu)] = xieruzhi;
}
void juzhenzhuanzhi(int a[], int hang, int lie, int b[])
{
	for (int i = 0; i < hang; i++)
	{
		for (int j = 0; j < lie; j++)
		{
			juzhenxieyuansu(b, lie, i, j, juzhenquyuansu(a, hang, j, i));
		}
	}
}
void print_juzhen(int a[], int hang, int lie)
{
	printf("{\n");
	for (int i = 0; i < hang; i++)
	{
		printf("[");
		for (int j = 0; j < lie; j++)
		{
			//printf("%d,", a[j + (i * lie)]);//这里是曾经不调用函数的写法
			printf("%d,", juzhenquyuansu(a, lie, i, j));
		}
		printf("\b],\n");
	}
	printf("\b};\n");
}
void juzhenchengfa(int a[], int b[], int c[], int hang, int lie)//表示c[hang][hang] = a[hang][lie] x b[lie][hang]
{
	for (int i = 0; i < hang; i++)//行循环
	{
		for (int j = 0; j < hang; j++)//列循环
		{
			int mid = 0;
			for (int k = 0; k < lie; k++)//向量内积循环
			{
				//mid = mid + a[k + (i * lie)] * b[j + (k * hang)];//这里是曾经不调用函数的写法
				mid = mid + juzhenquyuansu(a, lie, i, k) * juzhenquyuansu(b, hang, k, j);
			}
			//c[(i * hang) + j] = mid;//这里是曾经不调用函数的写法
			juzhenxieyuansu(c, hang, i, j, mid);
		}
	}
}

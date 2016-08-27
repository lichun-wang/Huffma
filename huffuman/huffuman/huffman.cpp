# include<stdio.h>
# include<stdlib.h>
# include <string.h>
struct  dui{                               //在用堆寻找最小值得时候 用于存放 位置和权重值
	int i;
	int a;
};
typedef struct {                            //haffman的结构体
	int weight;
	int parent, lchild, rchild;
}HTNode, *HuffmanTree;
typedef char * * HuffmanCode;
/////////////////////////////////////////////////////////////////////////
void adjust_heap(dui *heap, int root, int len)
{
	int d;                               // 是否可结束的变量     
	int j;
	dui temp;

	j = 2 * root;                           // 子结点指针           
	temp = heap[root];                      //堆的根值           
	d = 0;                               // 建立变量             
	while (j <= len && !d)             // 主循环              
	{
		if (j < len)                     // 找最大的子结点       
		if (heap[j].a < heap[j + 1].a)
			j++;                         // 下一结点             
		if (temp.a >= heap[j].a)        // 比较树根值           
			d = 1;                      // 结束                 
		else
		{
			heap[j / 2] = heap[j];           // 父结点是目前结点     
			j = 2 * j;                    // 其子结点             
		}
	}
	heap[j / 2] = temp;                     // 父结点为根值         
}
void heap(dui *heap, int len)
{
	int i;
	dui temp;

	for (i = (len / 2); i >= 1; i--)     //将二叉树转成堆
		adjust_heap(heap, i, len);

	for (i = len - 1; i >= 1; i--)         // 堆排序主循环   
	{
		temp = heap[i + 1];                     // 交换最后元素         
		heap[i + 1] = heap[1];
		heap[1] = temp;
		adjust_heap(heap, 1, i);                //重建堆             
	}
}
///////////////////////////////////////////////////////////用于查找最小的值
void select(HuffmanTree t, int i, int &s1, int &s2)
{
	dui * a;
	a = (dui*)malloc((i + 1)*sizeof(dui));
	int j, m = 0;
	a[0].a = 0;
	a[0].i = 0;
	for (j = 1; j <= i; j++)
	{
		if (t[j].parent == 0)                      // 将已经有父母的节点略掉
		{
			++m;
			a[m].a = t[j].weight;
			a[m].i = j;
		}
	}
	heap(a, m);
	s1 = a[1].i;
	s2 = a[2].i;
	t[s1].parent = 1;                            //找到后将父亲置为一，防止再次搜索
	t[s2].parent = 1;
	if (s1>s2)
	{
		j = s1;
		s1 = s2;
		s2 = j;
	}
}
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n)
{
	int m, i, s1, s2, start;
	int c, f;
	HuffmanTree p;
	char *cd;
	if (n <= 1)
		return;
	m = 2 * n - 1;
	HT = (HuffmanTree)malloc((m + 1)*sizeof(HTNode));               //0号单元未用
	for (p = HT + 1, i = 1; i <= n; ++i, ++p, ++w)                            //初始化
	{
		(*p).weight = *w;
		(*p).parent = 0;
		(*p).lchild = 0;
		(*p).rchild = 0;
	}
	for (; i <= m; ++i, ++p)
	{
		(*p).weight = 0;
		(*p).parent = 0;
		(*p).lchild = 0;
		(*p).rchild = 0;
	}

	for (i = n + 1; i <= m; ++i)                                    //建huffman树
	{
		select(HT, i - 1, s1, s2);                              //选择最小的两个节点分别为s1,s2
		HT[s1].parent = HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	//*****************从叶子到根逆向求每个字符的huffman编码
	HC = (HuffmanCode)malloc((n + 1)*sizeof(char*));          //分配n个字符编码的头指针
	cd = (char*)malloc(n*sizeof(char));                     //分配求编码的工作空间
	cd[n - 1] = '\0';                                         //编码的结束符
	for (i = 1; i <= n; i++)                                     //生成haffman编码
	{
		start = n - 1;                                        //编码结束符的位置
		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)   //从叶子到根的逆向求编码
		if (HT[f].lchild == c)
			cd[--start] = '0';
		else
			cd[--start] = '1';
		HC[i] = (char *)malloc((n - start)*sizeof(char));    //为第i个字符编码分配空间
		strcpy(HC[i], &cd[start]);                        //编码的复制
	}
	free(cd);
}
////////////////////////////////////////////////////////////统计字符的个数
void  choose(char ch, int a[])
{
	switch (ch)
	{
	case 'a':
		a[1]++;
		break;
	case 'b':
		a[2]++;
		break;
	case 'c':
		a[3]++;
		break;
	case 'd':
		a[4]++;
		break;
	case 'e':
		a[5]++;
		break;
	case 'f':
		a[6]++;
		break;
	case 'g':
		a[7]++;
		break;
	case 'h':
		a[8]++;
		break;
	case 'i':
		a[9]++;
		break;
	case 'j':
		a[10]++;
		break;
	case 'k':
		a[11]++;
		break;
	case 'l':
		a[12]++;
		break;
	case 'm':
		a[13]++;
		break;
	case 'n':
		a[14]++;
		break;
	case 'o':
		a[15]++;
		break;
	case 'p':
		a[16]++;
		break;
	case 'q':
		a[17]++;
		break;
	case 'r':
		a[18]++;
		break;
	case 's':
		a[19]++;
		break;
	case 't':
		a[20]++;
		break;
	case 'u':
		a[21]++;
		break;
	case 'v':
		a[22]++;
		break;
	case 'w':
		a[23]++;
		break;
	case 'x':
		a[24]++;
		break;
	case 'y':
		a[25]++;
		break;
	case 'z':
		a[26]++;
		break;
	}
}
////////////////////////////////////////////////////////////读取文件中字符的个数
void readfile(int a[])
{
	FILE *fp;
	char ch;
	int i;
	for (i = 1; i <= 26; i++)
	{
		a[i] = 0;
	}
	fp = fopen("passage.txt", "r");
	if (fp == NULL)
	{
		printf("passage文件打开失败");
		exit(0);
	}
	while (!feof(fp))
	{
		ch = fgetc(fp);
		choose(ch, a);
	}
}


int main()
{

	int a[27];                                    //用于存放字符的个数 0号未用
	int i;
	char b[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	for (i = 1; i <= 26; i++)                           //数组的初始化
	{
		a[i] = 0;
	}
	printf("\n\n\n\n\t本程序默认读取本程序文件夹中的passage.txt文件中的字符\n\t\t可以修改该文件中的字符进行验证\n\n\t\t回车键输出该文件对应结果\n\n");
	getchar();
	readfile(a);
	HuffmanTree HT;
	HuffmanCode HC;
	int *w;
	w = (int *)malloc(26 * sizeof(int));
	for (i = 0; i <= 25; i++)
		w[i] = a[i + 1];
	HuffmanCoding(HT, HC, w, 26);
	for (i = 1; i <= 26; i++)
	{
		printf("字母 %c ", b[i - 1]);
		printf("的数量为%d\n", a[i]);
		printf("     其hafuman编码为: %s\n", HC[i]);
	}
	system("pause");
	return 0;
}

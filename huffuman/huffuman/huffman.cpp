# include<stdio.h>
# include<stdlib.h>
# include <string.h>
struct  dui{                               //���ö�Ѱ����Сֵ��ʱ�� ���ڴ�� λ�ú�Ȩ��ֵ
	int i;
	int a;
};
typedef struct {                            //haffman�Ľṹ��
	int weight;
	int parent, lchild, rchild;
}HTNode, *HuffmanTree;
typedef char * * HuffmanCode;
/////////////////////////////////////////////////////////////////////////
void adjust_heap(dui *heap, int root, int len)
{
	int d;                               // �Ƿ�ɽ����ı���     
	int j;
	dui temp;

	j = 2 * root;                           // �ӽ��ָ��           
	temp = heap[root];                      //�ѵĸ�ֵ           
	d = 0;                               // ��������             
	while (j <= len && !d)             // ��ѭ��              
	{
		if (j < len)                     // �������ӽ��       
		if (heap[j].a < heap[j + 1].a)
			j++;                         // ��һ���             
		if (temp.a >= heap[j].a)        // �Ƚ�����ֵ           
			d = 1;                      // ����                 
		else
		{
			heap[j / 2] = heap[j];           // �������Ŀǰ���     
			j = 2 * j;                    // ���ӽ��             
		}
	}
	heap[j / 2] = temp;                     // �����Ϊ��ֵ         
}
void heap(dui *heap, int len)
{
	int i;
	dui temp;

	for (i = (len / 2); i >= 1; i--)     //��������ת�ɶ�
		adjust_heap(heap, i, len);

	for (i = len - 1; i >= 1; i--)         // ��������ѭ��   
	{
		temp = heap[i + 1];                     // �������Ԫ��         
		heap[i + 1] = heap[1];
		heap[1] = temp;
		adjust_heap(heap, 1, i);                //�ؽ���             
	}
}
///////////////////////////////////////////////////////////���ڲ�����С��ֵ
void select(HuffmanTree t, int i, int &s1, int &s2)
{
	dui * a;
	a = (dui*)malloc((i + 1)*sizeof(dui));
	int j, m = 0;
	a[0].a = 0;
	a[0].i = 0;
	for (j = 1; j <= i; j++)
	{
		if (t[j].parent == 0)                      // ���Ѿ��и�ĸ�Ľڵ��Ե�
		{
			++m;
			a[m].a = t[j].weight;
			a[m].i = j;
		}
	}
	heap(a, m);
	s1 = a[1].i;
	s2 = a[2].i;
	t[s1].parent = 1;                            //�ҵ��󽫸�����Ϊһ����ֹ�ٴ�����
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
	HT = (HuffmanTree)malloc((m + 1)*sizeof(HTNode));               //0�ŵ�Ԫδ��
	for (p = HT + 1, i = 1; i <= n; ++i, ++p, ++w)                            //��ʼ��
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

	for (i = n + 1; i <= m; ++i)                                    //��huffman��
	{
		select(HT, i - 1, s1, s2);                              //ѡ����С�������ڵ�ֱ�Ϊs1,s2
		HT[s1].parent = HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	//*****************��Ҷ�ӵ���������ÿ���ַ���huffman����
	HC = (HuffmanCode)malloc((n + 1)*sizeof(char*));          //����n���ַ������ͷָ��
	cd = (char*)malloc(n*sizeof(char));                     //���������Ĺ����ռ�
	cd[n - 1] = '\0';                                         //����Ľ�����
	for (i = 1; i <= n; i++)                                     //����haffman����
	{
		start = n - 1;                                        //�����������λ��
		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)   //��Ҷ�ӵ��������������
		if (HT[f].lchild == c)
			cd[--start] = '0';
		else
			cd[--start] = '1';
		HC[i] = (char *)malloc((n - start)*sizeof(char));    //Ϊ��i���ַ��������ռ�
		strcpy(HC[i], &cd[start]);                        //����ĸ���
	}
	free(cd);
}
////////////////////////////////////////////////////////////ͳ���ַ��ĸ���
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
////////////////////////////////////////////////////////////��ȡ�ļ����ַ��ĸ���
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
		printf("passage�ļ���ʧ��");
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

	int a[27];                                    //���ڴ���ַ��ĸ��� 0��δ��
	int i;
	char b[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	for (i = 1; i <= 26; i++)                           //����ĳ�ʼ��
	{
		a[i] = 0;
	}
	printf("\n\n\n\n\t������Ĭ�϶�ȡ�������ļ����е�passage.txt�ļ��е��ַ�\n\t\t�����޸ĸ��ļ��е��ַ�������֤\n\n\t\t�س���������ļ���Ӧ���\n\n");
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
		printf("��ĸ %c ", b[i - 1]);
		printf("������Ϊ%d\n", a[i]);
		printf("     ��hafuman����Ϊ: %s\n", HC[i]);
	}
	system("pause");
	return 0;
}

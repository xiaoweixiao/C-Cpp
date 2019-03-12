#include"Slist.h"
void test1();
void test1()//测试尾打印
{
	SlistNode*s=NULL;
	SlistPushBack(&s, 0);
	SlistPushBack(&s, 1);
	SlistPushBack(&s, 2);
	SlistPushBack(&s, 3);
	SlistPushBack(&s, 4);
	SlistPushBack(&s, 5);
	//SlistPrint(s);
	//PrintTailToHeadR(s);
	SlistPrintTailToHead(s);
	SlistNode*p = SlistFind(s, 4);
	SlistDelNonTailNode(p);
	SlistPrintTailToHead(s);
}

void test2();
void test2()//测试无头链表pos前插入x，时间复杂度小O（n)
{
	SlistNode*p = NULL;
	SlistNode*list = NULL;
	SlistPushBack(&list, 5);
	SlistPushBack(&list, 2);
	SlistPushBack(&list, 1);
	SlistPushBack(&list, 99);
	SlistPrint(list);
	p = SlistFind(list,99);
	SlistInsertFront(p,1314);

	SlistPrint(list);
}

void test3();
void test3()//杰耶夫环谁死问题
{
	SlistNode*p = NULL;
	SlistNode*s = NULL;
	SlistPushBack(&s, 1);
	SlistPushBack(&s, 2);
	SlistPushBack(&s, 3);
	SlistPushBack(&s, 4);
	SlistPushBack(&s, 5);
	SlistPushBack(&s, 6);
	SlistPrint(s);
	p = SlistJosephCircle(s, 3);
	printf("%d\n", p->x);
}

void test4();
void test4()//逆置单链表
{
	SlistNode*tmp;
	SlistNode*s = NULL;
	SlistPushBack(&s, 1);
	SlistPushBack(&s, 2);
	SlistPushBack(&s, 3);
	SlistPushBack(&s, 4);
	SlistPushBack(&s, 5);
	SlistPushBack(&s, 6);
	SlistPrint(s);
	tmp=SlistReverse2(s);
	SlistPrint(tmp);
}

void test5();
void test5()//冒泡排序
{
	SlistNode*s = NULL;
	SlistPushBack(&s, 11);
	SlistPushBack(&s, 2);
	SlistPushBack(&s, 13);
	SlistPushBack(&s, 24);
	SlistPushBack(&s, 59);
	SlistPushBack(&s, 76);
	SlistPrint(s);
	SlistBubbleSort(s);
	SlistPrint(s);
}

void test6();
void test6()//测试两个有序链表合并成一个有序链表
{
	SlistNode*s1 = NULL;
	SlistNode*s2 = NULL;
	SlistNode*s = NULL;
	SlistPushBack(&s1, 1);
	SlistPushBack(&s1, 2);
	SlistPushBack(&s1, 3);
	SlistPushBack(&s2, 2);
	SlistPushBack(&s2, 6);
	SlistPushBack(&s2, 7);
	SlistPushBack(&s2, 110);
	SlistPrint(s1);
	SlistPrint(s2);
	s = SlistMerge(s1, s2);
	SlistPrint(s);

	printf("%d\n",SlistFindMidNode(s)->x);

}

void test7();
void test7()//找倒数第k个数并且删除倒数第k个数
{
	SlistNode*s=NULL;
	SlistPushBack(&s, 199);
	SlistPushBack(&s, 26);
	SlistPushBack(&s, 364);
	SlistPushBack(&s, 214);
	SlistPushBack(&s, 65);
	SlistPushBack(&s, 56);
	printf("%d\n",SlistFindTailKNode(s, 2)->x);
	DelTailK(&s, 3);
	SlistPrint(s);
}

void TestCycle();
void TestCycle()//链表带环问题测试
{
	SlistNode*list = NULL;
	SlistNode* pos, *tail, *meet,*entry;
	SlistPushBack(&list, 1);
	SlistPushBack(&list, 2);
	SlistPushBack(&list, 3);
	SlistPushBack(&list, 4);
	SlistPushBack(&list, 5);
	SlistPushBack(&list, 6);
	tail = SlistFind(list, 6);
	pos = SlistFind(list, 4);
	tail->next = pos;
	meet = SlistIsCycle(list);
	entry=SlistEntryNode(list, meet);
	printf("%d\n",meet->x);
	printf("%d\n", entry->x);
	printf("%d\n", SlistCycleLen(entry, meet));
}

void SlistCorss();
void SlistCross()
{
	SlistNode*list1=NULL;
	SlistNode*list2=NULL;
	SlistNode*pos1, *pos2;
	SlistPushBack(&list1, 1);
	SlistPushBack(&list1, 2);
	SlistPushBack(&list1, 3);

	SlistPushBack(&list2, 9);
	SlistPushBack(&list2, 8);
	SlistPushBack(&list2, 4);

	pos1 = SlistFind(list1, 3);
	pos2 = SlistFind(list2, 8);
	pos1->next = pos2;
	printf("%d\n", SlistIsCrossNode(list1, list2));
	printf("%d\n",SlistCrossNode(list1, list2)->x);
}

void ComplexListNodeTest()
{
	ComplexListNode*copylist=NULL;
	ComplexListNode*n1 = BuyComplexNode(1);
	ComplexListNode*n2 = BuyComplexNode(2);
	ComplexListNode*n3 = BuyComplexNode(3);
	ComplexListNode*n4 = BuyComplexNode(4);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;
	n1->random = n3;
	n2->random = n1;
	n3->random = n3;
	n4->random = NULL;
	ComplexListPrint(n1);
	printf("\n");
	copylist=CopyComplexList(n1);
	ComplexListPrint(copylist);
}

void UnionSetTest()
{
	SlistNode*s1=NULL,*s2=NULL;
	SlistPushBack(&s1, 0);
	SlistPushBack(&s1, 1);
	SlistPushBack(&s1, 2);
	SlistPushBack(&s1, 3);
	SlistPushBack(&s1, 4);
	SlistPushBack(&s2, 3);
	SlistPushBack(&s2, 4);
	SlistPushBack(&s2, 5);
	SlistPushBack(&s2, 6);
	UnionSet(s1, s2);
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//TestCycle();
	//SlistCross();
	ComplexListNodeTest();
	//UnionSetTest();
	system("pause");
	return 0;
}


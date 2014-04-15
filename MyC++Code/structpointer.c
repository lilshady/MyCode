#include <stdio.h>

struct test
{
	int i;
	char *p;
	char s[0];
};
/*
**一点总结：
**1.对于C语言中的一个指向结构体的指针，比如下面的p
**则&(p->i)、&(p->p)得到的时“相对地址”而不是绝对地址
**p->i转换为*(p+i的相对地址)
**而通过结构本身得到的地址如下面的&(obj.i)，则为绝对地址。
**
**2.->的优先级大于&，所以 &(p->i) == &p->i
**
**3.对于数组S[N]来说，S == &S，所以p->s == &(p->s)
**返回的是S的相对地址，而不是S的内容。这点是指针和数组的区别
**如果S是指针，则p->s得到的是S的内容
*/
int  main(int argc, char const *argv[])
{
	struct test *p = NULL;
    struct test obj;

    printf("%i\n", &(p->i));
	printf("%i\n", &(p->p));

	printf("%i\n", int(&(obj.i))-int(&(obj)));
	printf("%i\n", int(&(obj.p))-int(&(obj)));

	printf("%x\n",&p->i);
    printf("%x\n",p->s);
    printf("%x\n",&(p->s));
	return 0;
}
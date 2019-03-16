#include<stdio.h>
#include<malloc.h>
void caidan(int i);
void funprint(struct yezhu_type *p,int len );
struct yezhu_type
{
	int number;        //业主编号
	char name[20];     //业主姓名
	long int phone;   //业主电话
	int home;       //业主房号
	char unite[100];     //业主工作单位
	int ele;        //用电量
	int water;     //用水量
	int hfee;     //物业费
	int wfee;      //水电费

};


int main()
{
    int len,i;
	struct yezhu_type *p;
	/*申请储存空间*/
	caidan(i);

/*	p= (struct yezhu_type *) malloc (sizeof (struct yezhu_type));
	puts ("请输入业主信息：\n编号 姓名 电话 房号 工作单位 用电量 用水量 物业费 水电费\n");
	scanf ("%d %s %ld %d %s %d %d %d %d",&p->number,p->name,&p->phone,&p->home,p->unite,&p->ele,&p->water,&p->hfee,&p->wfee);
	printf("编号 姓名 电话 房号 工作单位 用电量 用水量 物业费 水电费\n");
	printf("%0d %s %ld %d %s %d %d %d %d",p->number,p->name,p->phone,p->home,p->unite,p->ele,p->water,p->hfee,p->wfee);
	*/
	free( p );

	printf("\n-----运行完毕----\n");
	return 0;


}

void caidan(int i)
{
    struct yezhu_type *p;
    int len;
    printf("\n\n");

    printf("***************某小区物业管理系统***************\n");
    printf("\n");
    printf("*********请选择输入对应序号选择所需功能*********\n\n");
    printf ("            1  录入业主信息\n\n");
    printf ("            2  修改业主信息\n\n");
    printf ("            3  删除业主信息\n\n");
    printf ("            4  业主信息排序\n\n");
    printf ("            5  浏览业主信息\n\n");
    printf ("            6  查询业主信息\n\n");
    printf ("            7  查看业主缴费清单\n\n");
    printf("************************************************\n\n");

    switch (i)
    {
        case 1: funprint(p,len); break;
       // case 2: funchange( ); break;
      //  case 3: fundelete( ); break;
      //  case 4: funsort( ); break;
      //  case 5: funlook( ); break;
      //  case 6: funsearch( ); break;
      //  case 7: funfee( ); break;
        default :
            {
                printf("请输入菜单中对应的序号\n");
                caidan(i);
            }
    }


}
/////////////////////////
void funprint(struct yezhu_type *p,int len )
{
    printf("请输入要录入的业主人数:\n");
      scanf("%d",&len);
  //  p= (struct yezhu_type *) malloc (sizeof (struct yezhu_type));
      p= (struct yezhu_type *) malloc (*len);

	puts ("请输入业主信息：\n编号  姓名  电话     房号  工作单位  用电量  用水量  物业费  水电费\n");
	for (i=0;i<len;i++)
    {
        scanf ("%d %s %ld %d %s %d %d %d %d",&p->number,p->name,&p->phone,&p->home,p->unite,&p->ele,&p->water,&p->hfee,&p->wfee);
//	    printf("编号 姓名 电话 房号 工作单位 用电量 用水量 物业费 水电费\n");
 //       printf("%0d %s %ld %d %s %d %d %d %d",p->number,p->name,p->phone,p->home,p->unite,p->ele,p->water,p->hfee,p->wfee);
    }

    }


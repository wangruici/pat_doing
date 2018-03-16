#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int K = 111;//窗口数
const int INF = 1000000000;//无穷大
struct Player
{
	int arriveTime, startTime, trainTime;//到达时间、训练开始时间及训练时长
	bool isVIP;//是否是VIP球员
}newPlayer;//临时存放新读入的球员
struct Table
{
	int endTime, numServe;//当前占用该球桌的球员的结束时间及已训练的人数
	bool isVIP;//是否是VIP球桌
}table[K];//K个球桌
vector<Player> player;//球员队列
int convertTime(int h, int m, int s)
{
	return h * 3600 + m * 60 + s;//将时间转换为以s为单位，方便比较和计算
}
bool cmpArriveTime(Player a, Player b)
{
	return a.arriveTime < b.arriveTime;//按到达时间排序
}
bool cmpStartTime(Player a, Player b)
{
	return a.startTime < b.startTime;//按开始时间排序
}
//编号VIP从当前VIP球员移到下一个VIP球员
int nextVIPPlayer(int VIPi)
{
	VIPi++;//先将VIPi加1
	while (VIPi < player.size() && player[VIPi].isVIP == 0)
	{
		VIPi++;//只要当前球员不是VIP，就让VIPi后移一位
	}
	return VIPi;//返回下一个VIP球员的ID
}
//将编号为tID的球桌分配给编号为pID的球员
void allotTable(int pID, int tID)
{
	if (player[pID].arriveTime <= table[tID].endTime)//更新球员的开始时间
	{
		player[pID].startTime = table[tID].endTime;
	}
	else
	{
		player[pID].startTime = player[pID].arriveTime;
	}
	//该球桌的训练结束时间更新为新球员的结束时间，并让服务人数加1
	table[tID].endTime = player[pID].startTime + player[pID].trainTime;
	table[tID].numServe++;
}
int main()
{
	int n, k, m, VIPtable;
	scanf("%d", &n);//球员数
	int stTime = convertTime(8, 0, 0);//开门时间为8点
	int edTime = convertTime(21, 0, 0);//关门时间为21点
	for (int i = 0; i < n; i++)
	{
		int h, m, s, trainTime, isVIP;//时、分、秒、训练时长、是否是VIP球员
		scanf("%d:%d:%d %d %d", &h, &m, &s, &trainTime, &isVIP);
		newPlayer.arriveTime = convertTime(h, m, s);//到达时间
		newPlayer.startTime = edTime;//开始时间初始化为21点
		if (newPlayer.arriveTime >= edTime) continue;//21点及以后的直接排除
		//训练时长
		newPlayer.trainTime = trainTime <= 120 ? trainTime * 60 : 7200;
		newPlayer.isVIP = isVIP;//是否是VIP
		player.push_back(newPlayer);//将newPlayer加入到球员队列中
	}
	scanf("%d%d", &k, &m);//球桌数及VIP球桌数
	for (int i = 1; i <= k; i++)
	{
		table[i].endTime = stTime;//当前训练结束时间为8点
		table[i].numServe = table[i].isVIP = 0;//初始化numServe与isVIP
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &VIPtable);//VIP球桌编号
		table[VIPtable].isVIP = 1;//记为VIP球桌
	}
	sort(player.begin(), player.end(), cmpArriveTime);//按到达时间排序
	int i = 0, VIPi = -1;//i用来扫描所有球员，VIPi总是指向当前最前的VIP球员
	VIPi = nextVIPPlayer(VIPi);//找到第一个VIP球员
	while (i < player.size())//当前队列最前面的球员为i
	{
		int idx = -1, minEndTime = INF;//寻找最早能空闲的球桌
		for (int j = 1; j <= k; j++)
		{
			if (table[j].endTime < minEndTime)
			{
				minEndTime = table[j].endTime;
				idx = j;
			}
		}
		//idx为最早空闲的球桌编号
		if (table[idx].endTime >= edTime)break;//已经关门，直接break
		if (player[i].isVIP == 1 && i < VIPi)
		{
			i++;//如果i号是VIP球员，但是VIPi>i,说明i号球员已经在训练
			continue;
		}
		//以下按球桌是否是VIP、球员是否是VIP，进行4种情况讨论
		if (table[idx].isVIP == 1)
		{
			if (player[i].isVIP == 1)//①球桌是VIP，球员是VIP
			{
				allotTable(i, idx);//将球桌idx分配给球员i
				if (VIPi == i)VIPi = nextVIPPlayer(VIPi);//找到下一个VIP球员
				i++;//i号球员开始训练，因此继续队列的下一个人
			}
			else
			{//如果当前队首的VIP球员比该VIP球桌早，就把球桌idx分配给他
				if (VIPi < player.size() && player[VIPi].arriveTime <= table[idx].endTime)
				{
					allotTable(VIPi, idx);//将球桌idx分配给球员i
					VIPi = nextVIPPlayer(VIPi);//找到下一个VIP球员
				}
				else
				{//队首VIP球员比该VIP球桌迟，仍然把球桌idx分配给球员i
					allotTable(i, idx);//将球桌idx分配给球员i
					i++;//i号球员开始训练，因此继续队列的下一个人
				}
			}
		}
		else
		{
			if (player[i].isVIP == 0)//③球桌不是VIP，球员不是VIP
			{
				allotTable(i, idx);//将球桌idx分配给球员i
				i++;//i号球员开始训练，因此继续队列的下一个人
			}
			else
			{//④球桌不是VIP，球员是VIP
				//找到最早空闲的VIP球桌
				int VIPidx = -1, minVIPEndTime = INF;
				for (int j = 1; j <= k; j++)
				{
					if (table[j].isVIP == 1 && table[j].endTime < minVIPEndTime)
					{
						minVIPEndTime = table[j].endTime;
						VIPidx = j;
					}
				}
				//最早空闲的VIP球桌编号是VIPidx
				if (VIPidx != -1 && player[i].arriveTime >= table[VIPidx].endTime)
				{//如果VIP球桌存在，且空闲时间比球员来的时间早
				//就把它分配给球员i
					allotTable(i, VIPidx);
					if (VIPi == i)VIPi = nextVIPPlayer(VIPi);//找到下一个VIP球员
					i++;//i号球员开始训练，因此继续队列的下一个人
				}
				else
				{
					//如果球员来时VIP球桌还未空闲，就把球桌idx分配给他
					allotTable(i, idx);
					if (VIPi == i)VIPi = nextVIPPlayer(VIPi);//找到下一个VIP球员
					i++;//i号球员开始训练，因此继续队列的下一个人
				}
			}
		}
	}
	sort(player.begin(), player.end(), cmpStartTime);//按开始时间排序
	for (int i = 0; i < player.size() && player[i].startTime < edTime; i++)//输出
	{
		int t1 = player[i].arriveTime;
		int t2 = player[i].startTime;
		printf("%02d:%02d:%02d ", t1 / 3600, t1 % 3600 / 60, t1 % 60);
		printf("%02d:%02d:%02d ", t2 / 3600, t2 % 3600 / 60, t2 % 60);
		printf("%.0f\n", round((t2 - t1) / 60.0));
	}
	for (int i = 1; i <= k; i++)
	{
		printf("%d", table[i].numServe);
		if (i < k)printf(" ");
	}
	return 0;
}

#include <iostream>
using namespace std;



int gas_station(int* gas, int* cost, int n)
{
	int tank = 0;
	int begin = 0; 
	int end = 0;
	int cur = 0 ;
	do
	{
		tank += gas[cur]-cost[cur];
		if(tank >= 0)
		{
			end++;
			end = (end + n) % n ;
			cur = end;
		}
		else
		{
			begin--;
			begin = (begin + n) % n;
			cur = begin;
		}
	}while(begin != end);

	if (tank>=0)
		return begin;
	else 
		return -1;
}

int main()
{
	int gas[]={1,2,3,3};
	int cost[]={2,1,5,1};

	cout<<gas_station(gas,cost,4)<<endl;
}

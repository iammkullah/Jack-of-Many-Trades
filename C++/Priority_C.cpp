#include<iostream>
using namespace std;

int main()
{
	int Wind_KWH[]={30,32,35,21,20};
	int Solar_KWH[]={2,4,5,3,4};
	int Hydal_KWH[]={50,55,60,55,45};
	int Load_KWH[]={50,45,22,24,36};
	float Cost[]={0,0,0,0,0};
	float T_Price,Cost1,Cost2,Cost3,Rem1,Rem2;
	
	
	float Price_W=0.035;
	float Price_H=0.0554;
	float Price_S=0.065;
	
	for(int i=0;i<5;i++)
	{
		int Priority_1= Wind_KWH[i];
   		int Priority_2= Solar_KWH[i];
   		int Priority_3= Hydal_KWH[i];
   		int Load=Load_KWH[i];
   		
   		if(Priority_1>0)  //Is Wind Available
   		{
   			if(Priority_1>=Load) // Can Wind Bear Load         Case-1
   			{
   				Cost[i]=Load*Price_W;              //Calculate Price Of Wind
			}
			else if(Priority_2>0)  //Is Solar Available
			{
						if(Priority_1+Priority_2>=Load)            // Wind+Solar      Case-2
					{
						Rem1=Load-Priority_1;                  //Remaining For Solar
						Cost1=Priority_1*Price_W;  //Price of Wind
						Cost2=Priority_2*Price_S;  // Price Of Solar
						T_Price=Cost1+Cost2;
						Cost[i]=T_Price;
					}
					else
					{
						if(Priority_1+Priority_2+Priority_3>=Load) //Wind+Solar+Hydal    //Case-3               
						{
							Rem1=Load-Priority_1;                  //Remaining For Solar
							Cost1=Priority_1*Price_W;  //Price of Wind
							Rem2=Rem1-Priority_2;            //Remaining for Hydal
							Cost2=Priority_2*Price_S;     //Price of Solar
							Cost3=Rem2*Price_H;           // Price of Hydal
							T_Price=Cost1+Cost2+Cost3;
							Cost[i]=T_Price;
						}
					}
			}
				else
					{
						if(Priority_1+Priority_3>=Load)        // Wind+Hydal Case-4
						{
							Rem1=Load-Priority_1;
							Cost1=Priority_1*Price_W;
							Cost2=Priority_2*Price_S;
							T_Price=Cost1-Cost2;
							Cost[i]=T_Price;
						}
					}
		}		
		else if(Priority_2>0)         //Is Solar Available
		{
			if(Priority_2>=Load)                // Case-5
			{
				Cost[i]=Priority_2*Price_S;
			}
			else if(Priority_2+Priority_3>=Load)  //Case-6
			{
				Rem1=Load-Priority_2;
				Cost1=Priority_2*Price_S;
				Cost2=Rem1*Price_H;
				T_Price=Cost1+Cost2;
				Cost[i]=T_Price;
			}
		}
		else if(Priority_3>=Load)      //Case-7
		{
			Cost[i] = Load*Price_H;
		}
		
		//cout<<i<<"\n\t When Load Was"<<Load<<" Cost Calculated Was "<<Cost[i];
		
	}
	
	for(int i=0;i<5;i++)
	{
		cout<<Cost[i]<<"\n";
	}
}

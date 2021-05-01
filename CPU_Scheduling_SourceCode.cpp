#include<iostream>
#include<conio.h>
#include<stdio.h>

using namespace std;
using std::cout;

class scheduling
{
	int processNum, burstTime[100];
	float total_Wt, total_Tt, average_Wt, average_Tt, A[100], Wt[100], Tt[100], w;
public:
	//데이터 입력 함수
	void Getdata();
	//First come First served 알고리즘
	void Fcfs();
	//Shortest job First 알고리즘
	void Sjf();
	//Shortest job First with Preemption 알고리즘
	void SjfP();
	//Round Robin 알고리즘
	void RoundRobin();
	//Priority 알고리즘
	void Priority();
};

//프로세스 개수, 프로세스 당 burst time 입력
void scheduling::Getdata()
{
	int i;
	cout << "Enter the number of processes : ";
	cin >> processNum;
	cout << endl;
	for (i = 0; i < processNum; i++)
	{
		cout << "Enter The BurstTime for Process p" << i + 1 << " : ";
		cin >> burstTime[i];
	}
	cout << endl << endl;
}

//First come First served
void scheduling::Fcfs()
{
	int i, j, B[100];
	total_Wt = 0.0, total_Tt = 0.0, average_Wt = 0.0, average_Tt = 0.0;
	for (i = 0; i < processNum; i++)
	{
		B[i] = burstTime[i];
		cout << "Burst time for process p" << i + 1 << " : ";
		cout << B[i] << endl << endl;
	}
	Wt[0] = 0;
	Tt[0] = B[0];

	for (i = 0; i < processNum; i++)	//Waiting Time, Turnaround Time 계산
	{
		Wt[i + 1] = B[i] + Wt[i];
		Tt[i + 1] = B[i + 1] + Tt[i];
	}

	cout << "Processing Time" << endl;	// 프로세싱타임 시각화
	for (i = 0; i < processNum; i++)
	{
		cout << "p" << i + 1 << "(" << B[i] << ") ";
	}
	cout << endl << endl;

	//Waiting Time, Turnaround Time 계산
	for (i = 0; i < processNum; i++)
	{
		total_Wt += Wt[i];
		total_Tt += Tt[i];
	}


	cout << "Process      \tBurst Time\tWaiting Time\tTurnaround Time\n";	//프로세스들의 정보 출력
	for (i = 0; i < processNum; i++)
	{
		cout << "p" << i + 1 << " \t\t" << burstTime[i] << " \t\t" << Wt[i] << " \t\t" << Tt[i] << endl;
	}

	average_Wt = total_Wt / processNum;
	average_Tt = total_Tt / processNum;

	cout << endl;
	cout << "Total Waiting Time : " << total_Wt << endl;
	cout << "Average waiting Time : " << average_Wt << endl;
	cout << "Average turnaround Time : " << average_Tt << " " << endl << endl << endl;
}

//Shortest job First Algorithm
void scheduling::Sjf()
{
	int i = 0, j = 0, temp = 0, B[100], pT[100];
	total_Wt = 0.0, total_Tt = 0.0, average_Wt = 0.0, average_Tt = 0.0;
	for (i = 0; i < processNum; i++)
	{
		B[i] = burstTime[i];
		cout << "Burst time for process p" << i + 1 << " : ";
		cout << B[i] << endl << endl;
	}

	Wt[0] = 0;
	Tt[0] = B[0];

	cout << "Processing Time" << endl;	// 프로세싱타임 시각화
	for (i = 0; i < processNum; i++)
	{
		pT[i] = i + 1;
		Wt[i] = 0;
		Tt[i] = 0;
	}

	for (i = processNum; i > 0; i--)
	{
		for (j = 0; j < processNum; j++)
		{
			if (B[j - 1] > B[j])
			{
				temp = pT[j - 1];
				pT[j - 1] = pT[j];
				pT[j] = temp;
				temp = B[j - 1];
				B[j - 1] = B[j];
				B[j] = temp;
				temp = Wt[j - 1];
				Wt[j - 1] = Wt[j];
				Wt[j] = temp;
				temp = Tt[j - 1];
				Tt[j - 1] = Tt[j];
				Tt[j] = temp;
			}
		}
	}

	for (i = 0; i < processNum; i++)
	{
		Wt[i + 1] = B[i] + Wt[i];
		Tt[i] = Wt[i + 1];
	}

	for (i = 0; i < processNum; i++)
	{
		cout << "p" << pT[i] << "(" << B[i] << ") ";
	}
	cout << endl << endl;


	//Waiting Time 계산
	for (i = 0; i < processNum; i++)
	{
		total_Wt += Wt[i];
		total_Tt += Tt[i];
	}


	cout << "Process      \tBurst Time\tWaiting Time\tTurnaround Time\n";
	for (i = 0; i < processNum; i++)
	{
		cout << "p" << pT[i] << " \t\t" << B[i] << " \t\t" << Wt[i] << " \t\t" << Tt[i] << endl;
	}

	average_Wt = total_Wt / processNum;
	average_Tt = total_Tt / processNum;

	cout << endl;
	cout << "Total Waiting Time : " << total_Wt << endl;
	cout << "Average waiting Time : " << average_Wt << endl;
	cout << "Average turnaround Time : " << average_Tt << " " << endl << endl << endl;
}

//Shortest job First with Preemption
void scheduling::SjfP()
{
	int i = 0, j = 0, count = 0, temp = 0, B[100], pT[100], aT[100];
	total_Wt = 0.0, total_Tt = 0.0, average_Wt = 0.0, average_Tt = 0.0;
	for (i = 0; i < processNum; i++)
	{
		B[i] = burstTime[i];
		cout << "Burst time for process p" << i + 1 << " : ";
		cout << B[i] << endl;
		cout << "Enter the arrival time for process p" << i + 1 << " : ";
		cin >> aT[i];
		cout << endl;

	}

	Wt[0] = 0;
	Tt[0] = B[0];

	cout << "Processing Time" << endl;	// 프로세싱타임 시각화
	for (i = 0; i < processNum; i++)
	{
		pT[i] = i + 1;
		Wt[i] = 0;
		Tt[i] = 0;
	}

	for (i = processNum; i > 0; i--)
	{
		for (j = 0; j < processNum; j++)
		{
			if (aT[j - 1] > aT[j])
			{
				temp = aT[j - 1];
				aT[j - 1] = aT[j];
				aT[j] = temp;
				temp = pT[j - 1];
				pT[j - 1] = pT[j];
				pT[j] = temp;
				temp = Wt[j - 1];
				Wt[j - 1] = Wt[j];
				Wt[j] = temp;
				temp = Tt[j - 1];
				Tt[j - 1] = Tt[j];
				Tt[j] = temp;
				temp = B[j - 1];
				B[j - 1] = B[j];
				B[j] = temp;
			}
		}
	}

	for (i = 0; i < processNum; i++)
	{
		Wt[i + 1] = B[i] + Wt[i] - aT[i];
		Tt[i] = Wt[i + 1];
	}

	for (i = 0; i < processNum; i++)
	{
		cout << "p" << pT[i] << "(" << B[i] << ") ";
	}
	cout << endl << endl;


	//Waiting Time 계산
	for (i = 0; i < processNum; i++)
	{
		total_Wt += Wt[i];
		total_Tt += Tt[i];
	}


	cout << "Process      \tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
	for (i = 0; i < processNum; i++)
	{
		cout << "p" << pT[i] << " \t\t" << aT[i] << " \t\t" << B[i] << " \t\t" << Wt[i] << " \t\t" << Tt[i] << endl;
	}

	average_Wt = total_Wt / processNum;
	average_Tt = total_Tt / processNum;

	cout << endl;
	cout << "Total Waiting Time : " << total_Wt << endl;
	cout << "Average waiting Time : " << average_Wt << endl;
	cout << "Average turnaround Time : " << average_Tt << " " << endl << endl << endl;

}

//Round Robin Algorithm
void scheduling::RoundRobin()
{

	int i, B[100], count, temp;
	int tq = 0, j = 0;
	total_Wt = 0.0, total_Tt = 0.0, average_Wt = 0.0, average_Tt = 0.0;
	for (i = 0; i < processNum; i++)
	{
		Wt[i] = 0, Tt[i] = 0;
		B[i] = burstTime[i];
		cout << "Burst time for process p" << i + 1 << " : ";
		cout << B[i] << endl;
	}
	cout << endl;
	cout << "Enter the Time Quantum : ";
	cin >> tq;
	cout << endl;

	//Waiting Time 계산
	for (i = 0; i < processNum; i++)
	{
		total_Wt += Wt[i];
		total_Tt += Tt[i];
	}

	cout << "Processing Time" << endl;	// 프로세싱타임 시각화
	while (1)
	{
		for (i = 0, count = 0; i < processNum; i++)
		{
			temp = tq;

			if (B[i] == 0)
			{
				count++;
				continue;
			}

			if (B[i] > tq)
			{
				B[i] = B[i] - tq;
				cout << "p" << i + 1 << "(" << tq << ") ";
			}

			else
				if (B[i] >= 0)
				{
					temp = B[i];
					cout << "p" << i + 1 << "(" << B[i] << ") ";
					B[i] = 0;
				}
			j += temp;
			Tt[i] = j;
		}
		if (processNum == count)
		{
			break;
		}
	}
	for (i = 0; i < processNum; i++)
	{
		Wt[i] = Tt[i] - burstTime[i];
		total_Wt += Wt[i];
		total_Tt += Tt[i];
	}

	cout << endl << endl;
	cout << "Process      \tBurst Time\tWaiting Time\tTurnaround Time\n";
	for (i = 0; i < processNum; i++)
	{
		cout << "p" << i + 1 << " \t\t" << burstTime[i] << " \t\t" << Wt[i] << " \t\t" << Tt[i] << endl;
	}

	average_Wt = total_Wt / processNum;
	average_Tt = total_Tt / processNum;

	cout << endl;
	cout << "Total Waiting Time : " << total_Wt << endl;
	cout << "Average Waiting Time : " << average_Wt << " " << endl;
	cout << "Average Turnaround Time : " << average_Tt << " " << endl << endl << endl;
}

//Priority Algorithm
void scheduling::Priority()
{
	int i = 0, j = 0, temp = 0, B[100], pT[100], P[100];
	total_Wt = 0.0, total_Tt = 0.0, average_Wt = 0.0, average_Tt = 0.0;
	for (i = 0; i < processNum; i++)
	{
		B[i] = burstTime[i];
		cout << "Burst time for process p" << i + 1 << " : ";
		cout << B[i] << endl;
		cout << "Enter the priority for process p" << i + 1 << " : ";
		cin >> P[i];
		cout << endl;

	}

	Wt[0] = 0;
	Tt[0] = B[0];

	cout << "Processing Time" << endl;	// 프로세싱타임 시각화
	for (i = 0; i < processNum; i++)
	{
		pT[i] = i + 1;
		Wt[i] = 0;
		Tt[i] = 0;
	}

	for (i = processNum; i > 0; i--)
	{
		for (j = 0; j < processNum; j++)
		{
			if (P[j - 1] > P[j])
			{
				temp = P[j - 1];
				P[j - 1] = P[j];
				P[j] = temp;
				temp = pT[j - 1];
				pT[j - 1] = pT[j];
				pT[j] = temp;
				temp = Wt[j - 1];
				Wt[j - 1] = Wt[j];
				Wt[j] = temp;
				temp = Tt[j - 1];
				Tt[j - 1] = Tt[j];
				Tt[j] = temp;
				temp = B[j - 1];
				B[j - 1] = B[j];
				B[j] = temp;
			}
		}
	}
	for (i = 0; i < processNum; i++)
	{
		Wt[i + 1] = B[i] + Wt[i];
		Tt[i] = Wt[i + 1];
	}
	for (i = 0; i < processNum; i++)
	{
		cout << "p" << pT[i] << "(" << B[i] << ") ";
	}
	cout << endl << endl;
	//Waiting Time 계산
	for (i = 0; i < processNum; i++)
	{
		total_Wt += Wt[i];
		total_Tt += Tt[i];
	}


	cout << "Process      \tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n";
	for (i = 0; i < processNum; i++)
	{
		cout << "p" << pT[i] << " \t\t" << P[i] << " \t\t" << B[i] << " \t\t" << Wt[i] << " \t\t" << Tt[i] << endl;
	}

	average_Wt = total_Wt / processNum;
	average_Tt = total_Tt / processNum;

	cout << endl;
	cout << "Total Waiting Time : " << total_Wt << endl;
	cout << "Average waiting Time : " << average_Wt << endl;
	cout << "Average turnaround Time : " << average_Tt << " " << endl << endl << endl;
}

void main()
{
	int ch, cho;
	scheduling c;
	do
	{
		cout << "===============MENU===============" << endl << endl;
		cout << "1.Creat Processes" << endl;
		cout << "2.FirstComeFirstServed" << endl;
		cout << "3.ShortestJobFirst" << endl;
		cout << "4.RoundRobin" << endl;
		cout << "5.Priority" << endl;
		cout << "6.EXIT" << endl << endl;
		cout << "Enter your choice" << endl;
		cin >> ch;
		cout << endl;
		switch (ch)
		{
		case 1:
			c.Getdata();
			break;
		case 2:
			cout << "FIRST COME FIRST SERVED SCHEDULING" << endl << endl;
			c.Fcfs();
			break;
		case 3:
			cout << "SHORTEST JOB FIRST SCHEDULING" << endl << endl;
			do
			{
				cout << "1.SJF-Normel" << endl;
				cout << "2.SJF-Preemptive" << endl << endl;
				cout << "Enter your choice : ";
				cin >> cho;
				cout << endl;
				switch (cho)
				{
				case 1:
					c.Sjf();
					break;
				case 2:
					c.SjfP();
					break;
				}
			} while (cho <= 2);
			break;
		case 4:
			cout << "ROUND ROBIN SCHEDULING" << endl << endl;
			c.RoundRobin();
			break;
		case 5:
			cout << "PRIORITY SCHEDULING" << endl << endl;
			c.Priority();
			break;
		case 6:
			break;
		}
	} while (ch <= 5);
}
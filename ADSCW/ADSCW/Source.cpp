#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

const short int minWeight = 0;
const short int maxWeight = 1023;
const short int maxVer = 50;

class Edge
{
private:
	string Ver1;
	string Ver2;
	unsigned short weight;
	int Num1;
	int Num2;
public:
	Edge()
	{

		Ver1 = "";
		Num1 = 0;
		Num2 = 0;
		Ver2 = "";
		weight = 0;
	}

	void setWeight(unsigned short weight) { this->weight = weight; }
	void setVer2(string Ver2) { this->Ver2 = Ver2; }
	void setVer1(string  Ver1) { this->Ver1 = Ver1; }
	void setNum1(int Num1) { this->Num1 = Num1; }
	void setNum2(int Num2) { this->Num2 = Num2; }


	unsigned short getWeight() const { return weight; }
	string getVer2() const { return Ver2; }
	string getVer1() const { return Ver1; }
	int getNum1() const { return Num1; }
	int getNum2() const { return Num2; }
};

class Graph
{
private:
	vector<Edge> edges;
	vector<Edge> mod;
	vector<string> collection;
	void quicksort(vector<Edge>& arr, int first, int last);
	int max(int a, int b);
	int min(int a, int b);
	bool CheckLetter(char st);
	bool HaveCollect(string st);
public:
	Graph() : edges(0), mod(0) {}
	void BuildingGraph();
	void QuickSort();
	void Kruskal();
	void printmod();
};

void Graph::quicksort(vector<Edge>& arr, int first, int last)

{
	if (first < last)
	{
		int left = first, right = last;
		Edge middle = arr[(left + right) / 2];
		do
		{
			while (arr[left].getWeight() < middle.getWeight()) left++;
			while (arr[right].getWeight() > middle.getWeight()) right--;
			if (left <= right)
			{
				Edge tmp = arr[left];
				arr[left] = arr[right];
				arr[right] = tmp;
				left++;
				right--;
			}
		} while (left <= right);
		quicksort(arr, first, right);
		quicksort(arr, left, last);
	}
}


bool Graph::HaveCollect(string symbol)
{
	for (int i = 0; i < collection.size(); i++)
	{
		if (collection[i] == symbol || collection[i] == symbol)
		{
			return true;
		}
	}
	return false;
}

bool Graph::CheckLetter(char st)
{
	return (st >= 'A' && st <= 'Z') || (st >= 'a' && st <= 'z');
}
/* Входные данные: любая текстовая последовательность.
ОГРАНИЧЕНИЕ: вершины и вес должны быть хотя бы на одной строке
открывает файл, считает граф, записывает в класс ребер, каждое созданное ребро добавляет в граф.
*/

void Graph::BuildingGraph()
{
	cout << " _____________________" << endl;
	cout << "|                     |" << endl;
	cout << "| Kruskal's algorithm | " << endl;
	cout << "|_____________________|" << endl;
	cout << "Ввод графа: " << endl;

	cout << "1 Через файл" << endl;
	cout << "2 Через консоль" << endl;

	int answer;
	cin >> answer;
	cout << endl;
	if (answer == 1)
	{
		string str;
		string Ver1;
		string Ver2;
		string Weight;
		int temp = 0;
		ifstream file;
		string filepath = "C:\\kruskal\\kruskal.txt";
		file.open(filepath);
		if (!file.is_open())
		{
			cout << "Oшибка открытия файла" << endl;
		}
		else
		{
			while (!file.eof())
			{
				str = "";
				getline(file, str);
				for (int i = 0; i < str.length(); i++)
				{
					Ver1 = "";
					Ver2 = "";
					Weight = "";

					while (str[i] == ' ')
					{
						i++;     // перешагиваем пробелы если они есть
					}

					if (CheckLetter(str[i]))
					{
						Ver1 = str[i];
						while (str[i + 1] == ' ')
						{
							i++;
						}
						if (CheckLetter(str[i + 1]))
						{   //i+1 безопасно, т.к. если есть 1-ая вершина, то 2-ая точно есть
							Ver2 = str[i + 1];
							while (str[i + 2] == ' ')
							{
								i++;
							}
							if (!CheckLetter(str[i + 2]))
							{
								// число нужно проверить, т.к. может быть больше одного знака
								for (int j = i + 2; !CheckLetter(str[j]) && str[j] != ' ' && j < str.length(); j++)
								{
									Weight += str[j];    // число нужно проверить, т.к. может быть больше одного знака
								// цикл пока не встретили букву, пробел и пока не кончилась строка
								}
								i += Weight.length();
								if (Ver1.length() && Ver2.length() && Weight.length())
								{   //если все нашли:
									temp = stoi(Weight);
									if (minWeight <= temp && temp <= maxWeight)
									{
										Edge E;      // создаем, задаем, добавляем в граф
										E.setVer1(Ver1);
										E.setVer2(Ver2);
										int Number = (int)Ver1[0];
										E.setNum1(Number);
										Number = (int)Ver2[0];
										E.setNum2(Number);
										E.setWeight(temp);
										edges.push_back(E);
										if (!HaveCollect(E.getVer2()))
										{
											collection.push_back(E.getVer2());
										}
										if (!HaveCollect(E.getVer1()))
										{
											collection.push_back(E.getVer1());
										}
										if (edges.size() > 1225)
										{
											cout << "Ошибка! Количество ребер должна быть меньше либо равно 1225!" << endl;
											throw;
										}
										if (collection.size() > maxVer)
										{
											cout << "Ошибка! Количество вершин должна быть меньше либо равна 50!" << endl;
											throw;
										}
									}
									else
									{
										cout << "Ошибка! Веса ребер не входят в диапазон [0; 1023]." << endl;
										throw;
									}
								}
							}
						}
					}
				}
			}
			file.close();

			for (int i = 0; i < edges.size(); i++)
			{
				cout << edges[i].getVer2() << " " << edges[i].getVer1() << " " << edges[i].getWeight() << endl;

			}
		}
		cout << endl << "Количество ребер: " << edges.size() << endl;
		cout << "Количество вершин: " << collection.size() << endl;
	}
	else if (answer == 2)
	{
		string Ver1;
		string Ver2;
		string Weight;
		string str = "";
		int temp = 0;
		cout << "Введите количество ребер: ";
		int a; cin >> a;
		for (int i = 0; i < a; i++)
		{
			Ver1 = "";
			Ver2 = "";
			Weight = "";
			cin >> Ver1;
			cin >> Ver2;
			cin >> Weight;
			str = str + " " + Ver1 + " " + Ver2 + " " + Weight;
		}
		Ver1 = ""; Ver2 = ""; Weight = "";

		for (int i = 0; i < str.length(); i++)
		{
			Ver1 = "";
			Ver2 = "";
			Weight = "";

			while (str[i] == ' ')
			{
				i++;
			}

			if (CheckLetter(str[i]))
			{
				Ver1 = str[i];
				while (str[i + 1] == ' ')
				{
					i++;
				}
				if (CheckLetter(str[i + 1]))
				{
					Ver2 = str[i + 1];
					while (str[i + 2] == ' ')
					{
						i++;
					}
					if (!CheckLetter(str[i + 2]))
					{


						for (int j = i + 2; !CheckLetter(str[j]) && str[j] != ' ' && j < str.length(); j++)
						{
							Weight += str[j];
						}
						i += Weight.length();
						if (Ver1.length() && Ver2.length() && Weight.length())
						{
							temp = stoi(Weight);
							if (minWeight <= temp && temp <= maxWeight)
							{
								Edge E;
								E.setVer1(Ver1);
								E.setVer2(Ver2);
								int Number = (int)Ver1[0];
								E.setNum1(Number);
								Number = (int)Ver2[0];
								E.setNum2(Number);
								E.setWeight(temp);
								edges.push_back(E);
								if (!HaveCollect(E.getVer2()))
								{
									collection.push_back(E.getVer2());
								}
								if (!HaveCollect(E.getVer1()))
								{
									collection.push_back(E.getVer1());
								}
								if (edges.size() > 1225)
								{
									cout << "Ошибка! Число ребер должна быть меньше либо равно 1225 !" << endl;
									throw;
								}
								if (collection.size() > maxVer)
								{
									cout << "Ошибка! Число ребер вершин должна быть меньше либо равно 50 !" << endl;
									throw;
								}
							}
							else
							{
								cout << "Ошибка! Значение веса ребра не входит в диапазон [0; 1023]." << endl;
								throw;
							}
						}
					}
				}
			}
		}
	}
}

void Graph::QuickSort()
{
	quicksort(edges, 0, edges.size() - 1);
}
/*Функции возвращающие максимум и минимум из двух значений*/
int Graph::max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}
int Graph::min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

void Graph::Kruskal() {
	for (int i = 0; i < edges.size(); i++)
	{
		if (edges[i].getNum1() != edges[i].getNum2())
		{
			//если концы ребра окрашены в разные цвета:
			mod.push_back(edges[i]);
			int maxNum = max(edges[i].getNum1(), edges[i].getNum2());
			int minNum = min(edges[i].getNum1(), edges[i].getNum2());
			edges[i].setNum1(maxNum);
			edges[i].setNum2(maxNum);
			for (int j = 0; j < edges.size(); j++)
			{
				if (edges[j].getNum1() == minNum)
				{
					edges[j].setNum1(maxNum);
				}
				if (edges[j].getNum2() == minNum)
				{
					edges[j].setNum2(maxNum);
				}
			}
		}
	}
}

void Graph::printmod()
{
	cout << endl << "Минимальное остовное дерево" << endl;
	int sumWeight = 0;
	for (int i = 0; i < mod.size(); i++)
	{
		cout << mod[i].getVer1() << " "
			<< mod[i].getVer2() << " "
			<< endl;
		sumWeight += mod[i].getWeight();
	}
	cout << sumWeight << endl;
	cout << "Суммарный вес ребер в остовном дереве: " << sumWeight << endl;;
	cout << "Количество ребер в остовном дереве: " << mod.size() << endl;;
}

int main()
{
	setlocale(LC_ALL, "rus");
	Graph graph;
	graph.BuildingGraph();
	graph.QuickSort();
	graph.Kruskal();
	graph.printmod();
	system("pause");
	return 0;
}
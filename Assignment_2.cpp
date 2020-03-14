#include <iostream>
#include <fstream>
#include <list>
#include <queue>
using namespace std;

int total_column,total_row,start_row,start_column,goal_column, goal_row;

\\this is cloned by B on his own repository from his PC

struct node
{
	int rowposition = 0, columnposition = 0;
	node *childNode = NULL;
	node *siblingNode = NULL;
};

void menu()
{
	cout << "---------Algorithm List--------" << endl << endl;
    cout << "1. BFS" << endl;
    cout << "2. DFS" << endl;
    cout << "3. Uniform Cost Search" << endl;
    cout << "4. Iterative Deepening Search"<< endl; 
    cout << "5. Depth Limited Search" << endl; 
    cout << "6. Bidirectional Search"<< endl << endl;
}

class GRID
{
	public:
		node *root;
		queue  <node> Queueobj =queue<node>();
		Grid() 
		{
		root = NULL;
		}
	
	void insertNode(int rowpos, int colpos, node *n) 
	{
		if (rowpos == total_row && colpos == total_column) {
			return ;
		}
		node *ptrnode = new node;
		ptrnode->rowposition = rowpos;
		ptrnode->columnposition = colpos;
		if (root == NULL) {
			root = ptrnode;
		}
		else {
			if (n->childNode == NULL) {
				n->childNode = ptrnode;
			}
			else 
			{
				node *temp = n->childNode;
				while (temp->siblingNode) 
				{
					temp = temp->siblingNode;
				}
				temp->siblingNode = ptrnode;
			}
		}
	}
	
	bool stuckobstacle(int currentrowpos, int currentcolpos, int **board) {

		for (int i = 0; i < total_row; i++) 
		{
			for (int j = 0; j < total_column; j++) 
			{
				if (board[i][j] == 1 && currentrowpos == i && currentcolpos == j) 
				{
					return true;
				}
			}
		}
		return false;
	}
	bool checkIfGoalReached(int currentrowpos, int currentcolpos, int goalrowpos, int goalcolumnpos) 
	{	
		if (currentrowpos == goalrowpos&&currentcolpos == goalrowpos) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
		
	bool BFS(node *n, int **board,int &i) 
	{
		if (checkIfGoalReached(n->rowposition, n->columnposition, goal_row, goal_column)) 
		{
			return true;
		}
		else 
		{
			i++;
			node *traversaltemp = n->childNode;
			while (traversaltemp)
			{
				Queueobj.push(*traversaltemp);
				traversaltemp = traversaltemp->siblingNode;
			}
			node *temp = &Queueobj.front();
			Queueobj.pop();
			return BFS(temp, board,i);
		}
	}
	
	bool DFS(node *n, int **board, int &i) 
	{
		if (checkIfGoalReached(n->rowposition, n->columnposition, goal_row, goal_column)) 
		{
			return true;
		}
		else 
		{
			i++;
			node *traversaltemp = n->childNode;
			bool found = false;
			while (traversaltemp)
			{
				found=DFS(traversaltemp,board,i);
				if (found == true) {
					break;
				}
				traversaltemp = traversaltemp->siblingNode;
			}
			return found;
		}
	}
	
	bool UCS(node *n, int **board, int &i) 
	{}
	
	bool IDS(node *n, int **board, int &i) 
	{}
	
	bool DLS(node *n, int **board, int &i) 
	{}
	
	bool BDS(node *n, int **board, int &i) 
	{}
};




int main()
{
	menu();
	int num;
	cout << "Please enter your choice of algorithm [1-6]" << endl << endl;
    cin >> num;
	system("cls");
	
	int x=0;
	GRID obj;
	int **arr = new int*[1];
	if(obj.BFS(obj.root,arr,x) && num ==1)
	{
		cout << "-------Breath First Search-------" <<endl;
		cout << "Goal Found in "<<x<<" steps"<<endl;		
	}	
		else if(obj.DFS(obj.root,arr,x) && num==2)
		{
			cout << "-------Depth First Search-------" <<endl;
			cout << "Goal Found in "<<x<<" steps"<<endl;
		}
				else if(obj.UCS(obj.root,arr,x) && num==3)
				{
					cout << "-------Uniform Cost Search-------" <<endl;
					cout << "Goal Found in "<<x<<" steps"<<endl;
				}
					else if(obj.IDS(obj.root,arr,x) && num==4)
					{
						cout << "-------Iterative Deepening Search-------" <<endl;
						cout << "Goal Found in "<<x<<" steps"<<endl;
					}
						else if(obj.DLS(obj.root,arr,x) && num==5)
						{
							cout << "-------Depth Limited Search-------" <<endl;
							cout << "Goal Found in "<<x<<" steps"<<endl;
						}
							else if(obj.BDS(obj.root,arr,x) &&num==6)
							{
								cout << "-------Bidrectional Search-------" <<endl;
								cout << "Goal Found in "<<x<<" steps"<<endl;
							}
							else
							{
								cout << "Invalid Input" <<endl;
								system("cls");
								menu();
							}
								
								
		
	
	string line;
 	ifstream myfile ("grid.txt");
 	if (myfile.is_open())
  	{
    	while ( getline (myfile,line) )
    	{	
    		arr = new int*[total_row];
			for (int i = 0; i < total_row; i++)
			{
				arr[i] = new int[total_column];
			}
      		cout << line << '\n';
      		
      		int tempval = 0;
			for (int i = total_row-1; i >=0; i--) 
			{
				for (int j = 0; j < total_column; j++) 
				{
					tempval = 0;
					myfile >> tempval;
					arr[i][j] = tempval;
					cout << arr[i][j];
				}
			}
    	}
    	
   		myfile.close();
 	}

 	else 
	 cout << "Unable to open file"; 

 	return 0;
}


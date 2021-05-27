/*
    CREATED BY : SAOM BIN KHALED
*/
#include<iostream>
#include<string>
#include <iomanip>

using namespace std;

struct team{
    string NAME;
    int POINTS, MATCHES;
};

void initialise(struct team *arr, int num)
{
    cout << "input of teams" << endl << "==============" << endl;
    for(int i=0;i<num;i++) {
        cout << "team " << i+1 << ": ";
        cin >> arr[i].NAME;
        arr[i].POINTS = 0;
        arr[i].MATCHES = 0;
    }
}

void initial_output(struct team *arr, int num)
{
    cout << "initial ranking:" << endl << "================" << endl;
	cout << left << setw(10) << "points";
    cout << "done ";
    cout << left << setw(11) << "matches";
    cout << left << "name" << endl;
    for(int i=0;i<num;i++) {
        cout << left << setw(10) << arr[i].POINTS;
        cout << left << setw(16) << arr[i].MATCHES;
        cout << left << arr[i].NAME << endl;
    }
	cout << endl;
}

void output(struct team *arr, int num)
{
    cout << endl << "ranking" << endl << "=======" << endl;
    cout << left << setw(10) << "points";
    cout << "done ";
    cout << left << setw(11) << "matches";
    cout << left << "name" << endl;
    for(int i=0;i<num;i++) {
        cout << left << setw(10) << arr[i].POINTS;
        cout << left << setw(16) << arr[i].MATCHES;
        cout << left << arr[i].NAME << endl;
    }
    cout << endl;
}

int choose(struct team *arr, int n)
{
    cout << "teams" << endl << "=====" << endl;
    for(int i=0;i<n;i++) {
        cout << left << setw(8) << i+1;
        cout << left << arr[i].NAME << endl;
    }
    cout << "choose team by number: ";
    int index;
    cin >> index;
    return index - 1;
}

void store(struct team *arr, int n, int index, int points)
{
    arr[index].POINTS += points;
    arr[index].MATCHES++;
    for(int i=index;i>0;i--) {
        if(arr[i-1].POINTS < arr[i].POINTS) swap(arr[i], arr[i-1]);
        else if(arr[i].POINTS == arr[i-1].POINTS && arr[i].MATCHES < arr[i-1].MATCHES) swap(arr[i], arr[i-1]);
        else break;
    }
    for(int i=index;i+1<n;i++) {
        if(arr[i].POINTS < arr[i+1].POINTS) swap(arr[i], arr[i+1]);
        else if(arr[i].POINTS == arr[i+1].POINTS && arr[i].MATCHES > arr[i+1].MATCHES) swap(arr[i], arr[i+1]);
        else break;
    }
}

void add(struct team *arr, int n)
{
    cout << "please choose team 1?" << endl;
    int x = choose(arr, n);
    cout << "please choose team 2?" << endl;
    int y = choose(arr, n);
    if(x == y) {
        cout << "*** sorry teams need to be different ***" << endl << endl;
        return;
    }
    cout << "input as [points of " << arr[x].NAME << "] : [points of " << arr[y].NAME << "]? ";
    int a, b;
    char ch;
    cin >> a >> ch >> b;
    store(arr, n, x, a);
    store(arr, n, y, b);
}

void reset(struct team *arr, int n)
{
    for(int i=0;i<n;i++) {
        arr[i].MATCHES = 0;
        arr[i].POINTS = 0;
    }
}

int menu()
{
    cout << "0  end" << endl << "1  add result of a match" << endl << "2  show ranking" << endl << "9  reset points" << endl;
    cout << "your choice: ";
    int val;
    cin >> val;
    return val;
}

int main()
{
	cout << "number of teams: ";
	int noTeams;
	cin >> noTeams;
	cout << endl;

	struct team arr[noTeams];

	initialise(arr, noTeams);
	cout << endl;

	initial_output(arr, noTeams);

	while(true) {
        int op = menu();
        switch(op){
            case 0:
                break;
            case 1:
                add(arr, noTeams);
                break;
            case 2:
                output(arr, noTeams);
                break;
            case 9:
                reset(arr, noTeams);
                break;
            default:
                cout << "incorrect option!" << endl;
                break;
        }
        if(op == 0) break;
	}

    return 0;
}

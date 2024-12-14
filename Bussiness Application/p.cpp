#include <iostream>
using namespace std;
string likeordislike(string arr[], int size);
string arr[4];
int size;
main()
{
    string Catch;
    cout << "how many option u enter" << endl;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter choicer" << endl;
        cin >> arr[i];
    }
    Catch = likeordislike(arr, size);
    cout << Catch;
}
string likeordislike(string arr[], int size)
{
    string s;
    int repeat = 0;
    for(int j =0 ; j<size; j++)
    {
        if(arr[j]=="like")
        {
            s="like";
        }
        else
        {
            s="dislike";
        }
    }
    if(arr[size-1]==arr[size-2])
    {
        s="nothing";
    }
    if(arr[size]==arr[size-1])
    {
        s="nothing";
    }
    else
    {
        return s;
    }
   /* while (true)
    {
        if (arr[size - 1] == arr[size - 2])
        {
            s = "nothing";
            return s;
            break;
        }
        if (arr[size - 1] != arr[size - 2])
        {
            if (arr[size - 1] == "like")
            {
                s = "like";
                return s;
                break;
            }
            if (arr[size - 1] == "dislike")
            {
                s = "dislike";
                return s;
                break;
            }
        }
    }*/
}
#include <iostream>
#include <fstream>

using namespace std;

void Merge(int *Arr, int first, int last, int n){
    int start, middle, final;
    int *mas = new int[n];
    middle = (first + last) / 2;
    start = first;
    final = middle + 1;
    for (int i = first; i <= last; i++)
    if ((start <= middle) && ((final > last) || (Arr[start] < Arr[final]))) {
      mas[i] = Arr[start];
      start++;
    } else {
      mas[i] = Arr[final];
      final++;
    }
  for (int i = first; i <= last; i++)
    Arr[i] = mas[i];
  delete[] mas;
}

void MergeSort(int *Arr, int L, int R, int n)
{
    if(L < R){
        MergeSort(Arr, L, (L + R)/2, n);
        MergeSort(Arr, (L + R)/2 + 1, R, n);
        Merge(Arr, L, R, n);
    };
}

int main()
{
    int n;
    ifstream fin("input.txt");
    fin >> n;
    int *Arr = new int[n];
    for (int i = 1; i <= n; i++){
        fin >> Arr[i];
    }

    MergeSort(Arr, 1, n, n);

    cout << "\n";
    for (int i = 1; i <= n; i++){
        cout << Arr[i] << " ";
    }
    delete[] Arr;
    fin.close();
    return 0;
}

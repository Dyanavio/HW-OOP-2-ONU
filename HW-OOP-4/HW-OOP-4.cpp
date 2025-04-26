#include <iostream>
#include <vector>
#include "color.hpp"

using namespace std;

void generate(int* art, int n)
{
    for (int i = 0; i < n; i++)
    {
        art[i] = rand() % 15;
    }
}
void output(int* art, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << art[i] << " ";
    }
    cout << endl;
}

void insertionSort(int* art, int n)
{
    int swaps = 0;
    int checks = 0;
    for (int i = 1; i < n; i++)
    {
        int key = art[i];
        int j = i - 1;
        while (j >= 0 && art[j] > key)
        {
            checks++;
            swaps++;
            art[j + 1] = art[j];
            j = j - 1;
        }
        art[j + 1] = key;
        swaps++;
    }
    cout << "Swaps: " << swaps << " | " << "Checks: " << checks << endl;
}

void selectionSort(int* art, int n)
{
    int swaps = 0;
    int checks = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            checks++;
            if (art[j] < art[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swaps++;
            int temp = art[i];
            art[i] = art[minIndex];
            art[minIndex] = temp;
        }
    }
    cout << "Swaps: " << swaps << " | " << "Checks: " << checks << endl;
}

//void swap(int* art, int n)
//{
//    for (int i = 0; i < n / 2; i++)
//    {
//        int temp = art[i];
//        art[i] = art[n - i - 1];
//        art[n - i - 1] = temp;
//    }
//}

template <typename T>
void insertionSortGeneric(T& art, int n)
{
    int swaps = 0;
    int checks = 0;
    for (int i = 1; i < n; i++)
    {
        int key = art[i];
        int j = i - 1;
        while (j >= 0 && art[j] > key)
        {
            checks++;
            swaps++;
            art[j + 1] = art[j];
            j = j - 1;
        }
        art[j + 1] = key;
        swaps++;
    }
    cout << "Swaps: " << swaps << " | " << "Checks: " << checks << endl;
}

template <typename T>
void selectionSortGeneric(T& art, int n)
{
    int swaps = 0;
    int checks = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            checks++;
            if (art[j] < art[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swaps++;
            int temp = art[i];
            art[i] = art[minIndex];
            art[minIndex] = temp;
        }
    }
    cout << "Swaps: " << swaps << " | " << "Checks: " << checks << endl;
}

int main()
{
    srand(time(NULL));

    int n = 10;
    int* art = new int[n];
    int* sorted = new int[n] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int* reversed = new int[n] {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    

    cout << dye::green("----- Insertion sort -----") << endl;
    cout << dye::bright_white("Initial array: ") << endl;
    generate(art, n);
    output(art, n);

    insertionSort(art, n);
    cout << dye::bright_white("Sorted array: ") << endl;
    output(art, n);

    delete[] art;
    art = new int[n];
    cout << dye::blue("\n----- Selection sort -----") << endl;
    cout << dye::bright_white("Initial array: ") << endl;
    generate(art, n);
    output(art, n);

    selectionSort(art, n);
    cout << dye::bright_white("Sorted array: ") << endl;
    output(art, n);

    cout << dye::yellow("\nInsertion sort on an already sorted array: ") << endl;
    insertionSort(sorted, n);
    output(sorted, n);

    cout << dye::red("\nInsertion sort on a reversed array: ") << endl;
    insertionSort(reversed, n);
    output(reversed, n);
    delete[] reversed;
    reversed = new int[n] {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    cout << dye::light_yellow("\nSelection sort on an already sorted array: ") << endl;
    selectionSort(sorted, n);
    output(sorted, n);

    cout << dye::light_red("\nSelection sort on a reversed array: ") << endl;
    selectionSort(reversed, n);
    output(reversed, n);

    delete[] art;
    art = new int[n];
    cout << dye::light_blue("\n----- Templates -----") << endl;
    generate(art, n);
    cout << dye::bright_white("Initial array: ") << endl;
    output(art, n);
    insertionSortGeneric(art, n);
    cout << dye::light_purple("Insertion sorted array through generic: ") << endl;
    output(art, n);

    cout << dye::bright_white("Initial vector: ") << endl;
    vector<int> vtr = { 0, 14, 5, 8, 2, 11, 10, 3, 7 ,4 };
    for (int i = 0; i < vtr.size(); i++)
    {
        cout << vtr[i] << " ";
    }
    cout << endl;
    cout << dye::purple("\nInsertion sorted vector through generic: ") << endl;
    insertionSortGeneric(vtr, vtr.size());
    for (int i = 0; i < vtr.size(); i++)
    {
        cout << vtr[i] << " ";
    }
    cout << endl;

    vtr = { 0, 14, 5, 8, 2, 11, 10, 3, 7 ,4 }; // for further sorting purposes
    cout << dye::aqua("\Selection sorted vector through generic: ") << endl;
    selectionSortGeneric(vtr, vtr.size());
    for (int i = 0; i < vtr.size(); i++)
    {
        cout << vtr[i] << " ";
    }
    cout << endl;

}

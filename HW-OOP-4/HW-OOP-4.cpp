#include <iostream>
#include <vector>
#include <fstream>
#include "color.hpp"

using namespace std;

struct Data
{
    int swaps;
    int checks;
    Data(int swaps, int checks)
    {
        this->checks = checks;
        this->swaps = swaps;
    };
};

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

Data insertionSort(int* art, int n)
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
    return Data(swaps, checks);
}

Data selectionSort(int* art, int n)
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
    return Data(swaps, checks);
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

void copy(int* from, int* to, int n)
{
    for (int i = 0; i < n; i++)
    {
        to[i] = from[i];
    }
}

int main()
{
    srand(time(NULL));
    ofstream file;
    file.open("index.html");
    file << "<!DOCTYPE html>\n<html lang = \"en\">\n";
    file << "<head>\n<meta charset=\"UTF-8\">\n<meta name = \"viewport\" content = \"width=device-width, initial-scale=1.0\">\n<title>Sorting algorithms comparison</title>\n";
    file << "<style>\n";
    file << "#collapse {\n border-collapse: collapse;\n border: 3px solid black\n}\n";
    file << "</style>\n</head>\n";
    file << "<h1>Antonov - Insertion and Selection Sort</h1>\n";
    file << "<table id=\"collapse\" border=\"1\">\n";
    file << "<tr><td>Name of the algorithm</td><td>Length of the array</td><td>Arary type</td><td>Swaps</td><td>Checks</td></tr>\n";
   
    int n = 10;
    int* art = new int[n];
    int* art0 = new int[n];
    int* sorted = new int[n] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int* reversed = new int[n] {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    

    cout << dye::green("----- Insertion sort -----") << endl;
    cout << dye::bright_white("Initial array: ") << endl;
    generate(art, n);
    copy(art, art0, n);
    output(art, n);

    Data data = insertionSort(art, n);
    cout << dye::bright_white("Sorted array: ") << endl;
    output(art, n);

    file << "<tr><td>Insertion sort</td><td>10</td><td>Random</td><td>" << data.swaps << "</td><td>" << data.checks << "</td></tr>\n";

    delete[] art;
    art = new int[n];
    copy(art0, art, n);
    cout << dye::blue("\n----- Selection sort -----") << endl;
    cout << dye::bright_white("Initial array: ") << endl;
    //generate(art, n);
    output(art0, n);
    delete[] art0;

    data = selectionSort(art, n);
    cout << dye::bright_white("Sorted array: ") << endl;
    output(art, n);
    delete[] art;
    file << "<tr><td>Selection sort</td><td>10</td><td>Random</td><td>" << data.swaps << "</td><td>" << data.checks << "</td></tr>\n";

    cout << dye::yellow("\nInsertion sort on an already sorted array: ") << endl;
    data = insertionSort(sorted, n);
    output(sorted, n);
    file << "<tr><td>Insertion sort</td><td>10</td><td>Already sorted</td><td>" << data.swaps << "</td><td>" << data.checks << "</td></tr>\n";

    cout << dye::red("\nInsertion sort on a reversed array: ") << endl;
    data = insertionSort(reversed, n);
    output(reversed, n);

    file << "<tr><td>Insertion sort</td><td>10</td><td>Reversed</td><td>" << data.swaps << "</td><td>" << data.checks << "</td></tr>\n";
    delete[] reversed;
    reversed = new int[n] {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    cout << dye::light_yellow("\nSelection sort on an already sorted array: ") << endl;
    data = selectionSort(sorted, n);
    output(sorted, n);
    delete[] sorted;
    file << "<tr><td>Selection sort</td><td>10</td><td>Already sorted</td><td>" << data.swaps << "</td><td>" << data.checks << "</td></tr>\n";

    cout << dye::light_red("\nSelection sort on a reversed array: ") << endl;
    data = selectionSort(reversed, n);
    output(reversed, n);
    file << "<tr><td>Selection sort</td><td>10</td><td>Reversed</td><td>" << data.swaps << "</td><td>" << data.checks << "</td></tr>\n";

    n = 5;
    art = new int[n];
    art0 = new int[n];
    generate(art, n);
    copy(art, art0, n);

    data = insertionSort(art, n);
    file << "<tr><td>Insertion sort</td><td>5</td><td>Random</td><td>" << data.swaps << "</td><td>" << data.checks << "</td></tr>\n";
    data = selectionSort(art0, n);
    file << "<tr><td>Selection sort</td><td>5</td><td>Random</td><td>" << data.swaps << "</td><td>" << data.checks << "</td></tr>\n";

    data = insertionSort(art, n);
    file << "<tr><td>Insertion sort</td><td>5</td><td>Already sorted</td><td>" << data.swaps << "</td><td>" << data.checks << "</td></tr>\n";
    data = selectionSort(art0, n);
    file << "<tr><td>Selection sort</td><td>5</td><td>Already sorted</td><td>" << data.swaps << "</td><td>" << data.checks << "</td></tr>\n";

    reversed = new int[n] {4, 3, 2, 1, 0};
    data = insertionSort(reversed, n);
    file << "<tr><td>Insertion sort</td><td>5</td><td>Reversed</td><td>" << data.swaps << "</td><td>" << data.checks << "</td></tr>\n";
    delete[] reversed;

    reversed = new int[n] {4, 3, 2, 1, 0};
    data = selectionSort(reversed, n);
    file << "<tr><td>Selection sort</td><td>5</td><td>Reversed</td><td>" << data.swaps << "</td><td>" << data.checks << "</td></tr>\n";

    file << "</table>\n<p>If random insertion sort has more swaps than selection sort, but less checks.<br>When the array is already sorted insertion sort has 0 checks and selection sort has 0 swaps.<br>When array is reversed both algorithms have equal number of checks</p>\n</html>";



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

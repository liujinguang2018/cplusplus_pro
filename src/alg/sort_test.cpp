#include "sort.h"


static constexpr int MAX_NUMBER = 1000;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << " <1-1000000>" << endl;

        exit(1);
    }

    int number = atoi(argv[1]);
    if (number == 0 || number > 1000000)
    {
        cerr << "Usage: " << argv[0] << " <1-1000000>" << endl;

        exit(1);
    }

    int *array = generate_random_numbers<int>(number);
    if (array != NULL)
    {
        cout << "Before sorting: " << endl;
        display_sorted_array(array, number);

        //insert_sort(array, number);
        //selection_sort(array, number);
        //bubble_sort(array, number);
        comb_sort(array, number);

        cout << endl
             << "After sorting: " << endl;
        display_sorted_array(array, number);

        cout << endl
             << "Is array sorted: "
             << (is_array_sorted(array, number) ? "Yes" : "No") << endl;

        delete[] array;
    }

    return 0;
}
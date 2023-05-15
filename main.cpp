#include <iostream>
#include <vector>


/**
 * * Searches a vector using a binary search.
 *   This is useful for large vectors as it removes a lot of unnecessary checks.
 *
 * * The vector must be sorted into ascending order.
 *
 * @param nums The vector of integer values.
 * @param target An integer that we want to ensure is in the vector.
 * @returns The index of the array that the target is located. If the value does not exist, -1 is returned.
 */
int SearchVector(std::vector<int>& Nums, int Target) {

    if (!std::count(Nums.begin(), Nums.end(), Target)) return -1;

    int Begin = 0;
    int End = Nums.size() - 1;

    while (Begin <= End)
    {
        int Middle = Begin + (End - Begin) / 2;

        if (Nums[Middle] == Target) return Middle;

        else if (Nums[Middle] < Target)
        {
            Begin = Middle + 1;
        }
        else if (Nums[Middle] > Target)
        {
            End = Middle - 1;
        }
    }

    return -1;
}

/**
 * * Searches a matrix (vector of vectors) using a binary search method.
 *   Especially useful for large matrices.
 *
 * * Matrix must be non-decreasing in its rows and the first value in each row also increases.
 *
 * @param matrix The input vector of vectors of ints.
 * @param target The target to check belongs in the matrix.
 * @returns true of false depending on if the target is in the matrix.
 */
bool SearchMatrix(std::vector<std::vector<int>>& Matrix, int Target)
{
    int RowMax = Matrix.size();

    int RowIndex = 0;
    int ColIndex = Matrix[0].size() - 1;

    while (RowIndex < RowMax && ColIndex >= 0)
    {
        int CurrVal = Matrix[RowIndex][ColIndex];

        if (CurrVal == Target) return true;

        if (CurrVal < Target)
        {
            RowIndex++;
        }
        else
        {
            ColIndex--;
        }
    }

    return false;
}

int main() {

    return 0;
}

#include <iostream>
#include <vector>
#include <cmath>


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

/**
 * * An answer to the question "Given n piles of any amount of object, if a being can move
 *   these objects out of the piles at an unknown speed k, such that all the piles are empty
 *   at time h. Then what is the minimum possible value for k"
 *
 *  * Requires h > 0 and all elements in piles > 0.
 *
 * @param piles A vector of integers where piles[i] represents the number of objects in pile i.
 * @param h The number of hours the being is constrained to move all the objects in.
 * @returns The minimum possible speed such that all the piles are empty by time h.
 */
int MinMovingSpeed(std::vector<int>& Piles, int h)
{
    /*
     * Initialise binary search variables.
     * The slowest time of k is 1.
     * The fastest time of k is the maximum element of piles.
     */
    int Min = 1;
    int Max = *max_element(Piles.begin(), Piles.end());

    int Ans = -1; // Initialise a container to hold the answer, returns -1 if an answer is not found.

    // Binary search.
    while (Min <= Max)
    {
        int Mid = Min + (Max - Min) / 2;

        // Check if all piles can be eaten.
        int Hours = 0;
        bool CanMoveAllObjects = true;

        for (int PileSize : Piles)
        {
            Hours += std::ceil(PileSize / (double)Mid);

            if (Hours > h)
            {
                CanMoveAllObjects = false;
                break;
            }
        }

        if (CanMoveAllObjects)
        {
            Ans = Mid;
            Max = Mid - 1;
        }
        else
        {
            Min = Mid + 1;
        }
    }
    return Ans;
}

int main()
{
    return 0;
}

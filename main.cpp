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

/**
 * * A rotated vector is a sorted vector whose entries have been translated x times.
 *   For example [0, 1, 2, 3, 4, 5] rotated twice becomes [4, 5, 0, 1, 2, 3].
 *   The objective of this function is to find the minimum element in the rotated array.
 *
 * * The function uses a binary search method to accomplish this using the following steps..
 *   1) Initialise two integers which represent the index of the beginning and the end of the vector.
 *   2) Start iterating through steps 3), 4), 5) and 6).
 *   3) If the beginning and the end of the vector have equal values, then the vector is of size 1 so return this value.
 *   4) Calculate the index of the middle element in the vector using the arithemic mean of begin and end indexes.
 *   5) If the begin index is less than the middle index, then this half of the list is sorted, so remove this half.
 *   6) If the begin index is greater than the middle index, then this half contains the minimum element, keep this half.
 *   7) Return the beginning index of the nums vector, which is now pointing to the minimum element.
 *
 * @param nums A vector which is first sorted and then rotated.
 * @returns The value of the minimum element in the vector.
 */
int FindMinimumInRotatedVector(std::vector<int>& nums)
{
    // Initialise two variables to represent the start and end of the vector
    // These will be used to half the size of the vector on each iteration.
    int Begin = 0;
    int End = nums.size() - 1;

    while (Begin <= End)
    {
        if (nums[Begin] <= nums[End])
        {
            return nums[Begin];      // The current vector is not rotated, the first element is the smallest.
        }

        int Mid = (Begin + End) / 2; // Arithmetic mean of Begin and End gives the middle element of the vector.

        if (nums[Begin] <= nums[Mid])
        {
            Begin = Mid + 1;         // The minimum element does not exist in Begin to Mid, use the other half.
        }
        else
        {
            End = Mid;               // The minimum element does exist in this vector so do not remove the middle point.
        }
    }
    return nums[Begin];
}

/**
 * * Searches for a specific element in a sorted and then rotated array using a binary search.
 *   For example a rotated array looks like [2, 0, 1], which is the array [0, 1, 2] rotated once.
 *
 * @param nums A sorted, rotated vector of integers.
 * @param target A value we want to see if the vector contains.
 * @returns the index of the target value. If the target cannot be found, -1 is returned.
 */
int ElementSearchInSortedRotatedVector(std::vector<int>& nums, int target)
{
    int Begin = 0;
    int End = nums.size() - 1;

    while (Begin <= End)
    {
        int Mid = Begin + (End - Begin) / 2;

        if (nums[Mid] == target)
        {
            return Mid;
        }

        if (nums[Begin] <= nums[Mid])
        {
            if (nums[Begin] <= target && target < nums[Mid])
            {
                End = Mid - 1;
            }
            else
            {
                Begin = Mid + 1;
            }
        }
        else
        {
            if (nums[Mid] < target && target <= nums[End])
            {
                Begin = Mid + 1;
            }
            else
            {
                End = Mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    return 0;
}
